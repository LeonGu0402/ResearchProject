// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class ULookComponent;

UCLASS()
class RESEARCHPROJECT_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	/*bool LineTraceActor(const AActor* TargetActor);

	bool CanSeeActor(const AActor* TargetActor, FVector Start, FVector End) const;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bCanSeePlayer = false;

	UPROPERTY(EditAnywhere)
	TObjectPtr<ULookComponent> LookComponent;

private:
	TObjectPtr<ACharacter> TargetCharacter;
	UPROPERTY(EditAnywhere)
	TArray<FHitResult> TArrayResult;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
