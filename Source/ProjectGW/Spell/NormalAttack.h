// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell/ProjectileSpell.h"
#include "NormalAttack.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGW_API ANormalAttack : public AProjectileSpell
{
	GENERATED_BODY()
	

public:	
	ANormalAttack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
