// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Components/SphereComponent.h"
// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	bDead = false;
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerBase::TakeDamage(float damage) {
	health -= damage;
	UE_LOG(LogTemp, Error, TEXT("Base health is: %f"), health);
	if (health <= 0) {
		//Loose game
		bDead = true;
	}
}