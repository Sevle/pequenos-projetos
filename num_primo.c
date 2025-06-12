#include <iostream>
using namespace std;

int main(void)
{
	int primo = 1;
	int num = 0;

	cin >> num;

	while(num < 0)
	{
		cout << endl << "digite um numero positivo, bobao" << endl;
		cin >> num;
	}

	for(int i = (num - 1); i > 2; i--)
	{
		if(num % i == 0)
			primo = 0;
	}

	primo ? (cout << "é primo") : (cout << "não é primo");

	cout << endl;
}
