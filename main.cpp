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
    U64 whitePawns   = 0x000000000000FF00ULL;
    U64 whiteKnights = 0x0000000000000042ULL;
    U64 whiteBishops = 0x0000000000000024ULL;
    U64 whiteRooks   = 0x0000000000000081ULL;
    U64 whiteQueens  = 0x0000000000000008ULL;
    U64 whiteKing    = 0x0000000000000010ULL;

    // Black pieces
    U64 blackPawns   = 0x00FF000000000000ULL;
    U64 blackKnights = 0x4200000000000000ULL;
    U64 blackBishops = 0x2400000000000000ULL;
    U64 blackRooks   = 0x8100000000000000ULL;
    U64 blackQueens  = 0x0800000000000000ULL;
    U64 blackKing    = 0x1000000000000000ULL;
    U64 pawns = whitePawns | blackPawns;

    printf("Pawns only:\n");
    printBitboard(pawns);
    return 0;
}
