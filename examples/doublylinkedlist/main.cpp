#include <iostream>
using namespace std;
#include "LinkedList.cpp"

int main(){
    LinkedList<int>* ll = new LinkedList<int>();

    ll->add(1);
    ll->add(2);
    ll->add(3);

    cout << *ll << endl;
    //Iterator<int>* i = new Iterator<int>(ll);

    for(LinkedList<int>::Iterator i = ll->get_front(); i != ll->get_end(); i++){
        cout << *i << endl;
    }

    // quick insertion test
    LinkedList<int>::Iterator i = ll->get_front();
    i++;
    i.insert(5);

    cout << *ll << endl;
    i++;
    cout << "test" << endl;
    cout << *i << endl;
    i.insert(6);
    
    cout << *ll << endl;
    
}