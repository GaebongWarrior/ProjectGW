// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell/Spell.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"


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
	CreateEffectComponent->OnSystemFinished.AddDynamic(this, &ASpell::OnCreateEffectFinished);
	CreateEffectComponent->Activate(true);
	
}

void ASpell::Destroyed()
{
	if (DestroyEffectSystem)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(),
            DestroyEffectSystem,
            GetActorLocation(),
            GetActorRotation()
        );
	}
	Super::Destroyed();
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
		Comp->bAutoActivate = false;
	}
	else
	{
		Comp->bAutoActivate = false;
	}

	return Comp;
}

UNiagaraComponent* ASpell::LoadEffectComponent(FString Path)
{
	UNiagaraComponent* Comp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("EffectComponent"));
	Comp->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NS_Impact(*Path);
	if (NS_Impact.Succeeded())
	{
		Comp->SetAsset(NS_Impact.Object);
		//Comp->bAutoActivate = true; // 자동 활성화
		Comp->bAutoActivate = false;
	}
	else
	{
		Comp->bAutoActivate = false;
	}

	return Comp;
}

UNiagaraSystem* ASpell::LoadDestroyEffectSystem(FString Path)
{

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NS_Impact(*Path);
	if (NS_Impact.Succeeded())
	{
		return NS_Impact.Object;
	}
	else
	{
		return nullptr;
	}

}

void ASpell::OnCreateEffectFinished(UNiagaraComponent* FinishedComp)
{
	EffectComponent->Activate(true);
}
