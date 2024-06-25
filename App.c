#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdio.h>
//gcc App.c -I SDL2\i686-w64-mingw32\include -L SDL2\i686-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2

int main(int argc, char** argv)
{
  SDL_Init(SDL_INIT_EVERYTHING);
    
  SDL_Window* window = SDL_CreateWindow("App - Conecta 4", 100, 100, 1280, 720, SDL_WINDOW_SHOWN);
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
  //SDL_Texture * img;
  
  //interface tabuleiro

  //evento --> jogo
  while(1)
  {
    SDL_Event event;
    //sair do jogo
    while(SDL_PollEvent(&event))
    {
      if( event.type == SDL_QUIT )
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

  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 240, 250, 50, 255);
  SDL_SetRenderDrawColor(renderer, 9, 20, 255, 255);
  SDL_RenderPresent(renderer);
  

  //SDL_DestroyTexture(img);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

