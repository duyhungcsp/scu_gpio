#include <iostream>
#include <thread>
using namespace std;

void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        cout << "Thread using function"
               " pointer as callable\n";
    }
}

int main()
{
    cout << "Threads 1 and 2 and 3 "
         "operating independently" << endl;
  
    // This thread is launched by using 
    // function pointer as callable
    thread th1(foo, 3);

    th1.join();

    return 0;
}