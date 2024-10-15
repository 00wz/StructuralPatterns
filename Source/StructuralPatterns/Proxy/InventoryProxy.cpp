// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryProxy.h"

void UInventoryProxy::AddObj_Implementation(const FString& Name)
{
	m_inventory -> Execute_AddObj(m_inventory, Name);
	UE_LOG(LogTemp, Warning, TEXT("Inventory: Add item: %s"), *FString(Name));
}

void UInventoryProxy::RemoveObj_Implementation(const FString& Name)
{
	m_inventory -> Execute_RemoveObj(m_inventory, Name);
	UE_LOG(LogTemp, Warning, TEXT("Inventory: Remove item: %s"), *FString(Name));
}

const TMap<FString, int> UInventoryProxy::GetObjList_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Inventory: List getting"));
	return m_inventory -> Execute_GetObjList(m_inventory);
}
