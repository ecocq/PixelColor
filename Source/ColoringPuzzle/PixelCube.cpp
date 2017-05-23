// Fill out your copyright notice in the Description page of Project Settings.

#include "ColoringPuzzle.h"
#include "PixelCube.h"


// Sets default values
APixelCube::APixelCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(RootComponent);
	const ConstructorHelpers::FObjectFinder<UStaticMesh> meshObj(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mesh->SetStaticMesh(meshObj.Object);
	const ConstructorHelpers::FObjectFinder<UMaterial> matObj(TEXT("Material'/Game/Materials/PixelCubeMaterial.PixelCubeMaterial'"));
	mesh->SetMaterial(0, matObj.Object);

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	box->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APixelCube::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(1.5f, 1.5f, 0.2f));
	box->SetBoxExtent(FVector(50.0f, 50.0f, 30.0f));
	box->SetRelativeLocation(GetActorLocation());
	material = UMaterialInstanceDynamic::Create(mesh->GetMaterial(0), this);
	mesh->SetMaterial(0, material);
}

// Called every frame
void APixelCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APixelCube::changeColor(FLinearColor color)
{
	material->SetVectorParameterValue("Color", color);
}



