#include <string>
#include <unordered_map>
using std::string;
class Cipher{
public:
  Cipher();
  string encrypt(string stringToEncrypt);
  string decrypt(string stringToDecrypt);
  //
  // void store();
  // ~Cipher();

private:
  int cipherType; //type of cypher to use for string
  std::unordered_map<string, string> encryptedStrings;
  int lowerCasePos;
  int upperCasePos;
  char lowerChars[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
    'p','q','r','s','t','u','v','w','x','y','z'};
  char upperChars[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
  'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
};
