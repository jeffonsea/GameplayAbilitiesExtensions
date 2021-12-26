#include "Abilities/Tasks/Animation/JWaitForAnimNotifyWindowWithTagAbilityTask.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWindowWithTagAbilityTask::Activate()
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
                        &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowStartReceived
                    );

                    pAnimInstance->OnPlayMontageNotifyEnd.AddUniqueDynamic
                    (
                        this,
                        &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowEndReceived
                    );
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWindowWithTagAbilityTask::OnDestroy(bool AbilityEnded)
{
    pAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic
    (
        this,
        &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowStartReceived
    );

    pAnimInstance->OnPlayMontageNotifyEnd.RemoveDynamic
    (
        this,
        &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowEndReceived
    );

    Super::OnDestroy(AbilityEnded);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowStartReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
    if (ShouldBroadcastAbilityTaskDelegates())
    {
        if (m_notifyName.GetTagName() == NotifyName)
        {
            OnAnimNotifyWindowStartDelegate.Broadcast();
            
            pAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic
            (
                this,
                &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowStartReceived
            );
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
    if (ShouldBroadcastAbilityTaskDelegates())
    {
        if (m_notifyName.GetTagName() == NotifyName)
        {
            OnAnimNotifyWindowEndDelegate.Broadcast();
            
            pAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic
            (
                this,
                &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowStartReceived
            );
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJWaitForAnimNotifyWindowWithTagAbilityTask::BindDelegates()
{
    pAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic
    (
        this,
        &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowStartReceived
    );

    pAnimInstance->OnPlayMontageNotifyBegin.RemoveDynamic
    (
        this,
        &UJWaitForAnimNotifyWindowWithTagAbilityTask::OnAnimNotifyWindowEndReceived
    );
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

UJWaitForAnimNotifyWindowWithTagAbilityTask* UJWaitForAnimNotifyWindowWithTagAbilityTask::WaitForNotifyWindowWithTag(UGameplayAbility* OwningAbility, const FGameplayTag NotifyTag)
{
    UJWaitForAnimNotifyWindowWithTagAbilityTask* pAbilityTask = NewAbilityTask<UJWaitForAnimNotifyWindowWithTagAbilityTask>(OwningAbility);
    pAbilityTask->m_notifyName = NotifyTag.GetTagName();
    
    return pAbilityTask;
}
