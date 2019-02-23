// Dynamic Programming Problem

#include <iostream>
#include <vector>

using namespace std;

struct Cake {
    int weight;
    int value;
    cake(int x, int y) : weight(x), value(y) {}
};

const vector<Cake> cakeTypes {
    Cake(7,160),
    Cake(3,90),
    Cake(2,15)
};

unsigned int capacity = 20;

maxDuffelBagValue(cakeTypes, capacity)
{
    vector<unsigned long long> maxValuesAtCapacities(capacity + 1);
}