// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell/ProjectileSpell.h"
#include "GameFramework/ProjectileMovementComponent.h"


AProjectileSpell::AProjectileSpell()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AProjectileSpell::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectileSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UProjectileMovementComponent* AProjectileSpell::CreateProjectileMovementComponent(float InitSpeed, float MaxSpeed)
{
	UProjectileMovementComponent* Comp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	if (RootComponent) Comp->UpdatedComponent = RootComponent; // 충돌구체를 기준으로 설정
	Comp->InitialSpeed = InitSpeed; // 초기 속도 설정
	Comp->MaxSpeed = MaxSpeed; // 최대 속도 설정
	Comp->bRotationFollowsVelocity = false; // 진행 방향으로 오브젝트 방향 설정
	Comp->bShouldBounce = false;            // 튕김 여부
	Comp->ProjectileGravityScale = 0.f; // 중력 영향 설정(0이면 중력 영향 없음)
	Comp->UpdatedComponent = RootComponent;
	Comp->SetVelocityInLocalSpace(FVector::ForwardVector * Comp->InitialSpeed);
	Comp->Activate(true);
	return Comp;
}