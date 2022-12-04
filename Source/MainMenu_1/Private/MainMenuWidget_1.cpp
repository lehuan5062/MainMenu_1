// MainMenu_1
#include "MainMenuWidget_1.h" // UMainMenuWidget_1
#include "MainMenuStruct_1.h" // FMainMenuStruct_1
#include "MainMenuButton_1.h" // UMainMenuButton_1

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr

// SlateCore
#include "Layout/Margin.h" // FMargin

// UMG
#include "Blueprint/WidgetLayoutLibrary.h" // UWidgetLayoutLibrary
#include "Components/VerticalBoxSlot.h" // SetPadding

// constructor
UMainMenuWidget_1::UMainMenuWidget_1(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ButtonSpace{ 40.f }
{}

// event pre construct
void UMainMenuWidget_1::NativePreConstruct()
{
	Super::NativePreConstruct();

	// nếu ButtonClass đã được chọn và danh sách dữ liệu nút có ít nhất một thành viên
	if (ButtonClass->IsValidLowLevel() && ButtonList.IsValidIndex(0))
	{
		// index loop tạo nút
		uint8 index{};

		// cứ mỗi thành viên trong danh sách dữ liệu nút
		for (FMainMenuStruct_1 ButtonData : ButtonList)
		{
			// tạo một nút
			const TObjectPtr<UMainMenuButton_1> button{ CreateWidget<UMainMenuButton_1>(GetWorld(), ButtonClass) };

			// lưu dữ liệu nút
			// nên nằm trước construct
			button->ButtonData = ButtonList[index];

			// nếu PreviewImage valid
			if (PreviewImage->IsValidLowLevel())
			{
				// lưu widget hình để thay đổi
				button->PreviewImage = PreviewImage;
			}

			// nếu ButtonBox valid
			if (ButtonBox->IsValidLowLevel())
			{
				// thêm vào hộp đựng nút
				// nên nằm sau các biến cần cho pre construct (ButtonData)
				ButtonBox->AddChildToVerticalBox(button);

				// đối với nút đầu tiên
				if (index == 0)
				{
					// lấy hình preview nút đầu làm hình preview
					button->ChangeImage();
				}
				// từ nút thứ 2 trở đi
				else
				{
					// thêm khoảng cách bên trên
					UWidgetLayoutLibrary::SlotAsVerticalBoxSlot(button)->SetPadding(FMargin{ 0.f, ButtonSpace, 0.f, 0.f });
				}
			}

			// index tiếp theo
			index++;
		}
	}
}