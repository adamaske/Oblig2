// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "PlayerBullet.h"
// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set a empty object to root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//Creates mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	//Attaches
	MeshComponent->SetupAttachment(RootComponent);
	//Create the bullet spawn point
	bulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnPoint"));
	bulletSpawnPoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if CanMove, do movement
	if (bCanMove) {
		DoMovement(DeltaTime);
	}
	ShootTimer(DeltaTime);
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Actions
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AMyPlayer::Shoot);

	//Binds input to function that sets myVelocity
	InputComponent->BindAxis("MoveRight", this, &AMyPlayer::MoveRight);
	InputComponent->BindAxis("MoveForward", this, &AMyPlayer::MoveForward);
}

void AMyPlayer::DoMovement(float DeltaTime)
{
	if (!myVelocity.IsZero()) {
		FVector newLocation = GetActorLocation() + (myVelocity * moveSpeed * DeltaTime);

		SetActorLocation(newLocation);
	}
}

void AMyPlayer::MoveRight(float value) {
	myVelocity.Y = value;
}

void AMyPlayer::MoveForward(float value)
{
	//Disabled forward movemnet
	myVelocity.X = 0;
}

void AMyPlayer::Shoot() {
	if (!bCanFire) { 
		return; 
	}

	UWorld* world = GetWorld();
	if (world && bulletBlueprint) {
		/*FVector spawnLocation = bulletSpawnPoint->GetSocketLocation();
		FRotator spawnRotation = bulletSpawnPoint->GetComponentRotation();*/

		world->SpawnActor<APlayerBullet>(bulletBlueprint, GetActorLocation() + FVector(5,0,0) , GetActorRotation());
		bCanFire = false;
		shotTimer = 0;
	}
}

void AMyPlayer::ShootTimer(float DeltaTime) {
	shotTimer += DeltaTime;
	if (!bCanFire && shotTimer >= fireRate) {
		bCanFire = true;
		shotTimer = 0;
	}
}
