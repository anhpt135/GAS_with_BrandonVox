// @nhpt150

#pragma once

#include "CoreMinimal.h"
#include "MCO_Character.h"
#include "MCO_Character_Player.generated.h"

UCLASS()
class MELEECOMBATONLINE_API AMCO_Character_Player : public AMCO_Character
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMCO_Character_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
