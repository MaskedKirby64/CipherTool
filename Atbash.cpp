
#include "Atbash.h"
#include "Cipher.h"
#include <string>
#include<vector>
using namespace std;

//class Atbash: public Cipher {
 //public:
  // Name: Atbash (Default Constructor)
  // Desc: Constructor to build an empty Atbash Cipher
  // Preconditions - None
  // Postconditions - Creates a Atbash cipher to be encrypted
  Atbash::Atbash(){
    SetMessage("");
    ToggleEncrypted();

  };
  // Name: Atbash (Overloaded Constructor)
  // Desc: Constructor to build a populated Atbash Cipher
  // Preconditions - Pass it the message and isEncrypted
  // Postconditions - Creates a Atbash cipher to be encrypted
  Atbash::Atbash(string message, bool isEncrypted):
    Cipher(message,isEncrypted){}
  // Name: Atbash (Destructor)
  // Desc: Destructor - Anything specific to Atbash to delete?
  // Preconditions - ~Atbash exists
  // Postconditions - Atbash destroyed
  Atbash::~Atbash(){
    SetMessage("");
    ToggleEncrypted();
  }
  // Name: Encrypt
  // Desc: Reverses the alphabet (A ↔ Z, B ↔ Y, etc.)
  // Preconditions - Message exists
  // Postconditions - Reverses the characters. Ignores punctuation.
  void Atbash::Encrypt(){

    string message = GetMessage();
    vector<char>tokens;
    vector<char>atbash_encoding;
    string encryption;
    for(int i = 0; i<message.length(); i++){
        tokens.push_back(message[i]);
    }
    for(unsigned int i = 0; i<tokens.size(); i++){
       //taking advantage of the fact that chars are technically ASCII numbers
        if(tokens[i] >= 'a' && tokens[i]<='z'){
        atbash_encoding.push_back('z'-(tokens[i]-'a'));
        }
       //if uppercase
        else if(tokens[i] >= 'A' && tokens[i] <= 'Z'){
          atbash_encoding.push_back('A'-(tokens[i]-'Z'));
        }
        else{
          atbash_encoding.push_back(tokens[i]);

        }

      }
         tokens.clear();

  for(unsigned int i = 0; i<atbash_encoding.size(); i++){
          encryption+=atbash_encoding[i];
   }
   SetMessage(encryption);
   ToggleEncrypted();
}
  // Name: Decrypt
  // Desc: Reverses the alphabet (A ↔ Z, B ↔ Y, etc.)
  // Preconditions - Message exists
  // Postconditions - Reverses the characters. Ignores punctuation.
  void Atbash::Decrypt(){

    string message = GetMessage();
    //can call again since Encrypt() is the inverse of itself
    Encrypt();


  }
  // Name: ToString
  // Desc - A function that returns the string of the obect type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned (Atbash in this case)
  string Atbash::ToString(){
    return "Atbash";

  }
  // Name: FormatOutput()
  // Desc - A function that returns the formatted output for Output function
  // Preconditions - The object exists (use stringstream)
  // Postconditions - c, delimiter, isencrypted, delimiter,
  //                  message, delimiter are returned for output
  string Atbash::FormatOutput(){
    return " ";

  }
//};
