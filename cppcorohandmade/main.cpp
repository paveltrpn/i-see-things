
#include <iostream>

int foo() {
    return 1;
}

int bar(int first, int second) {
    return first * second;
}

int baz(int first, int second) {
    return first + second * 5;
}

void out(int arg) {
    std::cout << arg << std::endl;
}

class CoroStateMachine {
    public:
        CoroStateMachine(int z): z_(z), label_(0) {

        }
        
        void Resume() {
            switch(label_) {
                case 0:
                    a_ = foo();
                    label_ = 1;
                    return;
                case 1:
                    b_ = bar(a_, z_);
                    label_ = 2;
                    return;
                case 2:
                    c_ = baz(a_, b_);
                    out(c_);
                    return;
            }
        }

    private:
        // coroutine arggument
        int z_;

        // coroutine local vars
        int a_;
        int b_;
        int c_;

        // coroutine state machine states label
        int label_;
};

void coro(int z) {
    int a = foo();
    // suspend
    int b = bar(a, z);
    // suspend
    int c = baz(a, b);
    out(c);
}

int main() {
    coro(50);

    CoroStateMachine foo{50};
    foo.Resume();
    foo.Resume();
    foo.Resume();


    return 0;
}
