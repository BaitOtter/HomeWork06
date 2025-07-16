// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class HW06_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector StartLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TargetLocation = FVector(0.0f, 0.0f, 200.0f);

	bool bIsMoveToTarget = true;

	float MoveSpeed = 75.0f;
	float MaxRange = 50.0f;

public:	
	virtual void Tick(float DeltaTime) override;

};
