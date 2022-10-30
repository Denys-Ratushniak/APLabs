#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define fi first
#define eps 0.00000000000001
#define se second
#define x1 sfhshfd
#define y1 sfhs321321hfd
#define glhf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define GG cout << " OPANA " << endl;
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;

typedef unsigned long long ull;
typedef long double ld;
typedef pair < ll, ll > pairll;
typedef tree < ll, null_type, less < ll >, rb_tree_tag, tree_order_statistics_node_update > SATANA;
typedef tree < ll, null_type, less_equal < ll >, rb_tree_tag, tree_order_statistics_node_update > MULSATANA;

const ll DIM = 107;
const ll INF = 1e9 + 7;

struct node
{
    int val;
    node * next;
    node * prev;
    node(int x)
    {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct mylist
{
    int sz;
    node * first;
    node * last;
    mylist()
    {
        sz = 0;
        first = NULL;
        last = NULL;
    }
};

void addtoend(mylist * LIST, int x)
{
    node * a = new node(x);
    if (LIST -> sz == 0)
    {
        LIST -> first = a;
        LIST -> last = a;
        LIST -> sz++;
        return;
    }
    LIST -> last -> next = a;
    a -> prev = LIST -> last;
    LIST -> last = a;
    LIST -> sz++;
}
void deletelist(mylist ** LIST)
{
    node * a = ( * LIST) -> first;
    //cout << "DEL : " << a->val << endl;
    node * b;
    int i = 0;
    while (a)
    {
        b = a -> next;
        delete a;
        a = b;
    }
    delete * LIST;
    * LIST = NULL;
}

void delfrombegin(mylist * LIST)
{
    if (LIST -> sz == 0)
    {
        cout << "List is empty. Cannot delete" << endl;
        return;
    }
    node * a = LIST -> first;
    LIST -> first = LIST -> first -> next;
    if (LIST -> first) LIST -> first -> prev = NULL;
    if (a == LIST -> last) LIST -> last = NULL;
    LIST -> sz--;
    delete a;
}

mylist * create()
{
    mylist * LIST = new mylist();
    cout << "Enter count of numbers in list:";
    int n, x;
    cin >> n;
    cout << "Enter integer values:";
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        addtoend(LIST, x);
    }
    return LIST;
}

void printlist(mylist * LIST)
{
    if (LIST == NULL || LIST -> sz == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    node * a = LIST -> first;
    cout << a -> val << " ";
    for (int i = 2; i <= LIST -> sz; i++)
    {
        a = a -> next;
        cout << a -> val << " ";
    }
    cout << endl;
}

void writetofile(mylist * LIST)
{

    ofstream myfile("file.txt");
    myfile << LIST -> sz << " ";
    if (LIST -> sz != 0)
    {
        node * a = LIST -> first;
        myfile << a -> val << " ";
        for (int i = 2; i <= LIST -> sz; i++)
        {
            a = a -> next;
            myfile << a -> val << " ";
        }
    }
    myfile.close();
}

mylist * readfromfile()
{
    ifstream myfile("file.txt");

    mylist * LIST = new mylist();
    int x;
    int k = 0;
    int sz;
    myfile >> sz;
    for (int i = 1; i <= sz; i++)
    {
        myfile >> x;
        addtoend(LIST, x);
    }
    myfile.close();
    return LIST;
}

int main()
{
    mylist * LIST = create();
    cout << "Beginning: ";
    printlist(LIST);

    delfrombegin(LIST);

    cout << "After deleting beginning element: ";
    printlist(LIST);

    cout << "Enter the integer you want to add to the end of list: " << endl;
    int x;
    cin >> x;
    addtoend(LIST, x);

    cout << "After adding element in the end: ";
    printlist(LIST);

    writetofile(LIST);

    deletelist( & LIST);

    cout << "After whole deleting: ";
    printlist(LIST);

    LIST = readfromfile();

    cout << "After reading from file: ";
    printlist(LIST);
    return 0;
}
