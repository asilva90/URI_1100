#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

struct No{
  int posX;
  int posY;
  int salto;

  No(int posX, int posY, int salto){
    this->posX = posX;
    this->posY = posY;
    this->salto = salto;
  }

};

int BFS(int iniX, int iniY, int fimX, int fimY){
  int movX[] = {1, 1, -1, -1, 2, 2, -2, -2};
  int movY[] = {2, -2, 2, -2, 1, -1, 1, -1};
  int newX, newY;

  queue<No>fila;
  fila.push(No(iniX, iniY, 0));

  while(!fila.empty()){
    No aux = fila.front();
    fila.pop();

    if(aux.posX == fimX && aux.posY == fimY) return aux.salto;

    for(int i = 0; i < 8; i++){
      newX = aux.posX + movX[i];
      newY = aux.posY + movY[i];

      if(newX >= 1 && newY >= 1 && newX <= 8 && newY <= 8)
        fila.push(No(newX, newY, aux.salto+1));
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x1, x2, y1, y2, saltos;
  string ini, fim;

  while(cin >> ini >> fim){
    x1 = ini[0] - 'a' + 1;
    y1 = ini[1] - 48;

    x2 = fim[0] - 'a' + 1;
    y2 = fim[1] - 48;

    saltos = BFS(x1, y1, x2, y2);

    cout << "To get from "<< ini << " to " << fim << " takes "<< saltos << " knight moves." << endl;
  }

}
