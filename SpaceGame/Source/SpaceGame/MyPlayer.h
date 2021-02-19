// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

class APlayerBullet;
UCLASS()
class SPACEGAME_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

	UPROPERTY(EditAnywhere, Category = "Stats")
	float moveSpeed{200.f};

	FVector myVelocity;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<APlayerBullet> bulletBlueprint;

	UPROPERTY(EditAnywhere, Category = "Setup")
	USceneComponent* bulletSpawnPoint;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void DoMovement(float);

	void MoveRight(float);

	void MoveForward(float);

	void Shoot();
};
