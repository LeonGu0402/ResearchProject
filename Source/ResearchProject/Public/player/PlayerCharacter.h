// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class RESEARCHPROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	//UFUNCTION test
	UFUNCTION(BlueprintCallable)
	void CallableFunction();
	UFUNCTION(BlueprintPure)
	bool PureFucntion();

	//BluePrintInplimentation
	UFUNCTION(BlueprintImplementableEvent)
	void MyBluePrintFunction();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> PlayerCamera;

protected:
	virtual void BeginPlay() override;

	//UPROPERTY test
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "U|test")
	float testLine = 0.f;


public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
