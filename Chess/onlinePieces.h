//
//  main.cpp
//  Chess
//
//  Created by Karan Mukhi on 20/03/2019.
//  Copyright © 2019 Karan Mukhi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>


#include <wchar.h>
#include <stdio.h>
#include <locale.h>
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;
enum ChessPiecesT
{
    King,
    Queen,
    Rock,
    Bishop,
    Knight,
    Pawn,
};

enum PlayerT
{
    White=0x2654,   /* white king */
    Black=0x265a,   /* black king */
};

/* Provides the character for the piece */
wchar_t PieceChar(enum PlayerT Player, enum ChessPiecesT Piece)
{
    return (wchar_t)(Player + Piece);
}

/* First row of the chessboard (black) */
enum ChessPiecesT TopRow[]={Rock, Knight, Bishop, Queen, King, Bishop, Knight, Rock};

void PrintTopRow(enum PlayerT Player)
{
    int i;
    for(i=0; i<8; i++)
        putwchar(PieceChar(Player, TopRow[Player==Black?i: (7-i)]));
    putwchar(L'\n');
}

/* Prints the eight pawns */
void PrintPawns(enum PlayerT Player)
{
    wchar_t pawnChar=PieceChar(Player, Pawn);
    int i;
    for(i=0; i<8; i++)
        putwchar(pawnChar);
    putwchar(L'\n');
}

int main()
{
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
#else
    setlocale(LC_CTYPE, "");
#endif
    PrintTopRow(Black);
    PrintPawns(White);
    fputws(L"\n\n\n\n", stdout);
    PrintPawns(White);
    PrintTopRow(White);
    return 0;
}
/*int main(int argc, const char * argv[]) {
 int i;
 
 for(i='A'; i<=200; i++)
 cout<<"CHAR: "<<(char)i<<" ASCII: "<<i<<endl;
 
 
 return 0;
 }*/
