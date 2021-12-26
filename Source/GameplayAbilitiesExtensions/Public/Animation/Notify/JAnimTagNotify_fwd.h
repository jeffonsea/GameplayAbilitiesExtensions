#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "AnimNotifies/AnimNotify_PlayMontageNotify.h"

#include "JAnimTagNotify_fwd.generated.h"

UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UJAnimTagNotify : public UAnimNotify_PlayMontageNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag NotifyTag = FGameplayTag::EmptyTag;

public:
	virtual FString GetNotifyName_Implementation() const override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};

UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UJAnimTagNotifyWindow : public UAnimNotify_PlayMontageNotifyWindow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag NotifyTag = FGameplayTag::EmptyTag;

public:
	virtual FString GetNotifyName_Implementation() const override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};
