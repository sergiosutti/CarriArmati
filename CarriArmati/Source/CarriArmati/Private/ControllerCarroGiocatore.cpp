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

	FVector HitLocation;	//paramentro out
	if (GetSightRayHitLocation(HitLocation))	//ray trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

//fa il linetrace e ritorna true se colpisce il terreno
bool AControllerCarroGiocatore::GetSightRayHitLocation(FVector& HitLocation) const
{
	//trova posizione del mirino
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screenlocation: %s"), *ScreenLocation.ToString());
	//deproject la posizione del mirino ad una direzione
	//linetrace e vediamo cosa stiamo puntando
	return true;
}