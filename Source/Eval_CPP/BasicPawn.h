// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "Camera/CameraComponent.h"
#include "BasicPawn.generated.h"

UCLASS()
class EVAL_CPP_API ABasicPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasicPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyControllerChanged() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void SetMappingContext(bool value);
	void Move(const FInputActionValue& Value);
	void Turn(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* InspectMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RotateAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objects", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objects", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* mCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	FVector mCameraOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	FRotator mCameraDefaultRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float mMovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float mRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inertia", meta = (AllowPrivateAccess = "true"))
	float mMovementInertia;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inertia", meta = (AllowPrivateAccess = "true"))
	float mRotationInertia;

	FVector mRotationInput;
	FVector mInertiaInput;

	FVector CurrentVelocity;
	FRotator CurrentRotationSpeed;
};
