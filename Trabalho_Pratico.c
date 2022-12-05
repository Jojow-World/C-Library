#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_BIBLIO 50

typedef struct
{
    int id;
    char nome[50];
    char tipo[50];
    char autor[50];
    char autorApelido[50];
    int ano_publi;
    char local[15];
    int num_pag;
    char palavra_chave[5][20]; // 5 palvras de 20 letras
    int total_chave;

} Publi; // typedef da o apelido da struct, para nao precisar usar struct "..." toda vez

// array que armazena o nome e tipo de publicação e restatante das vs

void totalPalavrasChave(Publi obras[], int totalObras)
{

    int totalPalavrasChavePossivel = 250;

    char aux[totalPalavrasChavePossivel][20];
    int totalAux = 0; // variavel contadora
    int palavraChaveJaExistente = 0;

    for (int i = 0; i < totalObras; i++)
    {
        for (int j = 0; j < obras[i].total_chave; j++)
        {
            if (totalAux == 0)
            {
                strcpy(aux[totalAux], obras[i].palavra_chave[j]);
                totalAux++;
                continue;
            }

            for (int k = 0; k < totalAux; k++)
            {
                if (!strcmp(obras[i].palavra_chave[j], aux[k]))
                {
                    palavraChaveJaExistente = 1;
                    break;
                }
            }

            if (!palavraChaveJaExistente)
            {
                strcpy(aux[totalAux], obras[i].palavra_chave[j]);
                totalAux++;
            }

            palavraChaveJaExistente = 0;
        }
    }

    for (int i = 0; i < totalAux; i++)
    {
        printf("Palavra chave: %s\n", aux[i]);
    }

    printf("\nTotal de palavras chave: %d \n", totalAux);

    system("pause");
    system("cls");
}

int inserir(Publi obras[], int totalObras) // inteiro para add ao total de obras
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

        printf("\nApelido Autor: ");
        fflush(stdin);
        gets(obras[totalObras].autorApelido);

        printf("\nAno da publicacao:");
        scanf("%d", &obras[totalObras].ano_publi);

        printf("\nDigite o numero de paginas da publicacao: ");
        scanf("%d", &obras[totalObras].num_pag);

        printf("\nLocal da publicacao: ");
        fflush(stdin);
        gets(obras[totalObras].local);

        printf("\nQuantas palavras chaves para esta publicao(Digite 1,2,..., ou 0 para nenhuma palavra chave): ");
        fflush(stdin);
        scanf("%d", &obras[totalObras].total_chave);

        for (int i = 0; i < obras[totalObras].total_chave; i++)
        {
            printf("\nDigite(Ex: suspense,terror,academico): %d ", i + 1);
            fflush(stdin);
            gets(obras[totalObras].palavra_chave[i]);
        }

        printf("\nDeseja registrar mais alguma publicao? Digite s ou n:\n");
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

