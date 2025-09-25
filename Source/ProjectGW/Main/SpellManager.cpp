// Fill out your copyright notice in the Description page of Project Settings.


#include "Main/SpellManager.h"
#include "Kismet/GameplayStatics.h"


USpellManager::USpellManager()
{
	// 이팩트 지연로딩 설정
	NormalAttackSpell = TSoftClassPtr<ANormalAttack>(FSoftObjectPath(TEXT("/Game/Spell/NormalAttack.NormalAttack_C")));
}
void USpellManager::Init(UDispatchManager* DM)
{
	Super::Init(); // 부모 클래스의 Init 호출
	DispatchManager = DM; // 디스패치 매니저 포인터 설정
	UE_LOG(LogTemp, Warning, TEXT("Spell Manager Initialized"));
	SubscribeEvent(); // 이벤트 구독
}

void USpellManager::Shutdown()
{
	UE_LOG(LogTemp, Warning, TEXT("Spell Manager Shutdowned"));
	Super::Shutdown(); // 부모 클래스의 Shutdown 호출
	UnSubscribeEvent(); // 이벤트 구독
}

void USpellManager::SubscribeEvent()
{
	Super::SubscribeEvent(); // 부모 클래스의 SubscribeEvent 호출
	// 이벤트 구독 로직
	DispatchManager->OnAttackEvent.AddDynamic(this, &USpellManager::Spell);
	UE_LOG(LogTemp, Warning, TEXT("Subscribed to Spell Events"));
}

void USpellManager::UnSubscribeEvent()
{
	Super::UnSubscribeEvent(); // 부모 클래스의 UnSubscribeEvent 호출
	// 이벤트 구독 해제 로직
	UE_LOG(LogTemp, Warning, TEXT("Unsubscribed from Spell Events"));
}

void USpellManager::Spell()
{
	UE_LOG(LogTemp, Warning, TEXT("Spell Casted"));

	if (UClass* Cls = NormalAttackSpell.LoadSynchronous())
	{
		FVector Loc(410.f, -20.f, 340.f);
		FRotator Rot(0.f, 0.f, 0.f);
		GameInstance->GetWorld()->SpawnActor<ANormalAttack>(Cls, Loc, Rot);
	}
}
