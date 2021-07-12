
using namespace std;
#include <iostream>
#include<fstream>
#include <vector>
//#include <sstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include "HashTable.h"
#include "BinarySearchTree.h"

	struct BNode {
	string word;
	int lineNum;
	bool operator < (BNode otherStruct) const {
	return ( word < otherStruct.word );
	}
	};


	typedef BinarySearchTree<BNode> BST;
	ostream & operator << (ostream & out, BNode & temp) {
		out << temp.word << " " << temp.lineNum;
	return out;
	}


 	void StartUp(int argc, char *argv[],HashTable &dict, vector <string> &input, BST &bt, HashTable &ignoreWord); //prototype for StartUp method
	void loadHash(HashTable &dict); //prototype for loadHash method
        void OpenFile(ifstream &infile, char *argv[], int argc); //prototype for OpenFile method
	void processLines(HashTable &dict, vector <string> &input, BST &bt, HashTable &ignoreWord); //prototype for processLines method
	void splitUp(string currentLine, vector <string> &words); //prototype for splitUp method
	void makeLowerCase(vector <string> &words); //prototype for lowerCase method
	void misspelledWords(BST &bt); //prototype for misspelledWords method
	void suggestWord(HashTable &dict, string word); //prototype for suggestWord
	void add(string word); //prototype for add word to end of dicitonary method
	void printMenu(HashTable &dict,string word, int currLineNum, HashTable &ignoreWord,BST &bt);//prototyoe for printMenu method
	void selectOption(char letter, HashTable &dict, string word, HashTable &ignoreWord, BST &bt, int CurrLineNum); //prototype for selectOption method



	bool addLetter(string word,HashTable &dict);
	bool removeLetter(string word, HashTable &dict);	




int main(int argc, char *argv[]){
HashTable dict = HashTable(500);
HashTable ignoreWord = HashTable(500);
vector <string> input;
BNode nf = {"ZZZ",-1};
BST bt(nf);
//system("clear");
StartUp(argc,argv,dict,input,bt,ignoreWord);
return 0;
}

//Precondition: A valid hashtable of dictionary words and ignored words, a vector of strings, a binary search tree, and command line argumentswill be passed in as a parameter.
//Postcondition: Will get the hashtable initalized and open the file and start processing each line one by one.
 void StartUp(int argc, char *argv[], HashTable &dict, vector <string> &input, BST &bt, HashTable &ignoreWord){



		  loadHash(dict); //load hashtable with the dict.txt input file
             
		  ifstream infile; //infile

                OpenFile(infile, argv, argc); //call OpenFile method
                string s; //string s

                 while (getline(infile, s)){ //getting each line
                       //load line by line of the file that you are trying to spell check
                       input.push_back(s);

                }
                //do whatever you need to do after here
                


		processLines(dict, input, bt, ignoreWord);
        }

//Precondition: A valid hashtable will be passed in as a parameter.
//Postcondition: The hashtable will be intialized with the words in the master dictionary file.
 void loadHash(HashTable &dict){
	

	fstream dictionary;
	dictionary.open("dict.txt", ios::in);
	string s1;
	while (getline(dictionary,s1)){

		dict.insert(s1);

	}


	}

//Precondition: A valid ifstream and command line arguments will be passed in as a parameter.
//Postcondition:Will open the file that is sent to the command line if there is one.
 void OpenFile(ifstream &infile,char *argv[], int argc){

                if(argc == 1){ //if argc equals 1
                cout << " No Filename Given -- Program Exiting" << endl; //they did not enter a filename and display error message
                exit(1); //exit
                }
		system("clear");
                string namef =argv[1]; //string for filename

                infile.open(namef.c_str(),ifstream::in); //open up file

        }

