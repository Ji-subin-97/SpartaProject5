// Copyright Epic Games, Inc. All Rights Reserved.


#include "SampleMyActor.h"

// Sets default values
ASampleMyActor::ASampleMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASampleMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASampleMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

