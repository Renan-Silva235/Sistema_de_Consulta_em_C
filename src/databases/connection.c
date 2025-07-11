#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "../../include/connection.h"
#include "../../include/readVarEnv.h"


MYSQL *createConnection(){
    MYSQL *connect = mysql_init(NULL);

    if(connect == NULL){
        printf("Erro ao inicializar conexão. \n");
        return NULL;
    }

    char host[100], user[100], password[100], database[100];


    readVarEnv(host, user, password, database);


    if(mysql_real_connect(connect, host, user, password, database, 0, NULL, 0) == NULL){
        printf("Erro ao conectar: %s\n", mysql_error(connect));
        mysql_close(connect);
        return NULL;
    }

    return connect;
}