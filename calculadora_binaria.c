#include <iostream>
#define HEX 16
#define QT_BIN 2
using namespace std;

int main(void)
{
	int numero_binario[QT_BIN][HEX] = {0};
	int numero_decimal[QT_BIN];
	int qt[QT_BIN];
	int bin_expoente[QT_BIN] = {0};

	for(int i = 0; i < QT_BIN; i++)
		qt[i] = 1;

	for(int i = 0; i < QT_BIN; i++)
		cin >> numero_decimal[i];

	for(int i = 0; i < QT_BIN; i++)
	{
		for(int j = 1; qt[i] <= numero_decimal[i]; j++)
		{
			qt[i] = qt[i] * 2;
			bin_expoente[i] = j;
		}
	}

	for(int i = 0; i < QT_BIN; i++)
	{
		for(int j = 1; j <= bin_expoente[i]; j++)
		{
			if(numero_decimal[i] % 2 == 0)
				numero_binario[i][j] = 0;
			else
				numero_binario[i][j] = 1;
			numero_decimal[i] = numero_decimal[i] / 2;
		}
	}

	for(int i = 0; i < QT_BIN; i++)
	{
		for(int j = bin_expoente[i]; j > 0; j--)
			cout << numero_binario[i][j];
		cout << endl << endl;
	}
}
