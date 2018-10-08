#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "TAD_fila.h"
#include "TAD_pilha.h"
#include "cenario.h"
#include "snake.h"
#include "fruta.h"

//caso esteja no Linux, descomentar a proxima linha
//#define LINUX

#ifdef LINUX
    #include <sys/ioctl.h>
    #include <termios.h>
    #include <unistd.h>
#else
    #include <conio.h>
    #include <Windows.h>
#endif

using namespace std;

#ifdef LINUX
void enable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
    tcsetattr(0, TCSANOW, &term);
}

void disable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(0, TCSANOW, &term);
}

bool kbhit()
{
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}
#endif // LINUX

void render(Fila *snake, char **cenario, Fruta *fruta, int lin, int col, int orien, int dire, int cen_tam, int pnts){
    #ifndef LINUX
        system("CLS");
    #else
        system("clear");
    #endif
    cout << "Pontos: " << pnts << '\n';
    start_cenario(cenario, cen_tam);
    draw_snake(snake, cenario, lin, col, orien, dire, cen_tam);
    draw_fruta(cenario, fruta);
    draw_cenario(cenario, cen_tam);
}

int main(){
    #ifdef LINUX
        enable_raw_mode();
    #endif
    Fila *snake;
    Fruta *fruta;
    int cen_tam, pnts, lin, col, orien, dire, vel, exec=1;
    char **cenario;

    //Defini��es iniciais do jogo
    lin = 3; //linha inicial
    col = 4; //coluna inicial
    orien = 180; //180 = horizontal 90 = vertical
    dire= 1; // dire > 0 eixo positivo | dire < 0 eixo negativo
    cen_tam = 30; //100x100
    #ifndef LINUX
    vel = 300; //tempo que passa no sleep
    #else
    vel = 100000;
    #endif
    pnts=0;
    //fim das defini��es iniciais

    cenario = set_cenario(cen_tam); //aloca a mem�ria para o cen�rio
    snake = set_snake(cen_tam);//aloca a mem�ria para a snake
    fruta = new_fruta(cen_tam, lin, col); //define uma posicao inicial para a fruta

    if(cenario != NULL && snake != NULL){
        while(exec){
            render(snake, cenario, fruta, lin, col, orien, dire, cen_tam, pnts);
            #ifndef LINUX //c�digo para windows
            if (_kbhit()){
                switch(_getch()){
            #else //codigo para Linux
            if (kbhit()){
                switch(getchar()){
            #endif
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
            #ifdef LINUX
            tcflush(0, TCIFLUSH); // Clear stdin to prevent characters appearing on prompt
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
            usleep(vel);
            #endif
        }
    }else{
        cout << "Erro na inicializacao do jogo, veja seu sistema operacional ou estado de memoria";
    }
    #ifndef LINUX
    system("CLS");
    #else
    system("clear");
    #endif
    cout << "Game Over\n" << "Pontuacao total: " << pnts;
    #ifdef LINUX
    disable_raw_mode();
    #endif
    return 0;
}
