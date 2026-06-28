#include "ImpulseShooter.h"
#include "ImpulseMissile.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

UImpulseShooter::UImpulseShooter()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UImpulseShooter::BeginPlay()
{
	Super::BeginPlay();
}


void UImpulseShooter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UImpulseShooter::FireMissile()
{
	if (ImpulseMissile == nullptr)
		return;
	
	auto SpawnTransform = MissileSpawnPlaceHolder == nullptr ? GetOwner()->GetActorTransform() : MissileSpawnPlaceHolder->GetComponentTransform();
	AImpulseMissile* Missile = GetWorld()->SpawnActor<AImpulseMissile>(ImpulseMissile, SpawnTransform);
	
	Missile->StaticMeshComponent->SetSimulatePhysics(true);
	Missile->StaticMeshComponent->SetEnableGravity(true);
	Missile->StaticMeshComponent->AddImpulse((SpawnTransform.GetRotation().GetForwardVector() * 1000.f), NAME_None, true);
}

