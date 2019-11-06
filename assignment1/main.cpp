/******************************
/ James Bertel - berte005@cougars.csusm.edu
/ CS 211 – CRN 40978
/ Dr. Ahmad R. Hadaegh
/ Assignment #1: Encryption & Decryption
/ September 25, 2018
/
/ This program performs the encryption/decryption of a text
/ file. 
/ INPUT: The user will input whether or not they wish to encrypt
/ or decrypt a message as well as express which procedure they 
/ would like to be executed (rotation or cryptogram).
/ OUTPUT: The program will output the encrypted/decrypted message
/ into separate files.
/******************************/
#include <iostream>  
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

void securityDriver();
void toLower(string & word);
void DoEncryptionUsingRot(int & RotNum);
int getRotNumber();
string InputFileName();
string OutputFileName();
vector<string> placeFileIntoVector(const string fileName);
vector<string> EncryptTheVectorUsingRot(const int RotNum, const vector<string> OriginalData);
void placeVectorIntoFile(const string fileName, const vector<string> newVector);
void DoDecryptionUsingRot(const int RotNum);
vector<string> DecryptTheVectorUsingRot(const int RotNum, const vector<string> EncryptedData);
void DoEncryptionUsingCryptogram();
vector<string> EncryptTheVectorUsingCrypto(const vector<string> OriginalData);
void DoDecryptionUsingCryptogram();
vector<string> DecryptTheVectorUsingCrypto(const vector<string> EncryptedData);

//------------------------------------------------------------------------------

int main()
{
  securityDriver();
  return 0;
}

/*********************
/ Started: 9/18/18
/ Completed: 9/19/18
/ This function asks the user whether they would like to execute
/ an encryption or decryption function, as well as which method
/ they would prefer to use (Rotation or Cryptogram).
/********************/
void securityDriver()
{
  char choice = ' ';
  int rotationNum = 0; //number to use between rotation methods

  do{ 
    cout << endl;
    cout << "A: Do Encryption Using Rot" << endl;
    cout << "B: Do Decryption Using Rot" << endl;
    cout << "C: Do Encryption Using Cryptogram" << endl;
    cout << "D: Do Decryption Using Cryptogram" << endl;
    cout << "Q: Quit the Program" << endl;
    cout << "\nEnter a choice: ";
    cin >> choice;
    
      if((choice == 'A')||(choice == 'a'))
	DoEncryptionUsingRot(rotationNum);

      else if((choice == 'B')||(choice== 'b'))
	DoDecryptionUsingRot(rotationNum);

      else if((choice == 'C')||(choice== 'c'))
	DoEncryptionUsingCryptogram;

      else if((choice == 'D')||(choice== 'd'))
	DoDecryptionUsingCryptogram;

  }while( (choice != 'Q')&&(choice != 'q') );
}

