// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Main/Manager.h"
#include "CharacterManager.generated.h"

// 이벤트 정의(외부 블루프린트 및 C++에서 사용 가능)

// 캐릭터 이동 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterMoveEventInput, FVector2D, Value); // 캐릭터 이동 이벤트 입력
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterMoveEvent, FVector2D, Value); // 캐릭터 이동 이벤트

// 캐릭터 시야 회전 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterLookAroundEventInput, FVector2D, Value); // 캐릭터 시야 회전 이벤트 입력
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterLookAroundEvent, FVector2D, Value); // 캐릭터 시야 회전 이벤트

// 달리기 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterSprintStartEventInput); // 달리기 시작 이벤트 입력
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterSprintEvent); // 달리기 시작 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterSprintEndEventInput); // 달리기 종료 이벤트 입력
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterSprintEndEvent); // 달리기 종료 이벤트

// 점프 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterJumpStartEventInput); // 점프 시작 이벤트 입력
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterJumpStartEvent); // 점프 시작 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterJumpEndEventInput); // 점프 종료 이벤트 입력
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterJumpEndEvent);  // 점프 종료 이벤트

// 줌 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FZoomEventInput, float, Value); // 마우스 휠 줌 이벤트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FZoomEvent, float, Value); // 마우스 휠 줌 이벤트

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
	void Shutdown(); // 종료 메소드 오버라이드

	// 이벤트 입력 및 이벤트 정의 ---------------------------------------
	
	// 캐릭터 이동 이벤트
	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterMoveEventInput OnCharacterMoveInput; // 캐릭터 이동 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterMoveEvent OnCharacterMove; // 캐릭터 이동 이벤트

	// 캐릭터 시야 회전 이벤트
	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterLookAroundEventInput OnCharacterLookAroundInput; // 캐릭터 시야 회전 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterLookAroundEvent OnCharacterLookAround; // 캐릭터 시야 회전 이벤트

	// 달리기 이벤트
	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterSprintStartEventInput OnCharacterSprintStartInput; // 달리기 시작 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterSprintEvent OnCharacterSprintStart; // 달리기 시작 이벤트
	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterSprintEndEventInput OnCharacterSprintEndInput; // 달리기 끝 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterSprintEndEvent OnCharacterSprintEnd; // 달리기 끝 이벤트

	// 점프 이벤트
	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterJumpStartEventInput OnCharacterJumpStartInput; // 점프 시작 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterJumpStartEvent OnCharacterJumpStart; // 점프 시작 이벤트
	UPROPERTY(BlueprintCallable, Category = "Events")
	FCharacterJumpEndEventInput OnCharacterJumpEndInput; // 점프 종료 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FCharacterJumpEndEvent OnCharacterJumpEnd; // 점프 종료 이벤트


	// 줌 이벤트
	UPROPERTY(BlueprintCallable, Category = "Events")
	FZoomEventInput OnZoomEventInput; // 줌 이벤트 입력
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FZoomEvent OnZoomEvent; // 줌 이벤트 입력

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
};
