
int main(int argc, char** argv) {
    int value = 10;
    const int* constPtr = &value;
    int* const ptrConst = &value;

    ptrConst += 1;
    (*constPtr) += 1;
    constPtr += 1;

    return 0;
}
