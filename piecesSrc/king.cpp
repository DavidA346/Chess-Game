#include "../piecesHeader/king.hpp"

King::~King(){
}

King::King(Color col){
    color = col;
}

bool King::canMoveTo(int sourceX, int sourceY, int targetX, int targetY, const chessBoard& board) const{
    // Calculate the differences in x and y coordinates
    int deltaX = abs(targetX - sourceX);
    int deltaY = abs(targetY - sourceY);

    // The king moves one square in any direction
    bool isOneSquareMove = (deltaX <= 1 && deltaY <= 1);

    // Check that the move is a one-square move and not to the same square it's already on
    if (isOneSquareMove){
        return true;
    }

    // If not a one-square move, it's invalid
    return false;
}

string King::getSymbol() const{
    return color == Color::White ? "K" : "k";
}

/* 
1) User enters a move 
2) The move is validated first 
3) The target square is checked for a piece, if there is no piece just move it there
   If target square has piece, then it'll invoke the capture method 
4) Capture method just stores the information that it was deleted and deletes piece from the current square. 
5) Logic to detect checkmate (king in check, no legal moves to escape) //isCheckMate

*/


/* 
2) A move class that has virutal function for finding valid moves.
It'll be composed up of chessboard class aswell. 
It'll pass in the chessboard, source square, target square as parameter.
and then each piece will also inherit from that move class implementing the boolvalidmove() function on their own.

*/

//need bool willGetChecked function

/* 

Valid moves function;
One function for move as of the empty board on the given square.
//Suppose I stored that in a array/vectors 
//if the move requested is not in the array/vectors return false.
//One function for move as the king is currently on check. 
//If on check wil it remove the check // calls willRemoveCheck() if false return invalid move. 
//Need to check if the move requested is in willGetCheckedMethod() if yes return invalid move. 
//Check if their path to destination square in unobstructed if yes return invalid move.
//return true. 
*/