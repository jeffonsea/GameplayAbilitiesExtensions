#include "Animation/Notify/AnimNotify_TagNotify.h"

FString UAnimNotify_TagNotify::GetNotifyName_Implementation() const
{
    return *NotifyTag.ToString();
}

void UAnimNotify_TagNotify::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    if (PropertyChangedEvent.GetPropertyName() == "NotifyTag")
    {
        NotifyName = FName(NotifyTag.ToString());
    }

    Super::PostEditChangeProperty(PropertyChangedEvent);
}
