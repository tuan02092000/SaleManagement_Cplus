#include "bill.h"

bool checkBillIdExist(ListBill l, string billID)
{
    for(NodeBill *k = l.phead; k != nullptr; k = k->pnext)
    {
        if(billID == k->data.billID)
        {
            return true;
        }
    }
    return false;
}
string generateBillId(ListBill l)
{
    string billID = "Billxxxx";
    do
    {
        for(int i = 4; i < (int)billID.length(); i++)
        {
            billID[i] = rand() % ('9' - '0' + 1) + '0';
        }
    }
    while(checkBillIdExist(l, billID));
    return billID;
}


void createListBill(ListBill &l)
{
    l.phead = l.ptail = nullptr;
}

NodeBill *createNodeBill(Bill b)
{
    NodeBill *p = new NodeBill;
    if(p == nullptr)
    {
        return nullptr;
    }
    else
    {
        p->data = b;
        p->pnext = nullptr;
        return p;
    }
}

double getPrice(string *productID, int n, double vat, ProductList pList)
{
    double price = 0;
    for(int i = 0; i < n; i++)
    {
        Product *p = searchProduct(pList, productID[i]);
        price += p->price;
    }
    return price + price * vat;
}

void setTotalPrice(Bill &b, ProductList pList)
{
    b.totalPrice = getPrice(b.productID, b.nProduct, b.vat, pList);
}

void inputBill(Bill &b, ProductList pList, ListBill l)
{
    cin.ignore();
    b.billID = generateBillId(l);
    cout << "\n=> Input number of product: ";
    cin >> b.nProduct;
    string *str = new string[b.nProduct];
    b.productID = str;
    cin.ignore();
    for(int i = 0; i < b.nProduct; i++)
    {
        string id;
        do
        {
            cout << " + Input productID " << i + 1 << ": ";
            getline(cin, id);
            if(checkProductIdExist(pList, id) < 0)
            {
                //SetColor(12);
                cout << " !Product ID is not exist! input a again.";
                //SetColor(2);
            }
        }
        while(checkProductIdExist(pList, id) < 0);
        b.productID[i] = id;
    }
    cout << "- VAT: ";
    cin >> b.vat;
    cin.ignore();
    cout << "- Customer name: ";
    getline(cin, b.customerName);
    fixString(b.customerName);
    cout << "- Date (DD/MM/YYYY): ";
    getline(cin, b.date);
    fixString(b.date);
    setTotalPrice(b, pList);
}

void showBillBar()
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

void outputBill(Bill b, ProductList pList)
{
    cout << " - ID: " << b.billID << endl;
    cout << " - Product list: " << endl;
    for(int i = 0; i < b.nProduct; i++)
    {
        for(int j = 0; j < pList.size; j++)
        {
            if(b.productID[i] == pList.product[j]->productID)
            {
                cout << "  + Product:" << pList.product[j]->productName << " & Price: " << pList.product[j]->price << endl;
            }
        }
    }
    cout << " - VAT: " << b.vat << endl;
    cout << " - Total price: " << b.totalPrice << endl;
    cout << " - Customer name: " << b.customerName << endl;
    cout << " - Date: " << b.date << endl;
}

void insertTail(ListBill &l, NodeBill *p)
{
    if(l.phead == nullptr)
    {
        l.phead = l.ptail = p;
    }
    else
    {
        l.ptail->pnext = p;
        l.ptail = p;
    }

}
void insertBillList(ListBill &l, ProductList pList)
{
    Bill b;
    inputBill(b, pList, l);
    NodeBill *p = createNodeBill(b);
    insertTail(l, p);
}
void showBillList(ListBill l, ProductList pList)
{
    int i = 0;
    for(NodeBill *k = l.phead; k != nullptr; k = k->pnext)
    {
        cout << "\n* Information of bill " << i + 1 << endl;
        outputBill(k->data, pList);
        i++;
    }
}

NodeBill* searchBill(ListBill l, string id, ProductList pList)
{
    for(NodeBill *k = l.phead; k != nullptr; k = k->pnext)
    {
        if(id == k->data.billID)
        {
            return k;
        }
    }
    return nullptr;
}

NodeBill* searchMaxPriceBill(ListBill l, ProductList pList)
{
    NodeBill* bMax = l.phead;
    for(NodeBill* k = l.phead->pnext; k != nullptr; k = k->pnext)
    {
        if(bMax->data.totalPrice < k->data.totalPrice)
        {
            bMax = k;
        }
    }
    return bMax;
}

NodeBill* searchMinPriceBill(ListBill l, ProductList pList)
{
    NodeBill* bMin = l.phead;
    for(NodeBill* k = l.phead->pnext; k != nullptr; k = k->pnext)
    {
        if(bMin->data.totalPrice > k->data.totalPrice)
        {
            bMin = k;
        }
    }
    return bMin;
}
