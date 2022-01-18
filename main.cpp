#include "utils.h"
#include "processFile.h"

int main()
{
    srand(time(nullptr));

    ProductList pList;

    ListBill lBill;
    createListBill(lBill);

    EmployeeTree eTree;

    mainMenu(pList, lBill, eTree);

    return 0;
}
