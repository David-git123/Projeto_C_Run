

#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct dificuldade {
    int qtd_decrescimo;
    int max_loops;
    struct dificuldade* proximo;
}dificuldade;



int main(void)
{
    Color cor = BLACK;
    const int screenWidth = 800;
    const int screenHeight = 450;
    int posicao_x_rect = 800;
    int numero = 0;
    int contador = 0;
    dificuldade* dificuldade_1 = malloc(sizeof(dificuldade));
    dificuldade* dificuldade_2 = malloc(sizeof(dificuldade));
    dificuldade* dificuldade_3 = malloc(sizeof(dificuldade));
    dificuldade* dificuldade_4 = malloc(sizeof(dificuldade));
    dificuldade_1->qtd_decrescimo = 5;
    dificuldade_1->max_loops = 3;
    dificuldade_1->proximo = dificuldade_2;
    dificuldade_2->qtd_decrescimo = 10;
    dificuldade_2->max_loops = 6;
    dificuldade_2->proximo = dificuldade_3;
    dificuldade_3->qtd_decrescimo = 18;
    dificuldade_3->max_loops = 10;
    dificuldade_3->proximo = dificuldade_4;
    dificuldade_4->qtd_decrescimo = 24;
    dificuldade_4->max_loops = 20;
    dificuldade_4->proximo = NULL;

    
   

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);              
 
    dificuldade* atual = dificuldade_1;
    while (!WindowShouldClose())    
    {
        
        if (contador == atual->max_loops && atual->proximo!=NULL) {
            atual = atual->proximo;
        }

        if (posicao_x_rect <= -100) {
            int time = 0;
            posicao_x_rect = 800;
            contador++;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (posicao_x_rect >= 700) {

            numero = rand() % (5);
            switch (numero) {

            case 0:
                cor = PURPLE;
                break;

            case 2:
                cor = GREEN;
                break;

            case 3:
                cor = DARKBROWN;
                break;

            case 4:
                cor = PINK;
                break;

            }

        }
        DrawRectangle(posicao_x_rect, 100, 100, 100, cor);
        DrawCircle(20, 125, 20, RED);
        posicao_x_rect = posicao_x_rect - atual->qtd_decrescimo;
        EndDrawing();
    }
    CloseWindow();

    return 0;
}

