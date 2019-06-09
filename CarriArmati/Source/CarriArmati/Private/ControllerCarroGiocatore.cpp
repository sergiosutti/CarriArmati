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

ACarro* AControllerCarroGiocatore::GetControlledTank() const
{
	return Cast<ACarro>(GetPawn());
}