/*****************************
/ phrase = message or phrase to convert to lowercase
/ Started: 9/6/18
/ Completed: 9/6/18
/ This function converts a 
/ string to lowercase letters only.
/****************************/
void toLower(string & phrase)
{
  //use ASCII to convert uppercase to lowercase
  int offset = 'a' - 'A';

  for(int i = 0; i < phrase.size(); i++)
    {
      //check for capital letters while excluding spaces
      if(phrase[i] <= 'Z' && phrase[i] >= 'A')
        phrase[i] = (char)(phrase[i] + offset);
    }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*****************************************************************************
/ RotNum: Rotation number to use in encryption process
/ Started: 9/6/18
/ Completed: 9/24/18
/ This function encrypts a message using the "rot" (rotation) method.
/****************************************************************************/
void DoEncryptionUsingRot(int & RotNum)
{
  RotNum = getRotNumber();
  string fileName = InputFileName(); 
  vector <string> EncryptedVector, OriginalData;
  OriginalData = placeFileIntoVector(fileName); 
  EncryptedVector = EncryptTheVectorUsingRot(RotNum, OriginalData);
  fileName = OutputFileName();
  placeVectorIntoFile(fileName, EncryptedVector); 
}

/*****************************
/ [No Parameters]
/ Started: 9/18/18 
/ Completed: 9/18/18
//This function asks the user for the rotation number.
/****************************/
int getRotNumber()
{
  int rotKey;
  do
    {
      cout << "Enter encryption key: ";
      cin >> rotKey;
    }while(rotKey <= 0 || rotKey >= 26);

  return rotKey;
}

/*****************************
/ [No Parameters]
/ Started: 9/20/18
/ Completed: 9/23/18
/ This function receives the name of the file 
/ that the user would like to encrypt or decrypt.
/****************************/
string InputFileName()
{
  string fileName;

  cout << "Enter input file name: ";
  cin >> fileName;

  if(! fileName.c_str())
    return fileName;
}

/*****************************
/ [No Parameters]
/ Started: 9/23/18
/ Completed: 9/23/18
/ This function receives the name of the file that 
/ the user would like to output their vector into.
/****************************/
string OutputFileName()
{
  string fileName;

  cout << "Enter output file name: ";
  cin >> fileName;

  return fileName;
}

/*****************************
/ fileName = name of file to place vector into
/ Started: 9/19/18
/ Completed: 9/20/18
/ This function receives data from the file and stores it
/ into a vector to be encrypted/decrypted.
/****************************/
vector<string> placeFileIntoVector(const string fileName)
{
  ifstream fin;
  string data; //temporary variable to store file data

  fin.open(fileName.c_str());
  vector<string> OriginalData; //vector storing the file data

  while(fin >> data)
    {
      toLower(data); //make data lowercase
      OriginalData.push_back(data); //put data in vector
    }

  fin.close();
  return OriginalData;
}

/*************************************************
/ RotNum: Rotation number to use in encryption process
/ Original Data: Vector data that will be encrypted
/ Started: 9/20/18
/ Completed: 9/20/18
/ This function encrypts the original vector 
/ & and places the encrypted data into a new vector.
/************************************************/
vector<string> EncryptTheVectorUsingRot(const int RotNum, const vector<string> OriginalData)
{
  vector<string> EncryptedData; //vector to put encrypted data in

  //go through each word in the original vector
  for(int i = 0; i < OriginalData.size(); i++)
    {
      string originalWord = OriginalData[i].substr(0, OriginalData[i].size());
      string encryptedWord = ""; //word that will be encrypted

      //go through each originalWord letter by letter
      for(int j = 0; j < originalWord.size(); j++)
	{
	  int encryptedChar; //typecast of character to be placed into encrypted vector

	  if(originalWord[j] >= 'a' && originalWord[j] <= 'z')
	    {
	      //encrypt the letter and place it into a local variable
	      encryptedChar = originalWord[j] + RotNum;

	      //fix rotation of numbers that go outside the ASCII alphabet and/or ASCII table
	      if(encryptedChar > 122)
		{
		  encryptedChar -= 26;
		}
	      else if(encryptedChar < 97 && encryptedChar > 0) 
		encryptedChar += 26;
	    }
	  
	    //if (char)encryptedChar not an alphabetical letter --> place in vector non-encrypted
	  else 
	    encryptedChar = originalWord[j];

	  //place (char)encryptedChar into encrypted word
	  encryptedWord += (char)encryptedChar;
	}   
   
      //place encrypted word into vector
      EncryptedData.push_back(encryptedWord);
    }

  return EncryptedData;
}

/*****************************
/ fileName: name of file vector will be outputed into
/ newVector: vector that will be placed into file
/ Started: 9/19/18 
/ Completed: 9/19/18
/ This function places the encrypted vector into an output file.
*****************************/
void placeVectorIntoFile(const string fileName, const vector<string> newVector)
{
  ofstream fileOut;
  fileOut.open(fileName.c_str());

  for(int i = 0; i < newVector.size(); i++)
    fileOut << newVector[i] << " ";

  fileOut.close();
}

/*****************************************************************************
/ RotNum: Rotation number to use in decryption
/ Started: 9/12/18
/ Completed: 9/24/18
/ This function decrypts a message that was
/ encrypted using the "rot" (rotation) method.
/****************************************************************************/
void DoDecryptionUsingRot(const int RotNum)
{
  string fileName = InputFileName();
  vector <string> DecryptedVector, EncryptedData;
  EncryptedData = placeFileIntoVector(fileName);
  DecryptedVector = DecryptTheVectorUsingRot(RotNum, EncryptedData);
  fileName = OutputFileName();
  placeVectorIntoFile(fileName, DecryptedVector);
}

/*************************************************
/ RotNum: Rotation number to use in encryption process
/ EncryptedData: Vector data that will be decrypted
/ Started: 9/23/18
/ Completed: 9/23/18
/ This function decrypts the encrypted vector 
/ & places the decrypted data into a new vector.
/************************************************/
vector<string> DecryptTheVectorUsingRot(const int RotNum, const vector<string> EncryptedData)
{
  vector<string> DecryptedData; //vector to put decrypted data in

  //go through each word in the encrypted vector
  for(int i = 0; i < EncryptedData.size(); i++)
    {
      string encryptedWord = EncryptedData[i].substr(0, EncryptedData[i].size());
      string decryptedWord = ""; //word that will be decrypted                                                                                                                    

      //go through each encryptedWord letter by letter
      for(int j = 0; j < encryptedWord.size(); j++)
	{
	  int decryptedChar; //typecast of character to be placed into encrypted vector
	  if(encryptedWord[j] >= 'a' && encryptedWord[j] <= 'z')
	    {
	      //decrypt the letter and place it into a local variable
	      decryptedChar = encryptedWord[j] - RotNum;
	      
	      //fix rotation of numbers that go outside the ASCII alphabet and/or ASCII table
	      if(decryptedChar > 122)
		{
		  decryptedChar -= 26;
		}
	      else if(decryptedChar < 97 && decryptedChar > 0)
		decryptedChar += 26;
	    }
	  
	  //if (char)decryptedChar not an alphabetical letter --> place in vector non-encrypted                                                                                                            
	  else
	    decryptedChar = encryptedWord[j];

	  //place (char)decryptedChar into decrypted word                                                                                                                                                  
	  decryptedWord += (char)decryptedChar;
	}
      //place decrypted word into vector
      DecryptedData.push_back(decryptedWord);
    }
  return DecryptedData;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*****************************************************************************
/ [No Parameters]
/ Started: 9/6/18
/ Completed: 9/23/18
/ This function encrypts a message using the cryptogram procedure.
/****************************************************************************/
void DoEncryptionUsingCryptogram()
{
  string fileName = InputFileName();
  vector <string> EncryptedVector, OriginalData;
  OriginalData = placeFileIntoVector(fileName);
  EncryptedVector = EncryptTheVectorUsingCrypto(OriginalData);
  fileName = OutputFileName();
  placeVectorIntoFile(fileName,EncryptedVector);
}

/*************************************************
/ OriginalData: Vector data to be encrypted
/ Started: 9/23/18  
/ Completed: 9/24/18
/ This function...
/************************************************/
vector<string> EncryptTheVectorUsingCrypto(const vector<string> OriginalData)
{}

//------------------------------------------------------------------------------

/*****************************************************************************
/ [No Parameters]
/ Started: 9/12/18
/ Completed: 9/24/18
/ This function decrypts a message that was 
/ encrypted using the cryptogram procedure
/****************************************************************************/
void DoDecryptionUsingCryptogram()
{
  string fileName = InputFileName();
  vector <string> DecryptedVector, EncryptedData;
  EncryptedData = placeFileIntoVector(fileName);
  DecryptedVector = DecryptTheVectorUsingCrypto(EncryptedData);
  fileName = OutputFileName();
  placeVectorIntoFile(fileName, DecryptedVector);
}

/*************************************************
/ EncryptedData: Vector data that will be decrypted
/ Started: 9/23/18
/ Completed: 9/24/18
/ This funciton...
/************************************************/
vector<string> DecryptTheVectorUsingCrypto(const vector<string> EncryptedData)
{}
