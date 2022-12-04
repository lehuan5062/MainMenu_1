#include "MainMenuRedDot_1.h" // UMainMenuRedDot_1

// constructor
UMainMenuRedDot_1::UMainMenuRedDot_1(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, size{ 23.f }
{}

// event pre construct
void UMainMenuRedDot_1::NativePreConstruct()
{
	Super::NativePreConstruct();

	// nếu SizeBox valid
	if (SizeBox->IsValidLowLevel())
	{
		// thay đổi chiều ngang
		SizeBox->SetWidthOverride(size);

		// thay đổi chiều dọc
		SizeBox->SetHeightOverride(size);
	}
}