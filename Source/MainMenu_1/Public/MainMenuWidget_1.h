#pragma once

// MainMenu_1
#include "MainMenuButton_1.h" // UMainMenuButton_1
#include "MainMenuStruct_1.h" // FMainMenuStruct_1

// core
#include "Containers/Array.h" // TArray

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr
#include "Templates/SubclassOf.h" // TSubclassOf

// UMG
#include "Blueprint/UserWidget.h" // UUserWidget
#include "Components/VerticalBox.h" // UVerticalBox
#include "Components/Image.h" // UImage

//
#include "MainMenuWidget_1.generated.h"

UCLASS(Abstract)
// cái main menu của dự án cafe entrance
class MAINMENU_1_API UMainMenuWidget_1 : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		// khung đựng nút
		TObjectPtr<UVerticalBox> ButtonBox;

	UPROPERTY(meta = (BindWidget))
		// hình preview nút
		TObjectPtr<UImage> PreviewImage;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere, Category = MainMenu)
		// nút để tạo ra từ danh sách
		TSubclassOf<UMainMenuButton_1> ButtonClass;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere, Category = MainMenu)
		// danh sách nút
		TArray<FMainMenuStruct_1> ButtonList;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere, Category = MainMenu)
		// khoản cách giữa các nút
		float ButtonSpace;

	// parent alias
	using Super = UUserWidget;

public:
	// constructor
	UMainMenuWidget_1(const FObjectInitializer& ObjectInitializer);

	// event pre construct
	virtual void NativePreConstruct() override;
};