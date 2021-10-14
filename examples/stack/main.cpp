#include <iostream>
using namespace std;
#include "Stack.cpp"

int main(){
    cout << "hello" << endl;

    Stack<int>* s = new Stack<int>();

    int test_length = 10;
    int arr[test_length];

    int val;
    int i;
    for(i=0; i < test_length; i++)
    {
        val = rand() % 100;
        cout << "pushing " << val << endl;
        s->push(val);
        arr[i] = val;
    }

    // take a look at the top
    cout << s->peek() << endl;

    cout << *s;

    for(i=test_length-1; i >= 0; i--){
        val = s->pop();
        cout << "popping " << val << endl;
        if(val != arr[i])
            cerr << "Error: expected to pop " << arr[i] << " but got " << val << endl;
    }

    cout << s->is_empty() << endl;
}