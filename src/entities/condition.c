#include <stdio.h>
#include <ctype.h>
#include "../../include/entities/condition.h"



int condition(char *option){
    char response = 'k';


    printf("Deseja mesmo alterar o(a) %s do produto (s/n): ", option);
    scanf("%c", &response);
    response = tolower(response);


    if(response != 's' && response != 'n'){
        do{
            printf("Opção inválida!\n");
            getchar();
            printf("Deseja mesmo alterar %s do produto (s/n): ", option);
            scanf("%c", &response);
            response = tolower(response);

        }while(response != 's' && response != 'n');
    }

    if(response == 's') return 1;
    if(response == 'n') return 0;

}