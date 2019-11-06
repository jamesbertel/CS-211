/*********************************************
/ James Bertel - berte005@cougars.csusm.edu
/ CS 211 - CRN 40978
/ Dr. Ahmad R. Hadaegh
/ Assignment #2: Dictionary
/ October 30, 2018
/
/ This function takes words from a file and 
/ puts each word into a file, sorted in
/ alphabetical order.
/ It then adds, deletes, prints, and searches
/ for words. It can also check a different
/ file and spellcheck each word.
/*********************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Dictionary
{
protected:
  const int maxWordsInDict;
  const int maxWordsPerFile;
  int totalWordsInDict;
  int numOfWordsInFile[26];
  static bool failure;
  static bool success;
  
public:
  Dictionary();
  Dictionary(int dictMaxWords, int fileMaxWords);
  bool AddAWord(string word);
  bool DeleteAWord(string word);
  bool SearchForWord(string word);
  bool PrintAFileInDict(string filename);
  bool SpellChecking(string fileName);
  bool InsertWordsIntoDict(string fileName);
  void ProcessTransactionFile();
  bool enoughSpaceInDict(string word);
  bool enoughSpaceInFile(string word);
  string getTheFileName(string word);
  char toUpper(char let);
  char toLower(char let);
  void PlaceWordIntoFile(string word);
  void toLowercase(string & word);
  void IncCounterInFileAndDict(string word);
  void DecCounterInFileAndDict(string word);
  void ReplaceFileWithVector(string word, vector <string> TempVec);
  bool DeleteWordFromVector(string word, vector <string> & TempVec);
  vector <string> PutFileInVector(string word);
  void CheckWord(string WordBeingChecked);
};

bool Dictionary::failure = false;
bool Dictionary::success = true;

//------------------------------------------------------------------
//------------------------------------------------------------------


/*******************************************************************
/ CONSTRUCTORS
/******************************************************************/
Dictionary::Dictionary():
  maxWordsInDict(10000), maxWordsPerFile(100)
{
  totalWordsInDict = 0;
  for(int i = 0; i < 26; i++)
    numOfWordsInFile[i] = 0;
}

//---------
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):
  maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords)
{
  totalWordsInDict = 0;
  for(int i = 0; i < 26; i++)
    numOfWordsInFile[i] = 0;
}

//------------------------------------------------------------------
//------------------------------------------------------------------

