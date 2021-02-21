// Copyright Epic Games, Inc. All Rights Reserved.


#include "SpaceGameGameModeBase.h"
#include "SpaceGame.h"
#include "Enemy.h"
#include "Engine/World.h"

ASpaceGameGameModeBase::ASpaceGameGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;

}

void ASpaceGameGameModeBase::BeginPlay() {
	Super::BeginPlay();

	SpawnEnemies();

	//Sets the first time to half to account for it starting in the middle
	timeElapsed = timePerDirection / 2;
	//Starts the movement to the right
	moveDirection = right;
	bCountingDown = true;
}

void ASpaceGameGameModeBase::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (bCountingDown) {
		Countdown(DeltaTime);
	}
	if (bEnemiesCanMove) {
		MoveEnemies(DeltaTime);
	}
}

void ASpaceGameGameModeBase::SpawnEnemies() {
	//Finds the middle of where to spawn the enemies
	FVector startPos = enemiesMiddlePos;
	//Adds half of rows and amounts in meters by * spaceBetweenEnemies
	startPos.X += (columns / 2) * spaceBewteenEnemies;
	startPos.Y -= (rows / 2) * spaceBewteenEnemies;
	//Sets the current spawn position
	FVector currentPos = startPos;
	UWorld* world = GetWorld();
	if (world) {
		//goes through each row and colums and spawns a Enemy at the currentPos
		for (int i{ 0 }; i < columns; i++)
		{
			for (int k{ 0 }; k < rows; k++)
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
		//Check if its time to switch
		
		if (moveDirection == right) {
			FVector currentPos = enemies[i]->GetActorLocation();
			currentPos -= enemies[i]->GetActorRightVector() * sidewaysSpeed * DeltaTime;
			currentPos.X -= forwardSpeed * DeltaTime;
			enemies[i]->SetActorLocation(currentPos);
		}
		else if (moveDirection == left) {
			FVector currentPos = enemies[i]->GetActorLocation();
			currentPos += enemies[i]->GetActorRightVector() * sidewaysSpeed * DeltaTime;
			currentPos.X -= forwardSpeed * DeltaTime;
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