// Fill out your copyright notice in the Description page of Project Settings.


#include "CharaPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "ShootComponent.h"

// Sets default values
ACharaPlayer::ACharaPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring Arms");
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);

	ShootComponentRef = CreateDefaultSubobject<UShootComponent>("SootComponent");
}

// Called when the game starts or when spawned
void ACharaPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharaPlayer::Move(const FInputActionValue& Value)
{
	MovementVector = Value.Get<FVector2D>();

	if (FMath::Abs(MovementVector.X) < 0.2f && FMath::Abs(MovementVector.Y) < 0.2f){return;}
	
	const FRotator Rotator = CameraComponent->GetComponentRotation();
	const FRotator YawRotation(0, Rotator.Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			
	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void ACharaPlayer::Rotation(const FInputActionValue& Value)
{
	RotationVector = Value.Get<FVector2D>();

	if (FMath::Abs(RotationVector.X) < 0.2f && FMath::Abs(RotationVector.Y) < 0.2f){return;}
	const FRotator Rotator = CameraComponent->GetComponentRotation();
	const FRotator YawRotation(0, Rotator.Yaw, 0);
	
}

// Called every frame
void ACharaPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharaPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(ShootAction,ETriggerEvent::Triggered,ShootComponentRef,&UShootComponent::ShootStart);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ACharaPlayer::Move);
		EnhancedInputComponent->BindAction(ShootAction,ETriggerEvent::Canceled,ShootComponentRef,&UShootComponent::ShootEnd);
		EnhancedInputComponent->BindAction(ShootAction,ETriggerEvent::Completed,ShootComponentRef,&UShootComponent::ShootEnd);
	}

}

