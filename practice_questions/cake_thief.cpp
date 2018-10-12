// Dynamic Programming Problem

#include <iostream>
#include <vector>

using namespace std;

struct cake {
    int weight;
    int value;
    cake(int x, int y) : weight(x), value(y) {}
};

int main()
{
    cake* myCake = new cake(5,10);

    cout << myCake->weight << endl;

    return 0;
}