 // Name: Cipher (Default Constructor)
  // Desc - Stores a message and if it is encrypted (or not)
  // Preconditions - None
  // Postconditions - A message is stored in a Cipher object
  Cipher::Cipher(){
    m_message = "";
    m_isEncrypted = false;
  }
  // Name: Cipher (Overloaded Constructor)
  // Desc - Passed a message and if it is encrypted (or not)
  // Preconditions - A message is passed to this constructor, and if it is encrypted
  // Postconditions - A message is stored in a Cipher object
  Cipher::Cipher(string message, bool isEncrypted){
    m_message = message;
    m_isEncrypted = isEncrypted;

  }
  // Name: ~Cipher (Destructor)
  // Desc - Virtual destructor
  // Preconditions - A derived class is being deleted
  // Postconditions - A base class is deleted
     Cipher:: ~Cipher(){
      m_message = "";
      m_isEncrypted = false;
    }
  // Name: Decrypt
  // Desc - A purely virtal function to decrypt a message
  // Preconditions - The message is not already decrypted
  // Postconditions - A message is decrypted based on the child class
  //virtual void Cipher:: Decrypt() = 0;
  // Name: Encrypt
  // Desc - A purely virtal function to encrypt a message
  // Preconditions - The message is not already encrypted
  // Postconditions - A message is encrypted based on the child class
 // virtual void  Cipher::Encrypt() = 0;
  // Name: GetMessage
  // Desc - Returns the message
  // Preconditions - The message exists
  // Postconditions - A message is returned
  string Cipher::GetMessage(){
    return m_message;

  }
  // Name: GetIsEncrypted
  // Desc - Returns isEncrypted (0 is not encrypted and 1 is encrypted)
  // Preconditions - The cipher exists
  // Postconditions - A bool is returned
  bool Cipher::GetIsEncrypted(){
    return m_isEncrypted;

  }
  // Name: SetMessage
  // Desc - Updates a message
  // Preconditions - The message exists
  // Postconditions - A message is updated
  void Cipher::SetMessage(string message){
    m_message = message;

  }
  // Name: ToggleEncrypted
  // Desc - Turns (true to false) or (false to true)
  // Preconditions - The cipher exists
  // Postconditions - The m_isEncrypted is toggled
  void Cipher::ToggleEncrypted(){
    if(!m_isEncrypted){
       m_isEncrypted = true;
    }
    else{
        m_isEncrypted = false;
    }
  }
  // Name: ToString
  // Desc - A purely virtual function that returns the string of the object type
  // Preconditions - The object exists
  // Postconditions - The subtype is returned
  //virtual string Cipher::ToString() = 0;
  // Name: FormatOutput
  // Desc - A purely virtual function that returns the formatted data for Output
  // Preconditions - The object exists
  // Postconditions - The type, message, and key are output
  //virtual string Cipher::FormatOutput() = 0;
  // Name: Overloaded << Operator
  // Desc - Outputs the message
  // Preconditions - The object exists
  // Postconditions - The message from the object is returned
  ostream &operator<<( ostream &output, Cipher &C){
    output << C.m_message;
    return output;
  }
//private:
  //string m_message; //The message being encrypted/decrypted
  //bool m_isEncrypted; //Indicates if the message is encrypted/decrypted
//};
