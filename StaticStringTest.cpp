#include "StaticString.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

using std::cout;
using std::endl;
using std::out_of_range;
using std::strcmp;

template <typename T>
void test(int testNum, int& correct, T actual, T expected){

   if(actual == expected){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl; 
      cout << "Actual: " << actual << " Expected: " << expected << endl;
   } 
}

void testString(int testNum, int& correct, const char* actual, const char* expected){

   if(actual && expected && strcmp(actual, expected) == 0){
      correct++;
      cout << "Passed Test " << testNum << endl;
   }
   else{
      cout << "***Failed Test " << testNum << "***" << endl; 
      if(actual && expected){
         cout << "Actual: " << actual << " Expected: " << expected << endl;
      }
   } 
}

int main(){

   cout << "StaticString Test" << endl;

   int testNum  = 1;
   int correct = 0;

   /*Basic initialization and accessor checks*/
   /*Checks len, capacity, c_str, char_at, []*/
   cout << "--------Accessor Tests--------" << endl;
   /*Empty String*/
   StaticString s1;
   cout << "LEN TEST" << endl;
   test(testNum++, correct, s1.len(), 0);

   cout << "CAPACITY TEST" << endl;
   test(testNum++, correct, s1.capacity(), 63);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s1.c_str(), "");

 

   /*Simple string*/
   StaticString s2("abc");

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s2.len(), 3);

    cout << "CAPACITY TEST" << endl;
   test(testNum++, correct, s2.capacity(), 63);

   cout << "CHAR_AT TEST" << endl;
   test(testNum++, correct, s2.char_at(0), 'a');

   cout <<"++++FUNCTION TEST+++++++"<<endl;
   test(testNum++, correct, s2[2], 'c');

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s2.c_str(), "abc");

   /*Long string*/
   StaticString s3("1234567890qwertyuiopasdfghjklzxcvbnm");
   cout << "LEN TEST" << endl;
   test(testNum++, correct, s3.len(), 36);

   cout << "CHAR_AT TEST" << endl;
   test(testNum++, correct, s3.char_at(3), '4');

   /*Symbols*/
   StaticString s4("abc ;2420* Rocks!ABC");
   cout << "LEN TEST" << endl;
   test(testNum++, correct, s4.len(), 20);

   cout << "CHAR_AT TEST" << endl;
   test(testNum++, correct, s4.char_at(3), ' ');

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s4.c_str(), "abc ;2420* Rocks!ABC");

   /*Max string*/
   StaticString s5("1234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREabc");

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s5.len(), 63);

   cout << "CAPACITY TEST" << endl;
   test(testNum++, correct, s5.capacity(), 63);

   cout << "FUNCTION TEST" << endl;
   test(testNum++, correct, s5[62], 'c');

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s5.c_str(), "1234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREabc");

   cout << "--------Comparison Tests--------" << endl;
   cout << "--------Prefix--------" << endl;
   /*Prefix*/
   test(testNum++, correct, s1.isPrefix(s2), false);
   test(testNum++, correct, s2.isPrefix(s1), true);
   test(testNum++, correct, s2.isPrefix(s2), true);
   test(testNum++, correct, s4.isPrefix(s2), true);
   test(testNum++, correct, s2.isPrefix(s4), false);
   test(testNum++, correct, s5.isPrefix(s3), true);
   test(testNum++, correct, s3.isPrefix(s5), false);
   test(testNum++, correct, s5.isPrefix(s5), true);
   //test(testNum++, correct, s3.isPrefix("1234"), true);
   /*IPrefix*/
  cout << "--------IPrefix--------" << endl;
   test(testNum++, correct, s1.isIPrefix(s2), false);
   test(testNum++, correct, s2.isIPrefix(s1), true);
   //test(testNum++, correct, s2.isIPrefix("AB"), true);
   //test(testNum++, correct, s2.isIPrefix("ABC"), true);
   test(testNum++, correct, s2.isIPrefix(s4), false);
   //test(testNum++, correct, s4.isIPrefix("ABc ;2"), true);
   //test(testNum++, correct, s5.isIPrefix("1234567890qweRTYuiopz"), false);
   /*Suffix*/
   cout << "--------Suffix--------" << endl;
   test(testNum++, correct, s1.isSuffix(s2), false);
   test(testNum++, correct, s2.isSuffix(s1), true);
   test(testNum++, correct, s2.isSuffix(s2), true);
   test(testNum++, correct, s5.isSuffix(s2), true);
   test(testNum++, correct, s2.isSuffix(s5), false);
   test(testNum++, correct, s5.isSuffix(s5), true);
   //test(testNum++, correct, s2.isSuffix("dbc"), false);
   //test(testNum++, correct, s3.isSuffix("zxcvbnm"), true);
   //test(testNum++, correct, s4.isSuffix("\t"), false);
   /*ISuffix*/
   cout << "--------ISuffix--------" << endl;
   test(testNum++, correct, s1.isISuffix(s2), false);
   test(testNum++, correct, s2.isISuffix(s1), true);
   //test(testNum++, correct, s2.isISuffix("aBC"), true);
   //test(testNum++, correct, s4.isISuffix("s!aBc"), true);
   //test(testNum++, correct, s2.isISuffix("s?AbC"), false);


   cout << "--------Modification Tests--------" << endl;
   cout << "--------Concatenation--------" << endl;
   /*Concatenation*/
   StaticString s6 = s1+s2;
   cout << "LEN TEST" << endl;
   test(testNum++, correct, s6.len(), 3);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s6.c_str(), "abc");

   StaticString s7 = s2+"abc";

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s7.len(), 6);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s7.c_str(), "abcabc");

   StaticString s8 = s5+s1;

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s8.len(), 63);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s8.c_str(), "1234567890qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREabc");

   cout << "CONCAT TEST" << endl;
   StaticString s9 = s3.concat(s4);

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s9.len(), 56);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s9.c_str(), "1234567890qwertyuiopasdfghjklzxcvbnmabc ;2420* Rocks!ABC");

   
   StaticString s10 = s2.concat("def");

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s10.len(), 6);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s10.c_str(), "abcdef");

   cout << "--------ToUpper--------" << endl;
   /*ToUpper*/
   StaticString s11 = s1;
   cout <<"UPPER TEST" << endl;
   s11.toUpper();

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s11.len(), 0);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s11.c_str(), "");

   StaticString s12 = s2;
   
   cout << "TO UPPER TEST" << endl;
   s12.toUpper();

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s12.len(), 3);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s12.c_str(), "ABC");

   StaticString s13 = s4;

   cout << "TO UPPER TEST" << endl;
   s13.toUpper();

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s13.c_str(), "ABC ;2420* ROCKS!ABC");

   StaticString s14 = s5;

   cout << "TO UPPER TEST" << endl;
   s14.toUpper();

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s14.c_str(), "1234567890QWERTYUIOPASDFGHJKLZXCVBNMMNBVCXZLKJHGFDSAPOIUYTREABC");

   /*ToLower*/
   cout << "--------ToLower--------" << endl;
   StaticString s15 = s1;

   cout << "TO LOWER TEST" << endl;
   s15.toLower();

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s15.len(), 0);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s15.c_str(), "");

   StaticString s16 = s4;

   cout << "TO LOWER TEST" << endl;
   s16.toLower();

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s16.c_str(), "abc ;2420* rocks!abc");

   StaticString s17 = s5;

   cout<< "TO_LOWER TEST" << endl;
   s17.toLower();

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s17.c_str(), "1234567890qwertyuiopasdfghjklzxcvbnmmnbvcxzlkjhgfdsapoiuytreabc");

   /*Trim*/
   cout << "--------- Trim -----------" << endl;
   StaticString s19 = "";			//new string
   cout << "TRIM TEST" << endl;
   s19.trim();

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s19.len(), 0);
	
   cout << " C_STR TEST" << endl;
   testString(testNum++, correct, s19.c_str(), "");

   StaticString s20 = "  abc  ";	//new string

   cout << "TRIM TEST" << endl;
   s20.trim();

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s20.len(), 3);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s20.c_str(), "abc");


   StaticString s21 = " \n\t!a b $ \r";		//new string
   cout << "TRIM TEST" << endl;
   s21.trim();

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s21.len(), 6);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s21.c_str(), "!a b $");

   StaticString s23 = "        ";			//new string
   cout << "TRIM TEST " << endl;
   s23.trim();

   cout << "LEN TEST" << endl;
   test(testNum++, correct, s23.len(), 0);

   cout << "C_STR TEST" << endl;
   testString(testNum++, correct, s23.c_str(), "");

   /*Assignment*/
   cout << "FUNCTION TEST" << endl;
   s2[0] = 'b';

   cout << "FUNCTION TEST" << endl;
   s3[3] = 'a';

   cout << "FUNCTION TEST" << endl;
   s4[1] = 'q';

   cout << "CHAR_AT TEST" << endl;
   s5.char_at(8) = 'z';

   cout << "CHAR_AT TEST" << endl;
   s6.char_at(0) = '\n';

   cout <<"FUNCTION TEST" << endl;
   test(testNum++, correct, s2[0], 'b');

   cout << "CHAR AT TEST" << endl;
   test(testNum++, correct, s3.char_at(3), 'a');

   cout << "CHAR AT TEST" << endl;
   test(testNum++, correct, s4.char_at(1), 'q');

   cout << "CHAR AT TEST" << endl;
   test(testNum++, correct, s5[8], 'z');

   cout << "CHAR AT TEST" << endl;
   test(testNum++, correct, s6[0], '\n');

   /*Bounds checking*/
   cout << "CHAR_AT OUT OF BOUNDS TEST" << endl;
   try{
      s1.char_at(1);//out_of_bounds
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   cout << "CHAR_AT OUT OF BOUNDS TEST" << endl;
   try{
      s2.char_at(-1);//out_of_bounds
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   cout << "FUNCTION OUT OF BOUNDS TEST" << endl;
   try{
      s1[0];//out_of_bounds
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   cout << "CONCATENATION OUT OF BOUNDS TEST" << endl;
   try{
      s3+s3;//too large
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   cout << "CONCATENATION OUT OF BOUNDS TEST" << endl;
   try{
      s8+"1111122222333334444455555666";//too large
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   try{
      StaticString s29 = "..... ..... ..... ..... ..... ..... ..... ..... ..... ..... ..... .....";
      test(testNum++, correct, 0, 1);
   }
   catch(out_of_range){
      test(testNum++, correct, 0, 0);
   }
   cout << "Passed " << correct << "/" << --testNum << " tests" << endl;
   cout << "Score: " << correct/float(testNum) << endl;
   cout << "Points: " << 60*correct/float(testNum) << endl;
   
}
