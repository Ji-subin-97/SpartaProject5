// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SampleMyActor.generated.h"

UCLASS()
class SPARTAPROJECT5_API ASampleMyActor : public AActor
{
	GENERATED_BODY()
private:
	FVector2D start;

	UPROPERTY(EditAnywhere, Category = "MoveCount")
	int32 moveCount;

	int32 evCnt;
	double totDist;
public:	
	// Sets default values for this actor's properties
	ASampleMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// New Function
	void Move();
	int32 Step();
	int32 createEvent();
};
