// @nhpt150


#include "Character/MCO_Character_Player.h"


// Sets default values
AMCO_Character_Player::AMCO_Character_Player()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMCO_Character_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMCO_Character_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMCO_Character_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

