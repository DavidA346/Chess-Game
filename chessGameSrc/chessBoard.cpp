#include "../chessGameHeader/chessBoard.hpp"
#include "../piecesHeader/pawn.hpp"
#include "../piecesHeader/bishop.hpp"
#include "../piecesHeader/king.hpp"
#include "../piecesHeader/queen.hpp"
#include "../piecesHeader/knight.hpp"
#include "../piecesHeader/rook.hpp"

#include <iostream>
using namespace std;

chessBoard::chessBoard() {
   for (int i = 0; i < 8; ++i){
       for (int j = 0; j < 8; ++j){
           board[i][j] = make_unique<Square>();
       }
   }
}

// chessBoard::~chessBoard(){


// }

Square& chessBoard::getSquare(int row, int col) const {
     return *(board[row][col]);
}

void chessBoard::setupBoard(){
    //setup black side
    
    board[0][0]->setPiece(make_unique<Rook>(Color::Black));
    board[0][1]->setPiece(make_unique<Knight>(Color::Black));
    board[0][2]->setPiece(make_unique<Bishop>(Color::Black));
    board[0][3]->setPiece(make_unique<Queen>(Color::Black));
    board[0][4]->setPiece(make_unique<King>(Color::Black));
    board[0][5]->setPiece(make_unique<Bishop>(Color::Black));
    board[0][6]->setPiece(make_unique<Knight>(Color::Black));
    board[0][7]->setPiece(make_unique<Rook>(Color::Black));

    for (int i = 0; i < 8; ++i){
        board[1][i]->setPiece(make_unique<Pawn>(Color::Black));
    }

    //setup white side
    board[7][0]->setPiece(make_unique<Rook>(Color::White));
    board[7][1]->setPiece(make_unique<Knight>(Color::White));
    board[7][2]->setPiece(make_unique<Bishop>(Color::White));
    board[7][3]->setPiece(make_unique<Queen>(Color::White));
    board[7][4]->setPiece(make_unique<King>(Color::White));
    board[7][5]->setPiece(make_unique<Bishop>(Color::White));
    board[7][6]->setPiece(make_unique<Knight>(Color::White));
    board[7][7]->setPiece(make_unique<Rook>(Color::White));
    for (int j = 0; j < 8; ++j){
        board[6][j]->setPiece(make_unique<Pawn>(Color::White));
    }
}


void chessBoard::displayBoard(){
    // setupBoard();
    cout << endl;
    cout << "   a b c d e f g h" << endl;
    cout << endl;
    Square* currSquare;
    Piece* currPiece;
    for (int i = 0; i < 8; ++i){
        cout << 8 - i << "  ";
       for (int j = 0; j < 8; ++j){
           currSquare = &this->getSquare(i, j);
           Piece* currPiece;
            if(currSquare->isEmpty() == true){
                currPiece = nullptr;
            }
            else {
                currPiece = &currSquare->getPiece();
            }

           if (currPiece == nullptr){
                cout << ". ";
               
           }
           else{
                if (currPiece->getSymbol() == "K") {
                cout << "\u2654 "; // WHITE CHESS KING
            } else if (currPiece->getSymbol() == "Q") {
                cout << "\u2655 "; // WHITE CHESS QUEEN
            } else if (currPiece->getSymbol() == "R") {
                cout << "\u2656 "; // WHITE CHESS ROOK
            } else if (currPiece->getSymbol() == "B") {
                cout << "\u2657 "; // WHITE CHESS BISHOP
            } else if (currPiece->getSymbol() == "N") {
                cout << "\u2658 "; // WHITE CHESS KNIGHT
            } else if (currPiece->getSymbol() == "P") {
                cout << "\u2659 "; // WHITE CHESS PAWN
            } else if (currPiece->getSymbol() == "k") {
                cout << "\u265A "; // BLACK CHESS KING
            } else if (currPiece->getSymbol() == "q") {
                cout << "\u265B "; // BLACK CHESS QUEEN
            } else if (currPiece->getSymbol() == "r") {
                cout << "\u265C "; // BLACK CHESS ROOK
            } else if (currPiece->getSymbol() == "b") {
                cout << "\u265D "; // BLACK CHESS BISHOP
            } else if (currPiece->getSymbol() == "n") {
                cout << "\u265E "; // BLACK CHESS KNIGHT
            } else if (currPiece->getSymbol() == "p") {
                cout << "\u265F "; // BLACK CHESS PAWN
            }
           }
       }
       cout << " " << 8 - i;
       cout << endl;
   }
   cout << endl;
   cout << "   a b c d e f g h" << endl;
   cout << endl;
//    if(currSquare != nullptr){
//         delete currSquare;
//    }
//    if(currPiece != nullptr){
//         delete currPiece;
//    }
}

