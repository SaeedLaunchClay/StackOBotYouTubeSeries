// Fill out your copyright notice in the Description page of Project Settings.


#include "AnotherClass.h"


// Sets default values
AAnotherClass::AAnotherClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAnotherClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnotherClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

