#pragma once

#include "CoreMinimal.h"
#include "AnimGraphRuntime/Public/AnimNotifies/AnimNotify_PlayMontageNotify.h"

#include "GameplayTagContainer.h"

#include "AnimNotify_TagNotify.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UAnimNotify_TagNotify : public UAnimNotify_PlayMontageNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag NotifyTag = FGameplayTag::EmptyTag;

	FString GetNotifyName_Implementation() const override;

	void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

};
