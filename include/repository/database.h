#include <mysql/mysql.h>
#include <stdbool.h>
#include "../structs/structs.h"

void insertProduct(MYSQL *connect, char *product, char *descriptionProduct, float *price, int *amount);
void listProduct(MYSQL *connect);
void searchProduct(MYSQL *connect, char *product);
void updateProduct(MYSQL *connect, UpdateOptions opt, char *data);
void deleteProduct(MYSQL *connect, char *nameProduct);