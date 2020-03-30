#pragma once
#ifndef CANDY_H
#define CANDY_H

namespace game_framework {
	class MapVariable {	//地圖的統一變數
		public:
			MapVariable();				//初始化
			int getX();					//獲得整個地圖的左上角開始點 x 軸
			int getY();					//獲得整個地圖的左上角開始點 y 軸
			int getMapWight();			//獲得每張圖的 "寬" 要隔多遠
			int getMapHigh();			//獲得每張圖的 "高" 要隔多遠
			int getBlockxN();			//獲得 x 軸總共有多少張圖 (左右總共幾張)
			int getBlockyN();			//獲得 y 軸總共有多少張圖 (上下總共幾張)
			int getMap(int x, int y);	//獲得地圖裡的值
		protected:
			int map[10][10];				//地圖
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
			void OnMove();
			void OnShow();
		protected:
			int candyMap[10][10];
			CMovingBitmap candy0;
			CMovingBitmap candyR;
			CMovingBitmap candyG;
			CMovingBitmap candyB;
			CMovingBitmap candyY;
	};

}

#endif	//!CANDY_H
