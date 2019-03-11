// Подключаем нужные библиотеки
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#define u_int unsigned int
// Подключаем пространство имен
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
//Используем отдельную переменную для сохранения символа конца строки
char nl('\n');
// Наводим красоту
void logo(){
	cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
	cout << "\033[37;1m\033[47m"<< "\n * Nizhniy Novgorod Technical University                  *";
	cout << "\033[37;1m\033[47m"<< "\n * Study work number 3. Task number 12.                   *";
	cout << "\033[37;1m\033[47m"<< "\n * Performed student 18-IVT-2 Kremlev Anton               *";
	cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
	cout << "\x1b[39;49m" << endl << endl;;
}
//Создаем функцию с подсказками пользователю
void help()
{
	cout<< "You can choose 2 startup options: "<<endl;
	cout<< "-с launch of the program in the mode of creating electronic tables"<<endl;
	cout<< "-r launch of the program in the content reading mode text file"<<endl;
	cout<< "Also you must specify the number [N] of entries and the [file_name]"<<endl;
	cout<< "Final view of the program launch structure -с [N] [file_name] or -r [N] [file_name]"<<endl;
}
//Создаем класс, который будет описывать наши машины
class Car {
private:
	char carmodel[31];
	char manufacturer[31];
	u_int productionyear;
	u_int mileage;
	u_int price;
public:
//Используем конструктор класса для первоночальной инициализации перменных
	Car() {
		productionyear = 0;
		mileage = 0;
		price = 0;
		return;
	}
//прописываем методы set для внесения данных об обьекте
	void setCarmodel(char* carmodel1) {
		for (int i = 0; i < strlen(carmodel1); i++) 
			carmodel[i] = carmodel1[i];
		carmodel[strlen(carmodel1)] = '\0';
	}
	void setManufacturer(char* manufacturer1) {
		for (int i = 0; i < strlen(manufacturer1); i++) 
			manufacturer[i] = manufacturer1[i];
		manufacturer[strlen(manufacturer1)] = '\0';
	}
	void setPrice(unsigned int price1) {
		price = price1;
	}
	void setMileage(unsigned int mileage1) {
		mileage = mileage1;
	}
	void setProductionyear(unsigned int productionyear1) {
		productionyear = productionyear1;
	}
// //прописываем методы get для получения данных об обьекте
	char* getCarmodel() {
		return carmodel;
	}
	char* getManufacturer() {
		return manufacturer;
	}
	unsigned int getPrice() {
		return price;
	}
	unsigned int getMileage() {
		return mileage;
	}
	unsigned int getProductionyear() {
		return productionyear;
	}
// //прописываем read/write для ввода вывода
	void read(ifstream& file) {
		file.read(carmodel, 31);
		file.read(manufacturer, 31);
		file.read((char*)&productionyear, sizeof(u_int));
		file.read((char*)&price, sizeof(u_int));
		file.read((char*)&mileage, sizeof(u_int));
		file.read(&nl,1);
	}
	void write(ofstream& file) {
		file.write(carmodel, 31);
		file.write(manufacturer, 31);
		file.write((char*)&productionyear, sizeof(u_int));
		file.write((char*)&price, sizeof(u_int));
		file.write((char*)&mileage, sizeof(u_int));
		file.write(&nl,1);
	}
};

int main(int argc, char* argv[]){
//Выводим лого
	logo();
//Прверяем нужна ли пользователю помощь
	if ((!strcmp(argv[1],"--help")) || (!strcmp(argv[1],"-h"))){
		help();
		return 0;
	}
//Проверка на верное количество аргументов
	if (argc != 4){
        cout << "Please get support by use --help" << endl;
        return 0;
	}
//Создаем локальные переменные 	
	char carmodel[31];
	char manufacturer[31];
	u_int productionyear;
	u_int mileage;
	u_int price;
//Создаем таблицу
	if ((!strcmp(argv[1],"-c"))){
		u_int k = atoi(argv[2]);
		ofstream fO(argv[3], ios::binary);
		Car* arrCar = new Car[k];
		fO.write((char*)&k, sizeof(int));
		fO.write(&nl, 1);
		cout <<"Model\tYear\tMileage\tManufacturer\tPrice\t\n";
//Вводим данные в обьект
		for (int i = 0; i < atoi(argv[2]); i++) {
			cin>>carmodel>>productionyear>>mileage>>manufacturer>>price;
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
	if ((!strcmp(argv[1],"-r"))){
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
