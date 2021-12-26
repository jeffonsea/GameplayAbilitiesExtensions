#include "Abilities/JAbilities_fwd.h"

#include "GameplayAbilitySpec.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"

DEFINE_LOG_CATEGORY_STATIC(LogAbilities, All, All);

void UJAbilitySet::GiveAbilities(AActor* AbilityActor)
{
    if (!AbilityActor->HasAuthority())
    {
        return;
    }

    if(IAbilitySystemInterface* pASI = Cast<IAbilitySystemInterface>(AbilityActor))
    {
        if (UAbilitySystemComponent* pASC = pASI->GetAbilitySystemComponent())
        {
            for (FJGameplayAbilityBindInfoExtended& BindInfo : Bindings)
            {
                FGameplayAbilitySpec spec = FGameplayAbilitySpec
                (
                    BindInfo.GameplayAbilityClass,
                    1,
                    (int32)BindInfo.Input,
                    nullptr
                );

                pASC->GiveAbility(spec);
            }
        }
    }
    else
    {
        // Add warning.
        UE_LOG(LogAbilities, Warning, TEXT("Attempted to GiveAbilities to a non IAbilitySystemInterface actor."));
    }
}

bool UJAbilitySet::GetAbilityBinding(EJAbilityInputsExtended Input, FJGameplayAbilityBindInfoExtended& OutBinding)
{
    for (const FJGameplayAbilityBindInfoExtended& binding : Bindings)
    {
        if (binding.Input != Input)
            continue;

        OutBinding = binding;
        return true;
    }

    return false;
}
