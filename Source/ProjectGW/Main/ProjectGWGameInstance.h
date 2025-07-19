// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ProjectGWGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGW_API UProjectGWGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	UProjectGWGameInstance();
	virtual void Init() override; // 게임 인스턴스 초기화(사실상 생성자 역할, 없으면 동작 안함)
	virtual void Shutdown() override; // 게임 인스턴스 종료(사실상 소멸자 역할, 없으면 동작 안함)

};
