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

public:
	ACarro* GetControlledTank() const;

	virtual void BeginPlay() override;	//override controlla che BeginPlay si trova pi� in alto nella gerarchia

	virtual void Tick(float DeltaTime) override;

	//Comincia a muovere la canna verso il mirino
	void AimTowardsCrosshair();
	
};
