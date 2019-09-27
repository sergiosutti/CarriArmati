// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerCarroAI.h"
#include "Carro.h"
#include "CarriArmati.h"
//dipende anche da movement component attraverso il pathfinding

void AControllerCarroAI::BeginPlay()
{
	Super::BeginPlay();
}

void AControllerCarroAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ACarro>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ACarro>(GetPawn());

	if (ensure(PlayerTank))
	{
		//muoviti verso il giocatore
		MoveToActor(PlayerTank, AcceptanceRadius);	//controllare raggio

		//mira
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//spara
		ControlledTank->Fire();
	}
}
