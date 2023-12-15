#include "../piecesHeader/bishop.hpp"

Bishop::~Bishop(){
}

Bishop::Bishop(Color col){
    color = col;  
}

bool Bishop::canMoveTo(int sourceX, int sourceY, int targetX, int targetY, const chessBoard& board) const{

// Check if the move is a diagonal move
// The reason this works is because to move diagonally if you shift two steps rights, you must shift two steps up to
// be in diagonal
    
    if (abs(targetX - sourceX) != abs(targetY - sourceY)) {
        return false; // not moving diagonally
    }

    // Determine the direction of movement
    int deltaX = (targetX > sourceX) ? 1 : -1;
    int deltaY = (targetY > sourceY) ? 1 : -1;

    // Check each square along the diagonal path
    int x = sourceX + deltaX;
    int y = sourceY + deltaY;
    while (x != targetX && y != targetY) {
        if (!board.getSquare(x, y).isEmpty()) {
            return false; // Path is obstructed
        }
        x += deltaX;
        y += deltaY;
    }

    return true; // Path is clear, move is valid
}

string Bishop::getSymbol() const{
    return color == Color::White ? "B" : "b";
}