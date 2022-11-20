#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_BIBLIO 100

typedef struct 
{


    char nome[50];
    char tipo[50];
    char autor[50];
    int ano_publi;
    char local[15];
    int num_pag;


}Publi; //typedef da o apelido da struct 

Publi obras[MAX_BIBLIO]; // array que armazena o nome e tipo de publicação e restatante das vs

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
        scanf ("%d", &op);

        getchar(); // limpar o buffer de memoria

            switch (op) {
            
                case 1:
                    inserir();
                    break;

                case 2:
                    listar();
                    break;
            
            default:
                break;
            }
            
            
        } while(op != 0);

        printf("Saindo...");
    } 



    char nome[50];
    char tipo[50];
    char autor[50];
    int ano_publi;
    char local[15];
    int num_pag;




void inserir(){

    system("cls");

    int op;
    char resp;

    
    do
    {

        printf("\nDigite o nome da publicacao: ");
        fgets(nome,sizeof(nome),stdin);
        //printf("\nDigite o nome da publicacao: ");
        //scanf("%s", &nome);

        printf("\nTipo de publicacao (Livro, artigo cientifico, artigo de jornal, outros):");
        fgets(tipo,sizeof(tipo),stdin);       
       // printf("\nTipo de publicacao (Livro, artigo cientifico, artigo de jornal, outros):");
        //scanf("%s", &tipo);
        
        printf("\nNome do autor:");
        scanf("%s", &autor);

        printf("\nAno da publicacao:");
        scanf("%d", &ano_publi);

        printf("\nDigite o numero de paginas da publicacao: ");
        scanf("%d", &num_pag);

        printf("\nLocal da publicacao: ");
        scanf("%s", &local);




        printf("Deseja registrar mais alguma publicao? Digite s ou n:\n");
        scanf("%s",&resp);

            if (resp == 'n')
            {
                op = 0;
            }
            
        



    } while (op != 0);
    
}


void listar(){

    system("cls");
    printf(" \n LISTA DE REFERENCIAS BIBLIOGRAFICAS \n");

    for ( int i = 0; i < MAX_BIBLIO; i++)
    {
        printf("\n ------------------\n");
        printf("Nome publicacao %s", nome);


    }
    

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

    
    
    //struct livros publicacao; // publicacao é a variavel, struct livros é um tipo de dado
    


    
    //printf("Nome da publicacao : ");
    //fgets(publicacao.nome, 50, stdin); // stdin pega do igual scanf mas em char ; a variavel *publicação* é do tipo struct livros, amazenando publi em *nome* dentro da struct

    //printf("Nome do livro : %s", publicacao.nome);



		
	}
	



