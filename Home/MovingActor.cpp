// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	RootComponent = StaticMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Stylized_Egypt/Meshes/building/SM_block_07.SM_block_07"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	}
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 시작 위치 초기화
	StartLocation = GetActorLocation();

	// 타겟 위치 초기화
	TargetLocation = StartLocation + TargetLocation;

}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 목적지 구하기
	FVector DestLocation = bIsMoveToTarget ? TargetLocation : StartLocation;
	
	// 방향 구하기
	FVector CurrentLocation = GetActorLocation();
	FVector Direction = (DestLocation - CurrentLocation).GetSafeNormal();

	// 방향 이동
	SetActorLocation(CurrentLocation + Direction * MoveSpeed * DeltaTime);
	//AddActorLocalOffset(Direction * MoveSpeed * DeltaTime);

	// 방향 바꾸기
	if (FVector::Distance(CurrentLocation, DestLocation) < 1.0f)
	{
		bIsMoveToTarget = !bIsMoveToTarget;
	}

}

