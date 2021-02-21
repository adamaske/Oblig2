// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAME_API ASpaceGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASpaceGameGameModeBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Enemies")
		int rows{ 5 };

	UPROPERTY(EditAnywhere, Category = "Enemies")
		int columns{ 5 };

	UPROPERTY(EditAnywhere, Category = "Enemies")
		float spaceBewteenEnemies{ 200 };

	UPROPERTY(EditAnywhere, Category = "Enemies")
		FVector enemiesMiddlePos;

	UPROPERTY(EditAnywhere, Category = "Enemies")
		FRotator startRotation;

	UPROPERTY(EditAnywhere, Category = "Enemies")
		float sidewaysSpeed{ 200 };
	UPROPERTY(EditAnywhere, Category = "Enemies")
		float forwardSpeed{ 100 };
private:
	UPROPERTY(EditAnywhere, Category = "Enemies");
	TSubclassOf<class AEnemy> EnemyBlueprint;

	TArray<class AEnemy*> enemies;

	UPROPERTY(EditAnywhere, Category = "Enemies")
	float timePerDirection{ 2.f };

	UPROPERTY(EditAnywhere, Category = "Enemies")
	float timeElapsed{ 0.f };

	//Start countdown
	bool bEnemiesCanMove{ 0 };
	UPROPERTY(EditAnywhere, Category = "Enemies")
		float countdownTIme{ 3 };
	bool bCountingDown{ 1 };
	void SpawnEnemies();

	void MoveEnemies(float); 
	
	void Countdown(float);

	enum MoveMode {
		right, left
	};
	MoveMode moveDirection{ right };
};
