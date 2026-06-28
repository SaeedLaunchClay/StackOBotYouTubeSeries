#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "ImpulseShooter.generated.h"


class AImpulseMissile;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class STACKOBOTYOUTUBE_API UImpulseShooter : public UActorComponent
{
	GENERATED_BODY()

public:
	UImpulseShooter();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
						   FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category="Missile")
	void FireMissile();

protected:
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditDefaultsOnly, Category="Missile")
	TSubclassOf<AImpulseMissile> ImpulseMissile;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Missile")
	USceneComponent* MissileSpawnPlaceHolder;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Missile")
	float ImpulsePower = 5000.0f;
};
