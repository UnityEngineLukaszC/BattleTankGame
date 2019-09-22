// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "SprungWheel.h"
#include "WheelSpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -5, 5);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();

	for (ASprungWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<class ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> Wheels;

	TArray <USceneComponent*> WheelSpawnPoints;
	GetChildrenComponents(false, WheelSpawnPoints);

	for (USceneComponent* WheelSpawnPoint : WheelSpawnPoints)
	{
		AActor* SpawnedActor = Cast<UWheelSpawnPoint>(WheelSpawnPoint)->GetSpawnedActor();
		ASprungWheel* SprungWheel= Cast<ASprungWheel>(SpawnedActor);
		if (!SprungWheel) continue;

		Wheels.Add(SprungWheel);
	}
	return Wheels;
}


