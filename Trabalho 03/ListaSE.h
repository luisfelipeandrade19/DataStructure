struct ListaSE
{
    int info;
    struct ListaSE *prox;  
};

typedef struct ListaSE Lista;

Lista* criarLista();

Lista* insere(Lista* l, int i);

Lista* insereFinal(Lista* l, int i);

Lista* inserePosicao(Lista* l, int i, int p);

Lista* removePosicao(Lista* l, int p);

Lista* removeValor(Lista* l, int i);

Lista* obterPosicao(Lista* l, int p);

Lista* procurar(Lista* l, int i);

int tamanho(Lista* l);

void imprimir(Lista* l);