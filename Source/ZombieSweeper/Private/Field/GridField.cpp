//
#include "Field/GridField.h"
#include "Field/Tile.h"

AGridField::AGridField()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AGridField::BeginPlay()
{
	Super::BeginPlay();
	
	GridArray.SetNumZeroed(GridHeight);
	for (int32 y = 0; y < GridHeight; y++)
	{
		GridArray[y].SetNumZeroed(GridWidth);
		for (int32 x = 0; x < GridWidth; x++)
		{
			TSubclassOf<ATile> TileToSpawn = Tile;
			ATile* NewTile = GetWorld()->SpawnActor<ATile>(TileToSpawn, FVector(FIntPoint(GetActorLocation().X + x * GridOffset, GetActorLocation().X + y * GridOffset)), FRotator::ZeroRotator);
			NewTile->TileIndex = FIntPoint(x, y);
			GridArray[y][x] = NewTile;
		}
	}
}
