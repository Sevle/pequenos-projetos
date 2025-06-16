#include <iostream>
using namespace std;

int main(void)
{
	char alfabeto[] = {"abcdefghijklmnopqrstuvwxyz"};
	char letra_user[2];
	int num[2];

	for(int i = 0; i < 2; i++)
	{
		cout << "insira a " << i+1 << "º letra" << endl << "-> ";
		cin >> letra_user[i];
	}

	for(int i = 0; i < sizeof(alfabeto); i++)
	{
		if(letra_user[0] == alfabeto[i]) num[0] = i;
		if(letra_user[1] == alfabeto[i]) num[1] = i;
	}
	cout << endl;

	if(num[0] > num[1])
	{
		int temp_num = num[0];
		num[0] = num[1];
		num[1] = temp_num;
	}

	for(int i = (num[0] + 1); i < num[1]; i++)
		cout << alfabeto[i] << " ";

	cout << endl;
}
