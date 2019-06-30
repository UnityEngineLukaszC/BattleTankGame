// Copyright Lukasz Cieplak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forword declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void BeginPlay();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();


private:	

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000; //Sensible launch speed

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;

	//local barrel reference for firing projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
	
};
