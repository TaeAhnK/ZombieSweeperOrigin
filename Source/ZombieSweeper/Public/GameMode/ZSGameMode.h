//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ZSGameMode.generated.h"

class FieldMap;
class AGridField;

UCLASS()
class ZOMBIESWEEPER_API AZSGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	~AZSGameMode();
	virtual void BeginPlay() override;

	FieldMap* MapData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AGridField* Field;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	TSubclassOf<AGridField> BP_Map;
protected:

private:
};
