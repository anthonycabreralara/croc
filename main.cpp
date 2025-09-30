#include <stdio.h>
#include <stdint.h>

typedef unsigned long long U64;
#define C64(x) x##ULL

enum { white, black };

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

U64 soutOne(U64 b) {return b >> 8;}
U64 nortOne(U64 b) {return b << 8;}

U64 wSinglePushTargets(U64 wpawns, U64 empty) {
   return nortOne(wpawns) & empty;
}

U64 wDblPushTargets(U64 wpawns, U64 empty) {
   const U64 rank4 = C64(0x00000000FF000000);
   U64 singlePushs = wSinglePushTargets(wpawns, empty);
   return nortOne(singlePushs) & empty & rank4;
}

U64 bSinglePushTargets(U64 bpawns, U64 empty) {
   return soutOne(bpawns) & empty;
}

U64 bDoublePushTargets(U64 bpawns, U64 empty) {
   const U64 rank5 = C64(0x000000FF00000000);
   U64 singlePushs = bSinglePushTargets(bpawns, empty);
   return soutOne(singlePushs) & empty & rank5;
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

    U64 occupied = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing | blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
    U64 empty = ~occupied;

    U64 whitePawnSinglePush = wSinglePushTargets(whitePawns, empty);
    U64 whitePawnDoublePush = wDblPushTargets(whitePawns, empty);
    U64 blackPawnSinglePush = bSinglePushTargets(blackPawns, empty);
    U64 blackPawnDoublePush = bDoublePushTargets(blackPawns, empty);

    printBitboard(blackPawnDoublePush);

    return 0;
}
