// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CPPPlayerController.h"

void ACPPPlayerController::OnPossess(APawn* InPawn)
{
	UE_LOG(LogTemp, Warning, TEXT("ACPPPlayerController::OnPossess"));
	Super::OnPossess(InPawn);
	if (InPawn) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn OnPossess"));
		InPawn->SetActorLocation(FVector(900.F, 1000.F, 100.F));

	}
}
