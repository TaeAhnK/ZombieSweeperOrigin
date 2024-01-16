#pragma once

class vector;
class Tile;

class FieldMap
{
public:
	FieldMap(int Width, int Height);
	~FieldMap();
	void PrintMap();
	void PrintZombie();
	void PlantZombie(int ZNum);
	bool DFS();

protected:
	std::vector<std::vector<Tile*>> Map;
	std::vector<int> Zombie;
	int MapWidth;
	int MapHeight;

private:
	void InitMap();
	void SetAdjNum(int x, int y);
	bool isValidXY(int x, int y);
	void Search(std::vector<std::vector<bool>>& Visited, int sx, int sy);
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
	int startX = 0;
	int startY = 0;
	int targetX = 31;
	int targetY = 31;
};

class Tile
{
public:
	int Num;
protected:
private:
};