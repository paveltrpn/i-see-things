
#include <iostream>

class matrix {
    public:
        matrix(size_t size) {
            data = new float[size]; 
        }
        
        
        ~matrix() {
            delete [] data;
        }

    private:
        float *data;
};
