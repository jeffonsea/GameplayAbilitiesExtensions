#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Abilities/GameplayAbility.h"

#include "Abilities_fwd.generated.h"

UENUM(BlueprintType)
enum class EAbilityInputsExtended : uint8 
{
	Ability1 UMETA(DisplayName = "Ability1 (LMB)"),
    Ability2 UMETA(DisplayName = "Ability2 (RMB)"),
    Ability3 UMETA(DisplayName = "Ability3 (Q)"),
    Ability4 UMETA(DisplayName = "Ability4 (E)"),
    Ability5 UMETA(DisplayName = "Ability5 (R)"),
    Ability6 UMETA(DisplayName = "Ability6 (F)"),
    Ability7 UMETA(DisplayName = "Ability7 (Space)"),
    Confirm UMETA(DisplayName = "Confirm"),
    Cancel UMETA(DisplayName = "Cancel")
};

USTRUCT(BlueprintType)
struct FGameplayAbilityBindInfoExtended
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere)
	EAbilityInputsExtended Input;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayAbility> GameplayAbilityClass;
};

UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UAbilitySet : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FGameplayAbilityBindInfoExtended> Bindings;

	UFUNCTION(BlueprintCallable)
	virtual void GiveAbilities(AActor* AbilityActor);
};
