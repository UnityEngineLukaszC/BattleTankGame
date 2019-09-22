// Copyright Lukasz Cieplak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"




DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSubjectName);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void BeginPlay();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercentage() const;

	FSubjectName OnDeath;


private:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;
	
	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;
};
