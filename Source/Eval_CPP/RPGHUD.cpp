#include "RPGHUD.h"
#include "Blueprint/UserWidget.h"

void ARPGHUD::BeginPlay()
{
    Super::BeginPlay();

    if (BarWidgetClass)
    {
        //Create widget from class
        BarWidgetInstance = CreateWidget<UBarWidget>(GetWorld(), BarWidgetClass);
        if (BarWidgetInstance)
        {
            //Add widget to viewport
            BarWidgetInstance->AddToViewport();
        }
    }
}

void ARPGHUD::SetPercent(const float& percent)
{
    if (BarWidgetInstance)
    {
        BarWidgetInstance->SetPercent(percent);
    }
}
