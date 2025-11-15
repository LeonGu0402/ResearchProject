// Fill out your copyright notice in the Description page of Project Settings.


#include "player/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//adding the spring arm to the mesh in the BP
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SetRelativeRotation(FRotator(-40.f, 0.f, 0.f));//pitch yaw roll
	//if change the rootcomponent
	//SetRootComponent(CameraBoom);

	//adding cemara to the arm
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Player Camera");
	PlayerCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	MyBluePrintFunction();
	UE_LOG(LogTemp, Warning, TEXT("CameraBoom : TargetArmLength: %f"), CameraBoom->TargetArmLength);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, FString::Printf(TEXT("CameraBoom : TargetArmLength: %f"), CameraBoom->TargetArmLength));

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//test functions

void APlayerCharacter::CallableFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Callable"));
}

bool APlayerCharacter::PureFucntion()
{
	return false;
}

