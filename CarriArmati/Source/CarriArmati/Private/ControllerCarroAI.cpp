// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerCarroAI.h"
#include "TankAimingComponent.h"
#include "CarriArmati.h"
//dipende anche da movement component attraverso il pathfinding

void AControllerCarroAI::BeginPlay()
{
	Super::BeginPlay();
}

void AControllerCarroAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	{
		//muoviti verso il giocatore
		MoveToActor(PlayerTank, AcceptanceRadius);	//controllare raggio

		//mira
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//spara
		//ControlledTank->Fire();
	}
}
