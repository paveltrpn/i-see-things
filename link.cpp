
#include <iostream>

using namespace std;

int a = 10;

int & foo(int t) {
    a = a + t;
    return a;
}

int main(int argc, char *argv[]) {
    int t = 5;

    cout << "a = " << a << "\n";
    
    foo(t);
    cout << "foo(t) = " << a << "\n";

    foo(t) = t; //Присвоится корректно, a будет ссылаться на t
    cout << "foo(t) = t - " << a << "\n";

    return 0;
}

