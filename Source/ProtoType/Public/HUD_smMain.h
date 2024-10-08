// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HUD_smMain.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE_API AHUD_smMain : public AHUD
{
	GENERATED_BODY()

public:
    AHUD_smMain();

    virtual void BeginPlay() override;

    void openToolBar();

protected:
    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<class UUW_smMain> MainWidgetClass;

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<class UUW_smMain> ToolBarWidgetClass;

private:
    UUW_smMain* MainWidget;
    UUW_smMain* ToolBarWidget;
	
};
