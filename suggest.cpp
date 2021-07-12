
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string word = "thsi";
	string wordN = "";

	for (int i = 0;  i < word.length()-1;  i++)
	{
		wordN += word.substr(0, i);
		wordN += word[i+1];
		wordN += word[i];
		wordN += word.substr(i+2);
		cout << wordN << endl;
		wordN = "";  //reset it back to original word

/*
		if (D.find(wordN)) //search on your hypothesis
  		{
  			cout << "Suggested Spelling is " << wordN << endl;
 			found = true;
  		} 
*/

		//wordN = "" // reset word after you this if statement once we have a dictionary object
	}


	return 0;
}
