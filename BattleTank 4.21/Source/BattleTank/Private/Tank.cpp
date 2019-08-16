// Copyright Lukasz Cieplak
#include "Tank.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0 , CurrentHealth);
	CurrentHealth = CurrentHealth - DamageToApply;

	UE_LOG(LogTemp, Warning, TEXT("DamageAmount=%f, DamageToApply=%d"), DamageAmount,DamageToApply);

	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Dead"));
	}
	return DamageToApply;
}

float ATank::GetHealthPercentage() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}
