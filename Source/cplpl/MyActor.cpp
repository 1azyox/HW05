// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned

// 게임이 시작되거나 엑터가 생성될 때 호출됨
//본인 액터의 BeginPlay()함수에 아래 코드를 넣으면 됩니다.

int32 AMyActor::step() {

    int32 RandomInt = FMath::RandRange(0, 1);
    
    return RandomInt;
}

bool AMyActor::event() {
    return FMath::RandRange(0, 1) == 0;
}

void AMyActor::move() {
    FVector location = FVector(0, 0, 0);
    int count = 0;
    float x = 0, y = 0;
    float distance = 0;

    for (int i = 0; i < 10; ++i) {
        x = location.X;
        y = location.Y;

        location.X += step();
        location.Y += step();

        distance = FMath::Sqrt(FMath::Pow(location.X - x, 2) + FMath::Pow(location.Y - y, 2));
       
        UE_LOG(LogTemp, Warning, TEXT("Location: (%f, %f)"), location.X, location.Y);
        UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), distance);

        if (event()) {
            count++;
            UE_LOG(LogTemp, Error, TEXT("Event!"));
        }
        
    }
    UE_LOG(LogTemp, Error, TEXT("Total event: %d"), count);
}


void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    move();
    
}




// Called every frames
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

