// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveComponentAbstract.generated.h"

UDELEGATE()
	DECLARE_DYNAMIC_DELEGATE(FOnReachTargetSignature);

/*
 * base class for realization of pawn movement
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Abstract)
class STRUCTURALPATTERNS_API UMoveComponentAbstract : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMoveComponentAbstract();

	/*
	 * forces the pawn to move to the specified location
	 */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "OnReachTarget"))
	virtual void Move(FVector targetPosition, const FOnReachTargetSignature& OnReachTarget);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
