// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Main/Manager.h"
#include "DispatchManager.h"
#include "Spell/NormalAttack.h"
#include "SpellManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGW_API USpellManager : public UManager
{
	GENERATED_BODY()
	
public:
	USpellManager();
	void Init(UDispatchManager* DM); // 초기화 메소드 오버라이드
	void Shutdown(); // 종료 메소드 오버라이드

	UPROPERTY()
	UGameInstance* GameInstance; // 게임 인스턴스 포인터

	UPROPERTY()
	UDispatchManager* DispatchManager; // 디스패치 매니저 포인터

	UPROPERTY()
	TSoftClassPtr<ANormalAttack> NormalAttackSpell;

	// 이벤트 구독 및 해제 메소드 재정의--------------------------------------
	void SubscribeEvent() override;
	void UnSubscribeEvent() override;

	UFUNCTION()
	void Spell();
};
