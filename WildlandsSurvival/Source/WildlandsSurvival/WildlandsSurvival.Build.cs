using UnrealBuildTool;

public class WildlandsSurvival : ModuleRules
{
    public WildlandsSurvival(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core", "CoreUObject", "Engine", "InputCore", "NetCore"
        });
    }
}