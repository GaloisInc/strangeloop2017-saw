#include <stdint.h>

#include "ffs_ref.c"

#include "ffs_imp.c"

uint32_t ffs_imp_nobranch(uint32_t i) {
  char n = 1;
  int s1 = !(i & 0xffff) << 4;
  n += s1; i >>= s1;
  int s2 = !(i & 0x00ff) << 3;
  n += s2;  i >>= s2;
  int s3 = !(i & 0x000f) << 2;
  n += s3;  i >>= s3;
  int s4 = !(i & 0x0003) << 1;
  n += s4;  i >>= s4;
  // Still does have one branch...
  return (i) ? (n+((i+1) & 0x01)) : 0;
}

#include "ffs_bug.c"

// Creative optimized version based on musl libc:
// http://www.musl-libc.org/.
//
// Apparently this is a well known approach:
// https://en.wikipedia.org/wiki/Find_first_set#CTZ. The DeBruijn
// (https://en.wikipedia.org/wiki/De_Bruijn_sequence) sequence here is
// different from the one in the Wikipedia article on 'ffs'.
uint32_t ffs_musl (uint32_t x)
{
  static const char debruijn32[32] = {
    0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13,
    31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14
  };
  return x ? debruijn32[(x&-x)*0x076be629 >> 27]+1 : 0;
}

int ffs_imp_correct(uint32_t x) {
    return ffs_imp(x) == ffs_ref(x);
}

int ffs_bug_correct(uint32_t x) {
    return ffs_bug(x) == ffs_ref(x);
}
