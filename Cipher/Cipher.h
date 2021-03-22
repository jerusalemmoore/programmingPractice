#include <string>
#include <unordered_map>
using std::string;
class Cipher{
public:
  Cipher(int steps);
  string encrypt(string stringToEncrypt);
  string decrypt(string stringToDecrypt);
  //
  // void store();
  // ~Cipher();

private:
  int cipherType; //type of cypher to use for string
  std::unordered_map<string, string> encryptedStrings;
  int steps;

};
