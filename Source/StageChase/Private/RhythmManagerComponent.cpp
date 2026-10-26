#include "RhythmManagerComponent.h"

URhythmManagerComponent::URhythmManagerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void URhythmManagerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void URhythmManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    CurrentTime += DeltaTime;

    // Remove expired notes
    ActiveNotes.RemoveAll([this](const FActiveNote& Note)
    {
        return CurrentTime > Note.TargetTime + OkWindow;
    });
}

void URhythmManagerComponent::SpawnTestNote(ERhythmLane Lane, float Delay)
{
    FActiveNote NewNote;
    NewNote.Lane = Lane;
    NewNote.TargetTime = CurrentTime + Delay;
    ActiveNotes.Add(NewNote);
}

void URhythmManagerComponent::OnRhythmInput(ERhythmLane Lane)
{
    FActiveNote* Closest = nullptr;
    float ClosestDiff = FLT_MAX;

    for (FActiveNote& Note : ActiveNotes)
    {
        if (Note.Lane != Lane) continue;
        float Diff = FMath::Abs(CurrentTime - Note.TargetTime);
        if (Diff < ClosestDiff)
        {
            ClosestDiff = Diff;
            Closest = &Note;
        }
    }

    if (Closest && ClosestDiff <= OkWindow)
    {
        JudgeNote(*Closest, ClosestDiff);
        ActiveNotes.RemoveAll([Closest](const FActiveNote& N) { return &N == Closest; });
    }
    else
    {
        // Miss
        PerformanceScore = FMath::Max(0.0f, PerformanceScore - 0.3f);
    }

    ClampPerformance();
}

void URhythmManagerComponent::JudgeNote(const FActiveNote& Note, float TimeDiff)
{
    if (TimeDiff <= SickWindow)
    {
        PerformanceScore += 1.0f;
    }
    else if (TimeDiff <= GoodWindow)
    {
        PerformanceScore += 0.5f;
    }
    else
    {
        PerformanceScore += 0.2f;
    }
}

void URhythmManagerComponent::ClampPerformance()
{
    PerformanceScore = FMath::Clamp(PerformanceScore, 0.0f, 10.0f);
}