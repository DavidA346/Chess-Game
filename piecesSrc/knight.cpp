#include "../piecesHeader/knight.hpp"

Knight::~Knight(){
}

Knight::Knight(Color col){
    color = col;
}

bool Knight::canMoveTo(int sourceX, int sourceY, int targetX, int targetY, const chessBoard& board) const{
    // Calculate the differences in x and y coordinates
    int deltaX = abs(targetX - sourceX);
    int deltaY = abs(targetY - sourceY);

    //Checks if an L-shape move
    if (!((deltaX == 1 && deltaY == 2) || (deltaX == 2 && deltaY == 1))) {
        return false; // Not valid movement
    }

   return true; // Path is clear, move is valid
}

string Knight::getSymbol() const{
    return color == Color::White ? "N" : "n";
}