// Fill out your copyright notice in the Description page of Project Settings.


#include "Main/CharacterManager.h"

UCharacterManager::UCharacterManager()
{
}

void UCharacterManager::Init(UDispatchManager* DM)
{
	Super::Init(); // 부모 클래스의 Init 호출
	DispatchManager = DM; // 디스패치 매니저 포인터 설정
	UE_LOG(LogTemp, Warning, TEXT("Character Manager Initialized"));
	SubscribeEvent(); // 이벤트 구독
}

void UCharacterManager::Shutdown()
{
	UE_LOG(LogTemp, Warning, TEXT("Character Manager Shutdowned"));
	Super::Shutdown(); // 부모 클래스의 Shutdown 호출
	UnSubscribeEvent(); // 이벤트 구독
}

void UCharacterManager::SubscribeEvent()
{	
	Super::SubscribeEvent(); // 부모 클래스의 SubscribeEvent 호출
	DispatchManager->OnCharacterMoveInput.AddDynamic(this, &UCharacterManager::MoveCharacterFired);
	DispatchManager->OnCharacterLookAroundInput.AddDynamic(this, &UCharacterManager::LookAroundCharacterFired);
	DispatchManager->OnCharacterSprintStartInput.AddDynamic(this, &UCharacterManager::SprintStartFired);
	DispatchManager->OnCharacterSprintEndInput.AddDynamic(this, &UCharacterManager::SprintEndFired);
	DispatchManager->OnCharacterJumpStartInput.AddDynamic(this, &UCharacterManager::JumpStartFired);
	DispatchManager->OnCharacterJumpEndInput.AddDynamic(this, &UCharacterManager::JumpEndFired);
	DispatchManager->OnZoomEventInput.AddDynamic(this, &UCharacterManager::ZoomFired);
	DispatchManager->OnAimEventInput.AddDynamic(this, &UCharacterManager::AimFired);
	DispatchManager->OnAimOnEventInput.AddDynamic(this, &UCharacterManager::AimOnFired);
	DispatchManager->OnAimOutEventInput.AddDynamic(this, &UCharacterManager::AimOutFired);
	DispatchManager->OnAttackEventInput.AddDynamic(this, &UCharacterManager::AttackFired);
	UE_LOG(LogTemp, Warning, TEXT("Event Binding End"));
}

void UCharacterManager::UnSubscribeEvent()
{
	Super::UnSubscribeEvent(); // 부모 클래스의 UnSubscribeEvent 호출
	DispatchManager->OnCharacterMoveInput.RemoveDynamic(this, &UCharacterManager::MoveCharacterFired);
	DispatchManager->OnCharacterLookAroundInput.RemoveDynamic(this, &UCharacterManager::LookAroundCharacterFired);
	DispatchManager->OnCharacterSprintStartInput.RemoveDynamic(this, &UCharacterManager::SprintStartFired);
	DispatchManager->OnCharacterSprintEndInput.RemoveDynamic(this, &UCharacterManager::SprintEndFired);
	DispatchManager->OnCharacterJumpStartInput.RemoveDynamic(this, &UCharacterManager::JumpStartFired);
	DispatchManager->OnCharacterJumpEndInput.RemoveDynamic(this, &UCharacterManager::JumpEndFired);
	DispatchManager->OnZoomEventInput.RemoveDynamic(this, &UCharacterManager::ZoomFired);
	DispatchManager->OnAimEventInput.RemoveDynamic(this, &UCharacterManager::AimFired);
	DispatchManager->OnAimOnEventInput.RemoveDynamic(this, &UCharacterManager::AimOnFired);
	DispatchManager->OnAimOutEventInput.RemoveDynamic(this, &UCharacterManager::AimOutFired);
	DispatchManager->OnAttackEventInput.RemoveDynamic(this, &UCharacterManager::AttackFired);
	// 이벤트 구독 해제
	UE_LOG(LogTemp, Warning, TEXT("Unsubscribed from Character Events"));
}

void UCharacterManager::MoveCharacterFired(FVector2D Value)
{
	DispatchManager->OnCharacterMove.Broadcast(Value); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("MoveEventFired: %s"), *Value.ToString());
}

void UCharacterManager::LookAroundCharacterFired(FVector2D Value)
{
	DispatchManager->OnCharacterLookAround.Broadcast(Value); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("LookAroundEventFired: %s"), *Value.ToString());
}

void UCharacterManager::SprintStartFired()
{
	DispatchManager->OnCharacterSprintStart.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("SprintStartEventFired"));
}

void UCharacterManager::SprintEndFired()
{
	DispatchManager->OnCharacterSprintEnd.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("SprintEndEventFired"));
}

void UCharacterManager::JumpStartFired()
{
	DispatchManager->OnCharacterJumpStart.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("JumpStartEventFired"));
}

void UCharacterManager::JumpEndFired()
{
	DispatchManager->OnCharacterJumpEnd.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("JumpEndEventFired"));
}

void UCharacterManager::ZoomFired(float Value)
{
	DispatchManager->OnZoomEvent.Broadcast(Value); // 줌 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("ZoomFired: %f"), Value);	
}

void UCharacterManager::AimFired()
{
	DispatchManager->OnAimEvent.Broadcast(); // 조준 이벤트 발생
}

void UCharacterManager::AimOnFired()
{
	DispatchManager->OnAimOnEvent.Broadcast(); // 조준 이벤트 발생
}

void UCharacterManager::AimOutFired()
{
	DispatchManager->OnAimOutEvent.Broadcast(); // 조준 이벤트 발생
}

void UCharacterManager::AttackFired()
{
	DispatchManager->OnAttackEvent.Broadcast(); // 조준 이벤트 발생
}


