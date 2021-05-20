#include <iostream>

using namespace std;

int findSmallest(const int list[], int numItems);

int main() {
    int list[] = {5, 6, 7, 8, -1, 10};
    cout << findSmallest(list, 6);
}

int findSmallest(const int list[], int numItems) {
    if(numItems == 1)
        return list[0];
    if(list[numItems - 2] < list[numItems - 1])
        return findSmallest(list, numItems - 1);
}