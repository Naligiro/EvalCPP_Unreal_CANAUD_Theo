#include "DestructionComponent.h"

UDestructionComponent::UDestructionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	m_Range = 1000.0f;
	m_Camera = nullptr;
}

// Called when the game starts
void UDestructionComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UDestructionComponent::DestructionBeam()
{
	if (!m_Camera) return;

	//Obtain the direction and position of the camera
	FVector Start = m_Camera->GetComponentLocation();
	FVector ForwardVector = m_Camera->GetForwardVector();
	FVector End = Start + (ForwardVector * m_Range);

	FHitResult Hit;

	//Linetrace parameters
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	//Linetrace
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start,
		End,
		ECollisionChannel::ECC_Visibility,
		Params
	);

	//Draw ray
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 5.0f);

	//Verify if ray has hit something
	if (bHit && Hit.GetActor())
	{
		//Verify if the actor implements IDestructible interface
		if (Hit.GetActor()->GetClass()->ImplementsInterface(UDestructible::StaticClass()))
		{
			//Call DestroyObject function from interface
			IDestructible::Execute_DestroyObject(Hit.GetActor());
		}
	}
}
