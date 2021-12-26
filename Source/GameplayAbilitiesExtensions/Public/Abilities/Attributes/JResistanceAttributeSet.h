// Copyright Jeff Onsea 2021

#pragma once

#include "CoreMinimal.h"
#include "JBaseAttributeSet.h"

#include "JResistanceAttributeSet.generated.h"

UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UJResistanceAttributeSet : public UJBaseAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_PhysicalResistance)
	FGameplayAttributeData PhysicalResistance;
	ATTRIBUTE_ACCESSORS(UJResistanceAttributeSet, PhysicalResistance)

	UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_MagicalResistance)
	FGameplayAttributeData MagicalResistance;
	ATTRIBUTE_ACCESSORS(UJResistanceAttributeSet, MagicalResistance)

public:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION()
	virtual void OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance);

	UFUNCTION()
	virtual void OnRep_MagicalResistance(const FGameplayAttributeData& OldMagicalResistance);
};
