// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell/Spell.h"
#include "ProjectileSpell.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGW_API AProjectileSpell : public ASpell
{
	GENERATED_BODY()
	

public:
	AProjectileSpell();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UShapeComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovement;

	template<typename Tshape>
	Tshape* CreateCollisionComponent(FName Name, TFunctionRef<void(Tshape*)> Init)
	{
		Tshape* Comp = CreateDefaultSubobject<Tshape>(Name);
		Init(Comp);
		Comp->SetEnableGravity(false);
		Comp->SetCollisionProfileName(TEXT("Projectile"));
		RootComponent = Comp;

		return Comp;
	}

	UProjectileMovementComponent* CreateProjectileMovementComponent(float InitSpeed, float MaxSpeed);
};
