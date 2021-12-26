// Copyright Jeff Onsea 2021

#include "Abilities/Attributes/JResistanceAttributeSet.h"

#include "Net/UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResistanceAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetPhysicalResistanceAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.0f);
	}
	else if (Attribute == GetMagicalResistanceAttribute())
	{
		NewValue = FMath::Max(NewValue, 0.0f);
	}
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResistanceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResistanceAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UJResistanceAttributeSet, PhysicalResistance,	COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UJResistanceAttributeSet, MagicalResistance,	COND_None, REPNOTIFY_Always);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResistanceAttributeSet::OnRep_PhysicalResistance(const FGameplayAttributeData& OldPhysicalResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJResistanceAttributeSet, PhysicalResistance, OldPhysicalResistance);
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////

void UJResistanceAttributeSet::OnRep_MagicalResistance(const FGameplayAttributeData& OldMagicalResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UJResistanceAttributeSet, MagicalResistance, OldMagicalResistance);
}
