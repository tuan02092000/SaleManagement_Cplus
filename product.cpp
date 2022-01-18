#include "product.h"

int checkProductIdExist(ProductList pList, string productID)
{
    for(int i = 0; i < pList.size; i++)
    {
        if(productID == (pList.product[i]->productID))
        {
            return i;
        }
    }
    return -1;
}
string generateProductId(ProductList pList)
{
    string productID = "Productxxxx";
    do
    {
        for(int i = 7; i < (int)productID.length(); i++)
        {
            productID[i] = rand() % ('9' - '0' + 1) + '0';
        }
    }
    while(checkProductIdExist(pList, productID) >= 0);
    return productID;
}

void sortProductList(ProductList &pList)
{
    for(int i = 1; i < pList.size; i++)
    {
        int index = i;
        Product *p = pList.product[i];
        while(index > 0 && pList.product[index -1]->price < p->price)
        {
            pList.product[index] = pList.product[index - 1];
            index--;
        }
        pList.product[index] = p;
    }
}

void inputProduct(Product *p, ProductList pList)
{
    p->productID = generateProductId(pList);
    cout << "\n=> Input information of product: " << endl;
    cout << " - Name: ";
    cin.ignore();
    getline(cin, p->productName);
    fixString(p->productName);
    cout << " - Price: ";
    cin >> p->price;
    cin.ignore();
    cout << " - Measure: ";
    getline(cin, p->measure);
    fixString(p->measure);
    cout <<" - Company: ";
    getline(cin, p->company);
    fixString(p->company);
    cout << " - Stock: ";
    cin >> p->stock;
    cin.ignore();
}

void showProductBar()
{
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "ID";
    cout << setw(25) << "Name";
    cout << setw(10) << "Price";
    cout << setw(20) << "Company";
    cout << setw(10) << "Measure";
    cout << setw(10) << "Stock" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
}
void outputProduct(Product *p)
{
    cout << setw(20) << left << p->productID;
    cout << setw(25) << p->productName;
    cout << setw(10) << p->price;
    cout << setw(20) << p->company;
    cout << setw(10) << p->measure;
    cout << setw(10) << p->stock;
    cout << endl;
}
void editProduct(Product *p)
{
    cout << "\n=> Input information of product: " << endl;
    cout << " - Name: ";
    getline(cin, p->productName);
    fixString(p->productName);
    cout << " - Price: ";
    cin >> p->price;
    cin.ignore();
    cout << " - Stock: ";
    cin >> p->stock;
    cin.ignore();
}

void insertProductList(ProductList &pList)
{
    Product *p = new Product;
    inputProduct(p, pList);
    pList.product[pList.size] = p;
    pList.size++;
}
void showProductList(ProductList pList)
{
    cout << "\n# Number of product: " << pList.size << endl;
    showProductBar();
    for(int i = 0; i < pList.size; i++)
    {
        outputProduct(pList.product[i]);
    }
}
bool deleteProduct(ProductList &pList)
{
    cin.ignore();
    string id;
    cout << "\n=> Enter product id (delete): ";
    getline(cin, id);
    fixString(id);
    int index = checkProductIdExist(pList, id);

    if(index < 0)
    {
        return false;
    }
    else
    {
        for(int i = index; i < pList.size - 1; i++)
        {
            pList.product[i] = pList.product[i + 1];
        }
        pList.size--;
        return true;
    }
}
bool editProductList(ProductList &pList)
{
    cin.ignore();
    string id;
    cout << "\n=> Enter product id (edit): ";
    getline(cin, id);
    fixString(id);
    int index = checkProductIdExist(pList, id);

    if(index < 0)
    {
        return false;
    }
    else
    {
        editProduct(pList.product[index]);
        return true;
    }
}
Product *searchProduct(ProductList pList, string productID)
{
    int index = checkProductIdExist(pList, productID);
    if(index < 0)
    {
        return nullptr;
    }
    else
    {
        return pList.product[index];
    }
}

void fixString(string &str)
{
    // Xu ly khoang trang dau
    while(str[0] == ' ')
    {
        str.erase(str.begin() + 0);
    }
    // Xoa khoang trang cuoi
    while(str[str.length() - 1] == ' ')
    {
        str.erase(str.begin() + str.length() - 1);
    }
    // Xoa khoang trang giua
    for(int i = 0; i < (int) str.length(); i++)
    {
        if(str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
    }

    // Chua hoa ki tu
    if(str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] -= ' ';
    }
    for(int i = 1; i < (int) str.length(); i++)
    {
        if(str[i] == ' ')
        {
            i++;
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= ' ';
            }
        }
        else
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += ' ';
            }
        }
    }
}
