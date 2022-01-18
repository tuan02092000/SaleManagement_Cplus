#include "employee.h"

int countEmployee(EmployeeTree eTree)
{
    return eTree.size;
}

bool checkEmployeeIdExist(Tree tree, int employeeID)
{
    if(tree == nullptr)
    {
        return false;
    }
    else
    {
        if(employeeID == tree->data.employeeID)
        {
            return true;
        }
        else if(employeeID > tree->data.employeeID)
        {
            checkEmployeeIdExist(tree->pright, employeeID);
        }
        else if(employeeID < tree->data.employeeID)
        {
            checkEmployeeIdExist(tree->pleft, employeeID);
        }
    }
}
int generateEmployeeID(Tree tree)
{
    int employeeID; // 1000 - 9999
    do
    {
        employeeID = rand() % (9999 - 1000 + 1) + 1000;
    }
    while(checkEmployeeIdExist(tree, employeeID));
    return employeeID;
}

void convertTreeToArray(Tree tree, Employee *e[], int &size)
{
    if(tree != nullptr)
    {
        e[size] = new Employee;
        e[size]->employeeID = tree->data.employeeID;
        e[size]->firstName = tree->data.firstName;
        e[size]->lastName = tree->data.lastName;
        e[size]->salary = tree->data.salary;
        e[size]->age = tree->data.age;
        e[size]->address = tree->data.address;
        e[size]->gender = tree->data.gender;
        size++;
        convertTreeToArray(tree->pleft, e, size);
        convertTreeToArray(tree->pright, e, size);
    }
}

void showEmployeeArray(Employee *e[], int &size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "*Information of employee " << i + 1 << endl;
        cout << " - ID: " << e[i]->employeeID << endl;
        cout << " - Name: " << e[i]->firstName << " " << e[i]->lastName << endl;
        cout << " - Age: " << e[i]->age << endl;
        cout << " - Address: " << e[i]->address << endl;
        cout << " - Gender: " << e[i]->gender << endl;
        cout << " - Salary: " << e[i]->salary << endl;
        cout << endl;
    }
}

void sortBySalary(Tree tree, Employee *e[], int &size)
{
    convertTreeToArray(tree, e, size);
    for(int i = size - 1; i > 0; i--)
    {
        bool rs = true;
        for(int j = 0; j < i; j++)
        {
            if(e[j]->salary < e[j + 1]->salary)
            {
                Employee *temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
                rs = false;
            }
        }
        if(rs)
        {
            break;
        }
    }
    showEmployeeArray(e, size);
}

NodeE* createNodeEmployee()
{
    NodeE* p = new NodeE;
    p->pleft = nullptr;
    p->pright = nullptr;
    return p;
}

void createEmployeeTree(EmployeeTree &eTree)
{
    eTree.root = nullptr;
    eTree.size = 0;
}

void addEmployee(Tree &tree, NodeE *e)
{
    if(tree == nullptr)
    {
        tree = e;
    }
    else
    {
        if(tree->data.employeeID < e->data.employeeID)
        {
            addEmployee(tree->pright, e);
        }
        else if(tree->data.employeeID > e->data.employeeID)
        {
            addEmployee(tree->pleft, e);
        }
    }
}
void insertEmployeeTree(EmployeeTree &eTree)
{
    cin.ignore();
    NodeE *e = createNodeEmployee();
    e->data.employeeID = generateEmployeeID(eTree.root);
    cout << "* Input information of employee" << endl;
    cout << " - First name: ";
    getline(cin, e->data.firstName);
    fixString(e->data.firstName);
    cout << " - Last name: ";
    getline(cin, e->data.lastName);
    fixString(e->data.lastName);
    cout << " - Age: ";
    cin >> e->data.age;
    cin.ignore();
    cout << " - Address: ";
    getline(cin, e->data.address);
    fixString(e->data.address);
    cout << " - Gender: ";
    getline(cin, e->data.gender);
    fixString(e->data.gender);
    cout << " - Salary: ";
    cin >> e->data.salary;
    addEmployee(eTree.root, e);
    eTree.size++;
}

void showEmployeeBar()
{
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << left << "ID";
    cout << setw(20) << "First Name";
    cout << setw(20) << "Last Name";
    cout << setw(10) << "Age";
    cout << setw(20) << "Address";
    cout << setw(10) << "Gender";
    cout << setw(15) << "Salary" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}

void outputEmployee(NodeE *e)
{
    cout << setw(10) << left << e->data.employeeID;
    cout << setw(20) << e->data.firstName;
    cout << setw(20) << e->data.lastName;
    cout << setw(10) << e->data.age;
    cout << setw(20) << e->data.address;
    cout << setw(10) << e->data.gender;
    cout << setw(15) << e->data.salary << endl;
}

