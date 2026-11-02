#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SurvivalStatsComponent.generated.h"

UCLASS(ClassGroup=(Survival), meta=(BlueprintSpawnableComponent))
class WILDLANDSSURVIVAL_API USurvivalStatsComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    USurvivalStatsComponent();

    UPROPERTY(Replicated, BlueprintReadOnly, Category="Survival") float Health = 100.0f;
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Survival") float Hunger = 100.0f;
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Survival") float Thirst = 100.0f;
    UPROPERTY(Replicated, BlueprintReadOnly, Category="Survival") float Stamina = 100.0f;

    UFUNCTION(BlueprintCallable, Category="Survival") void ConsumeFood(float Amount);
    UFUNCTION(BlueprintCallable, Category="Survival") void ConsumeWater(float Amount);
    UFUNCTION(BlueprintCallable, Category="Survival") bool SpendStamina(float Amount);

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    void UpdateSurvival();
    FTimerHandle SurvivalTimer;
};