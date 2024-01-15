#include <iostream>
#include <vector>
#include <ctime>
#include "MapGenerator.h"

using namespace std;

FieldMap::FieldMap(int Width, int Height) : Map(Width, std::vector<Tile*>(Height, NULL))
{
	MapHeight = Height;
	MapWidth = Width;

	for (int y = 0; y < MapHeight; y++)
	{
		for (int x = 0; x < MapWidth; x++)
		{
			Map[y][x] = new Tile;
		}
	}
}

FieldMap::~FieldMap()
{
}

void FieldMap::PrintMap()
{
	for (int y = 0; y < MapHeight; y++)
	{
		for (int x = 0; x < MapWidth; x++)
		{
			printf("%d", Map[y][x]->Num);
		}
		printf("\n");
	}
}

void FieldMap::PrintZombie()
{
	printf("\n");
	printf("%d\n", (int) Zombie.size());
	for (int i = 0; i < Zombie.size(); i++)
	{
		printf("%d ", Zombie[i]);
	}
}

void FieldMap::PlantZombie(int ZNum)
{
	int random, rx, ry;

	srand((unsigned int)time(NULL));

	InitMap();
	do
	{
		InitMap();
		for (int i = 0; i < ZNum; i++)
		{
			random = rand() % (MapHeight * MapWidth);
			ry = random / MapWidth;
			rx = random % MapHeight;

			if (Map[ry][rx]->Num != -1 && ry != 31 && rx != 31)
			{
				Map[ry][rx]->Num = -1;
				Zombie.push_back(random);
				SetAdjNum(rx, ry);
			}
			else
			{
				i--;
			}
		}
	} while (!DFS());

}

bool FieldMap::DFS()
{
	std::vector<std::vector<bool>> Visited(MapHeight, std::vector<bool>(MapWidth, false));

	Search(Visited, startX, startY);
	if (Visited[targetY][targetX])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void FieldMap::InitMap()
{
	for (int y = 0; y < MapHeight; y++)
	{
		for (int x = 0; x < MapWidth; x++)
		{
			Map[y][x]->Num = 0;
		}
	}
}

void FieldMap::SetAdjNum(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		if (isValidXY(x + dx[i], y + dy[i]))
		{
			Map[dy[i] + y][dx[i] + x]->Num++;
		}
	}
}

bool FieldMap::isValidXY(int x, int y)
{
	if (x < 0 || MapWidth <= x || y < 0 || MapHeight <= y || Map[y][x]->Num == -1)
	{
		return false;
	}

	return true;
}

void FieldMap::Search(std::vector<std::vector<bool>>& Visited, int sx, int sy)
{
	Visited[sy][sx] = true;

	for (int i = 0; i < 8; i++)
	{
		if (isValidXY(sx + dx[i], sy + dy[i]) && !Visited[sy + dy[i]][sx + dx[i]])
		{
			if (sx + dx[i] == targetX && sy + dy[i] == targetY)
			{
				Visited[sy + dy[i]][sx + dx[i]] = true;
				return;
			}
			Search(Visited, sx + dx[i], sy + dy[i]);
		}
	}
}

int main()
{
	int test = 10000;
	int error = 0;

	//for (int i = 0; i < test; i++)
	//{
	//	FieldMap M(32, 32);
	//	M.PlantZombie(200);
	//	if (!M.DFS(0, 0, 31, 31))
	//	{
	//		error++;
	//	}
	//}

	FieldMap M(32, 32);
	M.PlantZombie(200);
	M.PrintMap();
	printf("\n\n");
	printf("error : %d\nerror rate : %.2f", error, (((float)error)/test));
	return 0;
}