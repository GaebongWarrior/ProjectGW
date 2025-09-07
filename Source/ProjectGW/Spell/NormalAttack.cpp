// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell/NormalAttack.h"
#include "Components/SphereComponent.h"

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
	EffectMeshComponent = LoadEffectMeshComponent(TEXT("/Game/FX/Mesh/sm_shild_01.sm_shild_01"));
	CreateEffectComponent = LoadCreateEffectComponent(TEXT("/Game/FX/NS/Shield.Shield"));
}
// Called when the game starts or when spawned
void ANormalAttack::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ANormalAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}