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

class MapVariable {	//�a�Ϫ��Τ@�ܼ�
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
		int map[12][7];					//�a��
		const int X, Y;					//��Ӧa�Ϫ����W��
		const int mapWight, mapHigh;	//�a�Ϫ��e�P��
		const int blockxN, blockyN;		//�C�Ӥ�����e�P��
};



class CandyMap : public MapVariable {		//Candy�U�誺��� (�a��, ����)
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
