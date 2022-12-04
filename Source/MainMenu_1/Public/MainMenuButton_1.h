#pragma once

// MainMenu_1
#include "MainMenuStruct_1.h" // FMainMenuStruct_1
#include "MainMenuRedDot_1.h" // UMainMenuRedDot_1

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr

// UMG
#include "Blueprint/UserWidget.h" // UUserWidget
#include "Components/TextBlock.h" // UTextBlock
#include "Components/Image.h" // UImage
#include "Components/Button.h" // UButton

//
#include "MainMenuButton_1.generated.h"

UCLASS(Abstract)
// nút để chọn level
class MAINMENU_1_API UMainMenuButton_1 : public UUserWidget
{
	GENERATED_BODY()

private:
	// nhiều nơi kiểm tra ButtonTextBlock valid, đặc biệt là SetButtonState sẽ lặp lại
	// set trong init()
	bool bButtonTextValid;

	// nhiều nơi kiểm tra RedDotImage valid, đặc biệt là SetButtonState sẽ lặp lại
	// set trong init()
	bool bRedDotValid;

	// bind nút
	UFUNCTION()
		// chuyển trạng thái nút khi bình thường
		void NormalButton() noexcept;

	// bind nút
	UFUNCTION()
		// chuyển trạng thái nút khi được rê chuột
		void HoveredButton() noexcept;

	// bind nút
	UFUNCTION()
		// chuyển trạng thái nút khi được nhấn
		void ClickedButton() noexcept;

	// thay đổi opacity của chữ và sự hiển thị của chấm đỏ
	void SetButtonState(const float& TextOpacity, const ESlateVisibility& RedDotVisisbility) noexcept;

protected:
	UPROPERTY(meta = (BindWidget))
		// lưu địa chỉ chữ
		TObjectPtr<UTextBlock> text;

	UPROPERTY(meta = (BindWidget))
		// lưu địa chỉ chấm đỏ
		TObjectPtr<UMainMenuRedDot_1> RedDotImage;

	UPROPERTY(meta = (BindWidget))
		// nút để tương tác
		TObjectPtr<UButton> button;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere, Category = MainMenu)
		// opacity khi bình thường; nên nằm trước SetText()
		float NormalOpacity;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere, Category = MainMenu)
		// opacity khi rê chuột
		float HoveredOpacity;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere, Category = MainMenu)
		// opacity khi được nhấn
		float ClickedOpacity;

	// parent alias
	using Super = UUserWidget;

	// event pre construct
	virtual void NativePreConstruct() override;
	
	// event construct
	virtual void NativeConstruct() override;

public:
	// nội dung nút
	// nhận từ UMainMenuWidget_1 khi tạo nút
	FMainMenuStruct_1 ButtonData;

	// widget hình để đổi khi rê chuột vào
	// nhận từ UMainMenuWidget_1 khi tạo nút
	TObjectPtr<UImage> PreviewImage;

	// constructor
	UMainMenuButton_1(const FObjectInitializer& ObjectInitializer);

	// đổi hình preview
	void ChangeImage() noexcept;
};
