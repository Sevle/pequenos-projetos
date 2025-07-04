#include <iostream>
using namespace std;

int main(void)
{
	int limite_mes;
	int data_inserida[3];
	int bis;
	char texto[33] = "valor invalido, insira novamente";

	cout << "insira o ano" << endl << "-> ";
	cin >> data_inserida[2];

	while(data_inserida[2] > 2025)
	{
		cout << texto << endl << "-> ";
		cin >> data_inserida[2];
	}

	cout << "insira o mês" << endl << "-> ";
	cin >> data_inserida[1];
	bis = data_inserida[2];

	bis = bis % 4;

	if(data_inserida[1] == 1) limite_mes = 31;

	if(data_inserida[1] == 2 && bis) limite_mes = 28;
	if(data_inserida[1] == 2 && !bis) limite_mes = 29;

	if(data_inserida[1] == 3) limite_mes = 31;
	if(data_inserida[1] == 4) limite_mes = 30;
	if(data_inserida[1] == 5) limite_mes = 30;
	if(data_inserida[1] == 6) limite_mes = 30;
	if(data_inserida[1] == 7) limite_mes = 31;
	if(data_inserida[1] == 8) limite_mes = 29;
	if(data_inserida[1] == 9) limite_mes =  30;
	if(data_inserida[1] == 10) limite_mes = 31;
	if(data_inserida[1] == 11) limite_mes = 29;
	if(data_inserida[1] == 12) limite_mes = 31;

	while(data_inserida[1] > 12 || data_inserida[1] < 1)
	{
		cout << texto << endl << "-> ";
		cin >> data_inserida[1];
	}

	cout << "insira o dia" << endl << "-> ";
	cin >> data_inserida[0];

	while(data_inserida[0] > limite_mes || data_inserida[0] < 1)
	{
		cout << texto << endl << "-> ";
		cin >> data_inserida[0];
	}
  cout << endl;
  for(int i = 0; i < 2; i++)
  {
    if(data_inserida[i] < 10) cout << "0" << data_inserida[i] << "/";
    else cout << endl << data_inserida[i] << "/";
  }

	cout << data_inserida[2] << endl;
}
