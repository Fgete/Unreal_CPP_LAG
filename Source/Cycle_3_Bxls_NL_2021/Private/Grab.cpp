// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawDebugHelpers.h"
#include "Grab.h"

// Sets default values for this component's properties
UGrab::UGrab()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrab::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrab::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGrab::Grab(float grabDistance, FVector forwardVector, FTransform location) const
{
	FHitResult outHit;

	FVector start = location.GetLocation();
	FVector end = (forwardVector * grabDistance) + start;
	FCollisionQueryParams CollisionParams(FName(TEXT("")), false, GetOwner());

	GEngine->AddOnScreenDebugMessage(0, 2, FColor::Green, start.ToString());
	GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, end.ToString());

	// DrawDebugLine(GetWorld(), start, end, FColor::Green, false, 1, 0, 1);

	if (GetWorld()->LineTraceSingleByChannel(outHit, start, end, ECollisionChannel::ECC_PhysicsBody, CollisionParams))
	{
		GEngine->AddOnScreenDebugMessage(4, 2, FColor::Green, FString::Printf(TEXT("The Component Being Hit is: %s"), *outHit.GetActor()->GetName()));
		outHit.GetActor()->SetActorLocation(end);
	}
	else
		GEngine->AddOnScreenDebugMessage(4, 2, FColor::Green, FString::Printf(TEXT("NULL")));
}

