#include "ImpulseShooter.h"
#include "ImpulseMissile.h"
#include "Camera/CameraComponent.h"
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
	auto Camera = Cast<UCameraComponent>(GetOwner()->GetComponentByClass(UCameraComponent::StaticClass()));
	AImpulseMissile* Missile = GetWorld()->SpawnActor<AImpulseMissile>(ImpulseMissile, SpawnTransform);
	
	auto FireDirection = Camera == nullptr ? SpawnTransform.GetRotation().GetForwardVector() : Camera->GetForwardVector();
	Missile->StaticMeshComponent->SetSimulatePhysics(true);
	Missile->StaticMeshComponent->SetEnableGravity(true);
	Missile->StaticMeshComponent->AddImpulse((FireDirection * ImpulsePower), NAME_None, true);
}

