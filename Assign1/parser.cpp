#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <cstdlib>
#include <string>

using namespace std;

// test command to parse
//
// ls -a; echo "hello world" || echo "Goodbye world"

void breakstring(string Test)
{

	int lastend = 0;
	int currpos = 0;
	string str1;
	string str2;
	string str3;

	while(currpos != Test.size())
		{
			if (Test.at(currpos) == ';')
				{
					str1 = Test.substr(lastend, (currpos - lastend));
					lastend = currpos;
					str2 = Test.substr(lastend, (currpos - lastend + 1));
					lastend++;
					lastend++;
					cout << str1 << endl;
					cout << str2 << endl;
				}
			else if (Test.at(currpos) == '|')
				{
					if(Test.at(currpos + 1) == '|')
						{
							str1 = Test.substr(lastend, (currpos - lastend));
							lastend = currpos;
							str2 = Test.substr(lastend, (currpos - lastend + 2));
							lastend++;
							lastend++;
							lastend++;
							cout << str1 << endl;
							cout << str2 << endl;
						}
				}
			else if (Test.at(currpos) == '&')
				{
					if(Test.at(currpos + 1) == '&')
						{
							str1 = Test.substr(lastend, (currpos - lastend));
							lastend = currpos;
							str2 = Test.substr(lastend, (currpos - lastend + 2));
							lastend++;
							lastend++;
							lastend++;
							cout << str1 << endl;
							cout << str2 << endl;
						}
				}
			else if(currpos == (Test.size() - 1))
				{
					lastend--;
					str1 = Test.substr(lastend + 1, ((currpos + 1) - lastend));
					cout << str1 << endl;
				}

			currpos++;
		}
	return;
}
	

int main()
{
	cout << "Start of Program" << endl;
	string Test = "ls -a; echo 'hello world' || echo 'Goodbye world'; test command && test command; test command; testcommand || test";
	breakstring(Test);
	return 0;
}

