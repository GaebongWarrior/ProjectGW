// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Main/Manager.h"
#include "DispatchManager.h"
#include "CharacterManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGW_API UCharacterManager : public UManager
{
	GENERATED_BODY()
	
public:
	UCharacterManager();
	void Init(UDispatchManager* DM); // 초기화 메소드 오버라이드
	void Shutdown(); // 종료 메소드 오버라이드

	UPROPERTY()
	UDispatchManager* DispatchManager; // 디스패치 매니저 포인터
	

	// 이벤트 구독 및 해제 메소드 재정의--------------------------------------
	void SubscribeEvent() override;
	void UnSubscribeEvent() override;


	// 이벤트 핸들러 메소드 ---------------------------------------
	UFUNCTION()
	void MoveCharacterFired(FVector2D Value);
	UFUNCTION()
	void LookAroundCharacterFired(FVector2D Value);

	UFUNCTION()
	void SprintStartFired();

	UFUNCTION()
	void SprintEndFired();

	UFUNCTION()
	void JumpStartFired();

	UFUNCTION()
	void JumpEndFired();

	UFUNCTION()
	void ZoomFired(float Value);

	UFUNCTION()
	void AimFired();
	UFUNCTION()
	void AimOnFired();
	UFUNCTION()
	void AimOutFired();

	UFUNCTION()
	void AttackFired();
};
