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

typedef struct
{
    char surname[50];
    char name[50];
    char fathersname[50];
    char address[50];
    char group[50];
    float rating;
}
student;

student a[DIM], x;
ll number_of_students = 5;

void read_from_console()
{
    FILE * f;
    if ((f = fopen("in.txt", "w")) == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    for (int i = 1; i <= number_of_students; i++)
    {
        printf("Student #%d\n", i);
        printf("Surname: ");
        scanf("%s", x.surname);
        printf("Name: ");
        scanf("%s", x.name);
        printf("Fathersname: ");
        scanf("%s", x.fathersname);
        printf("Address: ");
        scanf("%s", x.address);
        printf("Group: ");
        scanf("%s", x.group);
        printf("Rating: ");
        scanf("%f", & x.rating);
        fwrite( & x, sizeof(student), 1, f);
    }
    fclose(f);
}
void print(char * name_of_file)
{
    FILE * f;
    if ((f = fopen(name_of_file, "r")) == NULL)
    {
        printf("Error\n");
        exit(2);
    }

    for (int i = 1; i <= number_of_students; i++)
    {
        fread( & a[i], sizeof(student), 1, f);
        printf("Student #%d ", i);
        printf("Surname: %s ", a[i].surname);
        printf("Name: %s ", a[i].name);
        printf("Fathersname: %s ", a[i].fathersname);
        printf("Address: %s ", a[i].address);
        printf("Group: %s ", a[i].group);
        printf("Rating: %f\n", a[i].rating);
    }
    fclose(f);
}

void remove_by_rating(ll value)
{
    FILE * f;
    if ((f = fopen("out.txt", "w")) == NULL)
    {
        printf("Error\n");
        exit(3);
    }
    ll k = 0;
    for (int i = 1; i <= number_of_students; i++)
    {
        if (a[i].rating >= value)
        {
            fwrite( & a[i], sizeof(student), 1, f);
            k++;
        }
    }
    number_of_students = k;
    fclose(f);
}
void addperson()
{
    FILE * f;
    if ((f = fopen("out.txt", "a")) == NULL)
    {
        printf("Error\n");
        exit(4);
    }
    printf("Enter information about 1 person to add to the list: \n");
    student x;
    printf("Surname: ");
    scanf("%s", x.surname);
    printf("Name: ");
    scanf("%s", x.name);
    printf("Fathersname: ");
    scanf("%s", x.fathersname);
    printf("Address: ");
    scanf("%s", x.address);
    printf("Group: ");
    scanf("%s", x.group);
    printf("Rating: ");
    scanf("%f", & x.rating);
    fwrite( & x, sizeof(student), 1, f);
    fclose(f);
    number_of_students++;
}

int main()
{
    read_from_console();

    print("in.txt");

    float VAL;
    printf("Enter value to kick students whose rating is less than it : ");
    scanf("%f", & VAL);
    remove_by_rating(VAL);

    addperson();

    print("out.txt");

    return 0;
}
