#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BarWidget.h"
#include "RPGHUD.generated.h"

UCLASS()
class EVAL_CPP_API ARPGHUD : public AHUD
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category = "HUD")
    void SetPercent(const float& percent);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
    TSubclassOf<UBarWidget> BarWidgetClass;

    UPROPERTY()
    UBarWidget* BarWidgetInstance;
};
