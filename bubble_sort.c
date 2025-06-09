#include <iostream>
#define TAM 5
using namespace std;

int main(void)
{
	int numero_bruto[TAM];
	for(int i = 0; i < TAM; i++)
		cin >> numero_bruto[i];

	cout << endl;

	for(int i = 0; i < TAM; i++)
	{
		for(int j = 0; j < TAM; j++)
		{
			if((numero_bruto[j+1] > numero_bruto[j]) && ((j+1) < TAM))
			{
				int buffer 	  = numero_bruto[j];
				numero_bruto[j]   = numero_bruto[j+1];
				numero_bruto[j+1] = buffer;
			}
		}
	}

	for(int i = 0; i < TAM; i++)
	{
		if(i > 0) cout << " ";
		cout << numero_bruto[i];
	}
	int temp_tam = TAM;
	cout << endl << endl<< "o maior valor é: " << numero_bruto[temp_tam - temp_tam] << endl;
	cout << "o menor valor é: " 		   << numero_bruto[temp_tam - 1] 	<< endl;
}
