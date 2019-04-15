#ifndef _mylab_hpp_
#define _mylab_hpp_
#include <fstream>
using std::ifstream;
using std::ofstream;
char nl('\n');

int Strlen(const char * str);
int Cmp(const char* str1, const char* str2);
class TCharArray {
protected:
	int size;
	char* buf;
private:
	char& at(int i){
		if (i >= 0 && i < size)
			return buf[i];
		else {
			std::cout << "this item doesn't exist\n";
			exit(-1);
		}
	}
public:
	TCharArray() ;
	~TCharArray() ;
	TCharArray(char* str) ;
	char& operator[](int i) {
		return at(i);
	}
	void setBuf(char* str);
	int length();
};
class String : public TCharArray {
public:
	String() ;
	String(char* str) ;
	~String() ;
	void setStr(String& str) ;
	char* getStr();
	void mystrcat(char*	str1, char* str2);
	void operator+ ( char* rvalue);
	bool operator>(const String& str);
	bool operator<(const String& str);
	bool operator==(const String& str);
	bool operator!=(const String& str);
};

void logo();
void help();
class Car {
private:
	String carmodel;
	String manufacturer;
	u_int productionyear;
	u_int mileage;
	u_int price;
public:
//Используем конструктор класса для первоночальной инициализации перменных
	Car():productionyear(0),mileage(0),price(0){}
	void setCarmodel(char* carmodel1) ;
	void setManufacturer(char* manufacturer1) ;
	void setPrice(unsigned int price1);
	void setMileage(unsigned int mileage1);
	void setProductionyear(unsigned int productionyear1);
	char* getCarmodel();
	char* getManufacturer();
	unsigned int getPrice();
	unsigned int getMileage();
	unsigned int getProductionyear();
	void read(ifstream& file);
	void write(ofstream& file);
};

#endif



