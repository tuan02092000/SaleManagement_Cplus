#include "processFile.h"

void readProductFile(ProductList &pList)
{
    ifstream filein;
    filein.open("product.txt", ios_base::in);
    while(!filein.eof())
    {
        pList.product[pList.size] = new Product;
        getline(filein, pList.product[pList.size]->productID, ',');
        getline(filein, pList.product[pList.size]->productName, ',');
        getline(filein, pList.product[pList.size]->company, ',');
        getline(filein, pList.product[pList.size]->measure, ',');
        filein >> pList.product[pList.size]->price;
        filein.ignore();
        filein >> pList.product[pList.size]->stock;
        filein.ignore();
        pList.size++;
    }
    filein.close();
}

void readEmployeeFile(EmployeeTree &eTree)
{
    ifstream filein;
    filein.open("employee.txt", ios_base::in);
    while(!filein.eof())
    {
        NodeE *e = createNodeEmployee();
        filein >> e->data.employeeID;
        filein.ignore();
        getline(filein, e->data.lastName, ',');
        getline(filein, e->data.firstName, ',');
        filein >> e->data.age;
        filein.ignore();
        getline(filein, e->data.address, ',');
        getline(filein, e->data.gender, ',');
        filein >> e->data.salary;
        filein.ignore();

        addEmployee(eTree.root, e);
        eTree.size++;
    }
    filein.close();
}
