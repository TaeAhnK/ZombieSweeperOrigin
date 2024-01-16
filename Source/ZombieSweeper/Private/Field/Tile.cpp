//
#include "Field/Tile.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

ATile::ATile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));

	PaperMesh = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperMesh"));
	PaperMesh->SetupAttachment(RootComponent);

    SetSprite();
}

void ATile::SetSprite()
{
    if (TileSprites.IsValidIndex(static_cast<int32>(TileType)))
    {
        UPaperSprite* CurrentMesh = TileSprites[static_cast<int32>(TileType)];

        if (CurrentMesh)
        {
            PaperMesh->SetSprite(CurrentMesh);
        }
    }
    else
    {
        PaperMesh->SetSprite(TileSprites[0]);
    }
}
