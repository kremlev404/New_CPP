#include "mylab.h"
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
#ifndef _myString_myCar_Tchar_
#define _myString_myCar_Tchar_
int Strlen(const char * str) {
	int len = 0;
    while(*str++) 
    	++len;
    return len;
}
int Cmp(const char* str1, const char* str2) {
	while (*str1 && *str2){
		if (*str1 > *str2)
	    	return 12;
	    if (*str1 < *str2)
	    	return -1;	    
    	str1++; str2++;
	}
	return *str1? -1 : *str2? 1 : 0;
}
	TCharArray::TCharArray() {
		buf = nullptr;
		size = 0;
	}
	TCharArray::~TCharArray() {
		delete[] buf;
		buf = nullptr;
		size = 0;
	}
	TCharArray::TCharArray(char* str) {
		size = Strlen(str);
		buf = new char[size + 1];
		for (int i = 0; i < size; i++)
			buf[i] = str[i];
		buf[size] = '\0';
	}
	
	void TCharArray::setBuf(char* str) {
		if (buf == nullptr) { 
			size = Strlen(str);
			buf = new char[size + 1];
			for (int i = 0; i < size; i++)
				buf[i] = str[i];
			buf[size] = '\0';
		}
		else {
			delete[] buf;
			size = Strlen(str);
			buf = new char[size + 1];
			for (int i = 0; i < size; i++)
				buf[i] = str[i];
			buf[size] = '\0';
		}
	}
	int TCharArray::length() {
		return size;
	}


	String::String() : TCharArray() {};
	String::String(char* str) : TCharArray(str) {};
	String::~String() {
		delete[] buf;
		buf = nullptr;
		size = 0;
	}
	void String::setStr(String& str) {
		if (buf == nullptr) {
			size = str.size;
			buf = new char[size + 1];
			for (int i = 0; i < size; i++)
				buf[i] = str[i];
			buf[size] = '\0';
		}
		else {
			delete[] buf;
			size = str.size;
			buf = new char[size + 1];
			for (int i = 0; i < size; i++)
				buf[i] = str[i];
			buf[size] = '\0';
		}

	}
	char* String::getStr() {
		return buf;
	}
	void String::mystrcat(char*	str1, char* str2)
	{
		while(*str1) 
			str1++;
		while(*str2){
				*str1 = *str2;
				str1++;
				str2++;
		}
		*str1 = '\0';
	}
	void String::operator+ ( char* rvalue){	
    	mystrcat(buf, rvalue);	
	}
	bool String::operator>(const String& str){
		if (Cmp(buf, str.buf) == 12)
			return true;
		else
			return false;
	}
	bool String::operator<(const String& str){
		if(Cmp(buf, str.buf) == -1)
			return true;
		else
			return false;
	}
	bool String::operator==(const String& str){
		return (!Cmp(buf, str.buf));
	}
	bool String::operator!=(const String& str){
		return Cmp(buf, str.buf);
	}
	

// Наводим красоту
void logo(){
	cout << "\033[37;1m\033[44m"<< " **********************************************************";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[47m"<< " * Nizhniy Novgorod Technical University                  *";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[47m"<< " * Study work number 4. Task number 12.                   *";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[47m"<< " * Performed student 18-IVT-2 Kremlev Anton               *";
	cout << "\x1b[39;49m" << endl;
	cout << "\033[37;1m\033[44m"<< " **********************************************************";
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


	void Car::setCarmodel(char* carmodel1) {
		carmodel.setBuf(carmodel1);
	}
	void Car::setManufacturer(char* manufacturer1) {
		manufacturer.setBuf(manufacturer1);
	}
	void Car::setPrice(unsigned int price1) {
		price = price1;
	}
	void Car::setMileage(unsigned int mileage1) {
		mileage = mileage1;
	}
	void Car::setProductionyear(unsigned int productionyear1) {
		productionyear = productionyear1;
	}
//прописываем методы get для получения данных об обьекте
	char* Car::getCarmodel() {
		return carmodel.getStr();
	}
	char* Car::getManufacturer() {
		return manufacturer.getStr();
	}
	unsigned int Car::getPrice() {
		return price;
	}
	unsigned int Car::getMileage() {
		return mileage;
	}
	unsigned int Car::getProductionyear() {
		return productionyear;
	}
//прописываем read/write для ввода вывода
	void Car::read(ifstream& file) {
		char arrCarmodel[31];
		char arrManufacturer[31];
		file.read(arrCarmodel, 31);
		carmodel.setBuf(arrCarmodel);
		file.read(arrManufacturer, 31);
		manufacturer.setBuf(arrManufacturer);
		file.read((char*)&productionyear, sizeof(u_int));
		file.read((char*)&price, sizeof(u_int));
		file.read((char*)&mileage, sizeof(u_int));
		file.read(&nl,1);
	}
	void Car::write(ofstream& file) {
		file.write(carmodel.getStr(), 31);
		file.write(manufacturer.getStr(), 31);
		file.write((char*)&productionyear, sizeof(u_int));
		file.write((char*)&price, sizeof(u_int));
		file.write((char*)&mileage, sizeof(u_int));
		file.write(&nl,1);
	}



#endif