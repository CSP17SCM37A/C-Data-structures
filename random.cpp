#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int x,a,p;
    cout << "Enter initial positive integer number: ";
    cin >> x;
    cout << "Enter final positive integer a: ";
    cin >> a;
    
    for(int i=1; i<=7; i++)
    {
        x=(a*x % 2);
        cout << x << endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
