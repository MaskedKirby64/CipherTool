#include "Cipher.h"
#include "Ong.h"
#include <istream>
#include <sstream>
#include <vector>
using namespace std;

//Constant for use with the ong cipher
//const string ong = "ong";

  // Name: Ong (Default Constructor)
  // Desc: Constructor to build an empty Ong Cipher
  // Preconditions - None
  // Postconditions - Creates a Ong cipher to be encrypted
  Ong::Ong(){

  }
  // Name: Ong (Overloaded Constructor)
  // Desc: Constructor to build a populated Ong Cipher
  // Preconditions - Pass it the message and isEncrypted
  // Postconditions - Creates a Ong cipher to be encrypted
  Ong::Ong(string message, bool isEncrypted)
        :Cipher(message,isEncrypted){}
  // Name: Ong (Destructor)
  // Desc: Destructor - Anything unique to Ong to delete?
  // Preconditions - ~Ong exists
  // Postconditions - Ong destroyed
  Ong::~Ong(){
    SetMessage("");
    ToggleEncrypted();

  }
  // Name: IsVowel (Helper function)
  // Desc: Returns true if vowel, space, or punctuation
  // Preconditions - Message exists
  // Postconditions - Returns true or false as above
  bool Ong::IsVowel(char v){

    if (v == 'o'||v == 'u'||v == 'e'||v == 'i'||v == 'a'){
        return true;
    }
    else{

        return false;
    }


  }
  bool Ong::IsPunct(char c){
    if (c == '-'){
        return true;
    }
    else{
        return false;
    }
  }

  // Name: Encrypt
  // Desc: If vowel then vowel and dash displayed. dog = dong-o-gong
  // If consonant then consonant and ong and dash displayed.
  // Preconditions - Message exists
  // Postconditions - Encrypts as above
  void Ong::Encrypt(){

     string message = GetMessage();

     //run through and insert ong string after each consonant.
     for(unsigned int i = 0; i<message.length(); i++){
         if(IsVowel(message[i]) == false){
             message.insert(i+1,"ong");
             i+=3;
         }else{
            //I added a second case to the logical statement to check if the current consonant is lower case
             if(IsVowel(message[i]) && islower(message[i])){
             message.insert(i,"-");
             }
             i++;
         }
     }

     ToggleEncrypted();
     SetMessage(message);


  }
  // Name: Decrypt
  // Desc: Removes the dashes and "ong" when necessary cong-a-tong = cat
  // Double check words like "wrong" so that they work correctly!
  // Preconditions - Message exists
  // Postconditions - Original message is displayed
  void Ong::Decrypt(){

    string message = GetMessage();
    string decrypted;
    //iterate through the message until we reach ong and remove it.
    for(unsigned int i = 0; i<message.length(); i++){
      if(message.substr(i,3) == "ong"){
          message.erase(i,3);
      }
  }

  //similar to the ong remove except we need to take care of the spaces as well
 for(unsigned int i = 0; i<message.length(); ++i){
     if(message[i]=='-'){
        message[i] = ' ';
        message.erase(i,1);
     }
    }

  ToggleEncrypted();
  SetMessage(message);

}
  // Name: ToString
  // Desc - A function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned (Ong in this case)
  string Ong::ToString(){
    return "Ong";

  }
  // Name: FormatOutput()
  // Desc - A function that returns the formatted output for Output function
  // Preconditions - The object exists (use stringstream)
  // Postconditions - o, delimiter, isencrypted, delimiter,
  //                  message, delimiter, blank are output
  string Ong::FormatOutput(){
    return "test";

  }