//Precondition: A valid hashtable of dictionary words and ignore words, vector of strings, and a binary search tree will be passed in as a paramter.
//Postcondition: The method will process each line in the file until the end of the file.
 void processLines(HashTable &dict, vector <string> &input, BST &bt, HashTable &ignoreWord){

	string currentLine;
	vector <string> words;
	int currLineNum;


	for(int i = 0; i < input.size(); i++){

		currLineNum = i+1;
		currentLine = input.at(i);
		splitUp(currentLine, words);
		makeLowerCase(words);
	


if(words.at(0).find_first_not_of(' ') != std::string::npos)
{
	for(int j = 0; j < words.size(); j++){ //words.size

		if(dict.find(words.at(j)) == false){
	

		system("clear");
		printMenu(dict, words.at(j), currLineNum, ignoreWord,bt);

		}

	}}

	words.clear();
	}
cout << endl;
cout <<	" ***  All Spell Checking Has Now Been Completed ***" << endl;
cout << endl;
cout <<       " Now Exiting Program..." << endl;
cout << endl;

	}
//Precondition: A valid vector of strings and a string will be passed in as a parameter.
//Postcondition: The method will split the string into individual words, and insert them into the vector.
  void splitUp(string currentLine, vector <string> &words){


	string word;
	string x;

	for(int i = 0; i < currentLine.length(); i++){

		if (currentLine.at(i)  == ' ')
     		 {


			words.push_back(word);
           		
            word = "";
        }
      	  else {

		if(isalpha(currentLine[i])){
            word = word + currentLine.at(i);}
        }
    	


}

	words.push_back(word);

	
	}


//Precondition: A valid vector of string will be passed in as a parameter.
//Postcondition: The method will make all the elements in the vector lowercase.

	void makeLowerCase(vector<string> &words){

		
		for(int i = 0; i < words.size(); i++){

		string current = words.at(i);
	

		transform(current.begin(), current.end(), current.begin(), ::tolower);


		words.at(i) = current;
	
		}

		}
//Precondition: A valid binary search tree will be passed in a paramater.
//Postcondition: The method will output what is in the binary search tree to the output file of "notfound.txt".
  void misspelledWords(BST &bt){

	ofstream outfile("notfound.txt");
	bt.printTree(outfile);

	}
//Precondition: A valid  hashtable of the dicitonary words and string will be passed as a parameters.
//Postcondition: The method will suggest a word if it finds it in the hashtable of the master dictionary words.
  void suggestWord(HashTable &dict, string currentWord){
      string word = currentWord;
        string wordN = "";
	bool found;

        for (int i = 0;  i < word.length()-1;  i++)
        {
                wordN += word.substr(0, i);
                wordN += word[i+1];
                wordN += word[i];
                wordN += word.substr(i+2);
    

                  if (dict.find(wordN)== true) //search on your hypothesis
                                  {
                                                    cout << endl;      
						    cout << "Suggested Spelling is: " << wordN << endl;
                                                                                  found = true;
										 // wordN = "";
                                                                                                  }
                                                                                                  

             wordN = ""; // reset word after you this if statement once we have a dictionary object
                        }

//////////////////////extra////////////////////////////////////
	if(found == false){

	found =	addLetter(word,dict);} //word is missing letters


	if(found == false){
	found =	removeLetter(word,dict);} //word needs more letters
		
		if(found == false){
		 cout << endl;
		 cout << "No Suggested Spellings Found in Dictionary." << endl;

		}
                


	}
//Precondition: A valid  hashtable of the dicitonary words and ignored words, string, integer, and binarysearchtree will be passed as parameters.
//Postcondition: The method will successfully print the menu with the misspelled word and line number.
  void printMenu(HashTable &dict, string word, int currLineNum, HashTable &ignoreWord, BST &bt){

 if(ignoreWord.find(word) == false){
	char letter;
	cout << "!@#$%^&*(){} THE SPELL CHECKER PROGRAM !@#$%^&*(){}" << endl;
	cout << endl;
	cout << word << " On Line " << currLineNum << " Was Not Found in Dictionary" << endl;
	cout << endl;
	cout << "A) Add the Word To Dictionary" << endl;
	cout << "I) Ignore Word, and Skip Future References" << endl;
	cout << "G) Go On To Next Word" << endl;
	cout << "S) Search For A Suggested Spelling" << endl;
	cout << "Q) Quit Spell Checking File" << endl;
	cout << endl;
	cout << "Selection: ";
	cin >> letter;
	selectOption(letter,dict, word,ignoreWord,bt, currLineNum); 

         }
	
}

