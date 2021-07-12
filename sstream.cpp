
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string line = "Monday March 22nd";
	stringstream ss(line);
	string word;
	while(ss >> word)
		cout << word << endl;

	return 0;
}
