#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.generated.h"

class USlider;
class UTextBlock;

UCLASS()
class CLOWNDESTROYER_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float StressPercent);

	UFUNCTION(BlueprintCallable)
	void UpdateScore(int NewScore);

	UFUNCTION(BlueprintCallable)
	void AddScore(int ScoreToAdd);
	
protected:
	UPROPERTY(meta = (BindWidget))
	USlider* HealthSlider;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	int CurrentScore = 0;
	
};
