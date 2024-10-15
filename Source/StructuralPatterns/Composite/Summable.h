// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Summable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class USummable : public UInterface
{
	GENERATED_BODY()
};

/**
 * an interface that will combine the operations of containers
 *	and simple tree components to obtain the sum of all elements
 */
class STRUCTURALPATTERNS_API ISummable
{
	GENERATED_BODY()

public:
	// returns the sum of the finite elements of the composite
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int GetSum();
public:
};
