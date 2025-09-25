// Fill out your copyright notice in the Description page of Project Settings.


#include "Main/CharacterManager.h"

UCharacterManager::UCharacterManager()
{
}

void UCharacterManager::Init()
{
	Super::Init(); // 부모 클래스의 Init 호출
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
	OnCharacterMoveInput.AddDynamic(this, &UCharacterManager::MoveCharacterFired);
	OnCharacterLookAroundInput.AddDynamic(this, &UCharacterManager::LookAroundCharacterFired);
	OnCharacterSprintStartInput.AddDynamic(this, &UCharacterManager::SprintStartFired);
	OnCharacterSprintEndInput.AddDynamic(this, &UCharacterManager::SprintEndFired);
	OnCharacterJumpStartInput.AddDynamic(this, &UCharacterManager::JumpStartFired);
	OnCharacterJumpEndInput.AddDynamic(this, &UCharacterManager::JumpEndFired);
	OnZoomEventInput.AddDynamic(this, &UCharacterManager::ZoomFired);
	OnAimEventInput.AddDynamic(this, &UCharacterManager::AimFired);
	OnAimOnEventInput.AddDynamic(this, &UCharacterManager::AimOnFired);
	OnAimOutEventInput.AddDynamic(this, &UCharacterManager::AimOutFired);
	OnAttackEventInput.AddDynamic(this, &UCharacterManager::AttackFired);
	UE_LOG(LogTemp, Warning, TEXT("Event Binding End"));
}

void UCharacterManager::UnSubscribeEvent()
{
	Super::UnSubscribeEvent(); // 부모 클래스의 UnSubscribeEvent 호출
	OnCharacterMoveInput.RemoveDynamic(this, &UCharacterManager::MoveCharacterFired);
	OnCharacterLookAroundInput.RemoveDynamic(this, &UCharacterManager::LookAroundCharacterFired);
	OnCharacterSprintStartInput.RemoveDynamic(this, &UCharacterManager::SprintStartFired);
	OnCharacterSprintEndInput.RemoveDynamic(this, &UCharacterManager::SprintEndFired);
	OnCharacterJumpStartInput.RemoveDynamic(this, &UCharacterManager::JumpStartFired);
	OnCharacterJumpEndInput.RemoveDynamic(this, &UCharacterManager::JumpEndFired);
	OnZoomEventInput.RemoveDynamic(this, &UCharacterManager::ZoomFired);
	OnAimEventInput.RemoveDynamic(this, &UCharacterManager::AimFired);
	OnAimOnEventInput.RemoveDynamic(this, &UCharacterManager::AimOnFired);
	OnAimOutEventInput.RemoveDynamic(this, &UCharacterManager::AimOutFired);
	OnAttackEventInput.RemoveDynamic(this, &UCharacterManager::AttackFired);
	// 이벤트 구독 해제
	UE_LOG(LogTemp, Warning, TEXT("Unsubscribed from Character Events"));
}

void UCharacterManager::MoveCharacterFired(FVector2D Value)
{
	OnCharacterMove.Broadcast(Value); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("MoveEventFired: %s"), *Value.ToString());
}

void UCharacterManager::LookAroundCharacterFired(FVector2D Value)
{
	OnCharacterLookAround.Broadcast(Value); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("LookAroundEventFired: %s"), *Value.ToString());
}

void UCharacterManager::SprintStartFired()
{
	OnCharacterSprintStart.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("SprintStartEventFired"));
}

void UCharacterManager::SprintEndFired()
{
	OnCharacterSprintEnd.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("SprintEndEventFired"));
}

void UCharacterManager::JumpStartFired()
{
	OnCharacterJumpStart.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("JumpStartEventFired"));
}

void UCharacterManager::JumpEndFired()
{
	OnCharacterJumpEnd.Broadcast(); // 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("JumpEndEventFired"));
}

void UCharacterManager::ZoomFired(float Value)
{
	OnZoomEvent.Broadcast(Value); // 줌 이벤트 발생
	//UE_LOG(LogTemp, Warning, TEXT("ZoomFired: %f"), Value);	
}

void UCharacterManager::AimFired()
{
	OnAimEvent.Broadcast(); // 조준 이벤트 발생
}

void UCharacterManager::AimOnFired()
{
	OnAimOnEvent.Broadcast(); // 조준 이벤트 발생
}

void UCharacterManager::AimOutFired()
{
	OnAimOutEvent.Broadcast(); // 조준 이벤트 발생
}

void UCharacterManager::AttackFired()
{
	OnAttackEvent.Broadcast(); // 조준 이벤트 발생
}


