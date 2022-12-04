// MainMenu_1
#include "MainMenuButton_1.h" // UMainMenuButton_1

// core
#include "Containers/UnrealString.h" // FString
#include "Internationalization/Text.h" // FText

// engine
#include "Engine/Texture2D.h" // UTexture2D
#include "Kismet/GameplayStatics.h" // UGameplayStatics

// UMG
#include "Components/SlateWrapperTypes.h" // ESlateVisibility

// constructor
UMainMenuButton_1::UMainMenuButton_1(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bButtonTextValid{ false }
	, bRedDotValid{ false }
	, NormalOpacity{ 0.7f }
	, HoveredOpacity{ 1.f }
	, ClickedOpacity{ 0.3f }
{}

// event pre construct
void UMainMenuButton_1::NativePreConstruct()
{
	Super::NativePreConstruct();

	// biến nội bộ để thêm Version đằng sau
	FString AppendVersion{ ButtonData.ButtonName };

	// thêm chữ Version
	AppendVersion.Append(" Version");

	// còn dùng ở trong SetButtonState
	bButtonTextValid = text->IsValidLowLevel();

	// nếu ButtonTextBlock valid
	if (bButtonTextValid)
	{
		// thay đổi chữ
		text->SetText(FText::FromString(AppendVersion));
	}

	// nếu RedDotImage valid
	bRedDotValid = RedDotImage->IsValidLowLevel();

	// chuyển nút về chế độ bình thường
	NormalButton();
}

// thay đổi opacity chữ và bật tắt chấm đỏ
void UMainMenuButton_1::SetButtonState(const float& TextOpacity, const ESlateVisibility& RedDotVisisbility) noexcept
{
	// cần check valid ButtonTextBlock vì hàm này gọi trong PreConstruct (trong NormalButton())
	if (bButtonTextValid)
	{
		// thay đổi opacity chữ
		text->SetRenderOpacity(TextOpacity);
	}

	// cần check valid RedDotImage vì hàm này gọi trong PreConstruct (trong NormalButton())
	if (bRedDotValid)
	{
		// bật tắt chấm đỏ
		RedDotImage->SetVisibility(RedDotVisisbility);
	}
}

// chuyển trạng thái nút khi bình thường
void UMainMenuButton_1::NormalButton() noexcept
{
	// chữ hơi mờ, ẩn chấm đỏ
	SetButtonState(NormalOpacity, ESlateVisibility::Hidden);
}

// đổi hình preview
void UMainMenuButton_1::ChangeImage() noexcept
{
	// kiểm tra có texture không
	if (ButtonData.image->IsValidLowLevel())
	{
		// đổi hình khi rê chuột vào nút
		PreviewImage->SetBrushFromTexture(ButtonData.image);
	}
}

// chuyển trạng thái nút khi được rê chuột
void UMainMenuButton_1::HoveredButton() noexcept
{
	// chữ rõ, hiện chấm đỏ
	SetButtonState(HoveredOpacity, ESlateVisibility::Visible);

	// đổi hình preview
	ChangeImage();
}

// chuyển trạng thái nút khi được nhấn
void UMainMenuButton_1::ClickedButton() noexcept
{
	// chữ mờ, hiện chấm đỏ
	SetButtonState(ClickedOpacity, ESlateVisibility::Visible);

	// kiểm tra LevelToPointer (TSoftObjectPtr) không bao giờ null
	if (!ButtonData.LevelToOpen.IsNull())
	{
		// mở level được chọn sau khi chọn nhân vật
		UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), ButtonData.LevelToOpen);
	}
}

// event construct
void UMainMenuButton_1::NativeConstruct()
{
	Super::NativeConstruct();
	
	// gọi HoveredButton khi rê chuột vào nút
	button->OnHovered.AddDynamic(this, &UMainMenuButton_1::HoveredButton);

	// gọi NormalButton khi thả chuột khỏi nút
	button->OnUnhovered.AddDynamic(this, &UMainMenuButton_1::NormalButton);

	// gọi PressedButton khi nhấn nút
	button->OnClicked.AddDynamic(this, &UMainMenuButton_1::ClickedButton);
}