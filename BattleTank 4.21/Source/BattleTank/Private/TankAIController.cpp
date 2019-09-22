// Copyright Lukasz Cieplak

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h"


void ATankAIController::OnAITankDeath()
{
	if (!ensure(GetPawn())) { return; }

	GetPawn()->DetachFromControllerPendingDestroy();
	UE_LOG(LogTemp,Warning,TEXT("Enemy dead"))
	//GetPawn()->Destroy();
}

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

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast <ATank>(InPawn);
		if (!ensure(PossesedTank)) { return; }

		//Subscribe our local method to the tanks's death event
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnAITankDeath);

	}
}
