// @nhpt150


#include "Character/MCO_Character_Player.h"

#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AMCO_Character_Player::AMCO_Character_Player()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
}

void AMCO_Character_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMCO_Character_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMCO_Character_Player::PawnClientRestart()
{
	Super::PawnClientRestart();
	/*
	 * Player controller ->Pawn/Character
	 * Local Player -> Player Controller -> Pawn/Character
	 * Camera/Input bindings
	 * Client machines
	 * Listen server
	 * Add Input Mapping Context by Local Player
	 */
	
	SetupInputMappingContext();
	
}
void AMCO_Character_Player::SetupInputMappingContext() const
{
	if (APlayerController* MyPlayerController = GetController<APlayerController>())
	{
		ULocalPlayer* MyLocalPlayer = MyPlayerController->GetLocalPlayer();
		
			UEnhancedInputLocalPlayerSubsystem* InputSubsystem = 
				ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(MyLocalPlayer);
		
		if (InputSubsystem)
		{
			InputSubsystem->RemoveMappingContext(MyInputMappingContext);
			InputSubsystem->AddMappingContext(MyInputMappingContext, 0);
		}
		

	}

}
