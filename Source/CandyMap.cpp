
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CandyMap.h"


MapVariable::MapVariable() :X(160), Y(30), mapWight(40), mapHigh(40), blockxN(10), blockyN(7) {
	int x = 0, y = 0;
	int map_init[10][7] = { {1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 1} };
	for (x = 0; x < blockxN; x++) {
		for (y = 0; y < blockyN; y++) {
			map[y][x] = map_init[y][x];
		}
	}
}

int MapVariable::getX() {
	return this->X;
}

int MapVariable::getY() {
	return this->Y;
}

int MapVariable::getMapWight() {
	return this->mapWight;
}

int MapVariable::getMapHigh() {
	return this->mapHigh;
}

int MapVariable::getBlockxN() {
	return this->blockxN;
}

int MapVariable::getBlockyN() {
	return this->blockyN;
}

int MapVariable::getMap(int x, int y) {
	return map[x][y];
}

CandyMap::CandyMap() {

}

void CandyMap::LoadBitmap() {
	block.LoadBitmap(IDB_MAPBLOCK1);
}

void CandyMap::OnShow() {
	int x = 0, y = 0;
	for (x = 0; x < getBlockxN(); x++) {
		for (y = 0; y < getBlockyN(); y++) {
			switch (getMap(y, x)) {
			case 0:
				break;
			case 1:
				block.SetTopLeft(getX() + (getMapWight() * y), getY() + (getMapHigh() * x));	//第一章圖的左上角 + (圖片寬度 * 第幾個)
				block.ShowBitmap();
				break;
			default:
				ASSERT(0);
			}
		}
	}
}