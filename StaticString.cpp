#include "StaticString.h"
#include <cstddef> 
#include <stdexcept>
#include <cctype>

using namespace std;
using std::out_of_range;


StaticString::StaticString(){
	cstr[0] = '\0';		
}

StaticString::StaticString(const char* str){
	int count = 0;								//Initializing a counter	
	for(int i = 0; str[i] != '\0'; i++)	{		//Counting the number of elements in char array
		count++;
	}
	if(count > 63) {										
		throw out_of_range("Out of Range");		//Checking if the str is out of range
	}			
	for(int i = 0; i <= count; i++)	{
		cstr[i]=str[i];							//Copying str to cstr
		}
	cstr[count] ='\0';							//putting a null terminator at the end
}

int StaticString::len() const{
	int count = 0;								//Initializing counter
	if(count > CAPACITY) {										
		throw out_of_range("Out of Range");		//Checking if the str is out of range
	}		
	for(int i = 0; cstr[i]!='\0'; i++)			//For loop to test length
		count++;
   return count;
}


int StaticString::capacity() const{
   return this->CAPACITY;
}

const char* StaticString::c_str() const{
   return cstr;
}

char& StaticString::char_at(int position){
	if(position < 0 || position >= len()){
		throw out_of_range("String Index is Out of Bounds");
	}
	return cstr[position];
}

char StaticString::char_at(int position) const{
	if(position < 0 || position >= len()){
		throw out_of_range("String Index is Out of Bounds");
	}
    return cstr[position];
}

char& StaticString::operator[](int position){
	return char_at(position);
}

char StaticString::operator[](int position) const{
   return char_at(position);
}

bool StaticString::isPrefix(const StaticString& other) const{
	StaticString a = *this;
	StaticString b = other.c_str();
	if(a.len() < other.len())
		{
		return false;
		}

	for(int i=0; i<other.len(); i++)
		{
		if(cstr[i] != other[i])
			{
			return false;
			}
		}
	 return true;	
}


bool StaticString::isIPrefix(const StaticString& other) const{
	StaticString left = *this;											
	StaticString right = other.c_str();
	return left.toLower().isPrefix(right.toLower());
}

bool StaticString::isSuffix(const StaticString& other) const{
	StaticString otherVar= other.c_str();									//converting into StaticString object to be used with toLower()
	StaticString cstrVar = cstr;

	if(cstrVar.len() < other.len()){
		return false;
	}
	for(int i = 0; i <= other.len(); i++){
		if(cstr[cstrVar.len()-i] != other.c_str()[other.len()-i]) {
			return false;
		}
	return true;
	}
}

bool StaticString::isISuffix(const StaticString& other) const{

	StaticString otherVar(other.c_str());										//Creating StaticString objects w/ passed in and Global vars
	StaticString cstrVar(cstr);
	return cstrVar.toLower().isSuffix(otherVar.toLower());
}

StaticString& StaticString::trim(){
	int size = 0;														//Initializing l	
	//counting passed in var
	while(cstr[size]){
		size++;
	}
	int i;															    //initializing i
	for(i = 0; i < size && isspace(cstr[i]); i++);						//when i is less than the length of cstr & it is a space
	int a = i;
	for(int j = 0; j <= size-a; j++,i++) {
		cstr[j] = cstr[i];												//Copying contents of i to cstr
	}
	size = size -a;
	//Trailing whitespace
	for(i = size-1; i >= 0 && isspace(cstr[i]); i--);
	i++;
	cstr[i] = '\0';
    return *this;
}

StaticString& StaticString::toLower(){
	int i = 0;
	while (cstr[i])
	{
    cstr[i] = (tolower(cstr[i]));
    i++;
	}
   return *this;
}

StaticString& StaticString::toUpper(){
	int i = 0;
	char c;														//changing case to upper
	while (cstr[i]) {
    c = cstr[i] = (toupper(cstr[i]));
    i++;
	}
   return *this;
}

StaticString StaticString::operator+(const StaticString& other) const{
   return concat(other);
}

StaticString StaticString::concat(const StaticString& other) const{
	int i= 0;
	StaticString a;								//initializing object to hold concatenated string
	StaticString cstrVar(cstr);					//Finding length of other by first changing it to StaticString object
	int cstrLen = cstrVar.len();
	StaticString otherVar(other);				//Finding length of other by first changing it to StaticString object
	int otherLen = otherVar.len();	
	const int size = otherLen+cstrLen;			//Adding lengths together
	if(size > CAPACITY)
		throw out_of_range ("out of range!");
    for(i = 0; i < cstrLen; i++ )	{			//Copying cstr to C
		a.cstr[i] = cstrVar[i];
	}
    for(int j = 0; j < otherLen; j++, i++) {	//Copying other to C + adding space
		a.cstr[i] = otherVar[j];
	}											//Adding up both c-strings elements and putting it in a constant integer
    a.cstr[size]='\0';							//Terminating the c-string
    return a;
}
