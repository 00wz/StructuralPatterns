// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponentAbstract.h"


// Sets default values for this component's properties
UMoveComponentAbstract::UMoveComponentAbstract()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMoveComponentAbstract::Move(FVector targetPosition, const FOnReachTargetSignature& OnReachTarget)
{
}


// Called when the game starts
void UMoveComponentAbstract::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMoveComponentAbstract::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

