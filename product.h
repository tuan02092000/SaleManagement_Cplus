#ifndef _PRODUCT_H
#define _PRODUCT_H

#include "lib.h"

#define MAX 1000

typedef struct product
{
    string productID; // ma san phan
    string productName; // ten san pham
    string measure; // don vi tinh
    string company; // nha san xuat
    double stock; // hang ton kho
    double price; // gia
}Product;

typedef struct productList
{
    Product *product[MAX];
    int size = 0;
}ProductList;

int checkProductIdExist(ProductList, string );
string generateProductId(ProductList);
int countProduct(ProductList);
void sortProductList(ProductList &); // insertion sort

void inputProduct(Product &, ProductList);
void outputProduct(Product *);
void editProduct(Product &);

void insertProductList(ProductList &);
void showProductList(ProductList);
bool deleteProduct(ProductList &);
bool editProductList(ProductList &);
Product* searchProduct(ProductList, string);

void fixString(string &str);

#endif // _PRODUCT_H
