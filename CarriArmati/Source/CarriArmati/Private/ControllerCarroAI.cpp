// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerCarroAI.h"
#include "CarriArmati.h"


void AControllerCarroAI::BeginPlay()
{
	Super::BeginPlay();

	auto CarroControllato = GetControlledTank();
	if (!CarroControllato)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller AI non sta possedendo"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI sta possedendo %s"), *(CarroControllato->GetName()));
	}
}

ACarro* AControllerCarroAI::GetControlledTank() const
{
	return Cast<ACarro>(GetPawn());
}