// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMoveComponent.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"

// Sets default values for this component's properties
UAIMoveComponent::UAIMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UAIMoveComponent::Move(FVector targetPosition, const FOnReachTargetSignature& OnReachTarget)
{
	OnReach = OnReachTarget;
	aiController -> AAIController::MoveToLocation(targetPosition);
}

void UAIMoveComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if(IsValid(aiController))
	{
		aiController->ReceiveMoveCompleted.RemoveDynamic(this, &UAIMoveComponent::OnMoveCompleted);
	}
	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

// Called when the game starts
void UAIMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	
	aiController = Cast<AAIController>(GetOwner()->GetInstigatorController());
	//subscribe to ReceiveMoveCompleted event
	aiController->ReceiveMoveCompleted.AddDynamic(this, &UAIMoveComponent::OnMoveCompleted);
}


// Called every frame
void UAIMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAIMoveComponent::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type MovementResult)
{
	OnReach.ExecuteIfBound();
}

