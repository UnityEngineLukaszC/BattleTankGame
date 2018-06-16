// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetContolledPawn() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank spawned: %s"), *GetContolledPawn()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI does not controll any tank"));
	}
}

ATank* ATankAIController::GetContolledPawn()
{
	if (controlledTank == nullptr)
	{
		controlledTank = Cast<ATank>(GetPawn());
		return controlledTank;
	}
	return controlledTank;
	
}

