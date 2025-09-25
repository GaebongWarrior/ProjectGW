// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h" // FTableRowBase 사용하려면 필요
#include "SpellData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSpellRow : public FTableRowBase
{
    GENERATED_BODY();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName SpellId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Power = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Cooldown = 0.f;
};