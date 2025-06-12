#include <iostream>
#include <random>
using namespace std;

void estrutura(int x, int y, int z, int modo)
{
	int abs_x = x * 3;
	int abs_y = y * 2;
	int abs_z = z * 2;
	if(modo == 1)
	{
		int dif = 0;
		int maior;
		if(abs_x > abs_y)
			maior = abs_x;
		if(abx_x < abs_y)
			maior = abs_y;
		if(abs_x == abs_y)
			maior = abs_x;

		int buffer = 11 + maior;
		for(int i = 0; i < buffer; i++)
			cout << "-";
	}

	if(modo == 2)
	{
		if(abs_x >= abs_y)
			cout << " ";
		if(abs_x < abs_y)
		{
			int dif = abs_y - abs_x + 2;
			for(int i = 0; i < dif; i++)
				cout << " ";
		}
	}
	if(modo == 3)
	{
		if(abs_y >= abs_x)
			cout << " ";
		if(abs_y < abs_x)
		{
			int dif = abs_x - abs_y;
			for(int i = 0; i < dif; i++)
				cout << " ";
		}
	}
	if(modo == 4)
	{
                if(abs_x >= abs_y)
                        cout << " ";
                if(abs_x < abs_y)
                {
                        int dif = abs_y - abs_z + 1;
                        for(int i = 0; i < dif; i++)
                                cout << " ";
                }
		else
		{
			int dif = abs_x - abs_z - 1;
			for(int i = 0; i < dif; i++)
				cout << " ";
		}
	}
	(modo != 1) ? (cout << "|" << endl) : (cout << endl);
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
		uniform_int_distribution<> distrib_operacao(0, 3);
		estrutura(vidas, pontos, streaks, 1);
		cout << "| vidas: ";
		for(int i = 0; i < vidas; i++)
			cout << "<3 ";

		estrutura(vidas, pontos, streaks, 2);
		cout << "| pontos: ";
		for(int i = 0; i < pontos; i++)
			cout << "* ";

		estrutura(vidas, pontos, streaks, 3);

		cout << "| streak: ";
		for(int i = 0; i < streaks; i++)
			cout << "# ";
		estrutura(vidas, pontos, streaks, 4);

		estrutura(vidas, pontos, streaks, 1);
		float num[2], resposta_player, resposta_certa;
		num[0] = distrib_numero(gen);
		num[1] = distrib_numero(gen);

		int opera = distrib_operacao(gen);

		cout << "| " << num[0];

		// somatório
		if(opera == 0)
		{
			cout << texto_opera[opera];
			resposta_certa = num[0] + num[1];
		}
		// subtração
		if(opera == 1)
		{
			cout << texto_opera[opera];
			resposta_certa = num[0] - num[1];
		}
		// multiplicação
		if(opera == 2)
		{
			cout << texto_opera[opera];
			resposta_certa = num[0] * num[1];
		}
		// divisão
		if(opera == 3)
		{
			cout << texto_opera[opera];
			resposta_certa = num[0] / num[1];

			int buffer = resposta_certa * 10000;
			resposta_certa = buffer / 10000.0;
		}
		sizeof(texto_opera[opera]);
		cout << num[1] << parte_pergunta;

		estrutura(vidas, pontos, streaks, 5);
		cout << "| -> " << endl;
		estrutura(vidas, pontos, streaks, 1);
		// códiog de escape em ANSI para retornar o curso 2 linhas pra cima e 5 para a esquerda
		cout << "\033[2A";
		cout << "\033[5C";
		cin >> resposta_player;
		if(resposta_player == resposta_certa)
		{
			cout << endl << "correto" << endl;
			pontos++;
			streaks++;

			if(streaks % 3 == 0)
				vidas++;
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
