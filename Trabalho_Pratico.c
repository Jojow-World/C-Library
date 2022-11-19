#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_BIBLIO 100



void abertura(){

    printf("****************************************************\n");
    printf("* Bem vindo ao registo referencias bibliograficas *\n");
    printf("****************************************************\n\n");

    system("pause"); // tem um pause
    system("cls"); // limpa a tela e segue pra outra linha de codigo

}




void menu(){

    int op; // option
    
    do{

        printf("Selecione uma das opcoes abaixo: \n\n");
        printf("\t1 - Inserir nova Refencia bibliografica \n");
        printf("\t2 - Listar \n");
        printf("\t3 - Estatistica total \n");
        printf("\t4 - Mostrar \n");
        printf("\t0 - Sair \n");

        scanf ("%d", op);

            switch (op) {
            
                case 1:
                    inserir();
                    break;
            
            default:
                break;
            }
            
            
        } while(op != 0);


    } 




typedef struct 
{

    char nome[50];
    char tipo[50];
    char autor[50];
    int num_publi;
    char local[15];
    int num_pag;


}Publi; //typedef da o apelido da struct 

Publi obras[MAX_BIBLIO]; // array que armazena o nome e tipo de publicação e restatante das vs







void inserir(){

    system("cls");

    char nome[50];
    char tipo[50];
   // char autor[50];int num_publi;  char local[15]; int num_pag; 
   int op;
    
    do
    {

        printf("\nDigite o nome da publicacao: ");
        fgets(nome,sizeof(nome),stdin);

        printf("\n1Tipo de publicacao (Livro, artigo cientifico, artigo de jornal, outros): ");
        fgets(tipo,sizeof(tipo),stdin);
        

    } while (op != 0);
    


}

void mostrar(){

}

void alterar(){

}

void eliminar(){

}

void pesquisar(){

}




 

int main(){

    abertura();
    menu();
    inserir();
    
    //struct livros publicacao; // publicacao é a variavel, struct livros é um tipo de dado
    


    
    //printf("Nome da publicacao : ");
    //fgets(publicacao.nome, 50, stdin); // stdin pega do igual scanf mas em char ; a variavel *publicação* é do tipo struct livros, amazenando publi em *nome* dentro da struct

    //printf("Nome do livro : %s", publicacao.nome);



		
	}
	



