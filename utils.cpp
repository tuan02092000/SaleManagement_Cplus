#include "utils.h"
#include "processFile.h"

void displayMainMenu()
{
    cout << "****************** SALE MANAGEMENT ******************" << endl;
    cout << "*\t\t1. Product Management\t\t    *" << endl;
    cout << "*\t\t2. Bill Management\t\t    *" << endl;
    cout << "*\t\t3. Employee Management\t\t    *" << endl;
    cout << "*\t\t0. Quit\t\t\t\t    *" << endl;
    cout << "********************** END MENU *********************" << endl << endl;
    cout << "-----------------------------------------------------" << endl;
}

void displayProductMenu()
{
    cout << "****************** PRODUCT MANAGEMENT *******************" << endl;
    cout << "*\t\t1. Insert product\t\t\t*" << endl;
    cout << "*\t\t2. Show all product\t\t\t*" << endl;
    cout << "*\t\t3. Edit product\t\t\t\t*" << endl;
    cout << "*\t\t4. Delete product\t\t\t*" << endl;
    cout << "*\t\t5. Search product\t\t\t*" << endl;
    cout << "*\t\t6. Sort product list (desc)\t\t*" << endl;
    cout << "*\t\t0. Quit\t\t\t\t\t*" << endl;
    cout << "********************** END MENU *************************" << endl << endl;
    cout << "-----------------------------------------------------" << endl;
}

void displayBillMenu()
{
    cout << "****************** BILL MANAGEMENT **********************" << endl;
    cout << "*\t\t1. Show all bill\t\t\t*" << endl;
    cout << "*\t\t2. Search bill\t\t\t\t*" << endl;
    cout << "*\t\t3. Search bill with largest price\t*" << endl;
    cout << "*\t\t4. Search bill with smallest price\t*" << endl;
    cout << "*\t\t0. Quit\t\t\t\t\t*" << endl;
    cout << "********************** END MENU *************************" << endl << endl;
    cout << "-----------------------------------------------------" << endl;
}

void displayEmployeeMenu()
{
    cout << "****************** EMPLOYEE MANAGEMENT ******************" << endl;
    cout << "*\t\t1. Insert employee\t\t\t*" << endl;
    cout << "*\t\t2. Show all employee\t\t\t*" << endl;
    cout << "*\t\t3. Edit employee\t\t\t*" << endl;
    cout << "*\t\t4. Delete employee\t\t\t*" << endl;
    cout << "*\t\t5. Search employee\t\t\t*" << endl;
    cout << "*\t\t6. Sort by salary (desc)\t\t*" << endl;
    cout << "*\t\t7. Create bill\t\t\t\t*" << endl;
    cout << "*\t\t8. Show bill create by employee\t\t*" << endl;
    cout << "*\t\t0. Quit\t\t\t\t\t*" << endl;
    cout << "********************** END MENU *************************" << endl << endl;
    cout << "-----------------------------------------------------" << endl;
}

