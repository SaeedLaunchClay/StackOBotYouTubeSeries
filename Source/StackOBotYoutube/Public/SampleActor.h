// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SampleActor.generated.h"

UCLASS()
class STACKOBOTYOUTUBE_API ASampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASampleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Setting")
	int32 InventoryCapacity = 5;
	float DistanceToTarget = 1000.5f;
	bool IsFlying = false;

	FVector CharacterLocation = FVector(0,100.f, 0);
	FRotator CharacterRotation = FRotator(10.0f, 0, 0);
	FTransform CharacterTransform;
	
	FName ArmorSocketName = "ArmorSocket";
	FString CharacterName = "John";
	
	UPROPERTY()
	AActor* TargetActor = nullptr;
	
	UPROPERTY()
	UStaticMeshComponent* StaticMeshComponent = nullptr;
};
