// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PixelCube.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class COLORINGPUZZLE_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* root;

	UPROPERTY(EditAnywhere, Category = "Config")
	int height;

	UPROPERTY(EditAnywhere, Category = "Config")
	int width;

	UPROPERTY(EditAnywhere, Category = "Config")
	float distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<APixelCube*> cubeArray;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
