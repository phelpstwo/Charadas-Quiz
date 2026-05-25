//
// Aluno: Philipe Gabriel Silva Gomes Calado
//
//===================================================Inclusao de cabecalhos==============================================================
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
//=======================================================================================================================================


//====================================================Prototipos de funcoes==============================================================
int inicio();
void  menu();
void questoes();
//=======================================================================================================================================


//======================================================Variaveis globais================================================================
char nome[20];
//=======================================================================================================================================


//======================================================Funcao principal=================================================================
int main(){
//======================================================Fluxo do usuario=================================================================

    if(strlen(nome) == 0){   // Verifica se o nome 'esta vazio' (inicialmente verdadeiro)

        system("clear");     // Funcao para limpar a tela do terminal

        printf("\n\n");
        printf("                                   QUIZ DE CHARADADAS                                 \n");
        printf("\n\n");
        //==================================================Inserir nome=================================================================
        printf("Escreva seu nome:");
        scanf(" %19[^\n]", nome);
    
        menu();               // Redireciona o menu

    }

    if(strlen(nome)  != 0){   // Verifica se o nome 'nao esta vazio' (verdadeiro depois de definir o nome)

        questoes();           // Redireciona para as questoes
    }

    return 0;

}
//=======================================================================================================================================


//==================================================Funcao de exibicao do menu===========================================================
void menu(){

    system("clear");
    printf("\n\n");
    printf("                                   QUIZ DE CHARADADAS                                 \n");
    printf("\n\n");
    printf("                              Seja bem-vindo %s!                                      \n", nome);
    printf("\n\n");
    printf("                                    Iniciar (Enter)                                   \n");

    while(getchar() != '\n');    // Limpa o buffer de entrada (teclado) para evitar erros de leitura

    getchar();                   // Aguarda o usuario pressionar "Enter" para iniciar o quiz
}
//=======================================================================================================================================


//=================================================Funcao de exibicao das questoes=======================================================
void questoes(){

    int i, j;                   // Variaveis usadas nos loops "for"
    int pontos = 0;             // Variavel para contagem de pontos
    char resposta;              // Variavel para armazenar a resposta do usuario
    char jogarNovamente;        // Variavel usada para verificar se o usuario deseja jogar novamente

    
    //=================================================== Loop de Questoes ==============================================================
    char charadas[6][150] = {   // Matriz que armazena as charadas do quiz

        // Charada 1
        "O que e, o que e? Tem coroa, mas nao e rei; tem escamas, mas nao e peixe?",

        // Charada 2
        "O que e, o que e? Corre a casa inteira e depois descansa num canto?",

        // Charada 3
        "O que e, o que e? Cai em pe e corre deitada?",

        // Charada 4
        "O que e, o que e? Tem perna e tem braco, mas nao anda e nem abraca?",

        // Charada 5
        "O que e, o que e? Objeto que mais pesa no mundo?",
        
        // Charada 6
        "O que e, o que e? Entra duro, sai mole e pingando?"

    };

    char alternativas[6][4][50] = {    // Matriz que amrazena as alternativas de cada charada

        // Alternativas da charada 1
        {   "A) Pente",
            "B) Cacto",
            "C) Jacare",
            "D) Abacaxi"
        },

        // Alternativas da charada 2
        {   "A) Gato",
            "B) Vassoura",
            "C) Barata",
            "D) Cadeira"
        },

        // Alternativas da charada 3
        {   "A) Cobra",
            "B) Chuva",
            "C) Cachorro",
            "D) Gato"
        },
        
        // Alternativas da charada 4
        {   "A) Guarda-chuva",
            "B) Homem",
            "C) Cadeira",
            "D) Arvore"
        },

        // Alternativas da charada 5
        {   "A) Ferro",
            "B) Ouro",
            "C) Balanca",
            "D) Atmosfera"},

            // Alternativas da charada 6
        {   "A) Macarrao",
            "B) Toalha",
            "C) Pao frances",
            "D) Chocolate"
        }
    };

    char respostaCorreta[6] = {    // Matriz que armazena as respostas corretas de cada charada

        'd',    // Resposta da charada 1
        'b',    // Resposta da charada 2
        'b',    // Resposta da charada 3
        'c',    // Resposta da charada 4
        'c',    // Resposta da charada 5
        'a'     // Resposta da charada 6
    };

    for(i = 0; i < 6; i++){       // Loop para exibir cada charada em ordem

        system("clear");
        printf("\n");
        printf("                                  Charada %d                                      \n", i + 1);
        printf("\n\n");
        printf("        %s\n", charadas[i]);
        printf("\n\n");

        printf("Alternativas:\n");

        for(j = 0; j < 4; j++){    // Loop para exibir as alternativas de cada charada em ordem

            printf("%s\n", alternativas[i][j]);

        }
        //===============================================================================================================================


        //================================================Verificacao da resposta========================================================
        printf("Sua resposta: ");
        scanf(" %c", &resposta);

        resposta = tolower(resposta);   // Converte a a resposta para minuscula

        if(resposta == respostaCorreta[i]){    // Verifica se a resposta do usuario e correta

            system("clear");
            printf("Parabens! Voce acertou! Uhuul :)\n");

            pontos += 100;   // Adiciona 100 pontos por acerto

            printf("Voce ganhou 100 pontos!\n");
            printf("Pontuacao atual: %d\n", pontos);
            sleep(5);
            while(getchar() != '\n');
            system("clear");

        }
        else{    // Se a resposta do usuario fo incorreta

            system("clear");
            printf("Infelizmente voce errou kk\nResposta correta: %c\n", respostaCorreta[i]);

            if(pontos > 20){   // Se a pontuacao for maior que 20

                pontos -= 20;  // Subtrai 20 pontos por erro
                
                printf("Voce perdeu 20 pontos :(\n");
                printf("Pontuacao atual: %d\n", pontos);
                sleep(5);
                while(getchar() != '\n');
                system("clear");

            }

            else{              // Se a pontuacao for menor que 20

                pontos = 0;    // Pontuacao zerada

                printf("Voce perdeu 0 pontos\n");
                printf("Pontuacao atual: %d", pontos);
                sleep(5);
                while(getchar() != '\n');
                system("clear");

            }
        }
        //===============================================================================================================================
    }


    //=======================================================Mensagem final==============================================================
    printf("Muito obrigado por jogar!\n");
    printf("\n");
    printf("Sua pontuacaao final: %d\n", pontos);    // Exibe a pontuacao final
    printf("\n");
    printf("\n");
    printf("Deseja Jogar novamenente? ('s' para sim; 'n' para nao): \n");
    scanf(" %c", &jogarNovamente);  

    if(jogarNovamente == 's'){   // Verifica se a resposta foi "s" (sim)

        main();   // Retorna para a funcao main() que redireciona para as questoes

    }
    else if(jogarNovamente == 'n'){    // Verifica se a resposta foi "n" (nao)

        system("clear");
        printf("Obrigado por jogar! Ate a proxima!\n");
        exit(0);   // Encerra o programa

    }
    //=============================================================FIM===================================================================

}