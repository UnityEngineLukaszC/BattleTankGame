// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	//Set track throttle
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	//Max force per track by default
	UPROPERTY(EditDefaultsOnly)
    float TrackMaxDrivingForce = 40000000; // Assume 40 tonne tank, and 1g acceleration

private:
	UTankTrack();

	void DriveTrack(float CurrentThrottle);

	TArray<class ASprungWheel*> GetWheels() const;

};
