// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD_smMain.h"
#include "UW_smMain.h"
#include "GameFramework/PlayerController.h"

AHUD_smMain::AHUD_smMain()
{
    static ConstructorHelpers::FClassFinder<UUW_smMain> UI_Main_C(TEXT("/Game/Kichan/WB_Main.WB_Main_C"));
    MainWidgetClass = UI_Main_C.Class;

    static ConstructorHelpers::FClassFinder<UUW_smMain> UI_ToolBar_C(TEXT("/Game/Kichan/WB_ToolBar_Layer.WB_ToolBar_Layer"));
    ToolBarWidgetClass = UI_ToolBar_C.Class;
}

void AHUD_smMain::BeginPlay()
{
    Super::BeginPlay();


    APlayerController* PlayerController = GetOwningPlayerController();

    if (PlayerController)
     {
        PlayerController->bShowMouseCursor = true;

        if (MainWidgetClass)
        {
            MainWidget = CreateWidget<UUW_smMain>(PlayerController, MainWidgetClass);
            if (MainWidget)
             {
                  MainWidget->AddToViewport();
             }
        }

        if (ToolBarWidgetClass)
        {
            ToolBarWidget = CreateWidget<UUW_smMain>(PlayerController, ToolBarWidgetClass);
        }
     }
    


}

void AHUD_smMain::openToolBar()
{
    if (ToolBarWidget)
    {
        ToolBarWidget->AddToViewport();
    }
}
