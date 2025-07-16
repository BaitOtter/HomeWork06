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
	
	// ���� ��ġ �ʱ�ȭ
	StartLocation = GetActorLocation();

	// Ÿ�� ��ġ �ʱ�ȭ
	TargetLocation = StartLocation + TargetLocation;

}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ������ ���ϱ�
	FVector DestLocation = bIsMoveToTarget ? TargetLocation : StartLocation;
	
	// ���� ���ϱ�
	FVector CurrentLocation = GetActorLocation();
	FVector Direction = (DestLocation - CurrentLocation).GetSafeNormal();

	// ���� �̵�
	SetActorLocation(CurrentLocation + Direction * MoveSpeed * DeltaTime);
	//AddActorLocalOffset(Direction * MoveSpeed * DeltaTime);

	// ���� �ٲٱ�
	if (FVector::Distance(CurrentLocation, DestLocation) < 1.0f)
	{
		bIsMoveToTarget = !bIsMoveToTarget;
	}

}