/*******************************************************************
/ Started: 10/12/18
/ Completed: 10/19/18 
/ This function opens the appropriate file and tries to
/ add the word that is passed to this function into that
/ file.
/******************************************************************/
bool Dictionary::AddAWord(string word)
{
  toLowercase(word);

  //check to see if there is room in file & dictionary
  if(!enoughSpaceInDict(word) || !enoughSpaceInFile(word))
    return failure; 
  if (SearchForWord(word) == success)
    return failure;

  //place word in proper file
  PlaceWordIntoFile(word);

  //increment counter
  IncCounterInFileAndDict(word);
  return success;
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function checks to see if there is enough space
/ in the dictionary to add words
/******************************************************************/
bool Dictionary::enoughSpaceInDict(string word)
{
  if(maxWordsInDict == totalWordsInDict)
    return failure;

  return success;
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function checks to see if there is enough space in
/ the file to add more words
/******************************************************************/
bool Dictionary::enoughSpaceInFile(string word)
{
  char ch = toUpper(word[0]);
  int index = ch - 'A';
  if(maxWordsPerFile == numOfWordsInFile[index])
    return failure;

  return success;
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function gets the name of the file that will
/ be used.
/******************************************************************/
string Dictionary:: getTheFileName(string word)
{
  string filename = "#.txt";
  filename[0] = toUpper(word[0]);
  return filename;
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function makes a letter uppercase.
/******************************************************************/
char Dictionary::toUpper(char let)
{
  int offset = 'A' - 'a';
  if(let >= 'a' && let <= 'z') //if letter is at least Z (aka lowercase)
    let = (char)(let + offset);

  return let;
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function makes a letter lowercase.
/******************************************************************/
char Dictionary::toLower(char let)
{
  int offset = 'a' - 'A';
  if(let >= 'A' && let <= 'Z') //if letter is at least Z (aka lowercase)
    let = (char)(let + offset);

  return let;
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function attempts to place a word into a file.
/******************************************************************/
void Dictionary::PlaceWordIntoFile(string word)
{
  ofstream fout;
  string filename = getTheFileName(word);
  fout.open(filename.data(), ios::app);
  
  fout << word << endl;
  fout.close();
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function makes a word entirely lowercase.
/******************************************************************/
void Dictionary::toLowercase(string & word)
{
  for(int i = 0; i < word.size(); i++)
    word[i] = toLower(word[i]);
}

/*******************************************************************
/ Started & Completed: 10/12/18 
/ This function increments the word's respective counters.
/******************************************************************/
void Dictionary::IncCounterInFileAndDict(string word)
{
  totalWordsInDict++;
  
  char letter = toUpper(word[0]);
  int index = letter - 'A';
  numOfWordsInFile[index]++;
}

//------------------------------------------------------------------

/*******************************************************************
/ Started: 10/19/18
/ Completed: 10/19/18
/ This function opens the appropriate file where the word that
/ you are looking for might be kept.
/ Then it places all the words into a vector and looks for the word
/ in that vector.
/ If the word is in the vector, it gets deleted, and the 
/ modified vector is inserted back into the appropriate file.
/******************************************************************/
bool Dictionary::DeleteAWord(string word)
{
  vector <string> TempVec = PutFileInVector(word);
  bool wordDeleted = DeleteWordFromVector(word, TempVec);
  if(wordDeleted == success)
    {
      ReplaceFileWithVector(word, TempVec);
      DecCounterInFileAndDict(word);
      return success;
    }
  else
    return failure;
}

/*******************************************************************
/ Started & Completed: 10/19/18
/ This functions puts the contents of a file in a vector.
/******************************************************************/
vector <string> Dictionary::PutFileInVector(string word)
{
  vector <string> TempVec;
  ifstream fin;
  string filename = getTheFileName(word);
  fin.open(filename.data(), ios::app);
  string temp;

  while(fin >> temp)
    TempVec.push_back(temp);
  fin.close();
  
  return TempVec;
}

/*******************************************************************
/ Started & Completed: 10/19/18
/ This function deletes a word from a vector.
/******************************************************************/
bool Dictionary::DeleteWordFromVector(string word, vector <string> & TempVec)
{
  for(int i = 0; i < TempVec.size(); i++)
    {
      if(TempVec[i] == word)
	{
	  TempVec.erase(TempVec.begin() + i);
	  return success;
	}
    }
  return failure;
}

/*******************************************************************
/ Started & Completed: 10/19/18 
/ This function replaces a file with the updated vector that has
/ removed the word. 
/******************************************************************/
void Dictionary::ReplaceFileWithVector(string word, vector <string> TempVec)
{
  ofstream fout;
  string filename = getTheFileName(word);
  fout.open(filename.data());

  for(int i = 0; i < TempVec.size(); i++)
      fout << TempVec[i] << endl;
  fout.close();
}

/*******************************************************************
/ Started & Completed: 10/19/18  
/ This function decrements the word's respective counters.
/******************************************************************/
void Dictionary::DecCounterInFileAndDict(string word)
{
  totalWordsInDict--;
  char ch = toUpper(word[0]);
  int index = ch - 'A';
  numOfWordsInFile[index]--;
}

//------------------------------------------------------------------

/*******************************************************************
/ Started & Completed: 10/20/18
/ This function searches for a word within a file.
/******************************************************************/
bool Dictionary::SearchForWord(string word)
{
  ifstream fin;
  string filename = getTheFileName(word);
  fin.open(filename.data(), ios::app);
  string temp;

  while(fin >> temp)
    {
      if(temp == word)
	{
	  fin.close();
	  return success;
	}
    }

  fin.close();
  return failure;
}

//------------------------------------------------------------------

/*******************************************************************
/ Started & Completed: 10/20/18 
/ This function prints a file in the dictionary.
/******************************************************************/
bool Dictionary::PrintAFileInDict(string filename)
{
  ifstream fin;
  fin.open(filename.data());
  string temp;

  if(!fin)
    return failure;
  else
    {
      int counter = 0;

      while(fin >> temp)
	{
	  //endl if five words already displayed
	  //on one line
	  if(counter % 5 == 0)
	    cout << endl;

	  cout << temp << " ";
	  counter++;
	}
      cout << endl;
      fin.close();
      return success;
    }
}

//------------------------------------------------------------------

/*******************************************************************
/ Started: 10/20/18 
/ Completed: 10/27/18
/ This file checks the spelling of word in a file, and prints out
/ incorrectly spelled words
/******************************************************************/
bool Dictionary::SpellChecking(string fileName)
{
  ifstream fin;
  fin.open(fileName.data());

  if(!fin)
    return failure;
  else
    {
      string WordBeingChecked;
      while(fin >> WordBeingChecked)
	{
	  toLowercase(WordBeingChecked);
	  CheckWord(WordBeingChecked);
	}
      cout << endl;
    } 
	  
  fin.close();
  return success;
}

/*******************************************************************
/ Started & Completed: 10/27/18
/ This song checks to see if a word matches the correctly
/ spelled word in the dictionary.
/******************************************************************/
void Dictionary::CheckWord(string WordBeingChecked)
{
  ifstream dict;
  string CorrectWord;
  bool found = failure;
  
  toLowercase(WordBeingChecked);
  string dictionary = getTheFileName(WordBeingChecked);
  dict.open(dictionary.data());
  
  if(!dict)
    cout << WordBeingChecked << endl;
  else
    {
      //check if word is in dictionary
      while(dict >> CorrectWord && found == failure)
	  if(WordBeingChecked == CorrectWord)
	    found = success;
      
      //if not, display word
      if(found == failure)
	cout << endl << WordBeingChecked;
      else
	found = failure;
      
      dict.close();
    }
}
//------------------------------------------------------------------

/*******************************************************************
/ Started: 10/20/18
/ Completed: 10/27/18 
/ This function inserts words from a file into
/ a dictionary that is split into multiple files, organized
/ by the first letter of each word.
/******************************************************************/
bool Dictionary::InsertWordsIntoDict(string fileName)
{
  ifstream fin;
  fin.open(fileName.data());

  if(!fin)
    return failure;
  else
    {
      string word;

      while(fin >> word)
	{
	  toLowercase(word);
	  bool WordIsInFile = SearchForWord(word);

	  //if word is not already in dictionary
	  //then place it in dictionary
	  if(WordIsInFile == failure)
	    {
	      PlaceWordIntoFile(word);
	      IncCounterInFileAndDict(word);
	    }
	}
      fin.close();
      return success;
    }
}

//------------------------------------------------------------------

/*******************************************************************
/ Started & Completed: 10/19/18 
/ This funtion processes the transaction file.
/******************************************************************/
void Dictionary::ProcessTransactionFile()
{
  ifstream fin;
  string command;
  string word;
  bool check;

  fin.open("transaction.txt");
  
  if(!fin)
    cout << "Error: File Does Not Exist" << endl;
  else
    {
      while(fin >> command && fin >> word)
	{ 
	  if(command == "AddW")
	    check = AddAWord(word);
	  else if(command == "InsertF")
	    check = InsertWordsIntoDict(word);
	  else if(command == "PrintF")
	    check = PrintAFileInDict(word);
	  else if(command == "DeleteW")
	    check = DeleteAWord(word);
	  else if(command == "SpellCheck")
	    check = SpellChecking(word);
	  else if(command == "SearchW")
	    check = SearchForWord(word);
	  else
	    {cout << "ERROR: NO COMMAND. CHECK FILE." << endl; break;}
	}	  
    }
  cout << endl;
  fin.close();
}

//------------------------------------------------------------------

int main()
{
  Dictionary DictForCS211;
  DictForCS211.ProcessTransactionFile();
  return 0;
}

