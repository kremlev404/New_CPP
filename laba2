// Подключаем нужные библиотеки
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
// Сокращаем запись
#define u_int unsigned short int
// Подключаем пространство имен
using std::cout;
using std::cin;
using std::endl;
// Наводим красоту
void logo(){
	cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
	cout << "\033[37;1m\033[47m"<< "\n * Nizhniy Novgorod Technical University                  *";
	cout << "\033[37;1m\033[47m"<< "\n * Study work number 2. Task number 12.                   *";
	cout << "\033[37;1m\033[47m"<< "\n * Performed student 18-IVT-2 Kremlev Anton               *";
	cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
	cout << "\x1b[39;49m" << endl << endl;;
}
//Создаем стуктуру
struct Car
{
	char carmodel[31];
	char manufacturer[63];
	u_int productionyear;
	u_int mileage;
	u_int price;
};
//Функция для ввода таблицы
void SetCars(char* filename, u_int N)
{
	//создаем открываем файл на запись и проверяем открылся ли он
	FILE* fout;
	fout = fopen(filename, "w");
	if (fout == 0) {
		cout << filename << ": can't be opened\n";
		exit(-1);
	}
	//создадим временный обьект структуры
	Car tmpC;
	cout <<"Model\tYear\tMileage\tManufacturer\tPrice\t\n";
	//начинаем заполнение таблицы и выводим ее в файл 
	for (int i = 1; i<=N; i++)
	{
		cin>>tmpC.carmodel>>tmpC.productionyear>>tmpC.mileage>>tmpC.manufacturer>>tmpC.price;
		fprintf(fout, "%s\t%u\t%u\t%s\t\t%u\n", tmpC.carmodel, tmpC.productionyear, tmpC.mileage, tmpC.manufacturer, tmpC.price);
	}
	//обязательно не забываем закрыть файл
	fclose(fout);
}
//Функция для вывода таблицы
void ShowCars(char* filename, u_int N)
{
	//создаем открываем файл на запись и проверяем открылся ли он
	FILE* fin;
	fin = fopen(filename, "r");
	if (fin == 0) {
		cout << filename << ": can't be opened\n";
		exit(-1);
	}
	//создадим счетчик для подсчета уже выведенных структур
	u_int k=0;
	//создадим временный обьект структуры
	Car tmpC;
	cout <<"Model\tYear\tMileage\tManufacturer\tPrice\t\n";
	//начинаем чтение таблицы и выводим ее в терминал
 	while(fscanf(fin,"%s\t%u\t%u\t%s\t\t%u\n", tmpC.carmodel, &tmpC.productionyear, &tmpC.mileage, tmpC.manufacturer, &tmpC.price) != EOF)
		if(!(N==k)){
			fprintf(stdout,"%s\t%u\t%u\t%s\t\t%u\n", tmpC.carmodel, tmpC.productionyear, tmpC.mileage, tmpC.manufacturer, tmpC.price);
			k++;	
		}
	//обязательно не забываем закрыть файл
	fclose(fin);
}
 
int main(int argc, char** argv)
{
	//Выводим лого
	logo();
		//Проверяем нужна ли пользователю наша помощь
	if ((!strcmp(argv[1],"--help")) || (!strcmp(argv[1],"-h"))){
		cout<< "You can choose 2 startup options: "<<endl;
		cout<< "-с launch of the program in the mode of creating electronic tables"<<endl;
		cout<< "-r launch of the program in the content reading mode text file"<<endl;
		cout<< "Also you must specify the number [N] of entries and the [file_name]"<<endl;
		cout<< "Final view of the program launch structure -с [N] [file_name] or -r [N] [file_name]"<<endl;
		return 0;
	}
	// Проверяем на верное кол-во аргументов 
  	if (argc != 4){
        cout << "Please get support by use --help or -h" << endl;
        return 0;
	}
	//создаем переменную, которая хранит кол-во записей
	u_int N = atoi(argv[2]);
	//если ввели -с то создаем таблицу
	if ((!strcmp(argv[1],"-c")))
		SetCars(argv[3], N);
	//если ввели -r то выводим таблицу
	if ((!strcmp(argv[1],"-r")))
		ShowCars(argv[3], N);

	return 0;
}
