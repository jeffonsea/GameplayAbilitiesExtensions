// Copyright Jeff Onsea 2021

#include "Abilities/Attributes/JResourceAttributeSet.h"

#include "Net/UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResourceAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	
	if (Attribute == GetEnergyAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxEnergy());
	}
	else if (Attribute == GetMaxEnergyAttribute()) // GetMaxHealthAttribute comes from the Macros defined at the top of the header
	{
		NewValue = FMath::Clamp<float>(NewValue, GetEnergy(), GetMaxEnergy());
		if (GetEnergy() > NewValue)
		{
			GetEnergyAttribute().SetNumericValueChecked(NewValue, this);
		}
	}
	else if (Attribute == GetEnergyRegenerationAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.0f);
	}
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResourceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResourceAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UJResourceAttributeSet, Energy,				COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UJResourceAttributeSet, MaxEnergy,			COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UJResourceAttributeSet, EnergyRegeneration,	COND_None, REPNOTIFY_Always);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResourceAttributeSet::OnRep_Energy(const FGameplayAttributeData& OldEnergy)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJResourceAttributeSet, Energy, OldEnergy);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResourceAttributeSet::OnRep_MaxEnergy(const FGameplayAttributeData& OldMaxEnergy)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJResourceAttributeSet, MaxEnergy, OldMaxEnergy);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResourceAttributeSet::OnRep_EnergyRegeneration(const FGameplayAttributeData& OldEnergyRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJResourceAttributeSet, EnergyRegeneration, OldEnergyRegeneration);
}
