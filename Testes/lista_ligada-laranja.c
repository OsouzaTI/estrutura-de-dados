//resolvendo a questão com o uso de lista encadeada 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int valor;          //informação de cada elemento
    struct node* prox;  //um ponteiro para o proximo elemento da lista
}Node;


//inicializa a lista vazia
Node* inicializar(void){            
    return NULL;
    
}
/*Inserção no inicio: retorna a lista atualizada
Nesse caso, o ultimo elemento inserido é o primeiro da lista
*/
Node* inserir(Node* lista, int val){
    Node* novo = (Node*) malloc (sizeof(Node));     //aloca dinamicanente o espaço para armazenar o novo no  da lista
    if( novo == NULL){
        printf("\nERROR MEMORIA NÃO ALOCADA !\n");
        exit(1);
    }
    novo->valor = val;    //guarda  a informamação do novo no
    novo->prox = lista;     //aponta seu ponteiro para o elemento que era o primeiro da lista. Agora este passa a ser o primeiro da lista
    
    return novo;
}

Node* InserirFinalLista(Node* lista, int val){                             
    if (lista == NULL){
        lista = (Node*) malloc(sizeof(Node));   
        lista->valor = val;
        lista->prox = NULL;
        return lista;
    }else{
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->valor = val;
        novo->prox = NULL;

        Node* p = lista;
        for(p = lista;p;p=p->prox)
            if(p->prox == NULL)break;
        p->prox = novo;
        return lista;        
    }
}

int vazia(Node* lista){
    return (lista == NULL); ///se a lista for vazia retorna 1 (true) senao 0 (false)
}

void imprimir(Node* lista){
    Node* p;                    //define uma variavel auxiliar pra percorrer a lista
    for(p = lista; p != NULL; p = p->prox){ //para p que recebe nossa lista, ele imprime até chegar no NULL (final), incrementando o proximo endereço de memória reservado
        printf("%d -> ", p->valor);
        
    }
    printf("NULL");
}
void libera(Node* lista){
    Node* p = lista;
    while( p != NULL){
        Node*  t = p->prox; //guardar a referencia  par o proximo elemento
        free(p);            //libero memoria apontada por p
        p = t;              //faz p apontar para o proximo
    }
}


int main(){
    Node* l;
    l = inicializar();
    l = InserirFinalLista(l,444);
    l = InserirFinalLista(l,4);
    l = InserirFinalLista(l,84);
    l = inserir(l, 15);
    l = inserir(l, 45);
    l = inserir(l, 35);
    l = inserir(l, 25);
    imprimir(l);
    return 0;
}