#ifndef PELOTITA_H
#define PELOTITA_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Pelotita
{
    public:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
        int x;
        int y;
        int cont;
        int current_image;
        int velocidad_x;
        int velocidad_y;
        Pelotita *sig;
        int ball_width;
        int ball_height;
        bool en_pantalla;
        vector <SDL_Surface*> images;
        Pelotita();
        void moverse();
        void dibujar(SDL_Surface* screen);
        virtual ~Pelotita();
    protected:
    private:
};

#endif // PELOTITA_H
