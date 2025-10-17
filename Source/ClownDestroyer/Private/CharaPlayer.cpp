// Fill out your copyright notice in the Description page of Project Settings.


#include "CharaPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "INodeAndChannelMappings.h"
#include "PaperFlipbookComponent.h"
#include "ShootComponent.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.h"
#include "Kismet/KismetMathLibrary.h"

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

	ArrowPlayer = CreateDefaultSubobject<UArrowComponent>("Arrow Player");
	ArrowPlayer->SetupAttachment(GetCapsuleComponent());
}

// Called when the game starts or when spawned
void ACharaPlayer::BeginPlay()
{
	Super::BeginPlay();
	if (HealthWidgetClass)
	{
		HealthWidgetInstance = CreateWidget<UHealthWidget>(GetWorld(), HealthWidgetClass);
		if (HealthWidgetInstance)
		{
			HealthWidgetInstance->AddToViewport();
			HealthWidgetInstance->UpdateHealth(0.5f);
		}
	}
	
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
	FVector Vector = FVector(RotationVector.X, RotationVector.Y, 0);
	if (FMath::Abs(RotationVector.X) < 0.2f && FMath::Abs(RotationVector.Y) < 0.2f){return;}
	const FRotator Rotator = CameraComponent->GetComponentRotation();
	const FRotator YawRotation(0, Rotator.Yaw, 0);
	ArrowPlayer->SetWorldRotation(UKismetMathLibrary::MakeRotFromX(Vector));

	if (ShootComponentRef)
	{
		ShootComponentRef->ShootBeginEnter();
	}
	
	
}

// Called every frame
void ACharaPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator Rotator = UKismetMathLibrary::FindLookAtRotation(GetSprite()->GetComponentLocation(),CameraComponent->GetComponentLocation());
	GetSprite()->SetWorldRotation(FRotator(0, Rotator.Yaw - 90, Rotator.Roll - 45));
	SetStress(-PassiveStress);

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
		EnhancedInputComponent->BindAction(ShootAction,ETriggerEvent::Triggered,this,&ACharaPlayer::Rotation);
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ACharaPlayer::Move);
		EnhancedInputComponent->BindAction(ShootAction,ETriggerEvent::Canceled,this,&ACharaPlayer::Rotation);
		EnhancedInputComponent->BindAction(ShootAction,ETriggerEvent::Completed,this,&ACharaPlayer::Rotation);
	}

}

void ACharaPlayer::SetStress(float StressAdd)
{
	float Stressing = StressAdd;
	if (rage && FMath::Abs(Stressing) >= 1)
	{
		Stressing = 0.f;
		GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,"Stressing");
	}
	Stress += Stressing;
	
	if (GetStress() <= 0)
	{
		if (EndGameClass && !EndGameInstance)
		{
			EndGameInstance = CreateWidget<UEndGame>(GetWorld(), EndGameClass);
			if (EndGameInstance)
			{
				EndGameInstance->AddToViewport();
			}
		}	
	}
	if (GetStress() >= 100)
	{
		rage = true;
		GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,"Rage");

	}
	if (GetStress() <= 50 && rage)
	{
		rage = false;
		GEngine->AddOnScreenDebugMessage(-1,2.f,FColor::Red,"NoRage");
	}
	Stress = FMath::Clamp(Stress, 0.0f, 100.0f);
}

float ACharaPlayer::GetStress()
{
	return Stress;
}

