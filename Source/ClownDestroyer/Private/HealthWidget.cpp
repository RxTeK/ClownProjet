#include "HealthWidget.h"
#include "Components/Slider.h"

void UHealthWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (HealthSlider)
	{
		HealthSlider->SetValue(1.0f);
	}
}

void UHealthWidget::UpdateHealth(float StressPercent)
{
	if (HealthSlider)
	{
		HealthSlider->SetValue(StressPercent);
	}
}