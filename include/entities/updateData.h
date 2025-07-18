#include <mysql/mysql.h>
#include "../structs/structs.h"

void updateDataDescriptionProduct(MYSQL *connect, char *data);
void updateDataPrice(MYSQL *connect, char *data);
void updateDataAmount(MYSQL *connect, char *data);