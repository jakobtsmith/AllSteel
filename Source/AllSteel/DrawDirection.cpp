// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDirection.h"

#define OUT

// Sets default values for this component's properties
UDrawDirection::UDrawDirection()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDrawDirection::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDrawDirection::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	bool Draw = true;
	Draw = false;
	if (Draw) {
		FVector PlayerViewPointLocation;
		FRotator PlayerViewPointRotation;

		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewPointLocation,
			OUT PlayerViewPointRotation
		);

		FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * 200.f;

		DrawDebugLine(
			GetWorld(),
			PlayerViewPointLocation,
			LineTraceEnd,
			FColor(255, 0, 255),
			false,
			0.f,
			0,
			5.f
		);
	}
}

