#include "../chessGameHeader/square.hpp"
#include <iostream>
Square::Square() : row(0), col(0), pieceType(nullptr) {}

Square::Square(int r, int c) : row(r), col(c), pieceType(nullptr) {}

int Square::getRow(){
   return row;
}

int Square::getCol(){
   return col;
}

Piece& Square::getPiece(){
   if (!pieceType) {
        throw std::runtime_error("Attempted to access a null piece");
    }
    return *(this->pieceType);
}

void Square::setPiece(unique_ptr<Piece> p){
   if (!p) {
      cout << "Received null piece in setPiece" << endl;
   }
      this->clearSquare();
      pieceType = std::move(p);
   }

bool Square::isEmpty() {
    return !pieceType;
}


void Square::clearSquare(){
   this->pieceType.reset();
}

unique_ptr<Piece> Square::releasePiece() {
    return std::move(pieceType);
}