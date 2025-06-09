#include <iostream>
using namespace std;

int main(void)
{
	const int size = 27;
	char alfabeto[size] = "abcdefghijklmnopqrstuvwxyz";
	char letra_user[2];
	int num[2];
	cout << "insira a primeira letra" << endl << "-> ";
	cin >> letra_user[0];
	cout << "insira a segunda letra" << endl << "-> ";
	cin >> letra_user[1];

	for(int i = 0; i < size; i++)
	{
		if(letra_user[0] == alfabeto[i])
			num[0] = i;
		if(letra_user[1] == alfabeto[i])
			num[1] = i;
	}
	cout << endl;


}
