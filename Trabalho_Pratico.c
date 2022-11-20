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

} Publi; // typedef da o apelido da struct

// array que armazena o nome e tipo de publicação e restatante das vs

void abertura()
{

    printf("****************************************************\n");
    printf("* Bem vindo ao registo referencias bibliograficas *\n");
    printf("****************************************************\n\n");

    system("pause"); // tem um pause
    system("cls");   // limpa a tela e segue pra outra linha de codigo
}

void menu(Publi obras[], int totalObras)
{

    int op; // option

    do
    {

        printf("Selecione uma das opcoes abaixo: \n\n");
        printf("\t1 - Inserir nova Refencia bibliografica \n");
        printf("\t2 - Listar \n");
        printf("\t3 - Estatistica total \n");
        printf("\t4 - Mostrar \n");
        printf("\t0 - Sair \n");
        scanf("%d", &op);

        getchar(); // limpar o buffer de memoria

        switch (op)
        {

        case 1:
            totalObras = inserir(obras, totalObras);
            break;

        case 2:
            listar(obras, totalObras);
            break;

        default:
            break;
        }

    } while (op != 0);

    printf("Saindo...");
}

int inserir(Publi obras[], int totalObras)
{

    system("cls");

    int op;
    char resp;

    do
    {

        printf("\nDigite o nome da publicacao: ");
        fflush(stdin);
        gets(obras[totalObras].nome);
        // printf("\nDigite o nome da publicacao: ");
        // scanf("%s", &nome);

        printf("\nTipo de publicacao (Livro, artigo cientifico, artigo de jornal, outros):");
        fflush(stdin);
        gets(obras[totalObras].tipo);
        // printf("\nTipo de publicacao (Livro, artigo cientifico, artigo de jornal, outros):");
        // scanf("%s", &tipo);

        printf("\nNome do autor:");
        fflush(stdin);
        gets(obras[totalObras].autor);

        printf("\nAno da publicacao:");
        scanf("%d", &obras[totalObras].ano_publi);

        printf("\nDigite o numero de paginas da publicacao: ");
        scanf("%d", &obras[totalObras].num_pag);

        printf("\nLocal da publicacao: ");
        fflush(stdin);
        gets(obras[totalObras].local);

        printf("Deseja registrar mais alguma publicao? Digite s ou n:\n");
        fflush(stdin);
        scanf("%c", &resp);

        totalObras = totalObras + 1;

        if (resp == 'n')
        {
            op = 0;
        }

    } while (op != 0);

    return totalObras;
}

void listar(Publi obras[], int totalObras)
{

    system("cls");
    printf(" \n LISTA DE REFERENCIAS BIBLIOGRAFICAS \n");

    for (int i = 0; i < totalObras; i++)
    {
        printf("%d - %s | %s | %s \n", i, obras[i].nome, obras[i].tipo, obras[i].autor);
    }
}

void alterar()
{
}

void eliminar()
{
}

void pesquisar()
{
}

int main()
{
    Publi obras[MAX_BIBLIO];
    int totalObras = 0;

    abertura();
    menu(obras, totalObras);

    // struct livros publicacao; // publicacao é a variavel, struct livros é um tipo de dado

    // printf("Nome da publicacao : ");
    // fgets(publicacao.nome, 50, stdin); // stdin pega do igual scanf mas em char ; a variavel *publicação* é do tipo struct livros, amazenando publi em *nome* dentro da struct

    // printf("Nome do livro : %s", publicacao.nome);
}
