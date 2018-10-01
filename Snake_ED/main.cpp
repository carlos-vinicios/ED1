#include <stdlib.h>
#include <stdio.h>
#include "TAD_fila.h"
#include "TAD_pilha.h"
#include "cenario.h"
#include "snake.h"
#include "fruta.h"

#define LINUX

//https://www.vivaolinux.com.br/topico/C-C%2B%2B/kbhit()-no-linux

#ifdef LINUX
	#include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#else
	#include <conio.h>
    #include <Windows.h>
    #include <iostream>
#endif

using namespace std;

#ifdef LINUX
int kbhit(void){
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}
#endif // LINUX

void render(Fila *snake, char **cenario, Fruta *fruta, int lin, int col, int orien, int dire, int cen_tam, int pnts){
    system("CLS");
    cout << "Pontos: " << pnts << '\n';
    start_cenario(cenario, cen_tam);
    draw_snake(snake, cenario, lin, col, orien, dire, cen_tam);
    draw_fruta(cenario, fruta);
    draw_cenario(cenario, cen_tam);
}

int main(){
    Fila *snake;
    Fruta *fruta;
    int cen_tam, pnts, lin, col, orien, dire, vel, exec=1;
    char **cenario;

    //Definições iniciais do jogo
    lin = 3; //linha inicial
    col = 4; //coluna inicial
    orien = 180; //180 = horizontal 90 = vertical
    dire= 1; // dire > 0 eixo positivo | dire < 0 eixo negativo
    cen_tam = 30; //100x100
    vel = 100; //tempo que passa no sleep
    pnts=0;
    //fim das definições iniciais

    cenario = set_cenario(cen_tam); //aloca a memória para o cenário
    snake = set_snake(cen_tam);//aloca a memória para a snake
    fruta = new_fruta(cen_tam, lin, col); //define uma posicao inicial para a fruta

    if(cenario != NULL && snake != NULL){
        while(exec){
            render(snake, cenario, fruta, lin, col, orien, dire, cen_tam, pnts);
            #ifndef LINUX //código para windows
            if (_kbhit()){
                switch(_getch()){
                    case 'w':
                        orien = 90;
                        dire = -1;
                        break;
                    case 's':
                        orien = 90;
                        dire = 1;
                        break;
                    case 'a':
                        orien = 180;
                        dire = -1;
                        break;
                    case 'd':
                        orien = 180;
                        dire = 1;
                        break;
                }
            }
            #else //código para linux

            #endif
            if(snake_eat(lin, col, fruta)){
                eat_fruit(snake);
                fruta = new_fruta(cen_tam, lin, col);
                pnts++;
            }
            move_snake(dire, orien, &lin, &col);
            if(hit_wall(lin, col, cen_tam)){
                if(snake_die(snake)){
                    exec = 0;
                }else{
                    lose_life(snake);
                }
                if(dire < 0)
                    dire = 1;
                else
                    dire = -1;
            }
            #ifndef LINUX
            Sleep(vel);
            #else

            #endif
        }
    }else{
        cout << "Erro na inicializacao do jogo, veja seu sistema operacional ou estado de memoria";
    }

    system("CLS");
    cout << "Game Over\n" << "Pontuacao total: " << pnts;
    return 0;
}
