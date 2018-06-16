// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank()
{
	if (controlledTank == nullptr)
	{
	return Cast<ATank>(GetPawn());
		return controlledTank;
	}
	return controlledTank;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetControlledTank() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank: %s"), *GetControlledTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Tank does not exist"));
	}
}



void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector hitLocation; // OUT

	if (GetSightRayHitLocation(hitLocation))
	{

		//TODO tell controlled tank to aim at this position
	}

}

//Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//deproject ScreenLocation to WorldDirection

	FVector CrosshairWorldLocation;
	FVector CrosshairWorldDirection;

	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CrosshairWorldLocation, CrosshairWorldDirection);
	UE_LOG(LogTemp, Warning, TEXT("Crosshair direction: %s"), *CrosshairWorldDirection.ToString());

	return true;
}
