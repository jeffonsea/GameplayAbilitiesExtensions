#include "Animation/Notify/JAnimTagNotify_fwd.h"

FString UJAnimTagNotify::GetNotifyName_Implementation() const
{
    return *NotifyTag.ToString();
}

void UJAnimTagNotify::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    
    if (PropertyChangedEvent.GetPropertyName() == "NotifyTag")
    {
        NotifyName = FName(NotifyTag.ToString());
    }
}

FString UJAnimTagNotifyWindow::GetNotifyName_Implementation() const
{
    return *NotifyTag.ToString();
}

void UJAnimTagNotifyWindow::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    
    if (PropertyChangedEvent.GetPropertyName() == "NotifyTag")
    {
        NotifyName = FName(NotifyTag.ToString());
    }
}
