// @nhpt150


#include "Character/MCO_Character_Player.h"
#include "EnhancedInputComponent.h"
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
	
	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent->bUsePawnControlRotation = false;
}

void AMCO_Character_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMCO_Character_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(
			InputAction_Jump,
			ETriggerEvent::Started, 
			this, 
			&AMCO_Character_Player::Input_Trigger_Jump);
		
		EnhancedInputComponent->BindAction(
			InputAction_Look,
			ETriggerEvent::Triggered, 
			this, 
			&AMCO_Character_Player::Input_Trigger_Look);
	}

}

void AMCO_Character_Player::PawnClientRestart()
{
	Super::PawnClientRestart();
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

void AMCO_Character_Player::Input_Trigger_Jump()
{
	Jump();
}

void AMCO_Character_Player::Input_Trigger_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisValue = InputActionValue.Get<FVector2D>();
	AddControllerYawInput(LookAxisValue.X);
	AddControllerPitchInput(LookAxisValue.Y);
}
