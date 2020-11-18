#include "Abilities/Tasks/Animation/AbilityTask_WaitForNotify.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UAbilityTask_WaitForNotifyWithTag::Activate()
{
    SetWaitingOnAvatar();

    if (AActor* pActor = GetAvatarActor())
    {
        if (ACharacter* pCharacter = Cast<ACharacter>(pActor))
        {
            pCharacter->GetMesh()->GetAnimInstance()->OnPlayMontageNotifyBegin.AddDynamic(this, &UAbilityTask_WaitForNotifyWithTag::OnAnimNotifyReceived);
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UAbilityTask_WaitForNotifyWithTag::OnDestroy(bool AbilityEnded)
{
    SetWaitingOnAvatar();

    if (AActor* pActor = GetAvatarActor())
    {
        if (ACharacter* pCharacter = Cast<ACharacter>(pActor))
        {
            pCharacter->GetMesh()->GetAnimInstance()->OnPlayMontageNotifyBegin.RemoveDynamic(this, &UAbilityTask_WaitForNotifyWithTag::OnAnimNotifyReceived);
        }
    }

    Super::OnDestroy(AbilityEnded);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UAbilityTask_WaitForNotifyWithTag::OnAnimNotifyReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload)
{
    if (ShouldBroadcastAbilityTaskDelegates())
    {
        if (m_notifyName == NotifyName)
        {
            OnAnimNotifyReceivedDelegate.Broadcast();

            if (AActor* pActor = GetAvatarActor())
            {
                if (ACharacter* pCharacter = Cast<ACharacter>(pActor))
                {
                    pCharacter->GetMesh()->GetAnimInstance()->OnPlayMontageNotifyBegin.RemoveDynamic(this, &UAbilityTask_WaitForNotifyWithTag::OnAnimNotifyReceived);
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

UAbilityTask_WaitForNotifyWithTag* UAbilityTask_WaitForNotifyWithTag::WaitForNotifyWithTag(UGameplayAbility* OwningAbility, const FGameplayTag NotifyName)
{
    UAbilityTask_WaitForNotifyWithTag* pAbilityTask = NewAbilityTask<UAbilityTask_WaitForNotifyWithTag>(OwningAbility);
    pAbilityTask->m_notifyName = FName(NotifyName.ToString());
    return pAbilityTask;
}
