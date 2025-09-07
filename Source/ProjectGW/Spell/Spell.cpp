// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell/Spell.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"


// Sets default values
ASpell::ASpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UNiagaraComponent* ASpell::LoadCreateEffectComponent(FString Path)
{
	UNiagaraComponent* Comp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("CreateEffectComponent"));
	Comp->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NS_Impact(*Path);
	if (NS_Impact.Succeeded())
	{
		Comp->SetAsset(NS_Impact.Object);
		Comp->bAutoActivate = true; // 자동 활성화
	}
	else
	{
		Comp->bAutoActivate = false;
	}

	return Comp;
}

UStaticMeshComponent* ASpell::LoadEffectMeshComponent(FString Path)
{
	UStaticMeshComponent* Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EffectMeshComponent"));
	Comp->SetupAttachment(RootComponent);
	Comp->SetEnableGravity(false); // 중력 영향 없음
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(*Path);
	if (MeshAsset.Succeeded())
	{
		Comp->SetStaticMesh(MeshAsset.Object);
	}
	else
	{
		Comp->SetStaticMesh(nullptr);
	}
	return Comp;
}
