#ifndef LISTA_H
#define LISTA_H
#include "Pelotita.h"

class Lista
{
    public:
        Lista();
        Pelotita *inicio;

        void imprimirTodos(SDL_Surface *screen);
        void moverTodos();
        void agregarNodo(Pelotita *pelotita);
        void borrarSiSalio();
        int borrar(int pos);
        int detectarClick(int x, int y);
        void liberarTodos();

        virtual ~Lista();
    protected:
    private:
};

#endif // LISTA_H
