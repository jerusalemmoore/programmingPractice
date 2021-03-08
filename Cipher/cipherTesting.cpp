#include "Cipher.h"
#include <iostream>
using std::cout;
using std::endl;
int main(){

  Cipher cipher;
  string newString = cipher.encrypt("hello, this is an encrypted message. special symbols !@#$%^^&**()__+");
  string anotherString = cipher.encrypt("HELLO");
  string decryptedString1 = cipher.decrypt(newString);
  string decryptedString2 = cipher.decrypt(anotherString);
  cout << newString << endl;
  cout << anotherString << endl;
  cout << decryptedString1 << endl;
  cout << decryptedString2 << endl;
  return 0;
}
