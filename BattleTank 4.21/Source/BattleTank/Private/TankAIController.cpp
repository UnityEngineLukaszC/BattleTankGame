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
	auto AiTankAimingComponent = Cast<UTankAimingComponent>(GetPawn()->FindComponentByClass<UTankAimingComponent>());

	if (!ensure(PlayerTank && AiTankAimingComponent)) { return; }

	if (AttackPlayerDebugSwitch){

		MoveToActor(PlayerTank, AcceptanceRadius);
		//AIM towards the player
		AiTankAimingComponent->AimAt(PlayerTank->GetActorLocation());

		if (AiTankAimingComponent->GetFiringStatus() == EFiringStatus::Locked )
		{
			AiTankAimingComponent->Fire(); //DO NOT FIRE EVERY FRAME
		}
	}
}