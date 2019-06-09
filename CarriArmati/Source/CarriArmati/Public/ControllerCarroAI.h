// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Carro.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "ControllerCarroAI.generated.h"

/**
 * 
 */
UCLASS()
class CARRIARMATI_API AControllerCarroAI : public AAIController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	ACarro* GetControlledTank() const;
};
