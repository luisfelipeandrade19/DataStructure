typedef struct pilha Pilha;


Pilha* criaPilha();

//push == inserir
void push(Pilha *p, float valor);       


int pilhaVazia(Pilha *p);

//pop == remover do topo
float pop(Pilha *p);                    


void pilhaLibera(Pilha *p);


void pilhaImprime(Pilha *p);