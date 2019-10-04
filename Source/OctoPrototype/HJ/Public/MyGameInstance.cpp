// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "SocketSubsystem.h"
#include <IPAddress.h>
#include "Engine/World.h"
#include "Blueprint/UserWidget.h"

UMyGameInstance::UMyGameInstance()
{

}

void UMyGameInstance::Init()
{
	Super::Init();
	GetEngine()->OnNetworkFailure().AddUObject(this, &UMyGameInstance::HandleNetworkFailure);

}

FString UMyGameInstance::GetMyIpAddress()
{
	FString IpAddr("NONE");
	bool canBind = false;
	TSharedRef<FInternetAddr> LocalIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, canBind);
	if (LocalIp->IsValid())
	{
		IpAddr = LocalIp->ToString(false);
	}

	return IpAddr;
}

void UMyGameInstance::HandleNetworkFailure(UWorld * World, UNetDriver * NetDriver, ENetworkFailure::Type FailureType, const FString & ErrorString)
{
	UE_LOG(LogClass, Warning, TEXT("%s"), *ErrorString);
	//World->NextURL = FString("/Game/Maps/TPSStart.TPSStart");

	/*FStringClassReference NetworkErrorWidgetRef(TEXT("WidgetBlueprint'/Game/HJ/Blueprints/Public/NetworkErrorWidget.NetworkErrorWidget_C'"));
	if (UClass* NetworkErrorWidgetClass = NetworkErrorWidgetRef.TryLoadClass<UUserWidget>())
	{*/
	//	NetworkErrorWidget = CreateWidget<UUserWidget>(this, NetworkErrorWidgetClass);
	//	NetworkErrorWidget->AddToViewport();
	//	NetworkErrorWidget->SetVisibility(ESlateVisibility::Collapsed);
	//}
	//NetworkErrorWidget->SetVisibility(ESlateVisibility::Visible);
}

