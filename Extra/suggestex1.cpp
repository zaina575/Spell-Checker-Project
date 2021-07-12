
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string word = "suggestt";
	string wordN = word;
//	char current;

	for (int i = 0;  i < word.length();  i++)
	{
	
//		current = word.at(i);

//		for(int j = 0; j < word.length(); j++){	
		wordN.erase(i,1);
//
//		cout << i << endl;
//		cout << wordN << endl;
//		}


//		wordN.insert(word.begin(),current);

//		wordN += word.substr(0, i);
//		wordN += word[i+1];
//		wordN += word[i];
//		wordN += word.substr(i+2);
		cout << wordN << endl;
		wordN = word;  //reset it back to original word

/*
		if (D.find(wordN)) //search on your hypothesis
  		{
  			cout << "Suggested Spelling is " << wordN << endl;
 			found = true;
  		} 
*/

		//wordN = "" // reset word after you this if statement once we have a dictionary object
	}


/*for(int i = 0; i < word.length(); i++){
current = word.at(i);
cout << current << endl;
wordN.insert(0,1,current);
cout << wordN << endl;
wordN = word;
}//else (if you don't find it) -- we need to try to insert the letter at the beginning
*/	

return 0;
}
