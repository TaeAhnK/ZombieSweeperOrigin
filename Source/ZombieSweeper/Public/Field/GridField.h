//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridField.generated.h"

class ATile;

UCLASS()
class ZOMBIESWEEPER_API AGridField : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridField();

protected:
	virtual void BeginPlay() override;

	TArray<TArray<ATile*>> GridArray;

	UPROPERTY(EditAnywhere, Category = Grid)
	int32 GridWidth;
	
	UPROPERTY(EditAnywhere, Category = Grid)
	int32 GridHeight;

	UPROPERTY(EditAnywhere, Category = Grid)
	int32 GridOffset;

	UPROPERTY(EditAnywhere, Category = Grid)
	TSubclassOf<ATile> Tile;
};
