#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "lib.h"
#include "bill.h"

typedef struct employee
{
    int employeeID;
    string firstName;
    string lastName;
    int age;
    string address;
    double salary;
    string gender;
    ListBill l;
}Employee;

typedef struct nodeE
{
    Employee data;
    nodeE *pleft, *pright;

}NodeE; // Node employee

typedef NodeE* Tree;

typedef struct employeeTree
{
    Tree root = nullptr;
    int size = 0;
}EmployeeTree;

void showEmployeeBar();

bool checkEmployeeIdExist(Tree, int);
int generateEmployeeID(Tree);

int countEmployee(EmployeeTree);
void sortBySalary(Tree, Employee *[], int &); // Bubble sort

NodeE* createNodeEmployee();
void createEmployeeTree(EmployeeTree &);

void addEmployee(Tree &, NodeE *);
void insertEmployeeTree(EmployeeTree &);

void outputEmployee(NodeE *);
void showEmployeeTree(Tree);

void editEmployee(Tree &, int);
bool editEmployeeTree(EmployeeTree &);

NodeE* searchEmployee(Tree , int);
bool searchEmployeeTree(EmployeeTree, int);

void deleteNode(Tree &);
void deleteTree(Tree &, int);
bool deleteEmployeeTree(EmployeeTree &);

void createBill(EmployeeTree &, ProductList, ListBill &);
void showBillByEmployee(EmployeeTree, ProductList);

#endif // _EMPLOYEE_H
