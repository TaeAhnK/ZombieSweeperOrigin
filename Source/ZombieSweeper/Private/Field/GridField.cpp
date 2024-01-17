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
	
	//if (!MapData)
	//{
	//	MapData = new FieldMap(32, 32, FIntPoint(0, 0), FIntPoint(31, 31));
	//}

	GridArray.SetNumZeroed(GridHeight);
	for (int32 y = 0; y < GridHeight; y++)
	{
		GridArray[y].SetNumZeroed(GridWidth);
		for (int32 x = 0; x < GridWidth; x++)
		{
			TSubclassOf<ATile> TileToSpawn = Tile;
			ATile* NewTile = GetWorld()->SpawnActor<ATile>(TileToSpawn, FVector(FIntPoint(GetActorLocation().X + x * GridOffset, GetActorLocation().X + y * GridOffset)), FRotator::ZeroRotator);
			NewTile->TileIndex = FIntPoint(x, y);
			NewTile->TileType = ETileType::TileNotOpen;
			NewTile->SetSprite();
			GridArray[y][x] = NewTile;
		}
	}
}

void AGridField::SetTile(int8 X, int8 Y, int8 index)
{

}
