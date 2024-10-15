// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "Inventoryable.h"
#include "UObject/Object.h"
#include "InventoryProxy.generated.h"

/**
 * inventory proxy with logging
 */
UCLASS(BlueprintType)
class STRUCTURALPATTERNS_API UInventoryProxy : public UObject, public IInventoryable
{
	GENERATED_BODY()

private:
	UInventory* m_inventory = NewObject<UInventory>();
	
public:
	void AddObj_Implementation(const FString& Name) override;

	void RemoveObj_Implementation(const FString& Name) override;

	const TMap<FString, int> GetObjList_Implementation() override;
};
