// Fill out your copyright notice in the Description page of Project Settings.


#include "Mage.h"
//카메라 관련 헤더---------------
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
//--------------------------------------
#include "Components/CapsuleComponent.h"

// Sets default values

AMage::AMage()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f); // 캐릭터 충돌 범위 지정

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	// 캐릭터 회전 설정 -> 회전 안함

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate
	// 이동 방향에 따라 캐릭터 회전 및 회전속도 설정

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 600.f; // 점프력
	GetCharacterMovement()->AirControl = 0.35f; // 공중에서 방향전환
	GetCharacterMovement()->GravityScale = 1.75f; // 중력
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;// 마찰력
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;// 공중 마찰력
	// 캐릭터 속도 설정


	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 600.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	
	AimCameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("AimCameraBoom"));
	AimCameraBoom->SetupAttachment(RootComponent);
	AimCameraBoom->TargetArmLength = -25.0f; //
	AimCameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f)); // AimCameraBoom 위치 설정
	AimCameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a aim camera	
	AimCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("AimCamera"));
	AimCamera->SetupAttachment(AimCameraBoom, USpringArmComponent::SocketName);
	AimCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to armz
	AimCamera->bAutoActivate = false; // AimCamera 비활성화
}

// Called when the game starts or when spawned
void AMage::BeginPlay()
{
	Super::BeginPlay();
	MoveComponent = GetCharacterMovement(); // 캐릭터 이동 컴포넌트 설정
	//CameraBoom = FindComponentByClass<USpringArmComponent>(); // 스프링 암 컴포넌트 찾기
	FollowCamera = GetCamera("FollowCamera"); // FollowCamera 컴포넌트 찾기
	AimCamera = GetCamera("AimCamera"); // AimCamera 컴포넌트 찾기
}

// Called every frame
void AMage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMage::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAxis("MoveForward", this, &AMage::MoveForward); // 앞/뒤쪽 입력
	//PlayerInputComponent->BindAxis("MoveRight", this, &AMage::MoveRight); // 왼/오른쪽 입력
}

void AMage::MoveForward(float AxisValue)
{
	//컨트롤러가 null이 아니면 사용
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		// 앞쪽 찾기
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// 앞쪽 벡터 구하기
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// 해당 방향으로 이동 추가
		AddMovementInput(Direction, AxisValue);
	}
}

void AMage::MoveRight(float AxisValue)
{
	//컨트롤러가 null이 아니면 사용
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		// 오른쪽 찾기
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// 오른쪽 벡터 구하기
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// 해당 방향으로 이동 추가
		AddMovementInput(Direction, AxisValue);
	}
}

void AMage::Look(const FVector2D Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Look: %s"), *Value.ToString());
	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Value.X);
		AddControllerPitchInput(Value.Y);
	}

}

void AMage::SprintStart()
{
	if (MoveComponent) { MoveComponent->MaxWalkSpeed = 800.f; }
}

void AMage::SprintEnd()
{
	if (MoveComponent) { MoveComponent->MaxWalkSpeed = 300.f; } // 달리기 속도 설정
}

void AMage::JumpStart()
{
	Jump();
}

void AMage::JumpEnd()
{
	StopJumping();
}

void AMage::Zoom(const float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Zoom: %f"), Value);
	
	//if (CameraBoom)
	//{
	//	CameraBoom->TargetArmLength = FMath::Clamp(CameraBoom->TargetArmLength - Value * 30.0f, 200.0f, 800.0f); // 줌 조절 Clmap는 거리 조절 기능
	//	UE_LOG(LogTemp, Warning, TEXT("Zoom: %f"), Value);
	//}
}

void AMage::Aim()
{
	if (!bIsAiming)
	{
		if (FollowCamera)
			FollowCamera->IsActive() ? FollowCamera->Deactivate() : FollowCamera->Activate(); // FollowCamera 활성화/비활성화 토글
		if (AimCamera)
			AimCamera->IsActive() ? AimCamera->Deactivate() : AimCamera->Activate(); // AimCamera 활성화/비활성화 토글
	}
}

void AMage::AimStart()
{
	bIsAiming = true; // 조준 상태 설정
	FollowCamera->Deactivate(); // FollowCamera 비활성화
	AimCamera->Activate(); // AimCamera 활성화
}

void AMage::AimEnd()
{
	if (bIsAiming)
	{
		AimCamera->Deactivate(); // AimCamera 비활성화
		FollowCamera->Activate(); // FollowCamera 활성화
		bIsAiming = false; // 조준 상태 해제
	}
	//UE_LOG(LogTemp, Warning, TEXT("AimEnd"));
}

UCameraComponent* AMage::GetCamera(FName Name)
{
	TArray<UCameraComponent*> Cameras;
	GetComponents<UCameraComponent>(Cameras);
	for (UCameraComponent* Camera : Cameras)
	{
		if (Camera && Camera-> GetFName() == Name)
			return Camera; // 카메라 이름이 일치하는 경우 반환
	}
	UE_LOG(LogTemp, Warning, TEXT("No camera found with name: %s"), *Name.ToString());
	return nullptr; // 일치하는 카메라가 없는 경우 nullptr 반환
}