#include <stdlib.h>
#include <time.h>


typedef struct pcb
{
    int cod;
    int tempo;
    int prioridade;
    int bloqueado;
    int tipo_bloqueio;
    pcb *prox;
    pbc *listaFilhos;
}PCB;



typedef struct filafifo
{
    PCB *inicio;
    PCB *fim;
}FILA;


PCB *criar_pcb(int cod, int tempo)
{
    srand(time(NULL));
    PCB *novo = new PCB();
    novo->cod = cod;
    novo->prox = NULL;
    novo->tempo = tempo;
    novo->prioridade = rand() % 11;
    novo->bloqueado = 0;
    novo->tipo_bloqueio = -1;
    novo->listaFilhos = NULL;
    return novo;
}

void addFilho(PCB **pai, int cod, int tempo)
{
    PCB *novo  = criar_pcb(cod,tempo);
    PCB *aux;
    if((*pai)->listaFilhos == NULL)
        (*pai)->listaFilhos = novo;
    else
    {
        aux = (*pai)->listaFilhos;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

void enqueue_fifo(FILA **f, PCB *novo)
{
    if((*f)->inicio == NULL)
        (*f)->fim = (*f)->inicio = novo;
    else
    {
        (*f)->fim->prox = novo;
        (*f)->fim = novo;
    }
}

void iniciar(FILA **f)
{
    (*f)->inicio = (*f)->fim = NULL;
}

bool isEmpty(FILA *f)
{
   return f->inicio == NULL;
}

PCB *dequeue_fifo(FILA **f)
{
    PCB *aux = (*f)->inicio;
    (*f)->inicio = (*f)->inicio->prox;

    return aux;
}

void enqueue_round(FILA **f, PCB *novo)
{
    if((*f)->inicio == null)
        (*f)->inicio = (*f)->fim = novo;
    else
    {
        novo->prox = (*f)->inicio;
        (*f)->fim->prox = novo;
        (*f)->fim = novo;
    }
}

int getTam(FILA *f)
{
    PCB *aux = f->inicio;
    int tam = 0;

    while(aux != null)
    {
        tam++;
        aux = aux->prox;
    }

    return tam;
}

PCB *dequeue_round(FILA **f)
{
    int tam = getTam(f);
    PCB *aux = (*f)->inicio;
    if(tam == 2)
       (*f)->inicio = (*f)->fim;
    else
    {
        (*f)->fim->prox = (*f)->inicio->prox;
        (*f)->inicio =  (*f)->inicio->prox;
    }
    return aux;

}
