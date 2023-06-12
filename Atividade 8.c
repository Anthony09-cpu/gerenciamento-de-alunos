#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

void incluir();
void editar();
int localizar(int op);
void listar();
void remover();
void busca_aluno();

struct alunos {
    int nota[3];
    char aluno[30];
};
struct alunos listaDeAlunos[30];

int contadoralunos = 0;

int main(){
    setlocale(LC_ALL,"PORTUGUESE");

    char loc[50];
    int i ,j,escolha,naoEncontrado,somanotas, sair, repetir;
    char alunoex;
    do{ system("cls");


    printf("\n\tEscolha qual opção deseja:");
    printf("\n\t__________________________");
    printf(" \n\n\t1 - Incluir um aluno com suas notas.");
    printf(" \n\t2 - Localizar um aluno e retornar a sua soma de notas.");
    printf(" \n\t3 - Listar todos os alunos e suas notas.");
    printf(" \n\t4 - Remover um aluno e suas notas.");
    printf(" \n\t5 - Editar / Alterar nome ou nota.");
    printf(" \n\t6 - Sair.");
    printf("\n\t__________________________\n\t\n\t-> ");
    scanf("%d", &escolha);

    system("cls");

       switch(escolha){
            case 1:
                incluir();
                break;
            case 2:
                localizar(1);
                break;

            case 3:
                listar();
                break;
            case 4:
                remover();
                break;
            case 5:
                editar();
                break;

            default:
                printf("Você saiu.\n");
                break;
       }
    }while(escolha != 6);
}
void incluir(){
    int i;
    printf("\n\tQual nome do aluno: ");
    fflush(stdin);
    scanf("%[^\n]s", listaDeAlunos[contadoralunos].aluno);
    for(i = 0; i < strlen(listaDeAlunos[contadoralunos].aluno); i++)
        listaDeAlunos[contadoralunos].aluno[i] = toupper(listaDeAlunos[contadoralunos].aluno[i]);

    for(i = 0; i < 3; i++){
        printf("\n\tEscreva a %d nota do aluno: ", i + 1);
        fflush(stdin);
        scanf("%d", &listaDeAlunos[contadoralunos].nota[i]);
    }
    contadoralunos++;

}
int localizar(int op){//passar valor inteiro e espera q voce mande um valor inteiro para ela

    int j, i, somanotas = 0, naoEncontrado = 1;
    char loc[50];

    printf("\n\tDigite o nome do aluno: ");
    fflush(stdin);
    scanf("%[^\n]s", loc);

    for(i = 0; i < strlen(loc); i++)
        loc[i] = toupper(loc[i]);

    for(i = 0; i < contadoralunos; i++){
        somanotas = 0;
        if(strstr(listaDeAlunos[i].aluno,loc)){
            printf("\n\n\t%d - Aluno: %s",i + 1, listaDeAlunos[i].aluno);

            for(j = 0; j < 3; j++){
                if(op == 1)
                    somanotas += listaDeAlunos[i].nota[j];

                if(op == 2)
                    printf("\n\tNota %d: %d",j + 1, listaDeAlunos[i].nota[j]);
            }
            if(op == 1)
                    printf("\n\tSoma das notas: %d", somanotas);
            naoEncontrado = 0;
        }
    }

    if(naoEncontrado)
        printf("\n\tAluno não encontrado");

    printf("\n\n\t");
    if(op == 1)
        system("pause");

    return naoEncontrado;
}
void listar(){

int i, j;
    for(i = 0; i < contadoralunos; i++){
        printf("\n\n\tNome: %s", listaDeAlunos[i].aluno);
            for(j = 0; j < 3; j++)
                printf("\n\tNota %d: %d",j + 1, listaDeAlunos[i].nota[j]);
    }
            printf("\n\t");
                system("pause");
}
void remover(){
    int i, j;
    char alunoex;

    if(!localizar(0)){
        printf("\n\tDigite o numero do aluno que você quer excluir: ");
        fflush(stdin);
        scanf("%d", &i);
        printf("\n\tConfirme a exclusão de: %s - (S/N) ", listaDeAlunos[i - 1].aluno);
        fflush(stdin);
        scanf("%c", &alunoex);

        if(alunoex == 'S' || alunoex == 's'){
            for(i = i - 1; i < contadoralunos - 1; i++){

                strcpy(listaDeAlunos[i].aluno,listaDeAlunos[i + 1].aluno);
                listaDeAlunos[i].nota[0] = listaDeAlunos[i + 1].nota[0];
                listaDeAlunos[i].nota[1]= listaDeAlunos[i + 1].nota[1];
                listaDeAlunos[i].nota[2]= listaDeAlunos[i + 1].nota[2];
            }
            contadoralunos--;
        }
        for(i = 0; i < contadoralunos; i++){
            printf("\n\n\tNome: %s", listaDeAlunos[i].aluno);
            for(j = 0; j < 3; j++)
                    printf("\n\tNota %d: %d",j + 1, listaDeAlunos[i].nota[j]);
        }
    }
    printf("\n");
    system("pause");
}
void editar(){

    int i, j, alunoEdit;

    if(!localizar(2)){
        printf("\n\tDigite o numero do aluno que você quer editar: ");
        fflush(stdin);
        scanf("%d", &j);
        printf("\n\tDeseja editar nome(1), nota(2) ou cancelar (0): %s ", listaDeAlunos[j - 1].aluno);
        fflush(stdin);
        scanf("%d", &alunoEdit);

        if(alunoEdit == 1){

            printf("\n\tQual nome do aluno: ");
            fflush(stdin);
            scanf("%[^\n]s", listaDeAlunos[j - 1].aluno);
            for(i = 0; i < strlen(listaDeAlunos[j - 1].aluno); i++)
                listaDeAlunos[j - 1].aluno[i] = toupper(listaDeAlunos[j - 1].aluno[i]);

        }
        else if(alunoEdit == 2){
            for(i = 0; i < 3; i++){
                    printf("\n\tEscreva a %d nota do aluno: ", i + 1);
                    fflush(stdin);
                    scanf("%d", &listaDeAlunos[j - 1].nota[i]);
                }
        }
    }
    printf("\n");
    system("pause");
}
