// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class SPACEGAME_API AEnemy : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshComponent;
	UPROPERTY(EditAnywhere)
	class USphereComponent* sphereComponent;
public:	
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(EditAnywhere)
		float health{ 100 };
	UPROPERTY(EditAnywhere)
		float damage{ 25 };
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HitByPlayer(float damage);

	bool dead;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);
};
