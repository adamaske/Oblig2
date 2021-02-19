// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBullet.generated.h"

UCLASS()
class SPACEGAME_API APlayerBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBullet();

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;

	UPROPERTY(EditAnywhere, Category = "Stats")
	float projectileSpeed{700};
	
	UPROPERTY(EditAnywhere, Category = "Stats")
	float allowedLifetime{ 5 };

	float timeLived{0};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForward(float);

	void Lifetime(float);
};
