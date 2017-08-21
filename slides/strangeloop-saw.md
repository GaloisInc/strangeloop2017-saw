%  From Testing to Proof using Symbolic Execution
% Aaron Tomb
% September 28, 2017

# Agenda

* TODO

# What is SAW?

* TODO

# Installing SAW Locally

* TODO: locally

* TODO: VM images

# Property Based Testing

* TODO

# XOR Swap Example

* TODO

~~~~ .c
void swap_xor(uint32_t *x, uint32_t *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}
~~~~

# Manual Swap Testing

* TODO

# Random Swap Testing

* TODO

# FFS Example

~~~~ .c
uint32_t ffs_ref(uint32_t word) {
  if(!word) return 0;
  for(int c = 0, i = 0; c < 32; c++)
    if(((1 << i++) & word) != 0)
      return i;
  return 0;
}
~~~~

~~~~ .c
uint32_t ffs_imp(uint32_t i) {
  char n = 1;
  if (!(i & 0xffff)) { n += 16; i >>= 16; }
  if (!(i & 0x00ff)) { n +=  8; i >>=  8; }
  if (!(i & 0x000f)) { n +=  4; i >>=  4; }
  if (!(i & 0x0003)) { n +=  2; i >>=  2; }
  return (i) ? (n+((i+1) & 0x01)) : 0;
}
~~~~

# Manual FFS Testing

* TODO

# Random FFS Testing

* TODO

# Translating Programs to Formulas

* TODO

# SAT and SMT Solvers

* TODO

# Verifying FFS with SAW

* TODO

# Verifying XOR swap with SAW

* TODO

# How More Complex Verifications Work

* TODO

# Salsa20 Example

* TODO

# Sidebar: Fuzzing for Property Based Tests

* TODO

# Sidebar: SAW on `libfuzzer` Harnesses

* TODO

# Other Ways to use SAT and SMT

* TODO

# Other Things Available in SAW

* TODO: Java

* TODO: Coming soon: Rust, Go, some degree of machine code

* TODO: more powerful interactive verification

* TODO: Coming soon: bindings to external interactive provers, including Lean and Coq

# How Much Can You Do?

* TODO

# Conclusion

* TODO
