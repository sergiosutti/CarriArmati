// Fill out your copyright notice in the Description page of Project Settings.

#include "ControllerCarroGiocatore.h"

ACarro* AControllerCarroGiocatore::GetControlledTank() const
{
	return Cast<ACarro>(GetPawn());
}