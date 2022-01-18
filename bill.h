#ifndef _BILL_H
#define _BILL_H

#include "lib.h"
#include "product.h"

typedef struct bill
{
    string billID;
    string customerName;
    string *productID;
    int nProduct = 0;
    double vat = 0.02;
    string date;
    double totalPrice;
}Bill;

typedef struct nodeBill
{
    Bill data;
    struct nodeBill *pnext;
}NodeBill;

typedef struct listBill
{
    NodeBill *phead, *ptail;
}ListBill;

bool checkBillIdExist(ListBill, string );
string generateBillId(ListBill);
void setTotalPrice(Bill &, ProductList);

NodeBill* searchBill(ListBill, string, ProductList);
NodeBill* searchMaxPriceBill(ListBill, ProductList);
NodeBill* searchMinPriceBill(ListBill, ProductList);

void createListBill(ListBill &);
NodeBill *createNodeBill(Bill);

double getPrice(string *, int , ProductList);
void inputBill(Bill &, ProductList, ListBill);
void outputBill(Bill, ProductList);

void insertTail(ListBill &, NodeBill *);
void insertBillList(ListBill &, ProductList);
void showBillList(ListBill, ProductList);

#endif // _BILL_H
