#include "SurvivalStatsComponent.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

USurvivalStatsComponent::USurvivalStatsComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
}

void USurvivalStatsComponent::BeginPlay()
{
    Super::BeginPlay();
    if (GetOwner() && GetOwner()->HasAuthority())
        GetWorld()->GetTimerManager().SetTimer(SurvivalTimer, this, &USurvivalStatsComponent::UpdateSurvival, 1.0f, true);
}

void USurvivalStatsComponent::UpdateSurvival()
{
    Hunger = FMath::Max(0.0f, Hunger - 0.035f);
    Thirst = FMath::Max(0.0f, Thirst - 0.06f);
    if (Hunger <= 0.0f || Thirst <= 0.0f) Health = FMath::Max(0.0f, Health - 0.15f);
    Stamina = FMath::Min(100.0f, Stamina + 1.5f);
}

void USurvivalStatsComponent::ConsumeFood(float Amount)
{
    if (GetOwner() && GetOwner()->HasAuthority()) Hunger = FMath::Clamp(Hunger + Amount, 0.0f, 100.0f);
}
void USurvivalStatsComponent::ConsumeWater(float Amount)
{
    if (GetOwner() && GetOwner()->HasAuthority()) Thirst = FMath::Clamp(Thirst + Amount, 0.0f, 100.0f);
}
bool USurvivalStatsComponent::SpendStamina(float Amount)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || Stamina < Amount) return false;
    Stamina = FMath::Max(0.0f, Stamina - Amount);
    return true;
}
void USurvivalStatsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(USurvivalStatsComponent, Health);
    DOREPLIFETIME(USurvivalStatsComponent, Hunger);
    DOREPLIFETIME(USurvivalStatsComponent, Thirst);
    DOREPLIFETIME(USurvivalStatsComponent, Stamina);
}