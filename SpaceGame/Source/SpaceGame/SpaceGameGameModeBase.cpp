// Copyright Epic Games, Inc. All Rights Reserved.


#include "SpaceGameGameModeBase.h"
#include "SpaceGame.h"
#include "Enemy.h"
#include "PlayerBase.h"
#include "Engine/World.h"

ASpaceGameGameModeBase::ASpaceGameGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;
	
}

void ASpaceGameGameModeBase::BeginPlay() {
	Super::BeginPlay();

	//Set the first wave to 0
	currentWave = 0;
	//Spawns the players base
	SpawnPlayerBase();
	//Spawn enemies
	SpawnEnemies();
	//Sets the first time to half to account for it starting in the middle
	timeElapsed = timePerDirection / 2;
	//Starts the movement to the right
	moveDirection = right;
	//Start countdown
	bCountingDown = true;
	//Sets the game to playing and lets the tick function continue
	playing = true;
}

void ASpaceGameGameModeBase::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (!playing) {
		return;
	}
	if (bCountingDown) {
		Countdown(DeltaTime);
	}
	if (bEnemiesCanMove) {
		MoveEnemies(DeltaTime);
	}
	//Checks if the players base is alive, if not end the game
	if (playerBase->bDead) {
		//Loose 
		GameOver(false);
		playerBase->Destroy();
	}
	//Checks if the wave is dead, if so go to next wave and spawn enemies
	if (WaveDead()) {
		SpawnEnemies();
	}
}

void ASpaceGameGameModeBase::SpawnEnemies() {
	//Finds the middle of where to spawn the enemies
	FVector startPos = enemiesMiddlePos;
	//Adds half of rows and amounts in meters by * spaceBetweenEnemies
	startPos.X += (waves[currentWave].colums / 2) * spaceBewteenEnemies;
	startPos.Y -= (waves[currentWave].rows / 2) * spaceBewteenEnemies;
	//Sets the current spawn position
	FVector currentPos = startPos;
	UWorld* world = GetWorld();
	if (world) {
		//goes through each row and colums and spawns a Enemy at the currentPos
		for (int i{ 0 }; i < waves[currentWave].colums; i++)
		{
			for (int k{ 0 }; k < waves[currentWave].rows; k++)
			{
				AEnemy* enemy = world->SpawnActor<AEnemy>(EnemyBlueprint, currentPos, startRotation);
				enemies.Add(enemy);
				//Moves current pos to the right by spaceBetweenEnemies amount
				currentPos.Y += spaceBewteenEnemies;
			}
			//Moves x position downward
			currentPos.X -= spaceBewteenEnemies;
			//Resets the y pos to the left side
			currentPos.Y = startPos.Y;
		}
	}
}

void ASpaceGameGameModeBase::MoveEnemies(float DeltaTime) {

	timeElapsed += DeltaTime;

	if (timeElapsed >= timePerDirection) {
		if (moveDirection == right) {
			moveDirection = left;
		}
		else if (moveDirection == left) {
			moveDirection = right;
		}
		timeElapsed = 0.f;
	}

	for (int i{0}; i < enemies.Num(); i++)
	{
		if (enemies[i]->dead) {
			enemies[i]->Destroy();
			enemies.RemoveAt(i);
		}
	}

	for (int i{0}; i < enemies.Num(); i++)
	{
		//Check if its time to switch
		
		if (moveDirection == right) {
			FVector currentPos = enemies[i]->GetActorLocation();
			currentPos -= enemies[i]->GetActorRightVector() * waves[currentWave].sidewaysSpeed * DeltaTime;
			currentPos.X -= waves[currentWave].forwardSpeed * DeltaTime;
			enemies[i]->SetActorLocation(currentPos);
		}
		else if (moveDirection == left) {
			FVector currentPos = enemies[i]->GetActorLocation();
			currentPos += enemies[i]->GetActorRightVector() * waves[currentWave].sidewaysSpeed * DeltaTime;
			currentPos.X -= waves[currentWave].forwardSpeed * DeltaTime;
			enemies[i]->SetActorLocation(currentPos);
		}
	}
}

void ASpaceGameGameModeBase::Countdown(float DeltaTime) {

	countdownTIme -= DeltaTime;
	if (countdownTIme <= 0) {
		bEnemiesCanMove = true;
		bCountingDown = false;
	}
}

void ASpaceGameGameModeBase::SpawnPlayerBase() {
	//Spawns the playerBaseBlueprint
	if (playerBaseBlueprint) {
		UWorld* world = GetWorld();
		if (world) {
			playerBase = world->SpawnActor<APlayerBase>(playerBaseBlueprint, playerBaseSpawnPoint, FRotator{ 0.f,0.f,0.f });
		}
	}
}

bool ASpaceGameGameModeBase::WaveDead()
{
	//Checks if it there is any enemy in enemies, if so the size will big larger than 0
	if (enemies.Num() == 0) {
		currentWave++;
		//If the currentWave is larger og the same as the size of waves, the game is over, the player defeated all the waves
		if (currentWave >= waves.Num()) {
			//Waves are over
			GameOver(true);
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

void ASpaceGameGameModeBase::GameOver(bool didPlayerWin)
{
	playing = false;
}