//Precondition: A valid character, hashtable of the dicitonary words and ignored words, string, integer, and binarysearchtree will be passed as parameters.
//Postcondition: The method will successfully process the character that is sent, and choose the option accordingly.
 void selectOption(char letter, HashTable &dict, string word, HashTable &ignoreWord,BST &bt, int currLineNum){

	char letterloc;
	BNode bN = {word, currLineNum};
                BNode result = bt.find(bN);

	 switch((toupper(letter))) //switch statement for each command
                        {

                                case 'A':{ //case A
                 
                            	dict.insert(word);	
				add(word);
				      if(result.word == "ZZZ"){

		                      bt.insert(bN);}
				       misspelledWords(bt);

				break;} 

                                case 'I' : //case I
                                {
                                

				 ignoreWord.insert(word);
				  if(result.word == "ZZZ"){

                                      bt.insert(bN);}
                                       misspelledWords(bt);


				break;} 

                                case 'G' : //case G
                                {
              
				break;} 

                                case 'S' : //case S
                                {
                           
                      		 suggestWord(dict,word);
				  if(result.word == "ZZZ"){

                                      bt.insert(bN);}
					 misspelledWords(bt);
					cin.ignore(1000000, '\n');
					cout << endl;
					cout << "Please Hit Return to Continue...";
					string hitreturn;
					getline(cin, hitreturn);
				break;} 

                                case 'Q' : //case Q
                                {
                        
                       		cout << endl;
			 	cout << "Now Exiting Program..." << endl;
			        cout << endl;
				misspelledWords(bt);
                                exit(1);
				break;} 

                                default: //default case
                                {

				cout << "Selection Error -- Please Try Again" << endl;
				cout << endl;
				cout << "Selection: " ;
				cin >> letterloc;
				selectOption(letterloc, dict, word,ignoreWord,bt, currLineNum);
				
				break;

                                }
             
}
}


//Precondition: A valid string will be passed in as a parameter. 
//Postcondition: The method will successfully insert the string passed as a parameter to the end of the dict.txt file.
void add(string word){


 ofstream out;

   out.open("dict.txt", std::ios::app);
      out << word;
      out << endl;
      out.close();
}




///////////////EXTRA//////////////////////
bool addLetter(string word,HashTable &dict){

 string wordN = word;
        char current;

        for (int i = 0;  i < word.length();  i++)
        {

                current = word.at(i);

		  wordN.insert(i,1,current);


	

	if (dict.find(wordN)== true) //search on your hypothesis
       
                           {
                                                    cout << endl;
                                                    cout << "Suggested Spelling is: " << wordN << endl;
                                                                                  return true;

			}
    	               wordN = word;
    	 }
                                                                                                                                                                                          

for(int i = 0; i < word.length(); i++){
current = word.at(i);

wordN.insert(0,1,current);


        if (dict.find(wordN)== true) //search on your hypothesis
                                  {
                                                    cout << endl;
                                                    cout << "Suggested Spelling is: " << wordN << endl;
                                                                                  return true;

                        }





wordN = word;
}

return false;

}




bool removeLetter(string word, HashTable &dict){
	 string wordN = word;
	  for (int i = 0;  i < word.length();  i++)
        {

	   wordN.erase(i,1);

 if (dict.find(wordN)== true) //search on your hypothesis
                                  {
                                                    cout << endl;
                                                    cout << "Suggested Spelling is: " << wordN << endl;
                                                                                  return true;

                        }



	 wordN = word;


}


	return false;

}

