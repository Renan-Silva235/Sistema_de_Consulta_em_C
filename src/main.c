#include <stdio.h>
#include "../include/connection.h"



int main() {
    MYSQL *conn = createConnection();
    if (conn == NULL)
        return 1;

    // Executar o SELECT
    if (mysql_query(conn, "SELECT id, product, descriptionProduct FROM loja")) {
        printf("Erro ao executar SELECT: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        printf("Erro ao obter resultados: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    MYSQL_ROW row;
    printf("ID | product      | descriptionProduct\n");
    printf("--------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("%s  | %-10s | %s\n", row[0], row[1], row[2]);
    }

    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}
