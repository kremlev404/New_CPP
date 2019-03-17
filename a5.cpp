// Подключаем нужные библиотеки
#include <iostream>
#include <fstream>
// Подключаем нашу локальную билиотеку
#include "mylab.h"
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
class Aircraft{
public:
	String type_of_aircraft;
	bool manual_contlor;
};
class Piloted_aircraft : public Aircraft {
	Piloted_aircraft():manual_contlor(true){}
};
class Not_piloted_aircraft : public Aircraft{
	Not_piloted_aircraft():manual_contlor(false){}
};
class Plane : public Piloted_aircraft{
	Plane():type_of_aircraft("Plane"){}
};
class Helicopter : public Piloted_aircraft{
	Helicopter():type_of_aircraft("Helicopter"){}
};
class Meteozond : public Not_piloted_aircraft{
	Meteozond():type_of_aircraft("Meteozond"){}
};
class Flying_robot : public Not_piloted_aircraft{
	Flying_robot():type_of_aircraft("Flying_robot"){}
};
int main(int argc, char* argv[]){
	//Выводим лого
	logo();
//Прверяем нужна ли пользователю помощь
 	if ((!Cmp(argv[1],"--help")) || (!Cmp(argv[1],"--h"))){
	help();
		return 0;
 	}
//Проверка на верное количество аргументов
	if (argc != 4){
        cout << "Please get support by use --help" << endl;
        return 0;
	}
  return 0;
}
