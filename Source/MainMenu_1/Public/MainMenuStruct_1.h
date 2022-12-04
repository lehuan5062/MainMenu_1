#pragma once

// core
#include "Containers/UnrealString.h" // FString

// CoreUObject
#include "UObject/ObjectPtr.h" // TObjectPtr
#include "UObject/SoftObjectPtr.h" // TSoftObjectPtr

// engine
#include "Engine/Texture2D.h" // UTexture2D
#include "Engine/World.h" // UWorld

//
#include "MainMenuStruct_1.generated.h"

USTRUCT()
// chứa tên nút và hình tương ứng
struct MAINMENU_1_API FMainMenuStruct_1
{
	GENERATED_BODY()

public:
	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere)
		// nội dung nút, sẽ tự thêm chữ Version đằng sau
		FString ButtonName;

	// chỉnh ở trong editor
	UPROPERTY(EditAnywhere)
		// hình preview version
		TObjectPtr<UTexture2D> image;

	// chỉnh trong editor
	UPROPERTY(EditAnywhere)
		// level để mở sau khi chọn nhân vật
		TSoftObjectPtr<UWorld> LevelToOpen;
};