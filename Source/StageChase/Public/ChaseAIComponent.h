#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChaseAIComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class STAGECHASE_API UChaseAIComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UChaseAIComponent();

    UFUNCTION(BlueprintCallable, Category = "Chase")
    void SetPerformanceScore(float Score);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chase")
    float BaseSpeed = 400.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chase")
    float SpeedPerPerformance = 80.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chase")
    float MaxSpeed = 1200.0f;

protected:
    virtual void BeginPlay() override;

private:
    float CurrentPerformance = 0.0f;
    class ACharacter* OwnerCharacter = nullptr;

    void UpdateSpeed();
};