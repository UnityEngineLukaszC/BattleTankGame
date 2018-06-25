// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetContolledTank() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI tank spawned: %s"), *GetContolledTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI does not controll any tank"));
	}

	if (GetPlayerTank() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank: %s"), *GetPlayerTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI did not find player tank"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//TO DO Move towards the player

		//AIM towards the player
		GetContolledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
}

ATank* ATankAIController::GetContolledTank()
{
	if (controlledTank == nullptr)
	{
		controlledTank = Cast<ATank>(GetPawn());
		return controlledTank;
	}
	return controlledTank;
	
}

ATank* ATankAIController::GetPlayerTank()
{
	if (playerTank == nullptr)
	{
		auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
		if (playerPawn != nullptr)
		{
			playerTank = Cast<ATank>(playerPawn);
		}
		return playerTank;
	}
	return playerTank;

}
