
#include <iostream>
#include <vector>

void foo(int n) {
	std::vector<float> bar(n);

	for (int i = 0; i < n; i++) {
		bar.push_back((float)i + 1.0);
	}
}

int vector_test() {
	std::cout << "TEST - vector.cpp" << "\n" << std::endl;

	return 0;
}