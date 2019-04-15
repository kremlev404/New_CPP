// Подключаем нужные библиотеки
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
// Подключаем нашу локальную билиотеку
#include "mylab.cpp"
#define u_int unsigned int
// Подключаем пространство имен
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
//Используем отдельную переменную для сохранения символа конца строки

int main(int argc, char* argv[]){
	if ((!Cmp(argv[1],"-help")) || (!Cmp(argv[1],"--h"))){
	help();
		return 0;
 	}

	try{
		if (argc!=4)
			throw "INCORRECT number of argc";
	}
	catch(const char* msg){
		cout<<msg<<endl;
		exit(-1);
	}
//Выводим лого
	logo();
//Прверяем нужна ли пользователю помощь
 	

//Создаем локальные переменные 	
	char carmodel[31];
	char manufacturer[31];
	u_int productionyear;
	u_int mileage;
	u_int price;
//Создаем таблицу
	if ((!Cmp(argv[1],"-c"))){
		u_int k = atoi(argv[2]);
		ofstream fO(argv[3], ios::binary);
		Car* arrCar = new Car[k];
		fO.write((char*)&k, sizeof(int));
		fO.write(&nl, 1);
		cout <<"Model\tYear\tMileage\tManufacturer\tPrice\t\n";
//Вводим данные в обьект
		for (int i = 0; i < atoi(argv[2]); i++) {
			try{
				if (!(cin>>carmodel>>productionyear>>mileage>>manufacturer>>price))
					throw "INPUT ERROR";
								
			}
			catch(const char* msg){
				cout<<msg<<endl;
				exit(-1);				
			}			
			arrCar[i].setCarmodel(carmodel);
			arrCar[i].setManufacturer(manufacturer);
			arrCar[i].setProductionyear(productionyear);
			arrCar[i].setMileage(mileage);
			arrCar[i].setPrice(price);
			arrCar[i].write(fO);
		}
//НЕ забываем закрыть файл и удалить массив
		fO.close();
		delete[] arrCar;
		arrCar = 0;
	}
//Выводим таблицу
	if ((!Cmp(argv[1],"-r"))){
		ifstream fI(argv[3], ios::binary);
		Car* arrCar = new Car[atoi(argv[2])];
		u_int k1 = 0;
		u_int column;
		fI.read((char*)&column, sizeof(u_int));
		fI.read(&nl, 1);
		cout <<"Model\tYear\tMileage\tManufacturer\tPrice\t\n";
//Выводим данные из обьекта и проверяем не пуст ли файл
		if(!fI.eof()){
			while (!fI.eof() && k1 < atoi(argv[2])) {
				arrCar[k1].read(fI);
				if (fI.eof())
					break;
				cout<<arrCar[k1].getCarmodel()<<"\t"<<arrCar[k1].getProductionyear()<<"\t"
					<<arrCar[k1].getMileage()<<"\t"<< arrCar[k1].getManufacturer()<<"\t\t"<<arrCar[k1].getPrice()<<"\t\n";
				k1++;
			}
		}
		else
			cout << "File is empty" << endl;
//НЕ забываем закрыть файл и удалить массив
		fI.close();
		delete[] arrCar;
		arrCar = 0;
	}
	return 0;
}