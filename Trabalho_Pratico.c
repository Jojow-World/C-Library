#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef struct livros
{
    char nome[50];
};



void abertura(){

    printf("****************************************************\n");
    printf("* Bem vindo ao registo referencias bibliograficas *\n");
    printf("****************************************************\n\n");

    system("pause"); // tem um pause
    system("cls"); // limpa a tela e segue pra outra linha de codigo

}



int main(){



abertura();

    struct livros publicacao;
    

    


    
    printf("Nome da publicacao : ");
    fgets(publicacao.nome, 50, stdin); // stdin pega do teclado igual scanf

    printf("Nome do livro : %s", publicacao.nome);



		
	}
	



