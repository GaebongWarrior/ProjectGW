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

void UCharacterManager::SubscribeEvent()
{	
	Super::SubscribeEvent(); // 부모 클래스의 SubscribeEvent 호출
	OnCharacterMoveInput.AddDynamic(this, &UCharacterManager::MoveCharacterFired);
	OnCharacterLookAroundInput.AddDynamic(this, &UCharacterManager::LookAroundCharacterFired);
	UE_LOG(LogTemp, Warning, TEXT("Event Binding End"));
}

void UCharacterManager::UnSubscribeEvent()
{
	Super::UnSubscribeEvent(); // 부모 클래스의 UnSubscribeEvent 호출
	OnCharacterMoveInput.RemoveDynamic(this, &UCharacterManager::MoveCharacterFired);
	OnCharacterLookAroundInput.RemoveDynamic(this, &UCharacterManager::LookAroundCharacterFired);
	// 이벤트 구독 해제
	UE_LOG(LogTemp, Warning, TEXT("Unsubscribed from Character Events"));
}

void UCharacterManager::MoveCharacterFired(FVector2D Value)
{
	OnCharacterMove.Broadcast(Value); // 이벤트 발생
	UE_LOG(LogTemp, Warning, TEXT("MoveEventFired: %s"), *Value.ToString());
}

void UCharacterManager::LookAroundCharacterFired(FVector2D Value)
{
	OnCharacterLookAround.Broadcast(Value); // 이벤트 발생
	UE_LOG(LogTemp, Warning, TEXT("LookAroundEventFired: %s"), *Value.ToString());
}


