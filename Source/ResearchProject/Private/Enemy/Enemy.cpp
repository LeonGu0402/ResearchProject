// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"
#include <Kismet/GameplayStatics.h>
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Component/LookComponent.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LookComponent = CreateDefaultSubobject<ULookComponent>(TEXT("look Component"));
	LookComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	TargetCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	//UE_LOG(LogTemp, Warning, TEXT("Check if this working, fuckfduckfuck"));

	LookComponent->SetTarget(TargetCharacter);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bCanSeePlayer = LookComponent->CanSeeTarget();;
	if (bCanSeePlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("See"));
	}
}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	

}



//bool AEnemy::LineTraceActor(const AActor* TargetActor)
//{
//	if (TargetActor == nullptr)
//	{
//		return false;
//	}
//	FVector Start = GetActorLocation();
//	FVector End = TargetActor->GetActorLocation();
//
//	if (CanSeeActor(TargetActor, Start, End))
//	{
//		FRotator DirectionRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);
//		SetActorRotation(DirectionRotation);
//		return true;
//	}
//
//	return false;
//}
//
//bool AEnemy::CanSeeActor(const AActor* TargetActor, FVector Start, FVector End) const
//{
//	if (TargetActor == nullptr)
//	{
//		return false;
//	}
//	FHitResult Hit;
//	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;
//
//
//	//ingore player and enemy(this)
//	FCollisionQueryParams QueryParams;
//	QueryParams.AddIgnoredActor(this);
//	QueryParams.AddIgnoredActor(TargetActor);
//
//
//	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);
//
//	//GetWorld()->LineTraceMultiByChannel(TArrayResult, Start, End, Channel, QueryParams);
//
//	DrawDebugLine(GetWorld(), Start, End, FColor::Green);
//
//	return !Hit.bBlockingHit;
//}

