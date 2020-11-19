// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAMEPLAYABILITIESEXTENSIONS_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_Energy)
    FGameplayAttributeData Energy;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Energy)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_MaxEnergy)
    FGameplayAttributeData MaxEnergy;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxEnergy)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_AttackSpeed)
    FGameplayAttributeData AttackSpeed;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, AttackSpeed)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_MoveSpeed)
    FGameplayAttributeData MoveSpeed;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MoveSpeed)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_Stamina)
    FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Stamina)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_Strength)
    FGameplayAttributeData Strength;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Strength)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_Intellect)
    FGameplayAttributeData Intellect;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Intellect)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_Agility)
    FGameplayAttributeData Agility;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Agility)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_CriticalChance)
    FGameplayAttributeData CriticalChance;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CriticalChance)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_PhysicalResistance)
    FGameplayAttributeData PhysicalResistance;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, PhysicalResistance)

    UPROPERTY(BlueprintReadOnly, Category = Attributes, ReplicatedUsing = OnRep_MagicalResistance)
    FGameplayAttributeData MagicalResistance;
    ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MagicalResistance)

public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

    UFUNCTION()
    virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

    UFUNCTION()
    virtual void OnRep_Energy(const FGameplayAttributeData& OldEnergy);

    UFUNCTION()
    virtual void OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy);

    UFUNCTION()
    virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);

    UFUNCTION()
    virtual void OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed);

    UFUNCTION()
    virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

    UFUNCTION()
    virtual void OnRep_Strength(const FGameplayAttributeData& OldStrength);

    UFUNCTION()
    virtual void OnRep_Intellect(const FGameplayAttributeData& OldIntellect);

    UFUNCTION()
    virtual void OnRep_Agility(const FGameplayAttributeData& OldAgility);

    UFUNCTION()
    virtual void OnRep_CriticalChance(const FGameplayAttributeData& OldCriticalChance);

    UFUNCTION()
    virtual void OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance);

    UFUNCTION()
    virtual void OnRep_MagicalResistance(const FGameplayAttributeData& OldMagicalResistance);
};