void listarTudo(Publi obras[], int totalObras)
{
    for (int i = 0; i < totalObras; i++)
    {
        printf("\tid: %d - Nome: %s | Tipo: %s | Autor: %s %s | Ano Public: %d \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor, obras[i].autorApelido, obras[i].ano_publi);
    }

    system("pause");
}

void todos_Autores(Publi obras[], int totalObras)
{

    char aux[MAX_BIBLIO][20];
    int totalAux = 0; // variavel contadora
    int autorJaExistente = 0;

    for (int i = 0; i < totalObras; i++)
    {
        if (totalAux == 0)
        {
            strcpy(aux[totalAux], obras[i].autor);
            totalAux++;
            continue;
        }

        for (int j = 0; j < totalAux; j++)
        {
            if (!strcmp(obras[i].autor, aux[j]))
            {
                autorJaExistente = 1;
                break;
            }
        }

        if (!autorJaExistente)
        {
            strcpy(aux[totalAux], obras[i].autor);
            totalAux++;
        }

        autorJaExistente = 0;
    }

    for (int i = 0; i < totalAux; i++)
    {
        printf("Autor: %s\n", aux[i]);
    }

    printf("\nTotal de autores: %d", totalAux);

    system("pause");
    system("cls");
}

void todasAsPublicacoesAutor(Publi obras[], int totalObras)
{
    char autor[20];

    printf("\nDigite nome do autor:\n ");
    fflush(stdin);
    gets(autor);

    for (int i = 0; i < totalObras; i++)
    {
        if (!strcmp(obras[i].autor, autor)) // string compar função de comparaçaõ, se obra[i].autor é diferente de autor
        {
            printf("\tId:%d - Nome: %s | Tipo: %s | Autor: %s %s \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor, obras[i].autorApelido);
        }

        else if (!strcmp(obras[i].autorApelido, autor))
        {
            printf("\tId:%d - Nome: %s | Tipo: %s | Autor: %s %s \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor, obras[i].autorApelido);
        }
    }

    system("pause");
    system("cls");
}

void todasAsPublicacoesTipo(Publi obras[], int totalObras)
{

    char tipo[20];

    printf("Digite um tipo de publicacao(Livro,jornal...etc): \n");
    fflush(stdin);
    gets(tipo);

    for (int i = 0; i < totalObras; i++)
    {
        if (!strcmp(obras[i].tipo, tipo))
        {
            printf("\t Id:%d - Nome: %s | Tipo: %s | Autor: %s %s \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor, obras[i].autorApelido);
        }
    }

    system("pause");
    system("cls");
}

void todasPublicacoesAno(Publi obras[], int totalObras)
{

    int ano;

    printf("Digite um ano, para acessar as todas as publicacoes lancadas no ano escolhido: \n");
    fflush(stdin);
    gets(ano);

    for (int i = 0; i < totalObras; i++)
    {
        if ((obras[i].ano_publi != ano))
        {
            printf("\t Id:%d - Nome: %s | Tipo: %s | Autor: %s %s | Ano: %d \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor, obras[i].autorApelido, obras[i].ano_publi);
        }
    }

    system("pause");
    system("cls");
}


void Publicaoes_que_contenha_PavraChave(Publi obras[], int totalObras){

    char publicacao;

    for (int i = 0; i < totalObras; i++)
    {   
        if (obras[i].total_chave > 0 )
        {
           printf("\t Id:%d - Nome: %s | Tipo: %s | Autor: %s %s | Ano: %d \n\n", obras[i].id, obras[i].nome, obras[i].tipo, obras[i].autor, obras[i].autorApelido, obras[i].ano_publi);
        }
        
        
    }

    system("pause");
    system("cls");

}

int verificaSeExisteId(Publi obras[], int totalObras, int id)
{

    for (int i = 0; i < totalObras; i++)
    {
        if (!obras[i].id == id)
        {

            return 1;
        }
    }
    return 0;
}

void alterar(Publi obras[], int totalObras)
{
    int alterar;
    int op;

    listarTudo(obras, totalObras);

    printf("\nInsira o id da obra que deseja alterar : ");
    scanf("%d", &alterar);

    if (verificaSeExisteId(obras, totalObras, alterar))
    {

        printf("Esse id nao existe\n");
        return;
    }

    while (1)
    {
        printf("\nO que deseja alterar?(nome,tipo...):\n");
        printf("\t1- Alterar autor \n");
        printf("\t2- Alterar apelido autor \n");
        printf("\t3- Alterar nome da publicacao \n");
        printf("\t4- Alterar tipo da publicao \n");
        printf("\t5- Alterar ano \n");
        printf("\t6- Alterar numero de paginas \n");
        printf("\t7- Alterar Local \n");
        printf("\t8- Alterar palavras chaves \n");
        printf("\t0- Sair \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\t1- Novo autor: \n");
            fflush(stdin);
            scanf("%s", obras[alterar - 1].autor);
            break;
        case 2:
            printf("\t2- Novo apelido autor: \n");
            fflush(stdin);
            scanf("%s", obras[alterar - 1].autorApelido);
            break;
        case 3:
            printf("\t3- Novo nome da publicao: \n");
            fflush(stdin);
            scanf("%s", obras[alterar - 1].nome);
            break;
        case 4:
            printf("\t4- Novo tipo: \n");
            fflush(stdin);
            scanf("%s", obras[alterar - 1].tipo);
            break;
        case 5:
            printf("\t5- Novo ano: \n");
            scanf("%d", &obras[alterar - 1].ano_publi);
            break;
        case 6:
            printf("\t6- Novo numero de paginas: \n");
            scanf("%d", &obras[alterar - 1].num_pag); // "&" para numero
            break;
        case 7:
            printf("\t7- Novo Local: \n");
            fflush(stdin);
            scanf("%s", obras[alterar - 1].local);
            break;
        case 8:
            printf("\t7- Novas palavras chave: \n");
            fflush(stdin);
            scanf("%s", obras[alterar - 1].palavra_chave);
            break;
        case 0:
            return;
        }
    }
    printf("**** Alteracao concluida**** \n");
    system("pause");
    system("cls");
}



int total_de_paginas(Publi obras[], int totalObras)
{

    int totalpag = 0;

    for (int i = 0; i < totalObras; i++)
    {

        totalpag = totalpag + obras[i].num_pag;
    }

    printf("\nNumero total de paginas(todas as obras): %d \n", totalpag);

    system("pause");
    system("cls");
}

void media_de_paginas(Publi obras[], int totalObras)
{

    int media;
    int totalpag = 0;

    for (int i = 0; i < totalObras; i++)
    {
        totalpag = totalpag + obras[i].num_pag;
        media = totalpag / totalObras;
    }

    printf("A media de paginas por obras eh : %d \n", media);

    system("pause");
    system("cls");
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
            for (int i = id - 1; i < totalObras; i++) // se nao for o ultimo do array(meio ou inicio)
            {
                obras[i] = obras[i + 1];
            }
            totalObras = totalObras - 1;
            return totalObras;
        }
    }
}

void estatisca(Publi obras[], int totalObras)
{

    system("cls");
    int op;

    do
    {

        printf("\nSelecione uma das opcoes abaixo: \n\n");
        printf("\t1- Total de publicacoes \n");
        printf("\t2- Total de autores \n");
        printf("\t3- Total de palavras chave \n ");
        printf("\t4- Total de paginas (todas as obras) \n");
        printf("\t5- Media de paginas por publicacao \n");
        printf("\t0- Voltar ao menu \n");
        scanf("%d", &op);

        getchar(); // limpar o buffer de memoria

        switch (op)
        {

        case 1:
            printf("Total publicaoes: %d\n", totalObras);
            break;
        case 2:
            todos_Autores(obras,totalObras);
            break;
        case 3:
            totalPalavrasChave(obras, totalObras);
            break;
        case 4:
            total_de_paginas(obras, totalObras);
            break;
        case 5:
            media_de_paginas(obras, totalObras);
            break;

        default:
            printf("\tSelecione apenas 1,2,3,4,5 ou 0 para voltar ao menu principal\n");
            break;
        }

    } while (op != 0);

    system("cls");
}

void listar(Publi obras[], int totalObras) // declaracao obras(struct publi) e inteiro totalObras
{

    system("cls");
    int op;

    do
    {

        printf("\nSelecione uma das opcoes abaixo: \n\n");
        printf("\t1- Listar tudo \n");
        printf("\t2- Todas as publicacoes de um autor \n");
        printf("\t3- Todas as publicacoes de um tipo \n ");
        printf("\t4- Todas as publicacoes de um ano \n");
        printf("\t5- Todos os autores \n");
        printf("\t6 - Todas as publicacoes com palavra chave \n");
        printf("\t0- Voltar ao menu \n");
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
        case 4:
            todasPublicacoesAno(obras, totalObras);
            break;
        case 5:
            todos_Autores(obras, totalObras);
            break;
        case 6:
            Publicaoes_que_contenha_PavraChave(obras, totalObras);
        default:
            printf("\tPor favor, selecione apenas 1,2,3,4 ou 0\n");
            break;
        }
    } while (op != 0);

    system("cls");
}

void menu(Publi obras[], int totalObras)
{

    int op; // option

    do
    {

        printf("Selecione uma das opcoes abaixo: \n\n");
        printf("\t1 - Inserir nova Refencia bibliografica \n");
        printf("\t2 - Listar \n");
        printf("\t3 - Estatistica das obras \n");
        printf("\t4 - Eliminar \n");
        printf("\t5 - Alterar \n");
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

        case 3:
            estatisca(obras, totalObras);
            break;

        case 4:
            totalObras = eliminar(obras, totalObras);
            printf("\tTotal de obras depois da eliminacao: %d \n\n", totalObras);
            break;

        case 5:
            alterar(obras, totalObras);

        case 0:
            break;
        default:
            printf("\tPor favor, selecione apenas 1,2,3,4 ou 0\n");
            break;
        }

    } while (op != 0);

    printf("Saindo...");
}

void abertura()
{

    printf("****************************************************\n");
    printf("* Bem vindo ao registo referencias bibliograficas *\n");
    printf("****************************************************\n\n");

    system("pause"); // tem um pause
    system("cls");   // limpa a tela e segue pra outra linha de codigo
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
