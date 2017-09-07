// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFlightSmilator.h"
#include "AirPlaneWing.h"


// Sets default values for this component's properties
UAirPlaneWing::UAirPlaneWing()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAirPlaneWing::BeginPlay()
{
	Super::BeginPlay();

	if(bIsUsingWingsToRotate){
		UseWingsToRotate(WingsScaleForRotate);
	}
	
}


// Called every frame
void UAirPlaneWing::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsUsingWingsToRotate) {
		UseWingsToRotate(WingsScaleForRotate);
	}
	if(bIsUsingWingsForDownMovement) {
		UseWingsToDown(WingsScaleForUpDownMovement);
	}else if(bIsUsingWingsForUpMovement) {
		UseWingsToUp(WingsScaleForUpDownMovement);
	}
}

void UAirPlaneWing::UseWingsToRotate(float Scale){

	float WingsRotation = Scale * PlaneRotatingSpeed;
	FRotator NewRotation = GetOwner()->GetActorRotation();
	NewRotation.Roll += WingsRotation;
	GetOwner()->SetActorRotation(NewRotation, ETeleportType::None);
}

void UAirPlaneWing::UseWingsToUp(float Scale) {

	float WingsRotation = Scale * PlaneUpDownSpeed;
	FRotator NewRotation = GetOwner()->GetActorRotation();
	NewRotation.Pitch -= WingsRotation;
	GetOwner()->SetActorRotation(NewRotation, ETeleportType::None);
}

void UAirPlaneWing::UseWingsToDown(float Scale) {

	float WingsRotation = Scale * PlaneUpDownSpeed;
	FRotator NewRotation = GetOwner()->GetActorRotation();
	NewRotation.Pitch += WingsRotation;
	GetOwner()->SetActorRotation(NewRotation, ETeleportType::None);
}


void UAirPlaneWing::SetWingsScaleForRotating(float ScaleToSet) {

	WingsScaleForRotate = ScaleToSet;
}

void UAirPlaneWing::SetIsUsingWingsForRotating(bool boolToSet) {
	bIsUsingWingsToRotate = boolToSet;
}

void UAirPlaneWing::SetWingsScaleForUpDownMovement(float ScaleToSet) {
	WingsScaleForUpDownMovement = ScaleToSet;
}

void UAirPlaneWing::SetIsUsingWingsForDownMovement(bool boolToSet) {
	bIsUsingWingsForDownMovement = boolToSet;
}

void UAirPlaneWing::SetIsUsingWingsForUpMovement(bool boolToSet) {
	bIsUsingWingsForUpMovement = boolToSet;
}