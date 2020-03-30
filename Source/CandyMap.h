#pragma once
#ifndef CANDY_H
#define CANDY_H

namespace game_framework {
	class MapVariable {	//�a�Ϫ��Τ@�ܼ�
		public:
			MapVariable();				//��l��
			int getX();					//��o��Ӧa�Ϫ����W���}�l�I x �b
			int getY();					//��o��Ӧa�Ϫ����W���}�l�I y �b
			int getMapWight();			//��o�C�i�Ϫ� "�e" �n�j�h��
			int getMapHigh();			//��o�C�i�Ϫ� "��" �n�j�h��
			int getBlockxN();			//��o x �b�`�@���h�ֱi�� (���k�`�@�X�i)
			int getBlockyN();			//��o y �b�`�@���h�ֱi�� (�W�U�`�@�X�i)
			int getMap(int x, int y);	//��o�a�ϸ̪���
		protected:
			int map[10][10];				//�a��
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
