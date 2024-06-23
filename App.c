#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdio.h>
//gcc App.c -I SDL2\i686-w64-mingw32\include -L SDL2\i686-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("App - Conecta 4", 100, 100, 1280, 720, SDL_WINDOW_SHOWN);

    //cria um redenizador
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    //SDL_Texture * img = IMG_LoadTexture(renderer, "WhatsApp Image 2024-06-18 at 10.02.39.jpeg.png");

    //interface tabuleiro

    //evento --> jogo
    while(1)
    {
        SDL_Event event;
        //sair do jogo
        while(SDL_PollEvent(&event))
        {
            //se o usuario fechar a janela do jogo, o programa encerra
            if(event.type == SDL_QUIT)
            {
                exit(0);
            }

          /*else if( event.type == SDL_MOUSEBUTTONDOWN)
          {
                //evento do jogador
            int mouse_x = event.button.x;
            int mouse_y = event.button.y;
            printf("A coord_x eh: %d\n", mouse_x);
            printf("A coord_y eh: %d\n", mouse_y);
            if(dentro das coordenadas)
            {
              if(com bolinha --> flag)
              {
              //erro
              }
              else{
              //coloca a bolinha na posição mouse_x e mouse_y
              }
            }
          //if 4 bolihas mesma cor, win
          }*/
        }
    }

    //limpa a cor do renderizador
    SDL_RenderClear(renderer);

    //renderizador está com a cor amarela, mas nao ta usando pra nada ainda
    SDL_SetRenderDrawColor(renderer, 240, 250, 50, 255);

    //renderizador vai usar a cor azul
    SDL_SetRenderDrawColor(renderer, 9, 20, 255, 255);

    //mostra o conteudo do renderizador na janela
    SDL_RenderPresent(renderer);



    //SDL_DestroyTexture(img);

    //libera memoria e recursos utilizados por um renderizador
    SDL_DestroyRenderer(renderer);

    //libera memoria e recursos utilizados por uma janela
    SDL_DestroyWindow(window);

    //so chamar depois de todos os recursos (janelas, renderizadores...) terem sido destruidos
    SDL_Quit();

    return 0;
}