void productMenu(ProductList &productList)
{
    int check;
    do
    {
        system("cls");
        displayProductMenu();
        cout << "\n=> Enter your select: ";
        cin >> check;
        cout << endl;
        switch(check)
        {
        case 1:
        {
            insertProductList(productList);
            system("pause");
            break;
        }
        case 2:
        {
            showProductList(productList);
            system("pause");
            break;
        }
        case 3:
        {
            if(editProductList(productList))
            {
                cout << "\n=> Edit successfully!!!" << endl;
            }
            else
            {
                cout << "\n=> Product ID is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 4:
        {
            if(deleteProduct(productList))
            {
                cout << "\n=> Delete successfully!!!" << endl;
            }
            else
            {
                cout << "\n=> Product ID is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 5:
        {
            cin.ignore();
            string id;
            cout << "\n=> Enter product id (search): ";
            getline(cin, id);
            fixString(id);
            Product *p = searchProduct(productList, id);
            if(p != nullptr)
            {
                outputProduct(p);
            }
            else
            {
                cout << "\n=> Product ID is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 6:
        {
            sortProductList(productList);
            showProductList(productList);
            system("pause");
            break;
        }
        case 0:
        {
            cout << "\n=> Quit Product Management" << endl;
            system("pause");
            break;
        }
        default:
        {
            cout << "\n=> Error!!! Try a again." << endl;
            system("pause");
            break;
        }
        }
    }
    while(check != 0);
}

void billMenu(ListBill &l, ProductList pList)
{
    int check;
    do
    {
        system("cls");
        displayBillMenu();
        cout << "\n=> Enter your select: ";
        cin >> check;
        switch(check)
        {
        case 1:
        {
            showBillList(l, pList);
            system("pause");
            break;
        }
        case 2:
        {
            cin.ignore();
            string id;
            cout << "\n=> Enter bill id (find): ";
            getline(cin, id);
            fixString(id);
            NodeBill* k = searchBill(l, id, pList);
            if(k != nullptr)
            {
                outputBill(k->data, pList);
            }
            else
            {
                cout << "\n=> Bill id is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 3:
        {
            cout << "\n=> Largest price: " << endl;
            NodeBill* k = searchMaxPriceBill(l, pList);
            if(k != nullptr)
            {
                outputBill(k->data, pList);
            }
            else
            {
                cout << "\n=> Bill id is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 4:
        {
            cout << "\n=> Smallest price: " << endl;
            NodeBill* k = searchMinPriceBill(l, pList);
            if(k != nullptr)
            {
                outputBill(k->data, pList);
            }
            else
            {
                cout << "\n=> Bill id is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 0:
        {
            cout << "\n=> Quit Bill Management" << endl;
            system("pause");
            break;
        }
        default:
        {
            cout << "\n=> Error!!! Try a again." << endl;
            system("pause");
            break;
        }
        }
    }
    while(check != 0);
}

void employeeMenu(EmployeeTree &eTree, ProductList pList, ListBill &lBill)
{
    int check;
    do
    {
        system("cls");
        displayEmployeeMenu();
        cout << "\n=> Enter your select: ";
        cin >> check;
        switch(check)
        {
        case 1:
        {
            insertEmployeeTree(eTree);
            system("pause");
            break;
        }
        case 2:
        {
            cout << "\n# Number of employee: " << countEmployee(eTree) << endl;
            showEmployeeBar();
            showEmployeeTree(eTree.root);
            system("pause");
            break;
        }
        case 3:
        {
            if(editEmployeeTree(eTree))
            {
                cout << "\n=> Edit successfully!!!" << endl;
            }
            else
            {
                cout << "\n=> Employee id is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 4:
        {
            if(deleteEmployeeTree(eTree))
            {
                cout << "\n=> Delete successfully!!!" << endl;
            }
            else
            {
                cout << "\n=> Employee id is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 5:
        {
            int employeeID;
            cout << "\n=> Enter employee id (search): ";
            cin >> employeeID;
            if(searchEmployeeTree(eTree, employeeID))
            {
                NodeE* e = searchEmployee(eTree.root, employeeID);
                outputEmployee(e);
            }
            else
            {
                cout << "\n=> Employee id is not exist!!!" << endl;
            }
            system("pause");
            break;
        }
        case 6:
        {
            Employee *e[MAX];
            int size = 0;
            sortBySalary(eTree.root, e, size);
            for(int i = 0; i < size; i++)
            {
                delete e[i];
            }
            system("pause");
            break;
        }
        case 7:
        {
            createBill(eTree, pList, lBill);
            system("pause");
            break;
        }
        case 8:
        {
            showBillByEmployee(eTree, pList);
            system("pause");
            break;
        }
        case 0:
        {
            cout << "\n=> Quit Employee Management" << endl;
            system("pause");
            break;
        }
        default:
        {
            cout << "\n=> Error!!! Try a again." << endl;
            system("pause");
            break;
        }
        }
    }
    while(check != 0);
}



void mainMenu(ProductList &pList, ListBill &lBill, EmployeeTree &eTree)
{
    int check;
    readProductFile(pList);
    readEmployeeFile(eTree);
    do
    {
        system("cls");
        displayMainMenu();
        cout << "\n=> Enter your select: ";
        cin >> check;
        switch(check)
        {
        case 1:
        {
            productMenu(pList);
            break;
        }
        case 2:
        {
            billMenu(lBill, pList);
            break;
        }
        case 3:
        {
            employeeMenu(eTree, pList, lBill);
            break;
        }
        case 0:
        {
            cout << "\n=> Quit Main Management!!! Bye Bye." << endl;
            system("pause");
            break;
        }
        default:
        {
            cout << "\n=> Error!!! Try a again." << endl;
            system("pause");
            break;
        }
        }
    }
    while(check != 0);
}
