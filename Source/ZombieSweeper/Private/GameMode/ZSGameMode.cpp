//

#include "GameMode/ZSGameMode.h"
#include "Field/FieldMap.h"
#include "Field/GridField.h"
#include "Field/Tile.h"

AZSGameMode::~AZSGameMode()
{
	delete MapData;
}

void AZSGameMode::BeginPlay()
{
	Super::BeginPlay();

	StartXY = FIntPoint(0, 0);
	TargetXY = FIntPoint(31, 31);

	MapData = new FieldMap(32, 32, StartXY, TargetXY);
	Field = GetWorld()->SpawnActor<AGridField>(BP_Map, FVector::ZeroVector, FRotator::ZeroRotator);

	Field->MapData = MapData;

	Field->BeginPlay();

	for (int y = 0; y < 32; y++)
	{
		for (int x = 0; x < 32; x++)
		{
			BindTileOverlapEvent(Field->GridArray[y][x]);
		}
	}
}

void AZSGameMode::BindTileOverlapEvent(ATile* Tile)
{
	if (Tile)
	{
		Tile->OnTileOverlapEvent.AddDynamic(this, &AZSGameMode::OnTileOverlap);
	}
}

void AZSGameMode::OnTileOverlap(FIntPoint TileIndex)
{
	UE_LOG(LogTemp, Log, TEXT("OverLap"));
	if (MapData->Map[TileIndex.Y][TileIndex.X] == -1)
	{
		// Cut Scene
		// Game Over
	}
	else
	{
		Field->OpenTile(TileIndex);
	}
}
