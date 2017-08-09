#include <assert.h>
#include <stdlib.h>

void swap_direct(uint8_t *x, uint8_t *y) {
    uint8_t tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_xor(uint8_t *x, uint8_t *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main() {
    uint8_t x, y;
    uint8_t x1=x, y1=y;
    uint8_t x2=x, y2=y;
    swap_direct(&x1, &y1);
    swap_xor(&x2, &y2);
    if(x1 != x2 || y1 != y2)
        assert(0);
}