void showEmployeeTree(Tree tree)
{
    if(tree != nullptr)
    {
        showEmployeeTree(tree->pleft);
        outputEmployee(tree);
        showEmployeeTree(tree->pright);
    }
}

void editEmployee(Tree &tree, int employeeID)
{
    if(tree != nullptr)
    {
        if(employeeID == tree->data.employeeID)
        {
            cin.ignore();
            cout << "* Edit information of employee" << endl;
            cout << " - First name: ";
            getline(cin, tree->data.firstName);
            fixString(tree->data.firstName);
            cout << " - Last name: ";
            getline(cin, tree->data.lastName);
            fixString(tree->data.lastName);
            cout << " - Age: ";
            cin >> tree->data.age;
            cin.ignore();
            cout << " - Address: ";
            getline(cin,tree->data.address);
            fixString(tree->data.address);
            cout << " - Gender: ";
            getline(cin, tree->data.gender);
            fixString(tree->data.gender);
            cout << " - Salary: ";
            cin >> tree->data.salary;
        }
        else if(employeeID > tree->data.employeeID)
        {
            editEmployee(tree->pright, employeeID);
        }
        else if(employeeID < tree->data.employeeID)
        {
            editEmployee(tree->pleft, employeeID);
        }
    }
}
bool editEmployeeTree(EmployeeTree &eTree)
{
    int employeeID;
    cout << "Enter employee id (edit): ";
    cin >> employeeID;
    bool check = checkEmployeeIdExist(eTree.root, employeeID);
    if(check)
    {
        editEmployee(eTree.root, employeeID);
        return true;
    }
    else
    {
        return false;
    }
}

NodeE* searchEmployee(Tree tree, int employeeID)
{
    if(tree == nullptr)
    {
        return nullptr;
    }
    else
    {
        if(employeeID == tree->data.employeeID)
        {
            return tree;
        }
        else if(employeeID > tree->data.employeeID)
        {
            searchEmployee(tree->pright, employeeID);
        }
        else if(employeeID < tree->data.employeeID)
        {
            searchEmployee(tree->pleft, employeeID);
        }
    }
}

bool searchEmployeeTree(EmployeeTree eTree, int employeeID)
{
    bool check = checkEmployeeIdExist(eTree.root, employeeID);
    if(check)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void deleteNode(Tree &p)
{
    NodeE *q;
    NodeE *r;
    if(p->pleft == nullptr)
    {
        q = p;
        p = p->pright;
    }
    else if(p->pright == nullptr)
    {
        q = p;
        p = p->pleft;
    }
    else
    {
        q = p->pright;
        if(q->pleft == nullptr)
        {
            p->data = q->data;
            p->pright = q->pright;
        }
        else
        {
            do
            {
                r = q;
                q = q->pleft;
            }
            while(q->pleft != nullptr);
            p->data = q->data;
            r->pleft = q->pright;
        }
    }
    delete q;
}
void deleteTree(Tree &tree, int employeeID)
{
    if(tree != nullptr)
    {
        if(employeeID < tree->data.employeeID)
        {
            deleteTree(tree->pleft, employeeID);
        }
        else if(employeeID > tree->data.employeeID)
        {
            deleteTree(tree->pright, employeeID);
        }
        else
        {
            deleteNode(tree);
        }

    }
}
bool deleteEmployeeTree(EmployeeTree &eTree)
{
    int employeeID;
    cout << "Enter employee id (delete): ";
    cin >> employeeID;
    bool check = checkEmployeeIdExist(eTree.root, employeeID);
    if(check)
    {
        deleteTree(eTree.root, employeeID);
        eTree.size--;
        return true;
    }
    else
    {
        return false;
    }
}

void createBill(EmployeeTree &eTree, ProductList pList, ListBill &lBill)
{
    int employeeID;
    cout << "Enter employee id (create bill): ";
    cin >> employeeID;
    bool check = checkEmployeeIdExist(eTree.root, employeeID);
    if(check)
    {
        NodeE* e = searchEmployee(eTree.root, employeeID);
        Bill b;
        inputBill(b, pList, lBill);
        NodeBill *p = createNodeBill(b);
        insertTail(e->data.l, p);
        insertTail(lBill, p);
    }
    else
    {
        cout << "Employee id is not exist!!!" << endl;
    }
}

void showBillByEmployee(EmployeeTree eTree, ProductList pList)
{
    int employeeID;
    cout << "Enter employee id (show bill of employee): ";
    cin >> employeeID;
    bool check = checkEmployeeIdExist(eTree.root, employeeID);
    if(check)
    {
        NodeE* e = searchEmployee(eTree.root, employeeID);
        showBillList(e->data.l, pList);
    }
    else
    {
        cout << "Employee id is not exist!!!" << endl;
    }
}
