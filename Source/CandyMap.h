#pragma once
#ifndef CANDY_H
#define CANDY_H
#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"

class MapVariable {	//地圖的統一變數
	public:
	 	MapVariable();
		int getX();
		int getY();
		int getMapWight();
		int getMapHigh();
		int getBlockxN();
		int getBlockyN();
		int getMap(int x, int y);
	protected:
		int map[12][7];					//地圖
		const int X, Y;					//整個地圖的左上角
		const int mapWight, mapHigh;	//地圖的寬與高
		const int blockxN, blockyN;		//每個方塊的寬與高
};



class CandyMap : public MapVariable {		//Candy下方的方格 (地圖, 底圖)
	public:
		CandyMap();
		void LoadBitmap();	//
		void OnShow();		//
	protected:
		CMovingBitmap block;	//
};

class Candy : public MapVariable {
	public:
		Candy();
		void LoadBitmap();
		void OnShow();
	protected:
		CMovingBitmap candy;
};


#endif	//!CANDY_H
