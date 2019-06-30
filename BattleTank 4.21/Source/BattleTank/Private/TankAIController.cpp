// Copyright Lukasz Cieplak

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = Cast<UTankAimingComponent>(GetPawn()->FindComponentByClass<UTankAimingComponent>());

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	if (AttackPlayerDebugSwitch){

		MoveToActor(PlayerTank, AcceptanceRadius);
		//AIM towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//ControlledTank->Fire(); //DO NOT FIRE EVERY FRAME
	}
}