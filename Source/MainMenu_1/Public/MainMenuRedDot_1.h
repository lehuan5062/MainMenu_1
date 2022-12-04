#pragma once

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr

// UMG
#include "Blueprint/UserWidget.h" // UUserWidget
#include "Components/SizeBox.h" // USizeBox

//
#include "MainMenuRedDot_1.generated.h"

UCLASS(Abstract)
// cái chấm tròn hiện lên khi rê chuột vào
class MAINMENU_1_API UMainMenuRedDot_1 : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		// khung đựng hình, ghi đè kích thước
		TObjectPtr<USizeBox> SizeBox;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere, Category = MainMenu)
		// kích thước chấm đỏ
		float size;

	// parent alias
	using Super = UUserWidget;

	// event pre construct
	virtual void NativePreConstruct() override;

public:
	// constructor
	UMainMenuRedDot_1(const FObjectInitializer& ObjectInitializer);
};