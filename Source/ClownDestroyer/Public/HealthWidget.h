#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.generated.h"

class USlider;

UCLASS()
class CLOWNDESTROYER_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float HealthPercent);

protected:
	UPROPERTY(meta = (BindWidget))
	USlider* HealthSlider;
};
