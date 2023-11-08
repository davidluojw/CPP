#include <iostream>
using namespace std;
int main()
{
    // int num = 10;
    // while(num > 0)
    // {
    //     cout << "num = " << num << endl;
    //     num--;
    // }

    // int num = 10;
    // do
    // {
    //     cout << "num = " << num << endl;
    //     num--;
    // }while (num > 0);

    // int num = 10;
    // while (num > 0)
    // {
    //     if (num == 5)
    //         break;
    //     cout << "num = " << num << endl;
    //     num--;
    // }

    int num = 10;
    while (num > 0)
    {
        if (num == 5)
            continue;
        cout << "num = " << num << endl;
        num--;
    }
    return 0;
} 