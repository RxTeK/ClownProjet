#include "HealthWidget.h"
#include "Components/ProgressBar.h"

void UHealthWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(1.0f); // Vie pleine par défaut
	}
}

void UHealthWidget::UpdateHealth(float HealthPercent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(HealthPercent);
	}
}
