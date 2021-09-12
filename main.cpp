#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

thread_local <atomic> i = 0;

void foo(){
cout<<i;
++i;
}

int main(){

thread t1(foo);
thread t2(foo);
thread t3(foo);

t1.join();
t2.join();
t3.join();

//the output should be 123
//but since we applied thread_local, the output is gonna be 111
//because thread_local made the variable i local, and each new thread has its own distinct value

return 0;
}
