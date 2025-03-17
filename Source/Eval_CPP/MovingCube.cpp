#include "MovingCube.h"

// Sets default values
AMovingCube::AMovingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	m_Mesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		cubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (cubeVisualAsset.Succeeded())
	{
		m_Mesh->SetStaticMesh(cubeVisualAsset.Object);
		m_Mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AMovingCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_RunningTime += DeltaTime;
	FVector NewLocation = GetActorLocation();
	float DeltaHeightX = FMath::Sin(m_RunningTime * m_OscillationSpeed) * m_OscillationAmplitude;
	float DeltaHeightY = FMath::Cos(m_RunningTime * m_OscillationSpeed) * m_OscillationAmplitude;
	NewLocation.X += DeltaHeightX;
	NewLocation.Y += DeltaHeightY;
	SetActorLocation(NewLocation);
}

