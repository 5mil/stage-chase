#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RhythmManagerComponent.generated.h"

UENUM(BlueprintType)
enum class ERhythmLane : uint8
{
    Left,
    Down,
    Up,
    Right
};

USTRUCT(BlueprintType)
struct FActiveNote
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    ERhythmLane Lane;

    UPROPERTY(BlueprintReadOnly)
    float TargetTime;

    UPROPERTY(BlueprintReadOnly)
    bool bIsHold = false;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class STAGECHASE_API URhythmManagerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    URhythmManagerComponent();

    UFUNCTION(BlueprintCallable, Category = "Rhythm")
    void OnRhythmInput(ERhythmLane Lane);

    UFUNCTION(BlueprintCallable, Category = "Rhythm")
    void SpawnTestNote(ERhythmLane Lane, float Delay = 1.0f);

    UPROPERTY(BlueprintReadWrite, Category = "Rhythm")
    float PerformanceScore = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rhythm")
    float SickWindow = 0.1f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rhythm")
    float GoodWindow = 0.2f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rhythm")
    float OkWindow = 0.3f;

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    TArray<FActiveNote> ActiveNotes;
    float CurrentTime = 0.0f;

    void JudgeNote(const FActiveNote& Note, float TimeDiff);
    void ClampPerformance();
};