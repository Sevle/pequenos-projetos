#include <iostream>
#include <random>
using namespace std;

#define QT_STATUS 3
#define QT_OPERACAO 4
#define QT_NUMEROS 2
enum Status {VIDAS, PONTOS, STREAKS};
enum Operador {SOMA, SUBT, MULTI, DIV};
int status[] = {3, 0, 0};

void tratarStatus(int *tam_alinharColunas, int *tam_icone, int modo)
{
	if(modo)
		for(int i = 0; i < 5; i++)
		{
			status[i] *= tam_icone[i];
			status[i] += tam_alinharColunas[i];
		}
	else
		for(int i = 0; i < 5; i++)
		{
			status[i] -= tam_alinharColunas[i];
			status[i] /= tam_icone[i];
		}
}

void desenharLinhas(int *tam_txt, int *tam_icone)
{
	int maior = 0;
	tratarStatus(tam_txt, tam_icone, 1);

	for(int i = 0; i < 5; i++)
		if(status[i] >= maior) maior = status[i];
	    maior++;
	for(int i = 0; i < maior; i++)
	{
		if( (i == 0) || (i == maior - 1)) cout << "+";
		else cout << "-";
	}
	cout << endl;
	tratarStatus(tam_txt, tam_icone, 0);
}

void alinharColunas(int *tam_txt, int *tam_icone,int linha)
{
  int id_status[] = {0, 1, 2, 3, 4, 5};
	char id_maior;
	int num_maior = 0;
	tratarStatus(tam_txt, tam_icone, 1);

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
	tratarStatus(tam_txt, tam_icone, 0);
}

void desenharStatus(int *tam_txt, int *tam_icone, char txt_status[][20], char icone_status[][4])
{
    desenharLinhas(tam_txt, tam_icone);
    for(int i = 0; i < QT_STATUS; i++)
    {
      cout << txt_status[i];
      for(int j = 0; j < status[i]; j++)
        cout << icone_status[i];
      alinharColunas(tam_txt, tam_icone, i);
    }
    desenharLinhas(tam_txt, tam_icone);
}

int calcularResultado(float *num, int id_operacao, char txt_operacao[][20])
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

int tamanhoNumeros(float *num)
{
  int resultado = 0;
  int expoente[QT_NUMEROS] = {0};
  for(int i = 0; i < QT_NUMEROS; i++)
  {
    int tamanho = 1;
    while(tamanho < num[i])
    {
      tamanho *= 10;
      expoente[i]++;
    }
  }
  for(int i = 0; i < QT_NUMEROS; i++)
    resultado += expoente[i];

  return resultado;
}

int tamanhoString(char *string)
{
  int tam = 0;
  while(string[tam] != '\0')
    tam++;
  return tam;
}

int descobrirId(int seed_numero, int *probabilidade)
{
  int id;
  int temp = 0;

  for(int i = 0; i < QT_OPERACAO; i++)
  {
    if(i > 0) temp = probabilidade[i-1];
    if(seed_numero <= probabilidade[i] && seed_numero > temp)
     id = i;
  }
  return id;
}

int main(void)
{
	int tam_txt[5], tam_icone[QT_STATUS];
	int tam_txt_status[QT_STATUS], tam_txt_operacao[QT_OPERACAO];
	int tam_pergunta, tam_pt, tam_num;
  int probabilidade[QT_OPERACAO] = {5, 10, 60, 100};
	char pt_pergunta[6] = " é? ";
	char txt_operacao[QT_OPERACAO][20] =
	{
		" + ",
		" - ",
		" * ",
		" / "
	};
	char txt_status[QT_STATUS][20] =
	{
		"| vidas: ",
		"| pontos: ",
		"| streaks: "
	};
  char icone_status[QT_STATUS][4] = {"<3 ", "* ", "# "};

  tam_pt = tamanhoString(pt_pergunta);
  for(int i = 0; i < QT_STATUS; i++)
    tam_icone[i] = tamanhoString(icone_status[i]);
  for(int i = 0; i < QT_OPERACAO; i++)
    tam_txt_operacao[i] = tamanhoString(txt_operacao[i]);
  for(int i = 0; i < QT_STATUS; i++)
    tam_txt_status[i] = tamanhoString(txt_status[i]);
  
	while(status[VIDAS] != 0)
	{
		random_device random;
		mt19937 gen(random());
		uniform_int_distribution<> distrib_numero(0, 999);
		uniform_int_distribution<> distrib_operacao(0, 99);

		float num[QT_NUMEROS], resposta_player, resposta_certa;

		for(int i = 0; i < QT_NUMEROS; i++)
			num[i] = distrib_numero(gen);

    tam_num = tamanhoNumeros(num);
    
		int opera = distrib_operacao(gen); 
		int id_operacao = descobrirId(opera, probabilidade);

		tam_pergunta = tam_num + tam_pt + tam_txt_operacao[id_operacao] + 1;
		for(int i = 0; i < QT_STATUS; i++)
			tam_txt[i] = tam_txt_status[i];
		tam_txt[3] = tam_pergunta;
		tam_txt[4] = 5;

    desenharStatus(tam_txt, tam_icone, txt_status, icone_status);

		cout << "| " << num[0];
    resposta_certa = calcularResultado(num, id_operacao, txt_operacao);

		cout << num[1] << pt_pergunta;
		alinharColunas(tam_txt, tam_icone, 3);
		cout << "| -> ";
		alinharColunas(tam_txt, tam_icone, 4);
		desenharLinhas(tam_txt, tam_icone);

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
