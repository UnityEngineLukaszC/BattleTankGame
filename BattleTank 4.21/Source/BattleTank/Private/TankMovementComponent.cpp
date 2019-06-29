// Copyright Lukasz Cieplak

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "DrawDebugHelpers.h"

void UTankMovementComponent::InitialiseTankMovementComponent(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet && RightTrackToSet)) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{

	auto ForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiMoveIntention = MoveVelocity.GetSafeNormal();


	/*auto StartLocation = GetOwner()->GetActorLocation();
	auto EndLocation = StartLocation + AiMoveIntention * 500;

	DrawDebugLine(
		GetWorld(),
		StartLocation,
		EndLocation,
		FColor(0, 255, 0),
		false, -1, 0,
		12.333
	);*/

	auto MoveThrow = FVector::DotProduct(ForwardVector, AiMoveIntention);
	IntendMoveForward(MoveThrow);

	auto TurnThrow = FVector::CrossProduct(ForwardVector, AiMoveIntention).Z;
	IntendTurnRight(TurnThrow);


}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }


	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO prevent double speed

}

void UTankMovementComponent::IntendTurnRight(float Throw)
{

	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO prevent double speed

}


