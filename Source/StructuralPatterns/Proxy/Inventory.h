// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventoryable.h"
#include "UObject/Object.h"
#include "Inventory.generated.h"

/**
 * inventory class
 */
UCLASS(BlueprintType)
class STRUCTURALPATTERNS_API UInventory : public UObject, public  IInventoryable
{
	GENERATED_BODY()
private:
	TMap<FString, int> m_objList{};
	
public:

	void AddObj_Implementation(const FString& Name) override;

	void RemoveObj_Implementation(const FString& Name) override;

	const TMap<FString, int> GetObjList_Implementation() override;
};
