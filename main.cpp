#include <stdio.h>
#include <stdint.h>

typedef unsigned long long U64;
#define C64(x) x##ULL

void printBitboard(U64 bb) {
    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            int sq = rank * 8 + file;
            U64 mask = C64(1) << sq;
            printf("%c ", (bb & mask) ? '1' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    U64 whitePawns = C64(0x000000000000FF00); // rank 2
    U64 blackPawns = C64(0x00FF000000000000); // rank 7
    U64 pawns = whitePawns | blackPawns;

    printf("Pawns only:\n");
    printBitboard(pawns);
    return 0;
}
