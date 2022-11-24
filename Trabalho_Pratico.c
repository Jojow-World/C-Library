#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_BIBLIO 100

typedef struct
{
    int id;
    char nome[50];
    char tipo[50];
    char autor[50];
    int ano_publi;
    char local[15];
    int num_pag;
    char palavra_chave[20][20];

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
        printf("\t4 - Eliminar \n");
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

        case 4:
            totalObras = eliminar(obras, totalObras);
            printf("%d", totalObras);
            break;
        case 0:
            break;
        default:
            
            break;
        }

    } while (op != 0);

    printf("Saindo...");
}



int inserir(Publi obras[], int totalObras) // inteiro ?
{

    system("cls");

    int op;
    char resp;

    do
    {

        printf("\nDigite o nome da publicacao: ");
        fflush(stdin);
        gets(obras[totalObras].nome);

        printf("\nTipo de publicacao (Livro, artigo cientifico, artigo de jornal, outros):");
        fflush(stdin);
        gets(obras[totalObras].tipo);

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

        obras[totalObras].id = totalObras + 1; // para o id n começar em 0, e sim em 1
        totalObras = totalObras + 1;

        if (resp == 'n')
        {
            op = 0;
        }

    } while (op != 0);

    system("cls");

    return totalObras;
}




void listar(Publi obras[], int totalObras) // declaracao obras(struct publi) e inteiro totalObras
{

    system("cls");
    int op;

    do
    {

        printf("\nSelecione uma das opcoes abaixo: \n\n");
        printf("\t1 - Listar tudo \n");
        printf("\t2 - Todas as publicações de um autor \n");
        printf("\t3- Todas as publicacoes de um tipo \n ");
        printf("\t0 - Voltar ao menu \n");
        scanf("%d", &op);

        getchar(); // limpar o buffer de memoria

        switch (op)
        {

        case 1:
            listarTudo(obras, totalObras);
            break;
        case 2:
            todasAsPublicacoesAutor(obras, totalObras);
            break;
        case 3:
            todasAsPublicacoesTipo(obras, totalObras);
            break;

        default:
            printf("\tPor favor, selecione apenas 1, 2 ou 0\n");
            break;
        }

    } while (op != 0);

    system("cls");
}


void listarTudo(Publi obras[], int totalObras)
{
    for (int i = 0; i < totalObras; i++)
    {
        printf("\tid: %d - Nome: %s | Tipo: %s | Autor:%s \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor);
    }

    system("pause");
}


void todasAsPublicacoesAutor(Publi obras[], int totalObras)
{
    char autor[20];

    printf("Digite nome do autor: ");
    fflush(stdin);
    gets(autor);

    for (int i = 0; i < totalObras; i++)
    {
        if (!strcmp(obras[i].autor, autor)) // string compar função de comparaçaõ, se obra[i].autor é diferente de autor
        {
            printf("\tId:%d - Nome: %s | Tipo: %s | Autor: %s \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor);
        }
    }

     system("pause");
}





void todasAsPublicacoesTipo(Publi obras[], int totalObras){

        char tipo[20];

        printf("Digite um tipo de publicacao(Livro,jornal...etc): ");
        fflush(stdin);
        gets(tipo);

        for (int i = 0; i < totalObras; i++)
        {
            if (!strcmp(obras[i].tipo, tipo))
            {
                printf("\t Id:%d - Nome: %s | Tipo: %s | Autor: %s \n\n",obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor);
            }
               
        }
        

}


void alterar()
{
}

int eliminar(Publi obras[], int totalObras)
{
    int id;

    listarTudo(obras, totalObras);

    printf("\tDigite id da obra que quer eliminar: \n");
    scanf("%d", &id);

    for (int i = 0; i < totalObras; i++)
    {
        if (obras[i].id == id)
        {
            // 2            4
            if (obras[i].id == totalObras) // comparar para saber se o id escolhido é a ultima posicao do array
            {
                totalObras = totalObras - 1;
                return totalObras;
            }
            //       1  =  2 - 1;    1 < 4
            for (int i = id - 1; i < totalObras; i++) // se nao for o ultimo do array
            {
                obras[i] = obras[i + 1];
            }
            totalObras = totalObras - 1;
            return totalObras;
        }
    }
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