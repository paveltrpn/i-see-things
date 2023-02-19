
#include <stdio.h>

typedef struct page_t * (*some_func_ptr_t)();

struct sage_t *ghgh() {
    return NULL;
}

struct go_t *go() {
    return NULL;
}

void baz(some_func_ptr_t f) {

}

int main() {
    some_func_ptr_t bar;
    int x;

    baz(&ghgh);
    
    printf("shittyy cdecl\n");
}
