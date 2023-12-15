#include "../piecesHeader/queen.hpp"

Queen::~Queen(){
}

Queen::Queen(Color col){
    color = col;
}

bool Queen::canMoveTo(int sourceX, int sourceY, int targetX, int targetY, const chessBoard& board) const{
    // Check for horizontal or vertical movement
    if (sourceX == targetX || sourceY == targetY) {
        int stepX = (targetX - sourceX != 0) ? (targetX - sourceX) / abs(targetX - sourceX) : 0;
        int stepY = (targetY - sourceY != 0) ? (targetY - sourceY) / abs(targetY - sourceY) : 0;
        int x = sourceX + stepX;
        int y = sourceY + stepY;
        
        // Traverse the path from source to target and check if it's clear
        while (x != targetX || y != targetY) {
            if (!board.getSquare(x, y).isEmpty()) {
            return false; // Path is obstructed
        }
            
            x += stepX;
            y += stepY;
        }
    }

    // Check for diagonal movement
    else if (abs(targetX - sourceX) == abs(targetY - sourceY)) {
        int stepX = (targetX - sourceX) / abs(targetX - sourceX);
        int stepY = (targetY - sourceY) / abs(targetY - sourceY);
        int x = sourceX + stepX;
        int y = sourceY + stepY;
        
        // Traverse the path from source to target and check if it's clear
        while (x != targetX && y != targetY) {
            if (!board.getSquare(x, y).isEmpty()) {
                return false; // Path is obstructed
            }
            x += stepX;
            y += stepY;
        }
    }
    else {
        // The move is not horizontal, vertical, or diagonal and thus is not valid for the queen
        return false;
    }

        
    
    // The move is valid if none of the invalid conditions are met
    return true;
}



string Queen::getSymbol() const{
    return color == Color::White ? "Q" : "q";
}