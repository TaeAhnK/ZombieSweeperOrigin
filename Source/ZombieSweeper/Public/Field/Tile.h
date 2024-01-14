//
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UStaticMeshComponent;

UCLASS()
class ZOMBIESWEEPER_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();

	UPROPERTY(VisibleAnywhere)
	FIntPoint TileIndex;
protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TileMesh;
};
