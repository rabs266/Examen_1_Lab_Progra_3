#include "Pelotita.h"

Pelotita::Pelotita()
{
    //PARA GENERAR ME AYUDO JAVIER EN ESTE CONSTRUCTOR
    this->sig = NULL;
    this->en_pantalla=true;

    //Inicializamos el tamao de la pelotita
    this->ball_height=40;
    this->ball_width=40;

    //Creamos la instancia de Random respecto al tiempo
    srand(time(NULL));

    //Generamos las pelotitas Random
    this-> x = 0 + rand()%(644+1-0);
    this-> y = 0 + rand()%(479+1-0);

    //Velocidad Random
    this-> velocidad_x = 1 + rand()%(2+1-0);
    this-> velocidad_y = 1 + rand()%(2+1-0);

    if(x>323){
    velocidad_x = (velocidad_x*-1);
    }
    if(y>240){
    velocidad_y = (velocidad_y*-1);
    }

    //Metemos las imagenes de pelotitas al Vector de Imagenes
    images.push_back(IMG_Load("PelotitaAzul.png"));
    images.push_back(IMG_Load("PelotitaRoja.png"));

    //Generamos Random el tipo de pelota a mostrar en la pantalla
    current_image= 0 + rand()%(2+0-0);
}

void Pelotita::moverse()
{
    this->x += this->velocidad_x;
    this->y += this->velocidad_y;
    if(y>SCREEN_WIDTH +50 || x>SCREEN_HEIGHT +50 || y < -50 || x < -50)
    {
        this->en_pantalla = false;
    }
    else
    {
        this->en_pantalla = true;
    }
}

void Pelotita::dibujar(SDL_Surface* screen){
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( images[current_image], NULL, screen, &offset);
}

Pelotita::~Pelotita()
{
    //dtor
}

