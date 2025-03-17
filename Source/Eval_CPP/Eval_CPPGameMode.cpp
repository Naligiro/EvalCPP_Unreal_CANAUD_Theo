// Copyright Epic Games, Inc. All Rights Reserved.

#include "Eval_CPPGameMode.h"
#include "Eval_CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEval_CPPGameMode::AEval_CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
