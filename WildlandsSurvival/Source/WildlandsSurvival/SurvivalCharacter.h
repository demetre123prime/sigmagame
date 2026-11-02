#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SurvivalCharacter.generated.h"

class USurvivalStatsComponent;
class UCameraComponent;

UCLASS()
class WILDLANDSSURVIVAL_API ASurvivalCharacter : public ACharacter
{
    GENERATED_BODY()
public:
    ASurvivalCharacter();
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Survival")
    TObjectPtr<USurvivalStatsComponent> SurvivalStats;

protected:
    virtual void BeginPlay() override;
    void MoveForward(float Value);
    void MoveRight(float Value);
    void SprintPressed();
    void SprintReleased();
    void Interact();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
    TObjectPtr<UCameraComponent> FirstPersonCamera;

    UPROPERTY(EditDefaultsOnly, Category="Movement") float WalkSpeed = 420.0f;
    UPROPERTY(EditDefaultsOnly, Category="Movement") float SprintSpeed = 650.0f;
    UPROPERTY(EditDefaultsOnly, Category="Interaction") float InteractionDistance = 300.0f;
};