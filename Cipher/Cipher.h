/*
  Cipher.h

  implementation of a Caesar cipher object that encrypts and decrypts strings
*/
#include <string>
#include <unordered_map>
using std::string;
class Cipher{
public:
  Cipher(int steps);
  string encrypt(string stringToEncrypt);
  string decrypt(string stringToDecrypt);

private:
  int cipherType; //type of cypher to use for string for future cipher implementations
  //std::unordered_map<string, string> encryptedStrings;
  int steps;

};
