// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell.generated.h"

UCLASS()
class PROJECTGW_API ASpell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
					
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditDefaultsOnly, Category = "VFX")
	class UNiagaraComponent* CreateEffectComponent;

	UPROPERTY(EditDefaultsOnly, Category = "VFX")
	class UNiagaraComponent* EffectComponent;

	UPROPERTY(EditDefaultsOnly, Category = "VFX")
	class UNiagaraSystem* DestroyEffectSystem;

	UNiagaraComponent* LoadCreateEffectComponent(FString Path);

	UNiagaraComponent* LoadEffectComponent(FString Path);

	UNiagaraSystem* LoadDestroyEffectSystem(FString Path);

	UFUNCTION()
	void OnCreateEffectFinished(UNiagaraComponent* FinishedComp);
};
