// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InterFaces/ManagerEventInterface.h"
#include "Manager.generated.h"


/**
 * 
 */
UCLASS()
class PROJECTGW_API UManager : public UObject, public IManagerEventInterface
{
	GENERATED_BODY()
	
public:
	UManager();

	void Init();
	void Shutdown();
	virtual void SubscribeEvent() override;
	virtual void UnSubscribeEvent() override;
};
