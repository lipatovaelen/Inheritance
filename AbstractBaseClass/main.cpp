#include<iostream>
using namespace std;

class Vehicle //виртуальный класс абстрактный транспорное средсво (первое в дереве)
{
	int speed;  //определяем что есть скорость с которой перемещается тр.средство 
	const int MAX_SPEED;  //определяем что есть предельная скорость = она константа
public: //перемещение транспортного средства из точки а в точку в не знам как именно это
		//происходит поэтому нечего написать о классе
	//проверить что класс абстрактныйй - не можем создать экземплчть абстрактного класса

	Vehicle(int speed = 0, int max_speed = 250) :speed(speed), MAX_SPEED(max_speed) {}
	virtual void move() = 0;	//Pure-virtual function - чисто виртуальная функция.
								//объявлена внутри класса виртального
};

class GroundVehicle : public Vehicle {}; // ничего не описываем, наземное транспортное средств
				// : public Vehicl наследует от абстрактный транспорное средсво

class Car :public GroundVehicle //колесный класс абстрактный унаследовал чистую виртуальность
					//метода class Vehicle (от является для него дочерним) и 
					//так же является абстрактным
{
public:
	void move()
	{
		cout << "Машина ездит на колесах" << endl; //определили метод movе класс конкретный
	}
};
class Buldozer :public GroundVehicle //класс бульдозер дочерний 
{
public:
	void move()
	{
		cout << "бульдозер ездит на гусеницах" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle transport; //Can not instantiate Abstract class 
	//GroundVehicle gv;

	Car car;
	car.move();

	Buldozer amd;
	amd.move();
}