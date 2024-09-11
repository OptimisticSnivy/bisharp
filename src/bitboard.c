#include <stdio.h>

// bitboard type
typedef unsigned long long u64;

// macros
#define get_bit(bb, square) (bb & (1ULL << square))

void outputbb(u64 bb) {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      int square = rank * 8 + file;
      printf(" %d ", get_bit(bb, square) ? 1 : 0);
    }
    printf("\n");
  }
}

u64 whitebb() {
  const u64 whitePawns = 0xff00;
  const u64 whiteRooks = 0x81;
  const u64 whiteBishops = 0x24;
  const u64 whiteKnights = 0x42;
  const u64 whiteKing = 0x8;
  const u64 whiteQueen = 0x10;

  return (whitePawns | whiteRooks | whiteBishops | whiteKnights | whiteKing |
          whiteQueen);
}

u64 blackbb() {
  const u64 blackPawns = 0xff000000000000;
  const u64 blackRooks = 0x8100000000000000;
  const u64 blackBishops = 0x2400000000000000;
  const u64 blackKnights = 0x4200000000000000;
  const u64 blackKing = 0x1000000000000000;
  const u64 blackQueen = 0x800000000000000;

  return (blackPawns | blackRooks | blackBishops | blackKnights | blackKing |
          blackQueen);
}

int main() {

  outputbb(whitebb());
  printf("\n");
  outputbb(blackbb());
  printf("\n");
  outputbb(blackbb() | whitebb());
  return 0;
}
