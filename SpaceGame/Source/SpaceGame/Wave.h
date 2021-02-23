// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SPACEGAME_API Wave
{
public:
	Wave();
	~Wave();
	
	int rows;
	int colums;

	float forwardSpeed;
	float sidewaysSpeed;
};
