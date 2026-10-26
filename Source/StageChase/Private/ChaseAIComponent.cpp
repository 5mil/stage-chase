#include "ChaseAIComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UChaseAIComponent::UChaseAIComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UChaseAIComponent::BeginPlay()
{
    Super::BeginPlay();
    OwnerCharacter = Cast<ACharacter>(GetOwner());
}

void UChaseAIComponent::SetPerformanceScore(float Score)
{
    CurrentPerformance = FMath::Clamp(Score, 0.0f, 10.0f);
    UpdateSpeed();
}

void UChaseAIComponent::UpdateSpeed()
{
    if (!OwnerCharacter) return;

    float NewSpeed = BaseSpeed + (CurrentPerformance * SpeedPerPerformance);
    NewSpeed = FMath::Min(NewSpeed, MaxSpeed);

    if (UCharacterMovementComponent* MoveComp = OwnerCharacter->GetCharacterMovement())
    {
        MoveComp->MaxWalkSpeed = NewSpeed;
    }
}