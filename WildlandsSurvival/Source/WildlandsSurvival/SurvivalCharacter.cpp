#include "SurvivalCharacter.h"
#include "SurvivalStatsComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

ASurvivalCharacter::ASurvivalCharacter()
{
    bReplicates = true;
    GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
    FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));
    FirstPersonCamera->bUsePawnControlRotation = true;
    SurvivalStats = CreateDefaultSubobject<USurvivalStatsComponent>(TEXT("SurvivalStats"));
}
void ASurvivalCharacter::BeginPlay()
{
    Super::BeginPlay();
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}
void ASurvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &ASurvivalCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASurvivalCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ASurvivalCharacter::Interact);
    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ASurvivalCharacter::SprintPressed);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ASurvivalCharacter::SprintReleased);
}
void ASurvivalCharacter::MoveForward(float Value)
{
    if (Controller && FMath::Abs(Value) > KINDA_SMALL_NUMBER) AddMovementInput(GetActorForwardVector(), Value);
}
void ASurvivalCharacter::MoveRight(float Value)
{
    if (Controller && FMath::Abs(Value) > KINDA_SMALL_NUMBER) AddMovementInput(GetActorRightVector(), Value);
}
void ASurvivalCharacter::SprintPressed()
{
    GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}
void ASurvivalCharacter::SprintReleased()
{
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}
void ASurvivalCharacter::Interact()
{
    if (!Controller) return;
    FVector Start;
    FRotator ViewRotation;
    Controller->GetPlayerViewPoint(Start, ViewRotation);
    const FVector End = Start + ViewRotation.Vector() * InteractionDistance;
    FHitResult Hit;
    FCollisionQueryParams Params(SCENE_QUERY_STAT(SurvivalInteract), false, this);
    if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
    {
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green,
                FString::Printf(TEXT("Looked at: %s"), *Hit.GetActor()->GetName()));
    }
}