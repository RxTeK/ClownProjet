#pragma once
 
#include "CoreMinimal.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/Actor.h"
#include "ParentAI.h"
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

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Projectile")
	int Damage;
 
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnComponentOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};