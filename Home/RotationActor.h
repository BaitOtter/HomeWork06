// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationActor.generated.h"

UCLASS()
class HW06_API ARotationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	FRotator RotationRate = FRotator(0.0f, 30.0f, 0.0f);

public:	
	virtual void Tick(float DeltaTime) override;

};
