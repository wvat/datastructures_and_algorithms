#include <iostream>
using namespace std;
#include "LinkedList.cpp"

int main(){
    LinkedList<int>* ll = new LinkedList<int>();

    ll->add(1);
    ll->add(2);
    ll->add(3);

    cout << *ll << endl;
}