#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../include/entities/updateData.h"
#include "../../include/entities/condition.h"
#include "../../include/entities/getId.h"
#include "../../include/structs/structs.h"
#include "../../include/connectionsDatabase/connection.h" 
#include "../../include/repository/database.h"

void updateDataDescriptionProduct(MYSQL *connect, char *data){

     searchProduct(connect, data);
    int option = condition("descrição");

    if(!option){
        system("clear");
        // menu();
        exit(1);
    }

    

    int id = getIdByProductName(connect, data);
    if(id == -1) return;
    
    
    char newDescription[100];
    printf("Digite a nova descrição do produto: ");
    fgets(newDescription, 100, stdin);
    strtok(newDescription, "\n");

    unsigned long lengthNewDescription = strlen(newDescription);


    MYSQL_STMT *stmt;
    stmt = mysql_stmt_init(connect); //incializa
    char *query = "UPDATE loja SET descriptionProduct = ? WHERE id = ?";



    if(mysql_stmt_prepare(stmt, query, strlen(query))){ // prepara a consulta
        fprintf(stderr, "Erro no prepare: %s\n", mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        return;
    } 

    MYSQL_BIND params[2]; // MYSQL_BIND envia os valores para os '?'
    memset(params, 0, sizeof(params)); //zera a memória da struct

    params[0].buffer_type = MYSQL_TYPE_STRING; //tipo do dado
    params[0].buffer = newDescription; // ponteiro para o novo valor
    params[0].buffer_length = sizeof(newDescription); // ponteiro para o novo valor
    params[0].length = &lengthNewDescription;
    
    params[1].buffer_type = MYSQL_TYPE_LONG;
    params[1].buffer = &id;

    if(mysql_stmt_bind_param(stmt, params)){ //liga os dados aos '?'
        fprintf(stderr, "Erro no Bind: %s\n", mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        return;
    }  

    if(mysql_stmt_execute(stmt)){
        fprintf(stderr, "Erro ao executar update: %s\n", mysql_stmt_error(stmt));
    }else{
        printf("Descrição atualizada com sucesso!\n");
    }
    mysql_stmt_close(stmt);
}




void updateDataPrice(MYSQL *connect, char *data){ //TODO: acrescentar para a função pegar o id do produto que vai ser alterado
    
    searchProduct(connect, data);
    int option = condition("preço");

    if(!option){
        system("clear");
        // menu();
        exit(1);
    }

    

    int id = getIdByProductName(connect, data);
    if(id == -1) return;
    
    float newPrice;
    printf("Digite o novo preço: ");
    scanf("%f", &newPrice);
    getchar();


    MYSQL_STMT *stmt;
    stmt = mysql_stmt_init(connect); //incializa
    char *query = "UPDATE loja SET price = ? WHERE id = ?";



    if(mysql_stmt_prepare(stmt, query, strlen(query))){ // prepara a consulta
        fprintf(stderr, "Erro no prepare: %s\n", mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        return;
    } 

    MYSQL_BIND params[2]; // MYSQL_BIND envia os valores para os '?'
    memset(params, 0, sizeof(params)); //zera a memória da struct

    params[0].buffer_type = MYSQL_TYPE_FLOAT; //tipo do dado
    params[0].buffer = &newPrice; // ponteiro para o novo valor

    params[1].buffer_type = MYSQL_TYPE_LONG;
    params[1].buffer = &id;

    if(mysql_stmt_bind_param(stmt, params)){ //liga os dados aos '?'
        fprintf(stderr, "Erro no Bind: %s\n", mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        return;
    }  

    if(mysql_stmt_execute(stmt)){
        fprintf(stderr, "Erro ao executar update: %s\n", mysql_stmt_error(stmt));
    }else{
        printf("Preço atualizado com sucesso!\n");
    }
    mysql_stmt_close(stmt);

}




void updateDataAmount(MYSQL *connect, char *data){

    searchProduct(connect, data);
    int option = condition("quantidade");

    if(!option){
        system("clear");
        // menu();
        exit(1);
    }

    

    int id = getIdByProductName(connect, data);
    if(id == -1) return;
    
    int newAmount;
    printf("Digite a nova quantidade do produto: ");
    scanf("%d", &newAmount);
    getchar();


    MYSQL_STMT *stmt;
    stmt = mysql_stmt_init(connect); //incializa
    char *query = "UPDATE loja SET amount = ? WHERE id = ?";



    if(mysql_stmt_prepare(stmt, query, strlen(query))){ // prepara a consulta
        fprintf(stderr, "Erro no prepare: %s\n", mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        return;
    } 

    MYSQL_BIND params[2]; // MYSQL_BIND envia os valores para os '?'
    memset(params, 0, sizeof(params)); //zera a memória da struct

    params[0].buffer_type = MYSQL_TYPE_LONG; //tipo do dado
    params[0].buffer = &newAmount; // ponteiro para o novo valor

    params[1].buffer_type = MYSQL_TYPE_LONG;
    params[1].buffer = &id;

    if(mysql_stmt_bind_param(stmt, params)){ //liga os dados aos '?'
        fprintf(stderr, "Erro no Bind: %s\n", mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        return;
    }  

    if(mysql_stmt_execute(stmt)){
        fprintf(stderr, "Erro ao executar update: %s\n", mysql_stmt_error(stmt));
    }else{
        printf("Quantidade atualizada com sucesso!\n");
    }
    mysql_stmt_close(stmt);

}