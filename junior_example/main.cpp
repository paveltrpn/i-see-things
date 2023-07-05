
#include <iostream>

class SomeClassBad
{
	int* some_ptr;

public:

	void print_value()
	{
		std::cout << *some_ptr;
	}

	void set_val(int* ptr)
	{
		delete some_ptr;
		some_ptr = ptr;
	}

	SomeClassBad& operator=(SomeClassBad& val)
	{
		delete some_ptr;
		some_ptr = val.some_ptr;		
	}

	~SomeClassBad()
	{
		delete some_ptr;
	}
};


class SecondClassBad: public SomeClassBad
{
public:

	void print_value()
	{
		std::cout << "wubba lubba dub dub" << std::endl;
	}
};

class SomeClassGood {
	int* some_ptr;

    public:
    
        SomeClassGood(): some_ptr(nullptr) {
        }

	    virtual void print_value() {
		    std::cout << "base" << std::endl;
            std::cout << *some_ptr << std::endl;
	    }

	    void set_val(int* ptr) {
		    delete some_ptr;
		    some_ptr = ptr;
	    }

	    SomeClassGood& operator=(SomeClassGood& val) {
		    delete some_ptr;
		    some_ptr = val.some_ptr;		
	    }

	    virtual ~SomeClassGood() {
		    delete some_ptr;
	    }
};


class SecondClassGood: public SomeClassGood {
    public:
	    void print_value() override {
		    std::cout << "derived" << std::endl;
            std::cout << "wubba lubba dub dub" << std::endl;
        }
};

int main(int argc, char **argv) {
    SecondClassGood sc;
    SomeClassGood *byPtr = new SecondClassGood();

    sc.print_value();
    byPtr->print_value();
    return 0;
}
