//
#include "Field/GridField.h"
#include "Field/Tile.h"
#include "Field/FieldMap.h"

AGridField::AGridField()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AGridField::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Grid"));
	if (!MapData)
	{
		return;
	}

	GridArray.SetNumZeroed(GridHeight);
	for (int32 y = 0; y < GridHeight; y++)
	{
		GridArray[y].SetNumZeroed(GridWidth);
		for (int32 x = 0; x < GridWidth; x++)
		{
			TSubclassOf<ATile> TileToSpawn = Tile;
			ATile* NewTile = GetWorld()->SpawnActor<ATile>(TileToSpawn, FVector(FIntPoint(GetActorLocation().X + x * GridOffset, GetActorLocation().X + y * GridOffset)), FRotator::ZeroRotator);
			NewTile->TileIndex = FIntPoint(x, y);
            //NewTile->TileType = ETileType::TileNotOpen;
            NewTile->TileType = IndexToTileType(MapData->Map[y][x]);
			NewTile->SetSprite();
			GridArray[y][x] = NewTile;
		}
	}
}

void AGridField::SetTile(int8 X, int8 Y, int8 index)
{

}

ETileType AGridField::IndexToTileType(int8 index)
{
    switch (index)
    {
    case -1:
        return ETileType::TileZombie;
    case 0:
        return ETileType::TileOpen;
    case 1:
        return ETileType::Tile1;
    case 2:
        return ETileType::Tile2;
    case 3:
        return ETileType::Tile3;
    case 4:
        return ETileType::Tile4;
    case 5:
        return ETileType::Tile5;
    case 6:
        return ETileType::Tile6;
    case 7:
        return ETileType::Tile7;
    case 8:
        return ETileType::Tile8;
    }

    return ETileType::TileNotOpen;
}

