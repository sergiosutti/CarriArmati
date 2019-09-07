// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerCarroAI.h"
#include "CarriArmati.h"


void AControllerCarroAI::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller non trova PT"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI ha trovato PT %s"), *(PlayerTank->GetName()));
	}
}

ACarro* AControllerCarroAI::GetControlledTank() const
{
	return Cast<ACarro>(GetPawn());
}

ACarro* AControllerCarroAI::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return(nullptr);
	}

	return Cast<ACarro>(PlayerPawn);
}