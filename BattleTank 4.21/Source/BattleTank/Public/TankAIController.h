// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:

	//This switch allows to turn off attacking the player for debuging purpose
	UPROPERTY(EditDefaultsOnly, Category = "Debug")
	bool AttackPlayerDebugSwitch = false;

	//How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;

	UFUNCTION()
	void OnAITankDeath();
	
private:


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;



	
};
