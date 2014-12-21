// Implement a function void reverse(char* str) which reverses a null terminated string.
/*
str = “i”
len = 1
len/2 = 0;

str = “”;
len = 0
len/2 = 0;

str = “ab”;
len = 2;
len/2 = 1;
str = “ba”

str = “abc”
len = 3
len/2 = 1
str = “cba”

str = “abcde”
len = 5
len/2 = 2
str = “edcba”
*/

void reverse( char* str ){
  char temp;
  int len = str.size();
  for( int i = 0; i < len/2; i++ ){
    temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}
