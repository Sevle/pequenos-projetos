#include <iostream>
#include <random>
using namespace std;

void teto_estrutura(int x, int y, int z)
{
  int status[3];
  int maior = 0;

  status[0] = x * 3;
  status[1] = y * 2;
  status[2] = z * 2;
  
  for(int i = 0; i < 3; i++)
    if(status[i] > maior)
      maior = status[i];

	int buffer = 11 + maior;

	for(int i = 0; i < buffer; i++) 
    cout << "-";
  cout << endl;
}

void estrutura(int x, int y, int z, char linha)
{
  int status[3];
  char id_status[3];

  id_status[0] = 'v';
  id_status[1] = 'p';
  id_status[2] = 's';
  status[0] = x * 3;
  status[1] = y * 2;
  status[2] = z * 2;

  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(status[j] > status[j+1] && j < 2)
      {
        int buffer[2];

        buffer[0] = status[j];
        buffer[1] = id_status[j];
        
        status[j] = status[j+1];
        status[j+1] = buffer[0];

        id_status[j] = id_status[j+1];
        id_status[j+1] = buffer[1];
      }

  if(id_status[2] == linha) cout << " ";
  else
  {
    int id;
    for(int i = 0; i < 2; i++)
      if(id_status[i] == linha) id = i;

    int dif = status[2] - status[id];
    for(int i = 0; i < dif; i++) 
      cout << " ";
  }
	cout << "|" << endl;
}

int main(void)
{
	int vidas = 3, pontos = 0;
	int streaks = 0;

	char texto_opera[4][16] =
	{
	  " somado a ",
		" subtraindo ",
		" vezes ",
		" dividido por "
	};

	char parte_pergunta[6] = " é? ";

	while(vidas != 0)
	{
		random_device random;
		mt19937 gen(random());
		uniform_int_distribution<> distrib_numero(0, 999);
		uniform_int_distribution<> distrib_operacao(0, 99);

		float num[2], resposta_player, resposta_certa; 

    for(int i = 0; i < 2; i++)
      num[i] = distrib_numero(gen);

		int opera = distrib_operacao(gen);

    teto_estrutura(vidas, pontos, streaks);
		cout << "| vidas: ";
		for(int i = 0; i < vidas; i++)
			cout << "<3 ";

		estrutura(vidas, pontos, streaks, 'v');
		cout << "| pontos: ";
		for(int i = 0; i < pontos; i++)
			cout << "* ";

		estrutura(vidas, pontos, streaks, 'p');

		cout << "| streak: ";
		for(int i = 0; i < streaks; i++)
			cout << "# ";

		estrutura(vidas, pontos, streaks, 's');
		teto_estrutura(vidas, pontos, streaks);

		cout << "| " << num[0];

		// somatório
		if(opera < 5)
		{
			cout << texto_opera[0];
			resposta_certa = num[0] + num[1];
		}
		// subtração
		if(opera >= 5 && opera < 10)
		{
			cout << texto_opera[1];
			resposta_certa = num[0] - num[1];
		}
		// multiplicação
		if(opera >= 10 && opera < 60)
		{
			cout << texto_opera[2];
			resposta_certa = num[0] * num[1];
		}
		// divisão
		if(opera >= 60 && opera < 100)
		{
			cout << texto_opera[3];
			resposta_certa = num[0] / num[1];

			int buffer = resposta_certa * 10000;
			resposta_certa = buffer / 10000.0;
		}

		cout << num[1] << parte_pergunta;

		cout << endl << "| -> " << endl;
    teto_estrutura(vidas, pontos, streaks);
    
		// ANSI para retornar o curso 2 linhas pra cima e 5 para a esquerda
		cout << "\033[2A";
		cout << "\033[5C";
		cin >> resposta_player;
		if(resposta_player == resposta_certa)
		{
			cout << endl << "correto" << endl;
			pontos++;
			streaks++;

			if(streaks % 3 == 0) vidas++;
		}
		else
		{
			cout << endl << "errado, era " << resposta_certa << endl;
			vidas--;
			streaks = 0;
      
			if( (resposta_player > (resposta_certa * 0.9) ) && (resposta_player < (resposta_certa * 1.1) ) )
					cout << "quase acertou" << endl;
		}
	}

	cout << endl << "GAME OVER!!!" << endl;
}
