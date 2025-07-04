#include <iostream>
#include <random>
using namespace std;

#define QT_STATUS 3
#define QT_OPERACAO 4
enum Status {VIDAS, PONTOS, STREAKS};
enum Operador {SOMA, SUBT, MULTI, DIV};
int status[] = {3, 0, 0};

void tratar_status(int *tam_estrutura, int *tam_icone, int modo)
{
	if(modo)
		for(int i = 0; i < 5; i++)
		{
			status[i] *= tam_icone[i];
			status[i] += tam_estrutura[i];
		}
	else
		for(int i = 0; i < 5; i++)
		{
			status[i] -= tam_estrutura[i];
			status[i] /= tam_icone[i];
		}
}

void teto_estrutura(int *tam_txt, int *tam_icone)
{
	int maior = 0;
	tratar_status(tam_txt, tam_icone, 1);

	for(int i = 0; i < 5; i++)
		if(status[i] >= maior) maior = status[i];
	maior++;
	for(int i = 0; i < maior; i++)
	{
		if( (i == 0) || (i == maior - 1)) cout << "+";
		else cout << "-";
	}
	cout << endl;
	tratar_status(tam_txt, tam_icone, 0);
}

void estrutura(int *tam_txt, int *tam_icone,int linha)
{
  int id_status[] = {0, 1, 2, 3, 4, 5};
	char id_maior;
	int num_maior = 0;
	tratar_status(tam_txt, tam_icone, 1);

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
	tratar_status(tam_txt, tam_icone, 0);
}

void desenhar_status(int *tam_txt, int *tam_icone, char txt_status[][20], char icone_status[][4])
{
    teto_estrutura(tam_txt, tam_icone);
    for(int i = 0; i < QT_STATUS; i++)
    {
      cout << txt_status[i];
      for(int j = 0; j < status[i]; j++)
        cout << icone_status[i];
      estrutura(tam_txt, tam_icone, i);
    }
    teto_estrutura(tam_txt, tam_icone);
}

int operacao(float *num, int id_operacao, char txt_operacao[][20])
{
  int resultado;
  // somatório
  if(id_operacao == 0)
  {
    cout << txt_operacao[SOMA];
    resultado = num[0] + num[1];
  }
  // subtração
  if(id_operacao == 1)
  {
    cout << txt_operacao[SUBT];
    resultado = num[0] - num[1];
  }
  // multiplicação
  if(id_operacao == 2)
  {
    cout << txt_operacao[MULTI];
    resultado = num[0] * num[1];
  }
  // divisão
  if(id_operacao == 3)
  {
    cout << txt_operacao[DIV];
    resultado = num[0] / num[1];
    // trunca 4 casas decimais
    int buffer = resultado * 10000;
    resultado = buffer / 10000.0;
  }
  return resultado;
}

int tam_string(char *string)
{
  int tam = 0;
  while(string[tam] != '\0')
    tam++;
  return tam;
}

int main(void)
{
	int tam_txt[5], tam_num[2], tam_icone[QT_STATUS];
	int tam_txt_status[QT_STATUS], tam_txt_operacao[QT_OPERACAO];
	int tam_pergunta, tam_pt;

	char pt_pergunta[6] = " é? ";
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
  char icone_status[QT_STATUS][4] = {"<3 ", "* ", "# "};

  tam_pt = tam_string(pt_pergunta);
  for(int i = 0; i < QT_STATUS; i++)
    tam_icone[i] = tam_string(icone_status[i]);
  for(int i = 0; i < QT_OPERACAO; i++)
    tam_txt_operacao[i] = tam_string(txt_operacao[i]);
  for(int i = 0; i < QT_STATUS; i++)
    tam_txt_status[i] = tam_string(txt_status[i]);
  
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
		int id_operacao;

		if(opera < 5) id_operacao = 0;
		if(opera >= 5 && opera < 10) id_operacao = 1;
		if(opera >= 10 && opera < 60) id_operacao = 2;
		if(opera >= 60 && opera < 100) id_operacao = 3;

		tam_pergunta = tam_num[0] + tam_num[1] + tam_pt + tam_txt_operacao[id_operacao] + 1;
		for(int i = 0; i < QT_STATUS; i++)
			tam_txt[i] = tam_txt_status[i];
		tam_txt[3] = tam_pergunta;
		tam_txt[4] = 5;

    desenhar_status(tam_txt, tam_icone, txt_status, icone_status);

		cout << "| " << num[0];
    resposta_certa = operacao(num, id_operacao, txt_operacao);

		cout << num[1] << pt_pergunta;
		estrutura(tam_txt, tam_icone, 3);
		cout << "| -> ";
		estrutura(tam_txt, tam_icone, 4);
		teto_estrutura(tam_txt, tam_icone);

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
