// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	float AcceptanceRadius = 3000;	//Quando � vicino quando si ferma (in cm?)
};
