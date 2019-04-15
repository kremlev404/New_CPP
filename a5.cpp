// Подключаем нужные библиотеки
#include <iostream>
#include <cstring>
// Подключаем пространство имен
using std::cout;
using std::endl;
// Наводим красоту
void logo(){
	cout << "\033[37;1m\033[44m"<< " **********************************************************";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[47m"<< " * Nizhniy Novgorod Technical University                  *";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[47m"<< " * Study work number 5. Task number 12.                   *";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[47m"<< " * Performed student 18-IVT-2 Kremlev Anton               *";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[44m"<< " **********************************************************";
	cout << "\x1b[39;49m" << endl << endl;;
}
//Создаем функцию с подсказками пользователю
void help()
{
	cout<< "You have to use this form"<<endl;
	cout<< "//FINAL FORM// -all filename"<<endl;
}
//Базовый класс
class Aircraft{
protected:
//Создадим два поля,1-стринг,2-булеан для проверки на ручное управление
    bool manual_contlor;
public:
//Метод для вывода информации в файл
	void getInfo(){				
		std::cout << std::boolalpha;
        if (manual_contlor == true)
			cout<<"YES\n";
		else 
			cout<<"NO\n";
    }
    virtual void TypeOfAircraft(){
    	cout<<"i am ur parent\n";
    }
};
//Производный от базового 
class Piloted_aircraft : public Aircraft {
protected:
//С помощью конструктора присвоим первоначальные значения
    Piloted_aircraft(){
        manual_contlor = true;
    }
};
//Производный от базового 
class Not_piloted_aircraft : public Aircraft{
protected:
//С помощью конструктора присвоим первоначальные значения
    Not_piloted_aircraft(){
        manual_contlor = false;
    }
};
//Производный от производного(конечный класс для описания обьекта)
class Plane : public Piloted_aircraft{
public:
//С помощью конструктора присвоим первоначальные значения
    
        void TypeOfAircraft() override{
        	cout<<"Plane\t\t";
        }
    
};
//Производный от производного(конечный класс для описания обьекта)
class Helicopter : public Piloted_aircraft{
public:
//С помощью конструктора присвоим первоначальные значения
    
    	 void TypeOfAircraft() override{
        	cout<<"Helicopter\t";
        }
    
};
//Производный от производного(конечный класс для описания обьекта)
class Meteozond : public Not_piloted_aircraft{
public:
//С помощью конструктора присвоим первоначальные значения
   
    	 void TypeOfAircraft() override{
        	cout<<"Meteozond\t";
       }
    
};
//Производный от производного(конечный класс для описания обьекта)
class Flying_robot : public Not_piloted_aircraft{
public:
//С помощью конструктора присвоим первоначальные значения
   
    	 void TypeOfAircraft() override{
        	cout<<"Flying_robot\t";
    	}
};

int main(int argc, char* argv[]){
	try{
		if (argc!=3)
			throw "INCORRECT number of argc";
	}
	catch(const char* msg){
		cout<<msg<<endl;
		exit(-1);
	}
    //Выводим лого
    logo();
 	
    //Проверка на помощь
    if (!strcmp(argv[1],"-help"))
    	help();
 
    //перенаправим поток вывода в файл 
	freopen(argv[2], "w", stdout);
	cout<<"TypeOf Aircraft\t Manual Control"<<endl;
	//Создадим обьекты
	Plane tu;
	Meteozond me;
	Helicopter he;
	Flying_robot fr;
	//Проверим что хочет от нас пользователь 
	if (!strcmp(argv[1],"-all")){
		tu.TypeOfAircraft();
		tu.getInfo();
		me.TypeOfAircraft();
		me.getInfo();
		he.TypeOfAircraft();
		he.getInfo();
		fr.TypeOfAircraft();
		fr.getInfo();	
	}
	else {
		if ((!strcmp(argv[1],"-Plane")))
	    	tu.TypeOfAircraft();
	    	tu.getInfo();	    		      
	    if(!strcmp(argv[1],"-Meteozond"))
	    	me.TypeOfAircraft();
	    	me.getInfo();	    	
	    if(!strcmp(argv[1],"-Helicopter"))
	    	he.TypeOfAircraft();
	    	he.getInfo();	    	
	    if(!strcmp(argv[1],"-Flying_robot"))
	    	fr.TypeOfAircraft();
	    	fr.getInfo();	    	
	}  
 	fclose(stdout);
    return 0;
}
