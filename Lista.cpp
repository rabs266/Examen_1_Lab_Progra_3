#include "Lista.h"

Lista::Lista()
{
    inicio = NULL;
}

void Lista::moverTodos()
{
    for(Pelotita *temp = inicio; temp!=NULL; temp = temp->sig)
    {
        temp->moverse();
    }
}

void Lista::agregarNodo(Pelotita *pelotita)
{
    if(inicio == NULL)
    {
        inicio = pelotita;
    }
    else
    {
        Pelotita *temp;
        for(temp = inicio; temp->sig!= NULL; temp = temp->sig)
        {
            //Solo para recorrer hasta donde queremos
        }
            temp->sig = pelotita;
    }
}

void Lista::imprimirTodos(SDL_Surface *screen)
{
    for(Pelotita *temp = inicio; temp!=NULL; temp = temp->sig)
    {
        temp->dibujar(screen);
    }
}

int Lista::detectarClick(int x, int y)
{
    if(x == -1 || y == -1)
    {
        return 0;
    }
    int cont = 0;
        Pelotita *temp;
        for(temp = inicio; temp->sig!= NULL; temp = temp->sig)
        {
            if(x >= temp->x && x <= temp->x+temp->ball_width &&
               y >= temp->y && y <= temp->y+temp->ball_height)
            {
                return borrar(cont);
            }
                cont++;
        }
        return 0;
}

int Lista::borrar(int pos)
{
    Pelotita *temp = inicio;
    if(pos == 0)
    {
        return 0;
    }

    if(pos == 0)
    {
        Pelotita *t_inicio = inicio;
        inicio = inicio->sig;
        int num = (t_inicio->current_image)+5;
        delete t_inicio;
        return num;
    }
    else
    {
        for(int i = 0; i < pos-1; i++)
        {
            temp = temp->sig;
            if(temp ==NULL)
            {
                return 0;
            }
        }
    }
    int num = 0;

    Pelotita *temp2;
    temp2 = temp->sig;
    num = (temp2->current_image)+5;
    temp->sig = temp2->sig;
    delete temp2;

    //Probando returnar Score y tomar en cuenta las pelotiras azules y rojas como score
    if(num < 2 && num > 0)
    {
        return num;
    }
    else
    {
        return 0;
    }

}

Lista::~Lista()
{
    //dtor
}
