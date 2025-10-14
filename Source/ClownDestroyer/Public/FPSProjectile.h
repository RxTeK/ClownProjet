#pragma once
 
#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/Actor.h"
#include "FPSProjectile.generated.h"
 
class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;
 
UCLASS(Blueprintable)
class CLOWNDESTROYER_API AFPSProjectile : public AActor
{
	GENERATED_BODY()
 
public:
	AFPSProjectile();
 
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* CollisionComponent;
 
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	UProjectileMovementComponent* ProjectileMovementComponent;
 
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Projectile")
	UPaperFlipbookComponent* ProjectileMeshComponent;
 
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void FireInDirection(const FVector& ShootDirection);
 
protected:
	virtual void BeginPlay() override;
};