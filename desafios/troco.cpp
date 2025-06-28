#include <iostream>
using namespace std;

// enunciado: faça um programa na qual o usuário digite um valor, e então o programa retorna a quantidade mínima de moedas necessárias pra dá aquele valor
// exemplo: se o usuário digitar 0.41, o programa deve retornar 4, pois ele irá usar 1 moeda de 25, 10, 5 e 1 para dá 0.41

int main(void)
{
  float moedas[] = {25, 10, 5, 1};
  int tipos_moedas = sizeof(moedas) / sizeof(moedas[0]);
  int qt_moeda = 0;
  int maior_multi = 0;
  float valor;

  cin >> valor;
  valor *= 100;

  for(int i = 0; i < tipos_moedas; i++)
  {
    int index = 0;

    for(int j = 1; maior_multi < valor; j++)
    {
      maior_multi = moedas[i] * j;
      
      if(maior_multi > valor) index = j - 1;
      else index = j;
    }

    maior_multi = moedas[i] * index;
    qt_moeda += index;
    
    valor -= maior_multi;
  }
  cout << endl << qt_moeda << endl;
}
