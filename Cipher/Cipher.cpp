#include "Cipher.h"

/*
  Caesar cipher constructor takes number of steps with which to encrypt string

  params
  @steps number of steps to shift for encryption
*/
Cipher::Cipher(int steps){
  this->steps = steps;
}
/*
  take a string and begin process of encrypting with a caesar cipher

  return: encrypted string

*/
string Cipher::encrypt(string stringToEncrypt){
  for(int i = 0; i < stringToEncrypt.length(); i++){
    if(stringToEncrypt[i] != 32){//does not equal space character
      if(stringToEncrypt[i] + steps > 126){
        stringToEncrypt[i] = ((stringToEncrypt[i] + steps) % 127) + 33;
      }
      else{
        stringToEncrypt[i] = stringToEncrypt[i] + steps;
      }
    }
  }
  return stringToEncrypt;
}
/*
  take a string and begin decrypting caesar cipher

  return: decrypted string
*/
string Cipher::decrypt(string stringToDecrypt){
  for(int i = 0; i < stringToDecrypt.length(); i++){
    if(stringToDecrypt[i] != 32){
      if(stringToDecrypt[i] - steps < 33){
        stringToDecrypt[i] = ((stringToDecrypt[i] - steps) + 127) - 33;
      }
      else{
        stringToDecrypt[i] = stringToDecrypt[i] - steps;
      }
    }
  }
  return stringToDecrypt;
}
