#include "HealthWidget.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"

void UHealthWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (HealthSlider)
	{
		HealthSlider->SetValue(1.0f);
	}

	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: 0"))));
	}
}

void UHealthWidget::UpdateHealth(float StressPercent)
{
	if (HealthSlider)
	{
		HealthSlider->SetValue(StressPercent);
	}
}

void UHealthWidget::UpdateScore(int NewScore)
{
	CurrentScore = NewScore;
    
	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), CurrentScore)));
	}
}

void UHealthWidget::AddScore(int ScoreToAdd)
{
	CurrentScore += ScoreToAdd;
    
	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), CurrentScore)));
	}
}
