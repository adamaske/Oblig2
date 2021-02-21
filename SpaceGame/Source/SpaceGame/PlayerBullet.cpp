// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBullet.h"
#include "Components/SphereComponent.h"
#include "Enemy.h"
// Sets default values
APlayerBullet::APlayerBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Set a empty object to root
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	meshComponent->SetupAttachment(RootComponent);

	Cast<USphereComponent>(RootComponent)->OnComponentBeginOverlap.AddDynamic(this, &APlayerBullet::OnOverlap);
}

// Called when the game starts or when spawned
void APlayerBullet::BeginPlay()
{



	Super::BeginPlay();

	timeLived = 0;
}

// Called every frame
void APlayerBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveForward(DeltaTime);

	Lifetime(DeltaTime);
}

void APlayerBullet::MoveForward(float DeltaTime)
{
	FVector newLocation = GetActorLocation();
	newLocation += GetActorForwardVector() * projectileSpeed * DeltaTime;
	SetActorLocation(newLocation);
}

void APlayerBullet::Lifetime(float DeltaTime) {
	//Adds time to timeLIved
	timeLived += DeltaTime;
	//Checks if its above or the same as allowed
	if (timeLived >= allowedLifetime) {
		this->Destroy();
	}
}

void APlayerBullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AEnemy::StaticClass())) {
		UE_LOG(LogTemp, Warning, TEXT("HitEnemy"));

		Cast<AEnemy>(OtherActor)->HitByPlayer(damage);

		this->Destroy();
	}
}
