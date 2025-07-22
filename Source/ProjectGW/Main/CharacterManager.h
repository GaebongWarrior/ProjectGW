// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Main/Manager.h"
#include "CharacterManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterMoveEventInput, FVector2D, Value); // 이벤트 정의(외부 블루프린트 및 C++에서 사용 가능)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterMoveEvent, FVector2D, Value); // 이벤트 정의(외부 블루프린트 및 C++에서 사용 가능)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterLookAroundEventInput, FVector2D, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterLookAroundEvent, FVector2D, Value);
/**
 * 
 */
UCLASS()
class PROJECTGW_API UCharacterManager : public UManager
{
	GENERATED_BODY()
	
public:
	UCharacterManager();
	void Init(); // 초기화 메소드 오버라이드

	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterMoveEventInput OnCharacterMoveInput; // 캐릭터 이동 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterMoveEvent OnCharacterMove; // 캐릭터 이동 이벤트

	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterLookAroundEventInput OnCharacterLookAroundInput; // 캐릭터 회전 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterLookAroundEvent OnCharacterLookAround; // 캐릭터 회전 이벤트

	void SubscribeEvent() override;
	void UnSubscribeEvent() override;

	UFUNCTION()
	void MoveCharacterFired(FVector2D Value);
	UFUNCTION()
	void LookAroundCharacterFired(FVector2D Value);
};
