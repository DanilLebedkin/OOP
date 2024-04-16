#include<iostream>
#include<vector>
using namespace std;


bool isIcecreamSandwich(vector<char> vectorForCheckOnSandwich)
{
	int counterOfrepetitionsOfSymbols=0;
	int counterOfSymbols = 0;
	for (int i = 0; i < vectorForCheckOnSandwich.size(); i++)
	{
		
		if (vectorForCheckOnSandwich[i] == vectorForCheckOnSandwich[vectorForCheckOnSandwich.size()-1 - i])
		{
			if (i== vectorForCheckOnSandwich.size() - 1 - i)
			{
				break;
			}
			counterOfrepetitionsOfSymbols++;
		}
		else
		{
			counterOfSymbols++;
			break;
		}
		counterOfSymbols++;
	}
	if (counterOfrepetitionsOfSymbols ==counterOfSymbols)
	{
		return true;
	}
	return false;
	
}
int main()
{
	string stringForChecking;
	char symbolFromString;
	vector<char>vectorForCheckOnSandwich;
	bool resultOfCheckOnSandwich;

	do
	{
		cout << "Input your string for check" << endl;
		cin >> stringForChecking;
	} while (stringForChecking.size()<3);


	for (int i = 0; i < stringForChecking.length(); i++)
	{
		symbolFromString = stringForChecking[i];
		vectorForCheckOnSandwich.push_back(symbolFromString);
	}

	resultOfCheckOnSandwich = isIcecreamSandwich(vectorForCheckOnSandwich);
	if (resultOfCheckOnSandwich ==true)
	{
		cout << "isIcecreamSandwich ( " << stringForChecking << " ) = true" << endl;
	}
	else
	{
		cout << "isIcecreamSandwich ( " << stringForChecking << " ) = false" << endl;
	}
	return 0;
}