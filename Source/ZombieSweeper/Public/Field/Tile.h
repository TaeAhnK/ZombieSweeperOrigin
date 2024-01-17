//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UPaperSprite;
class UPaperSpriteComponent;

UENUM(BlueprintType)
enum class ETileType : uint8
{
	TileNotOpen,
	Tile1,
	Tile2,
	Tile3,
	Tile4,
	Tile5,
	Tile6,
	Tile7,
	Tile8,
	TileOpen,
	TileZombie
};


UCLASS()
class ZOMBIESWEEPER_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();
	void SetSprite();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	ETileType TileType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile")
	FIntPoint TileIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	TArray<UPaperSprite*> TileSprites;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile")
	UPaperSpriteComponent* PaperMesh;
protected:

};
