// Fill out your copyright notice in the Description page of Project Settings.

#include "ColoringPuzzle.h"
#include "Spawner.h"


// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	height = 10;
	width = 5;
	distance = 100;
	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	int x = GetActorLocation().X + ((float)(width - 1) / 2.f) * distance;
	int y = GetActorLocation().Y - ((float)(height - 1) / 2.f) * distance;

	for (int i = 0; i < height; i++)
	{
		y = GetActorLocation().Y - ((float)(height - 1) / 2.f) * distance;

		for (int j = 0; j < width; j++)
		{
			APixelCube* cube = GetWorld()->SpawnActor<APixelCube>(FVector(x, y, GetActorLocation().Z), GetActorRotation());
			cubeArray.Add(cube);
			y += distance;
		}
		x -= distance;

	}
}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

