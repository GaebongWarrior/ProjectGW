// Fill out your copyright notice in the Description page of Project Settings.


#include "Main/Manager.h"

UManager::UManager()
{
	// 생성자에서 초기화 작업을 진행
}

void UManager::Init()
{
	// 초기화 작업을 진행
	UE_LOG(LogTemp, Warning, TEXT("Manager Initialized"));
}

void UManager::SubscribeEvent()
{
	// 이벤트 생성 로직
	UE_LOG(LogTemp, Warning, TEXT("Event Subscribed"));
}

void UManager::UnSubscribeEvent()
{
	// 이벤트 생성 로직
	UE_LOG(LogTemp, Warning, TEXT("Event Unsubscribed"));
}
