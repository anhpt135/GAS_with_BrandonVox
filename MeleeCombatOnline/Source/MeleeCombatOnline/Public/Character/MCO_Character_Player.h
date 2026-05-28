// @nhpt150

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "MCO_Character.h"
#include "MCO_Character_Player.generated.h"

class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MELEECOMBATONLINE_API AMCO_Character_Player : public AMCO_Character
{
	GENERATED_BODY()

public:
	AMCO_Character_Player();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PawnClientRestart() override;

protected:
	virtual void BeginPlay() override;
	
private://Function
	void SetupInputMappingContext() const;
	void Input_Trigger_Jump();
	void Input_Trigger_Look(const FInputActionValue& InputActionValue);
	
private: // Property
	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "MCO Settings|Input")
	TObjectPtr<UInputMappingContext> MyInputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "MCO Settings|Input")
	TObjectPtr<UInputAction> InputAction_Jump;
	
	UPROPERTY(EditDefaultsOnly, Category = "MCO Settings|Input")
	TObjectPtr<UInputAction> InputAction_Look;
};
