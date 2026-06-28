#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImpulseMissile.generated.h"

UCLASS()
class STACKOBOTYOUTUBE_API AImpulseMissile : public AActor
{
	GENERATED_BODY()

public:
	AImpulseMissile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category ="Component")
	UStaticMeshComponent* StaticMeshComponent;
};
