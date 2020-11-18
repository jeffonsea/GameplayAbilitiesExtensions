#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AbilityTask_WaitForNotify.generated.h"

/**
 * Ability task that listens to notifies on the animation montages and
 * checks by name if the given notify has been reached.
 */
UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UAbilityTask_WaitForNotifyWithTag : public UAbilityTask
{
    GENERATED_BODY()

public: // Public Variables

    // Delegate with the data send on the task
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimNotifyReceived);
    UPROPERTY(BlueprintAssignable)
    FAnimNotifyReceived OnAnimNotifyReceivedDelegate;

private: // Private Methods

    /** Function used to bind events and init things. */
    virtual void Activate() override;

    /** Function to unbind events. */
    virtual void OnDestroy(bool AbilityEnded) override;

    /** Function binded to the animation notify delegates. */
    UFUNCTION()
    void OnAnimNotifyReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

    /** Actual async task callable function. */
    UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
    static UAbilityTask_WaitForNotifyWithTag* WaitForNotifyWithTag(UGameplayAbility* OwningAbility, const FGameplayTag NotifyName);

private: // Private Variables

    // Name of the notify we are waiting for
    FName m_notifyName = NAME_None;
};
