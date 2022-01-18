#ifndef _UTILS_H
#define _UTILS_H

#include "lib.h"
#include "product.h"
#include "bill.h"
#include "employee.h"

void displayProductMenu();
void productMenu(ProductList &);

void displayBillMenu();
void billMenu(ListBill &, ProductList);

void displayEmployeeMenu();
void employeeMenu(EmployeeTree &, ProductList, ListBill &);


void displayMainMenu();
void mainMenu(ProductList &, ListBill &, EmployeeTree &);
#endif // _UTILS_H
