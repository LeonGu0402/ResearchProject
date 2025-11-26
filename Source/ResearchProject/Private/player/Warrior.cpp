// Fill out your copyright notice in the Description page of Project Settings.


#include "player/Warrior.h"

void AWarrior::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, FString::Printf(TEXT("Attack from character")));
}
