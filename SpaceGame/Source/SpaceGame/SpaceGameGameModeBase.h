// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceGameGameModeBase.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FWave
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Fields")
		int rows{0};
	UPROPERTY(EditAnywhere, Category = "Fields")
		int colums{ 0 };
	UPROPERTY(EditAnywhere, Category = "Fields")
		float forwardSpeed{ 0 };
	UPROPERTY(EditAnywhere, Category = "Fields")
		float sidewaysSpeed{ 0 };
};

UCLASS()
class SPACEGAME_API ASpaceGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASpaceGameGameModeBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Enemies")
		float spaceBewteenEnemies{ 200 };

	UPROPERTY(EditAnywhere, Category = "Enemies")
		FVector enemiesMiddlePos;

	UPROPERTY(EditAnywhere, Category = "Enemies")
		FRotator startRotation;

	//Players base
	UPROPERTY(EditAnywhere, Category = "PlayerBase")
	TSubclassOf<class APlayerBase> playerBaseBlueprint;

	class APlayerBase* playerBase;

	UPROPERTY(EditAnywhere, Category = "PlayerBase")
		FVector playerBaseSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Enemies", meta = (TitleProperty = "Enemies"))
		TArray<FWave> waves; 
	UPROPERTY(BlueprintReadWrite)
		int currentWave{ 0 };
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
	/*UPROPERTY(EditAnywhere, Category = "Enemies")
	TArray<class Wave> waves;*/
	bool bCountingDown{ 1 };

	void SpawnEnemies();

	void MoveEnemies(float); 
	
	void Countdown(float);

	void SpawnPlayerBase();

	bool WaveDead();

	

	void GameOver(bool);

	bool playing{ 1 };
	enum MoveMode {
		right, left
	};
	MoveMode moveDirection{ right };
};


