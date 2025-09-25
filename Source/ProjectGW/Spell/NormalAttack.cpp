// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell/NormalAttack.h"
#include "Components/SphereComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"

ANormalAttack::ANormalAttack()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateCollisionComponent<USphereComponent>(TEXT("CollisionComponent"), [](USphereComponent* Comp)
		{
			Comp->InitSphereRadius(5.0f);
		});
	InitialLifeSpan = 10.f; // 생명주기 설정 (초 단위)
	ProjectileMovement = CreateProjectileMovementComponent(100.f, 500.f);
	CreateEffectComponent = LoadCreateEffectComponent(TEXT("/Game/FX/NS/Shield_start.Shield_start"));
	EffectComponent = LoadEffectComponent(TEXT("/Game/FX/NS/Shield.Shield"));
	DestroyEffectSystem = LoadDestroyEffectSystem(TEXT("/Game/FX/NS/Shield_end.Shield_end"));
}
// Called when the game starts or when spawned
void ANormalAttack::BeginPlay()
{
	Super::BeginPlay();

}


void ANormalAttack::Destroyed()
{
	Super::Destroyed();
}

// Called every frame
void ANormalAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}