// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Eval_CPP : ModuleRules
{
	public Eval_CPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
