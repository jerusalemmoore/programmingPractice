#include "Cipher.h"
#include <iostream>
using std::cout;
using std::endl;
int main(){

  Cipher cipher(6);
  string newString = cipher.encrypt("hello, this is an encrypted message. special symbols !@#$%^^&**()__+");
  string decryptedString = cipher.decrypt(newString);
  cout << newString << endl;
  cout << decryptedString << endl;


  return 0;
}
