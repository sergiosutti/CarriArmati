// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerCarroGiocatore.h"
#include "TankAimingComponent.h"
#include "Carro.h"

void AControllerCarroGiocatore::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (AimingComponent)
	{
		FoundAimingComponenent(AimingComponent);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("male"))
	}

	/*
	auto CarroControllato = GetControlledTank();
	if (!CarroControllato)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller giocatore non sta possedendo"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller giocatore sta possedendo %s"), *(CarroControllato->GetName()));
	}
	*/
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
		GetControlledTank()->AimAt(HitLocation);
	}
}

//fa il linetrace e ritorna true se colpisce il terreno
bool AControllerCarroGiocatore::GetSightRayHitLocation(FVector& HitLocation) const
{
	//trova posizione del mirino
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Screenlocation: %s"), *ScreenLocation.ToString());

	//deproject la posizione del mirino ad una direzione
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//linetrace e vediamo cosa stiamo puntando
		//UE_LOG(LogTemp, Warning, TEXT("Screenlocation: %s"), *LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, HitLocation);

	}
	return true;
}

bool AControllerCarroGiocatore::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0); //linetrace non ha funzionato
	//UE_LOG(LogTemp, Warning, TEXT("Non trovo niente"));
	return false; //linetrace non ha funzionato
}

bool AControllerCarroGiocatore::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}