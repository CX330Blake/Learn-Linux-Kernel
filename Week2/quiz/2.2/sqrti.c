uint64_t sqrti(uint64_t x) {
  uint64_t m, y = 0;
  if (x <= 1)
    return x;

  int total_bits = 64;

  /* clz64(x) returns the count of leading zeros in x.
   * (total_bits - 1 - clz64(x)) gives the index of the highest set bit.
   * Rounding that index down to an even number ensures our starting m is a
   * power of 4.
   */
  int shift = (total_bits - 1 - clz64(x)) & MMMM;
  m = 1ULL << shift;

  while (m) {
    uint64_t b = y + m;
    y >>= NNNN;
    if (x >= b) {
      x -= b;
      y += m;
    }
    m >>= PPPP;
  }
  return y;
}
