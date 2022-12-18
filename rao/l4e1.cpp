#include <iostream>

enum CHESS_PIECES {
        Pawn,
        Rook,
        Knight,
        Bishop,
        Queen,
        King,
        Empty
    };

void displayChessPiece(CHESS_PIECES piece);
void displayChessboard(CHESS_PIECES chessboard[8][8]);


int main() {
    
    CHESS_PIECES chessboard[8][8] = {Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook, 
                                        Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                        Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                        Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                        Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                        Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                        Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                        Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook};
    
    displayChessboard(chessboard);
    
    return 0;
}

void displayChessPiece(CHESS_PIECES piece) {
    switch (piece) {
        case Pawn:
            std::cout << "P ";
            break;
        case Knight:
            std::cout << "N ";
            break;
        case Bishop:
            std::cout << "B ";
            break;
        case Rook:
            std::cout << "R ";
            break;
        case Queen:
            std::cout << "Q ";
            break;
        case King:
            std::cout << "K ";
            break;
        case Empty:
            std::cout << "X ";
            break;
        default:
            std::cout << " ";
            break;
    }
}

void displayChessboard(CHESS_PIECES chessboard[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            displayChessPiece(chessboard[i][j]);

            if (j == 7) {
                std::cout << std::endl;
            }
        }
    }
}