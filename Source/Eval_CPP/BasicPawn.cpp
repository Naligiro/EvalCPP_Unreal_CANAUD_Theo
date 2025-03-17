#include "BasicPawn.h"

// Sets default values
ABasicPawn::ABasicPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    m_Mesh->SetupAttachment(RootComponent);

    mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    mCamera->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh>
        cubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
    if (cubeVisualAsset.Succeeded())
    {
        m_Mesh->SetStaticMesh(cubeVisualAsset.Object);
        m_Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

    InspectMappingContext = nullptr;
    MoveAction = nullptr;
    RotateAction = nullptr;
    mMovementSpeed = 300.0f;
    mRotationSpeed = 100.0f;
    mMovementInertia = 0.1f;
    mRotationInertia = 0.1f;
    CurrentVelocity = FVector::ZeroVector;
    CurrentRotationSpeed = FRotator::ZeroRotator;
}

// Called when the game starts or when spawned
void ABasicPawn::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABasicPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //Applies inertia to the movement
    CurrentVelocity = FMath::Lerp(CurrentVelocity, mInertiaInput * mMovementSpeed, mMovementInertia);
    AddActorLocalOffset(CurrentVelocity * DeltaTime, true);

    //Applies inertia to the rotation
    CurrentRotationSpeed = FMath::Lerp(CurrentRotationSpeed, FRotator(0.0f, mRotationInput.Y * mRotationSpeed, 0.0f), mRotationInertia);
    AddActorLocalRotation(CurrentRotationSpeed * DeltaTime);
}

void ABasicPawn::NotifyControllerChanged()
{
    Super::NotifyControllerChanged();

    SetMappingContext(true);
}

// Called to bind functionality to input
void ABasicPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABasicPawn::Move);
        EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &ABasicPawn::Turn);
    }
}

void ABasicPawn::SetMappingContext(bool value)
{
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            if (value)
            {
                Subsystem->AddMappingContext(InspectMappingContext, 0);
            }
            else
            {
                Subsystem->RemoveMappingContext(InspectMappingContext);
            }
        }
    }
}

void ABasicPawn::Move(const FInputActionValue& Value)
{
    float MoveValue = Value.Get<float>();

    //Updates the inertia input
    mInertiaInput = FVector(MoveValue, 0.0f, 0.0f);
}

void ABasicPawn::Turn(const FInputActionValue& Value)
{
    float TurnValue = Value.Get<float>();

    //Update the rotation input
    mRotationInput = FVector(0.0f, TurnValue, 0.0f);
}