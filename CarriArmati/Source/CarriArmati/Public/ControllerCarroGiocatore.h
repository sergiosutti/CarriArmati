// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Carro.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ControllerCarroGiocatore.generated.h"	//ultimo include per forza

/**
 * 
 */
UCLASS()
class CARRIARMATI_API AControllerCarroGiocatore : public APlayerController
{
	GENERATED_BODY()

private:
	ACarro* GetControlledTank() const;

	virtual void BeginPlay() override;	//override controlla che BeginPlay si trova più in alto nella gerarchia

	virtual void Tick(float DeltaTime) override;

	//Comincia a muovere la canna verso il mirino
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
