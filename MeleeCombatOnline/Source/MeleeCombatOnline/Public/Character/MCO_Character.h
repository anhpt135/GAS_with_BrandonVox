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
	AMCO_Character();

protected:
	virtual void BeginPlay() override;
};
