#include "BarWidget.h"

void UBarWidget::NativeConstruct()
{
    Super::NativeConstruct();

    //Searches the ProgressBar by name
    ProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("ProgressBar")));

    if (!ProgressBar)
    {
        UE_LOG(LogTemp, Warning, TEXT("ProgressBar not found in widget!"));
    }
}

void UBarWidget::SetPercent(const float& percent)
{
    if (ProgressBar)
    {
        ProgressBar->SetPercent(FMath::Clamp(percent, 0.0f, 1.0f));

        //Change color depending on how much it's filled
        if (GradientCurve)
        {
            FLinearColor Color = GradientCurve->GetLinearColorValue(percent);
            ProgressBar->SetFillColorAndOpacity(Color);
        }
    }
}