// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Inventoryable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UInventoryable : public UInterface
{
	GENERATED_BODY()
};

/**
 * inventory interface
 */
class STRUCTURALPATTERNS_API IInventoryable
{
	GENERATED_BODY()

public:

	//add object with "Name" name to inventory
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AddObj(const FString& Name);

	//remove object with "Name" name from inventory
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RemoveObj(const FString& Name);

	//return list of objects names and them counts
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	const TMap<FString, int> GetObjList();
};
