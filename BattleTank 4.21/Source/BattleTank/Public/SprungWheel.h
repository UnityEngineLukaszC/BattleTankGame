// Copyright Lukasz Cieplak

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SprungWheel.generated.h"

class UPhysicsConstraintComponent;
class USphereComponent;

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddDrivingForce(float ForceMagniture);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	USphereComponent* Axel = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	USphereComponent* Wheel = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "Setup")
	UPhysicsConstraintComponent* Spring = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UPhysicsConstraintComponent* WheelRollConstraint = nullptr;
	

private:
	void SetupConstraints();

	void ApplyForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	float DrivingForce = 0;

};
