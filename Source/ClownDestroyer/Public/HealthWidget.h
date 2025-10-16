#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.generated.h"

class UProgressBar;

UCLASS()
class CLOWNDESTROYER_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	/** Met à jour la barre de vie (valeur entre 0.0f et 1.0f) */
	UFUNCTION(BlueprintCallable)
	void UpdateHealth(float HealthPercent);
	
};
