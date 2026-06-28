#include "ImpulseMissile.h"

#include "Components/StaticMeshComponent.h"


AImpulseMissile::AImpulseMissile()
{
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComponent);
}

void AImpulseMissile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AImpulseMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

