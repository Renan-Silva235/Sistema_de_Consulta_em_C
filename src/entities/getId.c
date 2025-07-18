#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int getIdByProductName(MYSQL *connect, const char *product){
    char query[200];
    sprintf(query, "SELECT * FROM loja WHERE product = '%s'", product);


    if(mysql_query(connect, query)){
        fprintf(stderr, "Erro de consulta: %s\n", mysql_error(connect));
        mysql_close(connect);
        return -1;
    }

    MYSQL_RES *res = mysql_store_result(connect);

    if(!res){
        fprintf(stderr, "Erro ao obter resultado: %s\n", mysql_error(connect));
        mysql_close(connect);
        return -1;
    }

    int num_rows = mysql_num_rows(res);

    if(num_rows == 0){
        printf("Nenhum produto encontrado.\n");
        mysql_free_result(res);
        return -1;
    }

    int *ids = calloc(sizeof(int), num_rows);
    if(!ids){
        fprintf(stderr, "Erro de memória.\n");
        mysql_free_result(res);
        return -1;
    }


    MYSQL_ROW row;
    int i = 0;
    while((row = mysql_fetch_row(res))){
        ids[i] = atoi(row[0]);
        if(num_rows > 1){
            printf("[%d] ID: %s | Produto: %s | Descrição: %s | Preço: %s | quantidade: %s\n", i + 1, row[0], row[1], row[2], row[3], row[4]);
        }
        i++;
    }



    int chosed_id;
    if(num_rows == 1){
        chosed_id = ids[0];
    }else{
        int choose;
        printf("Escolha o número do produto que deseja alterar: ");
        scanf("%d", &choose);
        getchar();

        if(choose < 1 || choose > num_rows){
            printf("Opção inválida.\n");
            free(ids);
            mysql_free_result(res);
            return -1;
        }

        chosed_id = ids[choose - 1];
    }

    free(ids);
    mysql_free_result(res);
    return chosed_id;
}