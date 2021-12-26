#include "Abilities/Tasks/Animation/JWaitForAnimNotifyWithTagAbilityTask.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWithTagAbilityTask::Activate()
{
    SetWaitingOnAvatar();

    if (AActor* pActor = GetAvatarActor())
    {
        if (const ACharacter* pCharacter = Cast<ACharacter>(pActor))
        {
            if (const USkeletalMeshComponent* pMesh = pCharacter->GetMesh())
            {
                pAnimInstance = pMesh->GetAnimInstance();
                if (pAnimInstance)
                {
                    pAnimInstance->OnPlayMontageNotifyBegin.AddUniqueDynamic
                    (
                        this,
                        &UJWaitForAnimNotifyWithTagAbilityTask::OnAnimNotifyReceived
                    );
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWithTagAbilityTask::OnDestroy(bool AbilityEnded)
{
    SetWaitingOnAvatar();
    
    pAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic
    (
        this,
        &UJWaitForAnimNotifyWithTagAbilityTask::OnAnimNotifyReceived
    );

    Super::OnDestroy(AbilityEnded);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWithTagAbilityTask::OnAnimNotifyReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
    if (ShouldBroadcastAbilityTaskDelegates())
    {
        if (m_notifyName == NotifyName)
        {
            OnAnimNotifyReceivedDelegate.Broadcast();

            OnAnimNotifyReceivedDelegate.RemoveDynamic
            (
                this,
                &UJWaitForAnimNotifyWithTagAbilityTask::OnAnimNotifyReceived
            );
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWithTagAbilityTask::BindDelegates()
{
    pAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic
    (
        this,
        &UJWaitForAnimNotifyWithTagAbilityTask::OnAnimNotifyReceived
    );
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

UJWaitForAnimNotifyWithTagAbilityTask* UJWaitForAnimNotifyWithTagAbilityTask::WaitForNotifyWithTag(UGameplayAbility* OwningAbility, const FGameplayTag NotifyTag)
{
    UJWaitForAnimNotifyWithTagAbilityTask* pAbilityTask = NewAbilityTask<UJWaitForAnimNotifyWithTagAbilityTask>(OwningAbility);
    pAbilityTask->m_notifyName = NotifyTag.GetTagName();
    
    return pAbilityTask;
}
