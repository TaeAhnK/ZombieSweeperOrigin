//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridField.generated.h"

class FieldMap;
class ATile;
enum class ETileType : uint8;

UCLASS()
class ZOMBIESWEEPER_API AGridField : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridField();
	virtual void BeginPlay() override;
	
	FieldMap* MapData;

protected:
	void OpenTile(FIntPoint StepIndex);
	
	ETileType IndexToTileType(int8 index);

	TArray<TArray<ATile*>> GridArray;

	UPROPERTY(EditAnywhere, Category = Grid)
	int32 GridWidth;
	
	UPROPERTY(EditAnywhere, Category = Grid)
	int32 GridHeight;

	UPROPERTY(EditAnywhere, Category = Grid)
	int32 GridOffset;

	UPROPERTY(EditAnywhere, Category = Grid)
	TSubclassOf<ATile> Tile;

private:
	bool isValidXY(int8 X, int8 Y);
};
