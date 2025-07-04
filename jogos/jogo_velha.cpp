#include <iostream>
#define ESCALA 9
using namespace std;
int tabuleiro[ESCALA][ESCALA] = {0};

int verificar(int linha, int coluna)
{
  int invalido = 0;

  for(int i = 0; i < ESCALA; i++)
    for(int j = 0; j < ESCALA; j++)
      if(tabuleiro[linha][coluna] > 0)
        invalido = 1;

  if(linha > (ESCALA-1) || coluna > (ESCALA-1) )
    invalido = 1;

  if(invalido)
    return 0;
  else
    return 1;
}

int fim_jogo()
{
  int velha[2][8] = {0};
  int temp = 0;
  for(int l = 0; l < 2; l++)
    for(int i = 0; i < ESCALA; i++)
      for(int j = 0; j < ESCALA; j++)
        if(tabuleiro[i][j] == (l+1))
          for(int k = 1; k < 3; k++)
          {
            if( ((l+1) == tabuleiro[i][j+k]) && ( (j+k) < ESCALA)) velha[l][0]++;
            if( ((l+1) == tabuleiro[i][j-k]) && ( (j-k) > 0)) velha[l][1]++;
            if( ((l+1) == tabuleiro[i+k][j]) && ( (i+k) < ESCALA)) velha[l][2]++;
            if( ((l+1) == tabuleiro[i-k][j]) && ( (i-k) > 0)) velha[l][3]++;

            if( ((l+1) == tabuleiro[i+k][j+k]) && (i+k) < ESCALA && (j+k) < ESCALA) velha[l][4]++;
            if( ((l+1) == tabuleiro[i-k][j-k]) && (i-k) > 0 && (j-k) > 0) velha[l][5]++;
            if( ((l+1) == tabuleiro[i-k][j+k]) && (i-k) > 0 && (j+k) < ESCALA) velha[l][6]++;
            if( ((l+1) == tabuleiro[i+k][j-k]) && (i+k) < ESCALA && (j-k) > 0 )velha[l][7]++;
          }

  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 8; j++)
      if(velha[i][j] == 3) temp = 1;
  if(temp) return 0;
  else return 1;
}

int empate()
{
  // 1 é porque não achou nenhum 0, portanto o tabuleiro não deu empate e ainda tem jogo
  int vazio = 0;

  for(int i = 0; i < ESCALA; i++)
    for(int j = 0; j < ESCALA; j++)
      if(tabuleiro[i][j] == 0)
        vazio = 1;
  
  if(vazio) return 1;
  else return 0;
}

void desenhar()
{
  cout << "   ";
  for(int i = 0; i < ESCALA; i++)
    cout << "   " << i+1;

  cout << endl;
  for(int i = 0; i < ESCALA; i++)
  {
    cout << "    ";
    for(int k = 0; k < (ESCALA * 4 + 1); k++)
      cout << "-";

    cout << endl; 

    cout << i + 1 << " - ";    
    for(int l = 0; l < ESCALA; l++)
    {
      if(l == 0) cout << "|"; 
      
      for(int m = 0; m < 3; m++)
      {
        if(tabuleiro[i][l] > 0 && m == 1) 
        {
          if(tabuleiro[i][l] == 1) cout << "O";
          else if(tabuleiro[i][l] == 2) cout << "X";
        }
        else cout << " ";
      }
      cout << "|";
    }
    cout << endl;
  }
  cout << "    ";
  for(int i = 0; i < (ESCALA * 4 + 1); i++)
    cout << "-";
}

int main(void)
{
  int jogador = 0;
  int jogada[2];
  int primeira = 1;
  while(fim_jogo() && empate())
  {
    if(primeira)
    {
      desenhar();
      primeira = 0;
    }

    if(jogador % 2 == 0) cout << endl << "### TURNO DO JOGADOR 1 ( X ) ###";
    else cout << endl << "### TURNO DO JOGADOR 2 ( O ) ###";

    cout << endl << "qual linha deseja marca?" << endl << "-> ";
    cin >> jogada[0];
    cout << "qual coluna deseja marca?" << endl << "-> ";
    cin >> jogada[1];

    jogada[0]--;
    jogada[1]--;
    
    if(verificar(jogada[0],jogada[1]))
    {
      jogador = jogador % 2;  
      
      if(jogador) tabuleiro[jogada[0]][jogada[1]] = 1;
      else tabuleiro[jogada[0]][jogada[1]] = 2;

      desenhar();
      jogador++;
    }
    else
      cout << "valor invalido, tente novamente" << endl;
    cout << endl;
  }

  if(!empate())
    cout << endl << "ninguem venceu, empate" << endl;
  else
  {
    if(jogador % 2 == 0) cout << endl << "jogador 2 venceu!" << endl;
    else cout << endl << "jogador 1 venceu" << endl;
  }

}
