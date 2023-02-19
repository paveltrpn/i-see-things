
#include <iostream>

template <typename T> T foo(T in) {
	return in + 11.6; 
}

int template_test() {
	std::cout << "TEST - template.cpp" << "\n" << std::endl;
	
	std::cout << "template out = " << foo(10.0) << "\n";
	
	return 0;
}