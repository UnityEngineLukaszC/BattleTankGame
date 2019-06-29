// Copyright Lukasz Cieplak

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	if (AttackPlayerDebugSwitch){

		MoveToActor(PlayerTank, AcceptanceRadius);
		//AIM towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//ControlledTank->Fire(); //DO NOT FIRE EVERY FRAME
	}
}