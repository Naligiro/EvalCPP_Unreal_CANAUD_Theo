#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Curves/CurveLinearColor.h"
#include "BarWidget.generated.h"

UCLASS()
class EVAL_CPP_API UBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable, Category = "Bar Widget")
    void SetPercent(const float& percent);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
    UProgressBar* ProgressBar;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bar Widget", meta = (AllowPrivateAccess = true))
    UCurveLinearColor* GradientCurve;
};
