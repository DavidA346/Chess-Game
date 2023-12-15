#include "../piecesHeader/pawn.hpp"

Pawn::~Pawn(){
}

Pawn::Pawn(Color col){
    color = col;
}

bool Pawn::canMoveTo(int sourceX, int sourceY, int targetX, int targetY, const chessBoard& board) const{
    // Determine whether pawn is white or black in order to determine movement
    int direction = 1;

    //If white, direction is -1 otherwise its 1
    if (this->getColor() == Color::White){
        direction = -1;
    }

    //Checks if pawn can move one space forward
    if (targetX == sourceX + direction && targetY == sourceY && board.getSquare(targetX, targetY).isEmpty()) {
        return true;
    }

    //If first move then pawn can move two spaces forward
    int sourceRow = 1;

    if (this->getColor() == Color::White){
        sourceRow = 6;
    }

    if (sourceX == sourceRow && targetX == sourceX + 2 * direction && targetY == sourceY) {
        if (board.getSquare(targetX, targetY).isEmpty() && board.getSquare(sourceX + direction, sourceY).isEmpty()) {
            return true;
        }
    }
     if (targetX == sourceX + direction && (targetY == sourceY + 1 || targetY == sourceY - 1)) {
        if(!board.getSquare(targetX, targetX).isEmpty()){
            return true; 
        }
     }
        

    return false; //Pawn cannot move
}

string Pawn::getSymbol() const{
    return color == Color::White ? "P" : "p";
}