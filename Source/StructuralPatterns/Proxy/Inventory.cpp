// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

void UInventory::AddObj_Implementation(const FString& Name)
{
	if(!m_objList.Contains(Name))
	{
		m_objList.Add(Name, 0);
	}
	m_objList[Name]++;
}

void UInventory::RemoveObj_Implementation(const FString& Name)
{
	if(!m_objList.Contains(Name))
	{
		return;
	}
	m_objList[Name]--;
	if(m_objList[Name] <= 0)
	{
		m_objList.Remove(Name);
	}
}

const TMap<FString, int> UInventory::GetObjList_Implementation()
{
	return m_objList;
}
