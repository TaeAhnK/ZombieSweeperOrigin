//

#include "GameMode/ZSGameMode.h"
#include "Field/FieldMap.h"
#include "Field/GridField.h"

AZSGameMode::~AZSGameMode()
{
	delete MapData;
}

void AZSGameMode::BeginPlay()
{
	Super::BeginPlay();

	MapData = new FieldMap(32, 32, FIntPoint(0, 0), FIntPoint(31, 31));
	Field = GetWorld()->SpawnActor<AGridField>(BP_Map, FVector::ZeroVector, FRotator::ZeroRotator);

	Field->MapData = MapData;

	Field->BeginPlay();

}
