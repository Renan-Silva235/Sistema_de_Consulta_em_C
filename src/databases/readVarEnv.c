#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/readVarEnv.h"


void readVarEnv(char *host, char *user, char *password, char *database){
    FILE *file = fopen("./src/var_env.txt", "r");

    if(!file){
        printf("Erro ao abrir variáveis de ambiente.\n");
        exit(1);
    }

    char line[128];

    while(fgets(line, sizeof(line), file)){
        if(strncmp(line, "host=", 5) == 0) strcpy(host, line + 5);
        else if(strncmp(line, "user=", 5) == 0) strcpy(user, line + 5);
        if(strncmp(line, "password=", 9) == 0) strcpy(password, line + 9);
        if(strncmp(line, "database=", 9) == 0) strcpy(database, line + 9);
    }

    host[strcspn(host, "\n")] = 0;
    user[strcspn(user, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;
    database[strcspn(database, "\n")] = 0;

    fclose(file);
}