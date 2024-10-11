// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "UObject/Object.h"
#include "HTTPModuleFacade.generated.h"

UDELEGATE()
	DECLARE_DYNAMIC_DELEGATE_OneParam(FHttpRequestSignature, FString, Response);


/**
 * provides a lightweight interface for sending HTML requests
 */
UCLASS()
class STRUCTURALPATTERNS_API UHTTPModuleFacade : public UObject
{
	GENERATED_BODY()
public:

	/*
	 * sends a Get request
	 *
	 * request - request in html format
	 * OnProcessRequestComplete - the event that is called after receiving the response
	 */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "OnProcessRequestComplete"))
	static void GET(FString request, const FHttpRequestSignature& OnProcessRequestComplete)
	{
		FHttpModule* Module = &FHttpModule::Get();
		TSharedRef<IHttpRequest,ESPMode::ThreadSafe> Request = Module->CreateRequest();
		Request->SetURL(request);
		auto onRequestComplete{
			[OnProcessRequestComplete](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
			{
				if(bWasSuccessful)
				{
					OnProcessRequestComplete.ExecuteIfBound(Response->GetContentAsString());
				}
			}
		};
		Request->OnProcessRequestComplete().BindLambda(onRequestComplete);
		Request->ProcessRequest();
	}
	
	static void POST()
	{
		//not implemented yet
	}

	static void PUT ()
	{
		//not implemented yet
	}
};
