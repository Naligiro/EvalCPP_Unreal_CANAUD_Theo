#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destructible.h"
#include "DestructibleCube.generated.h"

UCLASS()
class EVAL_CPP_API ADestructibleCube : public AActor, public IDestructible
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleCube();
	~ADestructibleCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface")
	void DestroyObject();

	void DestroyObject_Implementation() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destructible Cube", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_Mesh;
};
