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
  string toLowercase(string word);
  void IncCounterInFileAndDict(string word);
  void DecTheCounterInFileAndDict(string word);
  void ReplaceFileWithVector(string word, vector <string> TempVec);
  bool DeleteWordFromVector(string word, vector <string> &TempVec);
  vector <string> PutFileInVector(string word);
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

bool Dictionary::AddAWord(string word)
{
  word = toLowercase(word);

  //check to see if there is room in file & dictionary
  if(!enoughSpaceInDict(word) || !enoughSpaceInFile(word))
    { cout << "one";return failure;} 
  if (SearchForWord(word) == success)
    {cout << "two"; return failure;}

  //place word in proper file
  PlaceWordIntoFile(word);

  //increment counter
  IncCounterInFileAndDict(word);
  return success;
}

bool Dictionary::enoughSpaceInDict(string word)
{
  if(maxWordsInDict == totalWordsInDict)
    return failure;

  return success;
}

bool Dictionary::enoughSpaceInFile(string word)
{
  char ch = toUpper(word[0]);
  int index = ch - 'A';
  if(maxWordsPerFile == numOfWordsInFile[index])
    return failure;

  return success;
}

string Dictionary:: getTheFileName(string word)
{
  string filename = "#.txt";
  filename[0] = toUpper(word[0]);
  return filename;
}

char Dictionary::toUpper(char let)
{
  int offset = 'A' - 'a';
  if(let >= 'a' && let <= 'z') //if letter is at least Z (aka lowercase)
    let = (char)(let + offset);

  return let;
}

char Dictionary::toLower(char let)
{
  int offset = 'a' - 'A';
  if(let >= 'A' && let <= 'Z') //if letter is at least Z (aka lowercase)
    let = (char)(let + offset);

  return let;
}

void Dictionary::PlaceWordIntoFile(string word)
{
  ofstream fout;
  string filename = getTheFileName(word);
  fout.open(filename.data(), ios::app);
  
  fout << word << endl;
  fout.close();
}

string Dictionary::toLowercase(string word)
{
  for(int i = 0; i < word.size(); i++)
    word[i] = toLower( word[i] );

  return word;
}

void Dictionary::IncCounterInFileAndDict(string word)
{
  totalWordsInDict++;
  
  char letter = toUpper(word[0]);
  int index = letter - 'A';
  numOfWordsInFile[index]++;
}

//------------------------------------------------------------------



bool Dictionary::DeleteAWord(string word)
{
  vector <string> TempVec = PutFileInVector(word);

  bool wordDeleted = DeleteWordFromVector(word, TempVec);
  if(wordDeleted == success)
    {
      ReplaceFileWithVector(word, TempVec);
      DecTheCounterInFileAndDict(word);
      return success;
    }
  else
    return failure;
}

vector <string> Dictionary::PutFileInVector(string word)
{
  vector <string> TempVec;
  ifstream fin;
  string filename = getTheFileName(word);
  fin.open(filename.data(), ios::app);

  string temp;

  while(fin >> temp)
    TempVec.push_back(temp);

  return TempVec;
}

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

void Dictionary::ReplaceFileWithVector(string word, vector <string> TempVec)
{
  ofstream fout;
  string filename = getTheFileName(word);
  fout.open(filename.data());

  for(int i = 0; i < TempVec.size(); i++)
      fout << TempVec[i] << endl;
  fout.close();
}

void Dictionary::DecTheCounterInFileAndDict(string word)
{
  totalWordsInDict--;
  char ch = toUpper(word[0]);
  int index = ch - 'A';
  numOfWordsInFile[index]--;
}

//------------------------------------------------------------------


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

bool Dictionary::PrintAFileInDict(string filename)
{
  ifstream fin;
  fin.open(filename.data());
  string temp;

  if(!fin)
    return failure;
  else
    {
      int counter = 1;
      cout << endl;

      while(fin >> temp)
	{
	  cout << temp << " ";
	  counter++;

	  //make sure only 5 words per line
	  if(counter == 5)
	    {
	      cout << endl;
	      counter = 1;
	    }
	}

      cout << endl;
      fin.close();
      return success;
    }
}

//------------------------------------------------------------------


bool Dictionary::SpellChecking(string fileName)
{
  ifstream fin;
  fin.open(fileName.data());

  if(!fin)
    return failure;
  else
    {
      string temp;
      ifstream dict;
      string check;
      bool found = failure;

      while(fin >> temp)
	{
	  temp = toLowercase(temp);
	  string dictionary = getTheFileName(temp);
	  
	  dict.open(dictionary.data());
	  
	  while(dict >> check && found == false)
	    if(temp == check)
	      found == true;
	  
	  if(found == false)
	    cout << temp << " ";
	}
    } 
	  
  fin.close();
  return success;
}

//------------------------------------------------------------------


bool Dictionary::InsertWordsIntoDict(string fileName)
{
  ifstream fin;
  fin.open(fileName.data());

  if(!fin)
    return failure;
  else
    {
      string temp;

      while(fin >> temp)
	{
	  bool WordIsInFile = SearchForWord(temp);

	  if(WordIsInFile == failure)
	    {
	      bool tempIsAWord = success;
	      temp = toLowercase(temp);
	      
	      for(int i = 0; i < temp.size(); i++)
		{
		  if(temp[i] < 'a'|| temp[i] > 'z')
		    {
		  tempIsAWord = failure;
		  i = temp.size();
		    }
		}
	      
	      if(tempIsAWord==success)
		PlaceWordIntoFile(temp);
	    }
	}
      fin.close();
      return success;
    }

  return failure;
}

//------------------------------------------------------------------


void Dictionary::ProcessTransactionFile()
{
  ifstream fin;
  string command;
  string word;
  bool check = failure;

  fin.open("transaction.txt");


  if(!fin)
    cout << "Error:file DNE" << endl;
  else
    {
      fin >> command;
      fin >> word;
      while(fin)
	{ //call proper function based on command
	  if(command == "AddW")
	    check = AddAWord(word);
	  else if(command == "InsertF")
	    check = InsertWordsIntoDict(word);
	  else if(command == "PrintF")
	    check = PrintAFileInDict(word);
	  else if(command == "DeleteW")
	    check = DeleteAWord(word);
	  else if(command == "SpellCheck")
	    check = success;//SpellChecking(word);
	  else if(command == "SearchW")
	    check = SearchForWord(word);
	  else
	    {cout << "ERROR: NO COMMAND. CHECK FILE." << endl; break;}

	  if(check == success)
	    cout << command << " Successfully Executed.\n";
	  else //check == failure
	    cout << command << " Failed to execute.\n";

	  fin >> command;
	  fin >> word;
	}
    }
  cout << endl;
  fin.close();
}

//------------------------------------------------------------------

int main()
{
  Dictionary  DictForCS211;
  DictForCS211.ProcessTransactionFile();
  return 0;
}

