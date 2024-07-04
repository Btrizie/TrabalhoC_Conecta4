#include "SDL2/x86_64-w64-mingw32/include/SDL2/SDL.h"
#include "SDL2/x86_64-w64-mingw32/include/SDL2/SDL_image.h"
#include <stdbool.h>
#include <stdio.h>
//gcc App.c -I SDL2\x86_64-w64-mingw32\include\SDL2 -L SDL2\x86_64-w64-mingw32\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

int verificaColuna (int x);
int verificaLinha (int coluna, int matriz[6][7]);

int main(int argc, char** argv){
  SDL_Init(SDL_INIT_EVERYTHING);
  
  SDL_Window* window = SDL_CreateWindow("Interface Gráfica usando SDL", 100, 100, 1280, 720, SDL_WINDOW_SHOWN);
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Texture * img = IMG_LoadTexture(renderer, "Tabuleiro.png"); 
  SDL_Texture * circleR = IMG_LoadTexture(renderer, "CRed.png"); 
  SDL_Texture * circleY = IMG_LoadTexture(renderer, "CYellow.png"); 

//1, quando for a vez do jogador 1, e 2, quando for a vez do jogador 2  
  int jogador = 1;

//matriz que representa o tabuleiro
  int matriz[6][7];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            matriz[i][j]=0;
        }
    }

//interface tabuleiro
  SDL_Rect quad1, quad2, quad3; 
//quad1 --> é relacionado ao tabuleiro
  quad1.x = 20;
  quad1.y = 20;
  quad1.w = 900;
  quad1.h = 610;

//quad2 --> é relacionado a pecinha Vermelha
  //--> posição da imagem
  quad2.x = 27;
  quad2.y = 25;
  //--> achatar imagem
  quad2.w = 110;
  quad2.h = 85;

//quad3 --> é relacionado a pecinha Amarela
  //--> posição da imagem
  quad3.x = 157;
  quad3.y = 25;
  //--> achatar imagem
  quad3.w = 110;
  quad3.h = 85;

//evento --> jogo
  while(true)
  {
    SDL_Event event;
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, img, NULL, &quad1);
    SDL_SetRenderDrawColor(renderer, 127, 207, 240, 255); //altera cor de fundo
    
    while(SDL_PollEvent(&event)){
      //sair do jogo
      if( event.type == SDL_QUIT ){
        exit(0);
      }

	    else if( event.type == SDL_MOUSEBUTTONDOWN)
      {
        int mouse_x = event.button.x;
        int mouse_y = event.button.y;
        
        int x, y;
        x = verificaColuna (mouse_x);
        y = verificaLinha (mouse_y, matriz);

        if (x >= 0 && y >= 0)
        {
          matriz[x][y] = jogador; 
        }
        
        if (jogador == 1)
          jogador = 2;
        else 
          jogador = 1;
        
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
        //quad2.x -= 20;
      }
    }
    for (int i = 0; i < 6; ++i) 
    {
      for (int j = 0; j < 7; ++j) 
      {
        SDL_Rect posicaoPeca;
      posicaoPeca.x = 25;
      posicaoPeca.y = 27;
      posicaoPeca.w = 110;
      posicaoPeca.h = 85;
        if (matriz[i][j] == 1) 
        {
          posicaoPeca.x += 130 * i;
          posicaoPeca.y += 102 * j;
          SDL_RenderCopy(renderer, circleR, NULL, &posicaoPeca);
        } 
        else if (matriz[i][j] == 2) 
        {
          posicaoPeca.x += 130 * i;
          posicaoPeca.y += 102 * j;
          SDL_RenderCopy(renderer, circleY, NULL, &posicaoPeca);
        }
      }
    } 
    SDL_RenderCopy(renderer, circleR, NULL, &quad2);   
    SDL_RenderCopy(renderer, circleY, NULL, &quad3);   
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(img);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}


int verificaColuna (int x)
{
  if (x > 27 && x < 157) 
  {
    return 0;
  }    
  else if (x < 287)
  {
    return 1; 
  }
  else if (x < 417)
  {
    return 2;
  }
  else if (x < 547)
  {
    return 3;
  }
  else if (x < 677)
  {
    return 4;
  }
  else if (x < 807)
  {
    return 5;
  }
  else if (x < 937) //nao sei o limite do tabuleiro
  {
    return 6;
  }
  else
  {
    return -1;
  }
}

int verificaLinha (int coluna, int matriz[6][7]) 
{
  int linha = 5; 
  while (linha >= 0)
  {
    if (matriz[linha][coluna] > 0)
    {
      if (linha == 0)
        return -1;
      else
        return linha - 1;
    }
    linha--;
  }
  return 5;
}
