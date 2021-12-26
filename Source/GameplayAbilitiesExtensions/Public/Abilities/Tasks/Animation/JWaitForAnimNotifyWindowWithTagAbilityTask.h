#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Animation/AnimNotifies/AnimNotify.h"

#include "JWaitForAnimNotifyWindowWithTagAbilityTask.generated.h"

/**
 * Ability task that listens to notifies on the animation montages and
 * checks by name if the given notify has been reached.
 */
UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UJWaitForAnimNotifyWindowWithTagAbilityTask : public UAbilityTask
{
    GENERATED_BODY()

public:
    // Delegate with the data send on the task
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnimNotifyReceived);
    UPROPERTY(BlueprintAssignable)
    FAnimNotifyReceived OnAnimNotifyWindowStartDelegate;
    
    // Delegate with the data send on the task
    UPROPERTY(BlueprintAssignable)
    FAnimNotifyReceived OnAnimNotifyWindowEndDelegate;

private:
    /** Function used to bind events and init things. */
    virtual void Activate() override;

    /** Function to unbind events. */
    virtual void OnDestroy(bool AbilityEnded) override;

    /** Function bound to the animation notify window start delegate. */
    UFUNCTION()
    void OnAnimNotifyWindowStartReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);
    
    /** Function bound to the animation notify window end delegate.. */
    UFUNCTION()
    void OnAnimNotifyWindowEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

    void BindDelegates();

    /** Actual async task callable function. */
    UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
    static UJWaitForAnimNotifyWindowWithTagAbilityTask* WaitForNotifyWindowWithTag(UGameplayAbility* OwningAbility, const FGameplayTag NotifyName);

private:

    // Name of the notify we are waiting for
    UPROPERTY()
    FName m_notifyName = NAME_None;

    // Anim instance pointer.
    UPROPERTY()
    UAnimInstance* pAnimInstance = nullptr;
};
