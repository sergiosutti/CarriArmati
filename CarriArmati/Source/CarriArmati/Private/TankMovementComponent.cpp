// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//non serve Super perché stiamo sostituendo la funzione

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);	//prodotto scalare per trovare quanto sono paralleli, vedi coseno tra i due vettori
	IntendMoveForward(ForwardThrow);

	auto RightTrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;	//.Z perché il prodotto vettoriale da un vettore come soluzione e non uno scalare
	IntendTurnRight(RightTrow);



}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"), Throw);

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"), Throw);

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}