// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * ciao
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class CARRIARMATI_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)	
		float TrackMaxDrivingForce = 40000000; //F=ma (carro 40000 kg)
};