void chessBoard::displayBoardFromBlackSide() {
    // setupBoard();
    cout << endl;
    cout << "   h g f e d c b a" << endl;  // Flipped column labels
    cout << endl;
    Square* currSquare;
    Piece* currPiece;
    for (int i = 7; i >= 0; --i) {  // Start from 7 (row 8) and go down to 0 (row 1)
        cout << 8 - i << "  ";  // Print the reversed row number (8 to 1)
        for (int j = 7; j >= 0; --j) {  // Start from 7 (column h) and go to 0 (column a)
            currSquare = &this->getSquare(i, j);
            if (currSquare->isEmpty()) {
                cout << ". ";
            } else {
                currPiece = &currSquare->getPiece();
                if (currPiece->getSymbol() == "K") {
                cout << "\u2654 "; // WHITE CHESS KING
            } else if (currPiece->getSymbol() == "Q") {
                cout << "\u2655 "; // WHITE CHESS QUEEN
            } else if (currPiece->getSymbol() == "R") {
                cout << "\u2656 "; // WHITE CHESS ROOK
            } else if (currPiece->getSymbol() == "B") {
                cout << "\u2657 "; // WHITE CHESS BISHOP
            } else if (currPiece->getSymbol() == "N") {
                cout << "\u2658 "; // WHITE CHESS KNIGHT
            } else if (currPiece->getSymbol() == "P") {
                cout << "\u2659 "; // WHITE CHESS PAWN
            } else if (currPiece->getSymbol() == "k") {
                cout << "\u265A "; // BLACK CHESS KING
            } else if (currPiece->getSymbol() == "q") {
                cout << "\u265B "; // BLACK CHESS QUEEN
            } else if (currPiece->getSymbol() == "r") {
                cout << "\u265C "; // BLACK CHESS ROOK
            } else if (currPiece->getSymbol() == "b") {
                cout << "\u265D "; // BLACK CHESS BISHOP
            } else if (currPiece->getSymbol() == "n") {
                cout << "\u265E "; // BLACK CHESS KNIGHT
            } else if (currPiece->getSymbol() == "p") {
                cout << "\u265F "; // BLACK CHESS PAWN
            }
            }
        }
        cout << " " << 8 - i << endl;  // Print the reversed row number again (8 to 1)
    }
    cout << endl;
    cout << "   h g f e d c b a" << endl;  // Flipped column labels
    cout << endl;
}

void chessBoard::movePiece(int sourceX, int sourceY, int targetX, int targetY){
    unique_ptr<Piece> toMovePiece = this->getSquare(sourceX, sourceY).releasePiece();
    this->getSquare(targetX, targetY).setPiece(move(toMovePiece));
  
}

void chessBoard::capture(int sourceX, int sourceY, int targetX, int targetY){
    unique_ptr<Piece> toMovePiece = this->getSquare(sourceX, sourceY).releasePiece();
    this->getSquare(targetX, targetY).setPiece(move(toMovePiece));
}


bool chessBoard::EnPassantPossible(int sourceX, int sourceY, int targetX, int targetY){
    //To implement
    return false;
}

void chessBoard::perfomEnPassant(int sourceX, int sourceY, int targetX, int targetY) {
    //To implement
}

bool chessBoard::pawnPromotionPossible(int sourceX, int sourceY, int targetX, int targetY){
    //To implement
    return false;
}

void chessBoard::performPawnPromotion(int sourceX, int sourceY, int targetX, int targetY){
    //To implement
}

bool chessBoard::willRemoveCheck(int sourceX, int sourceY, int targetX, int targetY, int kingX, int kingY) const{
    //To implement
    return true;
}
bool chessBoard::willKingGetChecked(int sourceX, int sourceY, int targetX, int targetY, int kingX, int kingY) const{
    //To implement
    return false;
}
bool chessBoard::isKingChecked(int sourceX, int sourceY, int targetX, int targetY, int kingX, int kingY) const {
    //To implement
    return false;
}

