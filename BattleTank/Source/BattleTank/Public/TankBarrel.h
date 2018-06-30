// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/*
 Holds barrel's properties and elevate method
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed);
	
private:

	//Allows maximum degrees per second
	UPROPERTY(EditAnywhere, Category = "Setup")
    float MaxDegreesPerSecond = 5;
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaximumElevation = 40;
	UPROPERTY(EditAnywhere, Category = "Setup")
    float MinimumElevation = 0;
	
};
