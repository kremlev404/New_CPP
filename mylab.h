#include <iostream>
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
class TCharArray {
protected:
	int size;
	char* buf;

private:
	char& at(int i) {
		if (i >= 0 && i < size)
			return buf[i];
		else {
			std::cout << "this item doesn't exist\n";
			exit(-1);
		}
	}

public:
	TCharArray() {
		buf = nullptr;
		size = 0;
	}
	~TCharArray() {
		delete[] buf;
		buf = nullptr;
		size = 0;
	}
	TCharArray(char* str) {
		size = Strlen(str);
		buf = new char[size + 1];
		for (int i = 0; i < size; i++)
			buf[i] = str[i];
		buf[size] = '\0';
	}
	char& operator[](int i) {
		return at(i);
	}
	void setBuf(char* str) {
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
	int length() {
		return size;
	}
};

class String : public TCharArray {
public:
	String() : TCharArray() {};
	String(char* str) : TCharArray(str) {};
	~String() {
		delete[] buf;
		buf = nullptr;
		size = 0;
	}
	void setStr(String& str) {
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
	char* getStr() {
		return buf;
	}
	void mystrcat(char*	str1, char* str2)
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
	void operator+ ( char* rvalue){	
    	mystrcat(buf, rvalue);	
	}
	bool operator>(const String& str){
		if (Cmp(buf, str.buf) == 12)
			return true;
		else
			return false;
	}
	bool operator<(const String& str){
		if(Cmp(buf, str.buf) == -1)
			return true;
		else
			return false;
	}
	bool operator==(const String& str){
		return (!Cmp(buf, str.buf));
	}
	bool operator!=(const String& str){
		return Cmp(buf, str.buf);
	}
	
};

#endif
