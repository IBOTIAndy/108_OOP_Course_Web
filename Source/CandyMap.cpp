#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include "CandyMap.h"
#include <time.h>

namespace game_framework {

	////////////////////////////////
	// 地圖共用資料
	////////////////////////////////

	MapVariable::MapVariable() :X(160), Y(30), mapWight(40), mapHigh(40), blockxN(7), blockyN(10) {
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

	/////////////////////////////////////////
    // CandyMap	糖果的底圖
	/////////////////////////////////////////

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
					block.SetTopLeft(getX() + (getMapHigh() * x), getY() + (getMapWight() * y));	//第一章圖的左上角 + (圖片寬度 * 第幾個)
					block.ShowBitmap();
					break;
				default:
					ASSERT(0);
				}
			}
		}
	}

	////
	// Candys 糖果
	////

	Candy::Candy() {
		int x = 0, y = 0, random = 0;
		count = 0;
		candyN = 4;
		for (x = 0; x < getBlockxN(); x++) {
			for (y = 0; y < getBlockyN(); y++) {
				candyMap[y][x] = 0;
			}
		}
	}

	void Candy::LoadBitmap() {
		candy0.LoadBitmap(candy_0);
		candyR.LoadBitmap(candy_R);
		candyG.LoadBitmap(candy_G);
		candyB.LoadBitmap(candy_B);
		candyY.LoadBitmap(candy_Y);
	}

	void Candy::OnMove() {
		int x = 0, y = 0, random = 0;
		count++;
		if (count % 30 == 0) {	//
			srand((unsigned)time(NULL));
			for (x = getBlockxN(); x >= 0; x--) {	//把現在的糖果往下移動
				for (y = getBlockyN(); y > 0; y--) {
					if (candyMap[y][x] == 0) {
						candyMap[y][x] = candyMap[y - 1][x];
						candyMap[y - 1][x] = 0;
					}
				}
			}
			for (x = 0; x < getBlockxN(); x++) {	//放置新的糖果
				if (candyMap[0][x] == 0) {
					random = (rand() % candyN) + 1;
					candyMap[0][x] = random;
				}
			}
			count = 0;
		}
	}

	void Candy::OnShow() {
		int x = 0, y = 0;
		for (x = 0; x < getBlockxN(); x++) {
			for (y = 0; y < getBlockyN(); y++) {
				switch (candyMap[y][x]) {
				case 0:		//空
					candy0.SetTopLeft(getX() + (getMapHigh() * x), getY() + (getMapWight() * y));
					candy0.ShowBitmap();
					break;
				case 1:		//Red
					candyR.SetTopLeft(getX() + (getMapHigh() * x), getY() + (getMapWight() * y));	//第一章圖的左上角 + (圖片寬度 * 第幾個)
					candyR.ShowBitmap();
					break;
				case 2:		//Green
					candyG.SetTopLeft(getX() + (getMapHigh() * x), getY() + (getMapWight() * y));
					candyG.ShowBitmap();
					break;
				case 3:		//Blue
					candyB.SetTopLeft(getX() + (getMapHigh() * x), getY() + (getMapWight() * y));
					candyB.ShowBitmap();
					break;
				case 4:		//Yellow
					candyY.SetTopLeft(getX() + (getMapHigh() * x), getY() + (getMapWight() * y));
					candyY.ShowBitmap();
					break;
				default:
					ASSERT(0);
				}
			}
		}
	}

}	//namespace game_framework