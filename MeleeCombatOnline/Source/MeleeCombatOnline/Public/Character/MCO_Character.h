// @nhpt150

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MCO_Character.generated.h"

UCLASS()
class MELEECOMBATONLINE_API AMCO_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMCO_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
