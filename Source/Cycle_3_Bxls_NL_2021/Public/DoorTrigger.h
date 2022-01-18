// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorTrigger.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class CYCLE_3_BXLS_NL_2021_API UDoorTrigger : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorTrigger();
	int numberOfObjectOverlaping = 0;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "MyDoor")
	void OnTriggerEnter();
	UFUNCTION(BlueprintCallable, Category = "MyDoor")
	void OnTriggerExit();
	UFUNCTION(BlueprintCallable, Category = "MyDoor")
	int GetNumberOfOverlapingObjects();
};
