// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirPlaneEngine.h"

// Sets default values for this component's properties
UAirPlaneEngine::UAirPlaneEngine(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirPlaneEngine::BeginPlay(){
	Super::BeginPlay();
	
}


// Called every frame
void UAirPlaneEngine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (EngineLevel == 0) {
		UE_LOG(LogTemp, Warning, TEXT("EngineLevel: 0"));
	}
	else if (EngineLevel == 1) {
		UE_LOG(LogTemp, Warning, TEXT("EngineLevel: 1"));
	}
	else if (EngineLevel == 2) {
		UE_LOG(LogTemp, Warning, TEXT("EngineLevel: 2"));
	}
	else if (EngineLevel == 3) {
		UE_LOG(LogTemp, Warning, TEXT("EngineLevel: 3"));
	}

	
	PushPlane();
}

void UAirPlaneEngine::ChangeEngineLevel(int EngineLevelToChange){
	UE_LOG(LogTemp, Warning, TEXT("Engine level incremented."));
	EngineLevel += EngineLevelToChange;
}

void UAirPlaneEngine::SetEngineLevel(int EngineLevelToSet){
	UE_LOG(LogTemp, Warning, TEXT("Engine level Set."));
	EngineLevel = EngineLevelToSet;
}

void UAirPlaneEngine::PushPlane() {

	MaxSpeed = bIsBreaking == true ? 0 :EngineLevel * EnginePower;

	
	UE_LOG(LogTemp, Warning, TEXT("speed %f MaxSpeed:%f"), Speed ,MaxSpeed);
	if(Speed >= MaxSpeed) {
		Speed -= ((MaxSpeed) == 0 ? 200 : (MaxSpeed)) / 1000;
	} else{
		Speed += ((MaxSpeed) == 0 ? 200 : (MaxSpeed)) / 1000;
	}

	FVector DeltaLocation(Speed, 0, 0);
	GetOwner()->AddActorLocalOffset(DeltaLocation, true, nullptr, ETeleportType::None);
}

float UAirPlaneEngine::GetPlaneSpeed(){
	return Speed;
}

void UAirPlaneEngine::SetIsBreaking(bool BreakingToSet) {
	bIsBreaking = BreakingToSet;
}