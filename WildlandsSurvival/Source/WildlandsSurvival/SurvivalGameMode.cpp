#include "SurvivalGameMode.h"
#include "SurvivalCharacter.h"
ASurvivalGameMode::ASurvivalGameMode()
{
    DefaultPawnClass = ASurvivalCharacter::StaticClass();
}