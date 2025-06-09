#include <iostream>
#include <random>
using namespace std;

void estrutura (int vida, int ponto, int streak, int modo)
{
	int space_vida = vida * 3;
	int space_ponto = ponto * 2;
	int space_streak = streak * 2;
	if(modo == 1)
	{
		int dif = 0;
		int maior;
		if(space_vida > space_ponto)
			maior = space_vida;
		if(space_vida < space_ponto)
			maior = space_ponto;
		if(space_vida == space_ponto)
			maior = space_vida;

		int buffer = 11 + maior;
		for(int i = 0; i < buffer; i++)
			cout << "-";
	}

	if(modo == 2)
	{
		if(space_vida >= space_ponto)
			cout << " ";
		if(space_vida < space_ponto)
		{
			int dif = space_ponto - space_vida + 2;
			for(int i = 0; i < dif; i++)
				cout << " ";
		}
	}
	if(modo == 3)
	{
		if(space_ponto >= space_vida)
			cout << " ";
		if(space_ponto < space_vida)
		{
			int dif = space_vida - space_ponto;
			for(int i = 0; i < dif; i++)
				cout << " ";
		}
	}
	if(modo == 4)
	{
                if(space_vida >= space_ponto)
                        cout << " ";
                if(space_vida < space_ponto)
                {
                        int dif = space_ponto - space_streak + 1;
                        for(int i = 0; i < dif; i++)
                                cout << " ";
                }
		else
		{
			int dif = space_vida - space_streak - 1;
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

	char texto_opera[4];
	char parte_pergunta[5] = "é? ";

	texto_opera[0] = " somado a     ";
	texto_opera[1] = " subtraindo   ";
	texto_opera[2] = " vezes        ";
	texto_opera[3] = " dividido por ";

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
		cout << num[1] << texto_opera[opera] << parte_pergunta;

		estrutura(vidas, pontos, streaks, 5);
		cout << "| -> " << endl;
		estrutura(vidas, pontos, streaks, 1);
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
