#include <iostream>
#include <random>
#define QT_STATUS 3
#define QT_OPERACAO 4
using namespace std;
int status[] = {3, 0, 0};

void tratar_status(int *tam_estrutura, int modo)
{
	int multi[] = {3, 2, 2};
	if(modo)
		for(int i = 0; i < 5; i++)
		{
			status[i] *= multi[i];
			status[i] += tam_estrutura[i];
		}
	else
		for(int i = 0; i < 5; i++)
		{
			status[i] -= tam_estrutura[i];
			status[i] /= multi[i];
		}
}

void teto_estrutura(int *tam_txt)
{
	int maior = 0;
	int multi[] = {3, 2, 2};
	tratar_status(tam_txt, 1);

	for(int i = 0; i < 5; i++)
		if(status[i] >= maior) maior = status[i];
	maior++;
	for(int i = 0; i < maior; i++)
	{
		if( (i == 0) || (i == maior - 1)) cout << "+";
		else cout << "-";
	}
	cout << endl;
	tratar_status(tam_txt, 0);
}

void estrutura(int *tam_txt, char linha)
{
	char id_status[] = {'v', 'p', 's', 'o', 'r'};
	char id_maior;
	int num_maior = 0;
	tratar_status(tam_txt, 1);

	for(int i = 0; i < 5; i++)
		if(status[i] >= num_maior)
		{
			num_maior = status[i];
			id_maior = id_status[i];
		}
	if(id_maior != linha)
	{
		int id;
		for(int i = 0; i < 5; i++)
			if(id_status[i] == linha) id = i;

		int dif = num_maior - status[id];
		for(int i = 0; i < dif; i++)
			cout << " ";
	}
	cout << "|" << endl;
	tratar_status(tam_txt, 0);
}

int main(void)
{
	enum Status {VIDAS, PONTOS, STREAKS};
	enum Operador {SOMA, SUBT, MULTI, DIV};

	int tam_txt[5];
	int tam_txt_status[QT_STATUS];
	int tam_txt_operacao[QT_OPERACAO];
	int tam_num[2];
	int tam_pergunta;
	int tam_pt;
	char pt_pergunta[6] = " C)? ";
	char txt_operacao[QT_OPERACAO][20] =
	{
		" somado a ",
		" subtraindo ",
		" vezes ",
		" dividido por "
	};
	char txt_status[QT_STATUS][20] =
	{
		"| vidas: ",
		"| pontos: ",
		"| streaks: "
	};

	for(int i = 0; i < 6; i++)
		if(pt_pergunta[i] != '\0') tam_pt++;

	for(int i = 0; i < QT_OPERACAO; i++)
	{
		int tamanho = 0;
		while(txt_operacao[i][tamanho] != '\0') tamanho++;
		tam_txt_operacao[i] = tamanho;
	}
	for(int i = 0; i < QT_STATUS; i++)
	{
		int tamanho = 0;
		while(txt_status[i][tamanho] != '\0') tamanho++;
		tam_txt_status[i] = tamanho;
	}

	while(status[VIDAS] != 0)
	{
		random_device random;
		mt19937 gen(random());
		uniform_int_distribution<> distrib_numero(0, 999);
		uniform_int_distribution<> distrib_operacao(0, 99);

		float num[2], resposta_player, resposta_certa;

		for(int i = 0; i < 2; i++)
		{
			num[i] = distrib_numero(gen);
			if(num[i] < 9) tam_num[i] = 1;
			if(num[i] < 99 && num[i] > 9) tam_num[i] = 2;
			if(num[i] > 99) tam_num[i] = 3;
		}
		int opera = distrib_operacao(gen);
		int id_opera;

		if(opera < 5) id_opera = 0;
		if(opera >= 5 && opera < 10) id_opera = 1;
		if(opera >= 10 && opera < 60) id_opera = 2;
		if(opera >= 60 && opera < 100) id_opera = 3;

		tam_pergunta = tam_num[0] + tam_num[1] + tam_pt + tam_txt_operacao[id_opera] + 1;
		for(int i = 0; i < QT_STATUS; i++)
			tam_txt[i] = tam_txt_status[i];
		tam_txt[3] = tam_pergunta;
		tam_txt[4] = 5;

		teto_estrutura(tam_txt);
		cout << txt_status[VIDAS];
		for(int i = 0; i < status[VIDAS]; i++)
			cout << "<3 ";
		estrutura(tam_txt, 'v');

		cout << txt_status[PONTOS];
		for(int i = 0; i < status[PONTOS]; i++)
			cout << "* ";
		estrutura(tam_txt, 'p');

		cout << txt_status[STREAKS];
		for(int i = 0; i < status[STREAKS]; i++)
			cout << "# ";
		estrutura(tam_txt,'s');
		teto_estrutura(tam_txt);

		cout << "| " << num[0];

		// somatC3rio
		if(id_opera == 0)
		{
			cout << txt_operacao[SOMA];
			resposta_certa = num[0] + num[1];
		}
		// subtraC'C#o
		if(id_opera == 1)
		{
			cout << txt_operacao[SUBT];
			resposta_certa = num[0] - num[1];
		}
		// multiplicaC'C#o
		if(id_opera == 2)
		{
			cout << txt_operacao[MULTI];
			resposta_certa = num[0] * num[1];
		}
		// divisC#o
		if(id_opera == 3)
		{
			cout << txt_operacao[DIV];
			resposta_certa = num[0] / num[1];
			// trunca 4 casas decimais
			int buffer = resposta_certa * 10000;
			resposta_certa = buffer / 10000.0;
		}

		cout << num[1] << pt_pergunta;
		estrutura(tam_txt, 'o');
		cout << "| -> ";
		estrutura(tam_txt, 'r');
		teto_estrutura(tam_txt);

		// ANSI para retornar o curso 2 linhas pra cima e 5 para a esquerda
		cout << "\033[2A";
		cout << "\033[5C";
		cin >> resposta_player;
		if(resposta_player == resposta_certa)
		{
			cout << endl << "correto" << endl;
			status[PONTOS]++;
			status[STREAKS]++;

			if(status[STREAKS] % 3 == 0) status[VIDAS]++;
		}
		else
		{
			cout << endl << "errado, era " << resposta_certa << endl;
			status[VIDAS]--;
			status[STREAKS] = 0;

			if( (resposta_player > (resposta_certa * 0.9) ) && (resposta_player < (resposta_certa * 1.1) ) )
				cout << "quase acertou" << endl;
		}
	}

	cout << endl << "GAME OVER!!!" << endl;
}
