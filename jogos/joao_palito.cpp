#include <iostream>
using namespace std;

int jogo[] = {1, 3, 5, 7};
int tam = sizeof(jogo) / sizeof(jogo[0]);

int verificar(int linha, int num)
{
	if( (linha > (tam-1)) || (linha < 0) )
	{
		cout << "essa linha não existe, jogue novamente" << endl;
		return 0;
	}
	else if( (jogo[linha] - num) < 0)
	{
		cout << "não é possível tirar " << num << " palitos da linha " << linha << ", jogue novamente" << endl;
		return 0;
	}
	else
	{
		jogo[linha] -= num;
		return 1;
	}
}

void desenhar()
{
	for(int i = 0; i < tam; i++)
	{
		cout << (i+1) << " - ";
		for(int j = 0; j < jogo[i]; j++)
		{
			if(j == 0) for(int k = 0; k < ((tam-1)-i); k++) cout << "  ";
			cout << "I ";
		}
		cout << endl;
	}
}

int main(void)
{
	int jogador = 0;
	int somatorio = 1;
	int linha, coluna;
  for(int i = 0; i < 30; i++)
    cout << "#";
  cout << endl;
	desenhar();

	while(somatorio > 0)
	{
    somatorio = 0;

		for(int i = 0; i < tam; i++)
		{
			int temp = 0;
			temp += jogo[i];
			somatorio = temp;
		}

		if(somatorio != 0)
		{
      cout << endl << "### TURNO DO JOGADOR ";
      if(jogador % 2 == 0) cout << "1 ###";
      else cout << "2 ###";

			cout << endl << endl << "qual linha deseja retirar?" << endl << "-> ";
			cin >> linha;
			cout << "quantos palitos deseja retirar?" << endl << "-> ";
			cin >> coluna;
			linha--;

			if(verificar(linha, coluna))
				jogador++;
      for(int i = 0; i < 30; i++)
        cout << "#";
      cout << endl;
			desenhar();
		}
	}

	if(jogador % 2 == 0)
		cout << endl << "jogador 1 ganhou!" << endl;
	else
		cout << endl << "jogador 2 ganhou!" << endl;
}
