// Copyright Epic Games, Inc. All Rights Reserved.

#include "SampleMyActor.h"

// Sets default values
ASampleMyActor::ASampleMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D::ZeroVector; // 0, 0
	moveCount = 10;

	evCnt = 0;
	totDist = 0;
}

// Called when the game starts or when spawned
void ASampleMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Move
	Move();
	
}

// Called every frame
void ASampleMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// New Function
void ASampleMyActor::Move()
{
	double& x = start.X;
	double& y = start.Y;

	double xTemp = 0.0;
	double yTemp = 0.0;
	double dis = 0.0;

	UE_LOG(LogTemp, Warning, TEXT("처음 위치: ( %.2lf, %.2lf )"), x, y);

	if (GEngine) {
		for (int i = 0; i < moveCount; i++) {
			xTemp = x;
			yTemp = y;

			x += Step();
			y += Step();

			dis = FMath::Sqrt((x - xTemp) * (x - xTemp) + (y - yTemp) * (y - yTemp));
			if (dis > 0) {
				totDist += dis;
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("%d 번째 이동 거리: %.2lf"), i + 1, dis));
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("%d 번째 이동은 없었습니다."), i + 1));
			}

			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::Printf(TEXT("현재 위치: ( %.2lf, %.2lf )"), x, y));
		}

		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("총 이동 거리: %.2lf"), totDist));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("이벤트 발생횟수: %d"), evCnt));
	}

	// 로그출력
	// UE_LOG(LogTemp, Warning, TEXT("현재 위치: ( %.2lf, %.2lf )"), x, y);

	// 화면출력
	/*if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, FString::Printf("현재 위치: ( %.2lf, %.2lf )", x, y));
	}*/
}

int32 ASampleMyActor::Step()
{
	// 각 스탭마다 이벤트 발생
	evCnt += createEvent();

	return FMath::RandRange(0, 1);
}

int32 ASampleMyActor::createEvent()
{
	float Probability = 50.0f;
	float RandomValue = FMath::RandRange(1.0f, 100.0f);

	if (RandomValue < Probability) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("이동하는 도중 이벤트가 발생하였습니다.")));
			return 1;
		}
	}
	else {
		return 0;
	}
}
