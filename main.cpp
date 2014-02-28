#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Pelotita.h"
#include "SDL/SDL_mixer.h"
#include "Lista.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *main_menu = NULL;
SDL_Surface *start = NULL;
SDL_Surface *score = NULL;
SDL_Surface *quitgame = NULL;
Mix_Music *music = NULL;

int start_width = 100;
int start_heigth = 40;
int score_width = 100;
int score_heigth = 40;
int quitgame_width = 100;
int quitgame_heigth = 40;

SDL_Event event;

SDL_Surface *load_image( std::string filename )
{
    return IMG_Load(filename.c_str());
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    if( screen == NULL )
    {
        return false;
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    SDL_WM_SetCaption( "Press an Arrow Key", NULL );

    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "background.png" );
    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    music = Mix_LoadMUS( "DissonantWaltz.ogg" );

    if( music == NULL )
    {
        return false;
    }
        return true;

    return true;
}

void clean_up()
{
    SDL_FreeSurface( background );
    SDL_Quit();
}

int actual_logic = 0;

int start_x = 270;
int start_y = 260;
int score_x = 270;
int score_y = 310;
int quitgame_x = 270;
int quitgame_y = 360;

int contador=0;

Lista lis;

void crearPelotita(int num)
{
    // CON 5 SE CREA CHORIZO, Y CON 100 DE UNA EN UNA
    if(num%100==0)
    {
        lis.agregarNodo(new Pelotita());
    }
}

int main()
{
    bool quit = false;

    if( init() == false )
    {
        return 1;
    }

    if( load_files() == false )
    {
        return 1;
    }

    while( quit == false )
    {
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

    ////////////////////////////////////////////////////////////////MENU PRINCIPAL///////////////////////////////////////////////////////////////////
    apply_surface( 0, 0, background, screen );

    main_menu = load_image("MenuScreen.png");
    apply_surface( 200, 45, main_menu, screen );
    start = load_image("BotonStart.png");
    apply_surface( start_x, start_y, start, screen );
    score = load_image("BotonScore.png");
    apply_surface( score_x, score_y, score, screen );
    quitgame = load_image("BotonExit.png");
    apply_surface( quitgame_x, quitgame_y, quitgame, screen );

    ////////////////////////////////////////////////////////////VALIDACION DE LOS BOTONES/////////////////////////////////////////////////////////////

    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.x > start_x && event.button.x < start_width+start_x && event.button.y > start_y && event.button.y < start_heigth+start_y)
    {
        actual_logic = 1;
        quit = true;
    }

    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.x > score_x && event.button.x < score_width+score_x && event.button.y > score_y && event.button.y < score_heigth+score_y)
    {
        actual_logic = 2;
        quit = true;
    }

    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.x > quitgame_x && event.button.x < quitgame_width+score_x && event.button.y > quitgame_y && event.button.y < quitgame_heigth+quitgame_y)
    {
        actual_logic = 3;
        quit = true;
    }

    /////////////////////////////////////////////////////////FIN DE VALIDACION DE BOTONES/////////////////////////////////////////////////////////////

    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }
        SDL_Delay(1);
    }

    quit = false;

    /////////////////////////////////////////////////////CICLO DE JUEGO AL SELECCIONAR START/////////////////////////////////////////////////////////

    if(actual_logic == 1){

    int ball_count;
    int ball_freq;

    lis.agregarNodo(new Pelotita());

    while(quit == false){

        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

    //Creamos la pelotita
    crearPelotita(contador);

    //Evento que detecta si el mouse pasa por la pelotita
    int numero = lis.detectarClick(event.button.x, event.button.y);

    //Movemos las pelotitas
    lis.moverTodos();

    //Aplicamos la surface
    apply_surface( 0, 0, background, screen );

    //PLAY LA MUSICA
    if( Mix_PlayingMusic() == 0 )
    {
        if( Mix_PlayMusic( music, -1 ) == -1 )
        {
            return 1;
        }
    }

    //IMPRIMIMOS LAS PELOTITAS
    lis.imprimirTodos(screen);

    if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

       SDL_Delay(1);

        contador++;

    }
    }

    ///////////////////////////////////////////////////////////OPCION MOSTRAR SCORE/////////////////////////////////////////////////////////////////
    if(actual_logic == 2)
    {
        exit(0);
    }

    ///////////////////////////////////////////////////////////OPCION SALIR DEL JUEGO///////////////////////////////////////////////////////////////
    if(actual_logic == 2)
    {
        exit(0);
    }

    clean_up();

    return 0;
}
