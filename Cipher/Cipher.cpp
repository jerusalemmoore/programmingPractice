#include "Cipher.h"


Cipher::Cipher(){

}
/*
  take a string and begin process of encrypting with a caesar cipher

  note: The following aligns ascii vals to the alphabet array indices
  upperCase -> charToEncrypt[i] + 13 % 26
  lowercase -> charToEncrypt[i] + 7 % 26
*/
string Cipher::encrypt(string stringToEncrypt){
  int newPos = 6;//chars to shift
  for(int i = 0; i < stringToEncrypt.size(); i++){
    if(stringToEncrypt[i] != ' '){
      if(!isalpha(stringToEncrypt[i])){
        stringToEncrypt[i] += newPos;
        newPos = 6;// reset shift
      }
      else if(isupper(stringToEncrypt[i])){
        newPos += (stringToEncrypt[i]+13) %26;//add shift val to upperChar index val
        stringToEncrypt[i] = upperChars[newPos];//encrypt char at i
        newPos = 6;// reset shift
      }
      else{
        newPos += (stringToEncrypt[i]+7) % 26;
        stringToEncrypt[i] = lowerChars[newPos];
        newPos = 6;
      }
    }
  }
  return stringToEncrypt;
}
/*
  take a string and begin process of decrypting caesar cipher

  note: The following aligns ascii vals to the alphabet array indices
  upperCase -> charToEncrypt[i] + 13 % 26
  lowercase -> charToEncrypt[i] + 7 % 26
*/
string Cipher::decrypt(string stringToDecrypt){
  int newPos = -6;
  for(int i = 0; i < stringToDecrypt.size(); i++){
    if(stringToDecrypt[i] != ' '){//if space character, do nothing
      if(!isalpha(stringToDecrypt[i])){//check if special character
        stringToDecrypt[i] += newPos;
        newPos = -6;// reset shift
      }
      else if(isupper(stringToDecrypt[i])){
        newPos += (stringToDecrypt[i]+13) %26;//add shift val to upperChar index val
        stringToDecrypt[i] = upperChars[newPos];//encrypt char at i
        newPos = -6;// reset shift
      }
      else{
        newPos += (stringToDecrypt[i]+7) % 26;
        stringToDecrypt[i] = lowerChars[newPos];
        newPos = -6;
      }
    }
  }
  return stringToDecrypt;
}
