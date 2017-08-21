#include <assert.h>
#include <stdlib.h>

#include "direct-swap.c"

#include "xor-swap.c"

#include "swap-correct.c"

int main() {
    for(int i = 0; i < 100; i++) {
        uint32_t x = rand();
        uint32_t y = rand();
        assert(swap_correct(x, y));
    }
    return 0;
}

