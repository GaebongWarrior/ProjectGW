// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Mage.generated.h"

class USpringArmComponent; // 사용할 클래스 선언(카메라 붙이기 위한 스프링 암)
class UCameraComponent; // 사용할 클래스 선언(카메라)
class UInputMappingContext; // 사용할 클래스 선언(IMC)

UCLASS()
class PROJECTGW_API AMage : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMage();

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom; //스프링 암을 이용해서 카메라를 다루는 컴포넌트 선언

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera; // 카메라 컴포넌트 선언

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* AimCameraBoom; //스프링 암을 이용해서 카메라를 다루는 컴포넌트 선언

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* AimCamera; // 카메라 컴포넌트 선언

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* IMC_OnLevelCharacter; // 입력 매핑 컨텍스트 선언

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UCameraComponent* GetCamera(FName Name);

	// 앞/뒤쪽 입력을 위해 호출합니다.
	UFUNCTION(BlueprintCallable)
	void MoveForward(float InputAxis);

	// 왼/오른쪽 입력을 위해 호출합니다.
	UFUNCTION(BlueprintCallable)
	void MoveRight(float InputAxis);

	// 시야 전환을 위해 호출합니다.	
	UFUNCTION(BlueprintCallable)
	void Look(const FVector2D Value);

	// 달리기 시작을 위해 호출
	UFUNCTION(BlueprintCallable)
	void SprintStart();

	// 달리기 종료를 위해 호출
	UFUNCTION(BlueprintCallable)
	void SprintEnd();


	// 점프 시작을 위해 호출
	UFUNCTION(BlueprintCallable)
	void JumpStart();

	// 점프 종료를 위해 호출
	UFUNCTION(BlueprintCallable)
	void JumpEnd();

	// 확대를 위해 호출
	UFUNCTION(BlueprintCallable)
	void Zoom(const float Value);


	// 조준을 위해 호출
	UFUNCTION(BlueprintCallable)
	void Aim();
	UFUNCTION(BlueprintCallable)
	void AimStart();
	UFUNCTION(BlueprintCallable)
	void AimEnd();

	// 공격을 위해 호출
	UFUNCTION(BlueprintCallable)
	void Attack();

public:
	UPROPERTY()
	UCharacterMovementComponent* MoveComponent; // 캐릭터 이동 컴포넌트 포인터

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	bool bIsAiming = false;

};
