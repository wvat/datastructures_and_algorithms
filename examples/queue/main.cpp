#include <iostream>
using namespace std;

#include "Queue.cpp"

int main()
{

    Queue<int> *q = new Queue<int>();

    int test_length = 10;
    int arr[test_length];

    for(int i=0; i < test_length; i++)
    {
        int val = rand() % 100;
        q->enqueue(val);
        arr[i] = val;
    }

    cout << *q << endl;

    for(int i=0; i < test_length; i++)
    {
        int retval = q->dequeue();
        if(retval != arr[i])
        {
            cerr << "Error: incorrect dequeue value " << retval << " Expected " << arr[i] << endl;
        }
        else
            cout << retval << endl;
    }
}