// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MoveComponentAbstract.h"
#include "Components/ActorComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIMoveComponent.generated.h"

/*
 * AIController adapter for MoveComponentAbstract
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class STRUCTURALPATTERNS_API UAIMoveComponent : public UMoveComponentAbstract
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAIMoveComponent();

	/*
	 * realizes movement on the navigation mesh
	 */
	virtual void Move(FVector targetPosition, const FOnReachTargetSignature& OnReachTarget) override;

	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	AAIController* aiController;
	
	UFUNCTION()
	void OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type MovementResult);

	FOnReachTargetSignature OnReach;
};
