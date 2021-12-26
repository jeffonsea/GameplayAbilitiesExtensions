// Copyright Jeff Onsea 2021

#pragma once

#include "CoreMinimal.h"
#include "JBaseAttributeSet.h"

#include "JResourceAttributeSet.generated.h"

UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UJResourceAttributeSet : public UJBaseAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_Energy)
	FGameplayAttributeData Energy;
	ATTRIBUTE_ACCESSORS(UJResourceAttributeSet, Energy)

	UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_MaxEnergy)
	FGameplayAttributeData MaxEnergy;
	ATTRIBUTE_ACCESSORS(UJResourceAttributeSet, MaxEnergy)

	UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_EnergyRegeneration)
	FGameplayAttributeData EnergyRegeneration;
	ATTRIBUTE_ACCESSORS(UJResourceAttributeSet, EnergyRegeneration)

public:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	virtual void OnRep_Energy(const FGameplayAttributeData& OldEnergy);

	UFUNCTION()
	virtual void OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy);

	UFUNCTION()
	virtual void OnRep_EnergyRegeneration(const FGameplayAttributeData& OldEnergyRegeneration);
};
