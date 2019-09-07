// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Carro.generated.h"

UCLASS()
class CARRIARMATI_API ACarro : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

private:
	// Sets default values for this pawn's properties
	ACarro();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
