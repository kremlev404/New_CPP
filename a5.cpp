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

// Наводим красоту
void logo(){
    cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
    cout << "\033[37;1m\033[47m"<< "\n * Nizhniy Novgorod Technical University                  *";
    cout << "\033[37;1m\033[47m"<< "\n * Study work number 5. Task number 12.                   *";
    cout << "\033[37;1m\033[47m"<< "\n * Performed student 18-IVT-2 Kremlev Anton               *";
    cout << "\033[37;1m\033[44m"<< "\n **********************************************************";
    cout << "\x1b[39;49m" << endl << endl;;
}
//Создаем функцию с подсказками пользователю
void help()
{
	cout<< "You can choose 2 startup options: "<<endl;
	cout<< "-all to see all the information about the objects "<<endl;
	cout<< "-one [object] to see the information about the choosen object"<<endl;
	cout<< "Variants of objects:"<<endl;
	cout<< "-Plane"<<endl;
	cout<< "-Meteozond"<<endl;
	cout<< "-Helicopter"<<endl;
	cout<< "-Flying_robot"<<endl;
}
class Aircraft{
protected:
    std::string type_of_aircraft;
    bool manual_contlor;
public:
	void getInfo(){		
	cout<<"You've choosen : "<<type_of_aircraft<<endl;
        std::cout << std::boolalpha;
        if (manual_contlor == true)
        	cout<<"This type of Aircraft support manual control\n";
        else 
        	cout<<"This type of Aircraft doesn't support manual control\n";

    }
};
class Piloted_aircraft : public Aircraft {
protected:
    Piloted_aircraft(){
        manual_contlor = true;
    }
};
class Not_piloted_aircraft : public Aircraft{
protected:
    Not_piloted_aircraft(){
        manual_contlor = false;
    }
};

class Plane : public Piloted_aircraft{
public:
    Plane() : Piloted_aircraft(){
        type_of_aircraft ="Plane";
    }
};
class Helicopter : public Piloted_aircraft{
public:
    Helicopter() : Piloted_aircraft(){
        type_of_aircraft = "Helicopter";
    }
};
class Meteozond : public Not_piloted_aircraft{
public:
    Meteozond() : Not_piloted_aircraft(){
        type_of_aircraft = "Meteozond";
    }
};
class Flying_robot : public Not_piloted_aircraft{
public:
    Flying_robot() : Not_piloted_aircraft(){
        type_of_aircraft = "Flying_robot";
    }
};

int main(int argc, char* argv[]){
    //Выводим лого
    logo();
    //Проверка на помощь
    if (!strcmp(argv[1],"-help")){
    	help();
    //перенаправим поток вывода в файл 
	freopen("1.txt", "w", stdout);
	Plane tu;
	Meteozond me;
	Helicopter he;
	Flying_robot fr;
	if (!strcmp(argv[1],"-all")){
		tu.getInfo();
		me.getInfo();
		he.getInfo();
		fr.getInfo();
	}
	else if(!strcmp(argv[1],"-one")){
		if ((!strcmp(argv[2],"-Plane")))
	    	tu.getInfo();
	      
	    if(!strcmp(argv[2],"-Meteozond"))
	    	me.getInfo();
	    
	    if(!strcmp(argv[2],"-Helicopter"))
	    	he.getInfo();

	    if(!strcmp(argv[2],"-Flying_robot"))
	    	fr.getInfo();
	}  
 	fclose(stdout);
    return 0;
}
