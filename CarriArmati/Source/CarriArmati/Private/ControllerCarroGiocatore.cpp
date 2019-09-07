// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerCarroGiocatore.h"

void AControllerCarroGiocatore::BeginPlay()
{
	Super::BeginPlay();

	auto CarroControllato = GetControlledTank();
	if (!CarroControllato)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller giocatore non sta possedendo"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller giocatore sta possedendo %s"), *(CarroControllato->GetName()));
	}
}

void AControllerCarroGiocatore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ACarro* AControllerCarroGiocatore::GetControlledTank() const
{
	return Cast<ACarro>(GetPawn());
}

void AControllerCarroGiocatore::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}
}