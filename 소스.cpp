#include<iostream>
using namespace std;

int DISTANCE = 0;
void WhatDis() { cout << "운전 거리: " << DISTANCE << endl << endl; }

class Car
{
	int gasolineGauge;
public:
	Car(int n) :gasolineGauge(n) 
	{
		if (n < 0)cout << "가솔린 입력이 잘못되었습니다." << endl;
		DISTANCE = 0;
	}
	void CarDrive(int n) 
	{ 
		if (20 * gasolineGauge < n||n<0)
		{
			cout << "운전 거리 입력이 잘못되었습니다." << endl;
		}
		gasolineGauge -= n / 20;
		DISTANCE += n;
	}
	int GetGasGauge() { return gasolineGauge; }
};

class HybridCar :public Car
{
	int electricGauge;
public:
	HybridCar(int n) :Car(n) { electricGauge = 0; }
	void HNDrive(int n)
	{
		CarDrive(n);
		electricGauge += n;
	}
	void HHDrive(int n) 
	{ 
		electricGauge -= n;
		DISTANCE += n;
	}
	void HDrive(int n)
	{
		HNDrive(n);
		HHDrive(n);
	}
	int GetElecGauge() { return electricGauge; }
};

class HybridWaterCar :public HybridCar
{
	int waterGauge;
public:
	HybridWaterCar(int n1, int n2) :HybridCar(n1),waterGauge(n2){}
	void HWDrive(int n)
	{
		HDrive(n);
		DISTANCE += waterGauge * 10;
		waterGauge = 0;
	}
};

int main()
{
	HybridWaterCar myCar(30, 10);
	myCar.HWDrive(20);
	myCar.HWDrive(10);
	WhatDis();

	HybridWaterCar secondCar(-30, 10);
	secondCar.HWDrive(30);
	WhatDis();

	return 0;
}