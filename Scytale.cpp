#include "Cipher.h"
#include "Scytale.h"
#include <istream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//class Scytale : public Cipher {
//public:
  // Name: Scytale (Default Constructor)
  // Desc: Constructor to build an empty Scytale Cipher
  // Preconditions - None
  // Postconditions - Creates a Scytale cipher
  Scytale::Scytale(){
    m_key = 0;
  }
  // Name: Scytale (Overloaded Constructor)
  // Desc: Constructor to build a populated Scytale Cipher
  // Preconditions - Pass it the message, isEncrypted, and key (integer)
  // Postconditions - Creates a Scytale cipher to be encrypted
  Scytale::Scytale(string message, bool isEncrypted, int key):Cipher(message,isEncrypted), m_key(key) {}

  // Name: Scytale (Destructor)
  // Desc: Destructor - Anything specific part of Scytale to delete?
  // Preconditions - ~Scytale exists
  // Postconditions - Scytale destroyed
  Scytale::~Scytale(){
    SetMessage("");
    ToggleEncrypted();
  }

  // Name: Encrypt
  // Desc: Letters are placed on a fence rail based on the number of rails
  //       Letters are read from one rail at a time into a single string
  // Preconditions - Message exists
  // Postconditions - A single encrypted string is stored
  void Scytale::Encrypt(){

    string message = GetMessage();
    int length = message.length();
    int columns = ceil((double)length / m_key);
    const char padding = 'X';
    unsigned int c = 0;
    vector<vector<char>> matrix(columns, vector<char>(m_key));
    string encryption = "";


    //feed the string into an ixj 2D matrix
    for(int i = 0; i<columns; i++){
        for(int j = 0; j<m_key; j++){
            if(c<=message.length()){
              matrix[i][j] = message[c];
            }
            else{
              matrix[i][j]=padding;
            }
            c++;
        }
    }

    //then reconstruct it column wise
    for (int j = 0; j < m_key; j++) {
        for (int i = 0; i < columns; i++) {
            encryption+=matrix[i][j];

        }
    }


      ToggleEncrypted();
      SetMessage(encryption);



  }
  // Name: Decrypt
  // Desc: Single encrypted string is pushed back on the rails and reversed
  // Preconditions - Message exists
  // Postconditions - The decrypted string is stored
  void Scytale::Decrypt(){
    string message = GetMessage();
    string decryption = "";
    int key = 5;
    //we need to round due to C++ division
    int row = ceil((double)message.length()/key);

    for(int i=0; i<row; i++){
        for(int j = 0; j<key; j++){
             //this equation scales the row by the current column and adds the current row to it.
             unsigned int ind = j*row+i;
             if(ind<message.length()){
                decryption+=message[ind];
             }
        }
    }

    ToggleEncrypted();
    SetMessage(decryption);

}

  // Name: ToString
  // Desc - A function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned (Scytale in this case)
  string  Scytale::ToString(){
    return "Scytale";
  }
  // Name: FormatOutput()
  // Desc - A function that returns the formatted output for Output function
  // Preconditions - The object exists (use stringstream)
  // Postconditions - r, delimiter, isencrypted, delimiter,
  //                  message, delimiter, key are returned for output
  string Scytale::FormatOutput(){
    return "test";

  }
