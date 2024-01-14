//
#include "Field/Tile.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ATile::ATile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	TileMesh->SetupAttachment(RootComponent);
}
