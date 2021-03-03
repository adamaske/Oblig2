// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBase.generated.h"

UCLASS()
class SPACEGAME_API APlayerBase : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Mesh")
		UStaticMeshComponent* MeshComponent;
public:	
	// Sets default values for this actor's properties
	APlayerBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Stats")
	float health;

	bool bDead{ 0 };
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TakeDamage(float);
};
