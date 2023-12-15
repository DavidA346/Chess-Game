#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP


#include <vector>
#include <string>


#include "chessBoard.hpp"


class chessBoard;
enum class Color;

enum class gameStatus {IN_PROGRESS, CHECKMATE, DRAW, STALEMATE, CHECK};


using namespace std;


class chessGame{
   private:
   std::unique_ptr<chessBoard> board;
   std::pair<int, int> whiteKingPosition;
   std::pair<int, int> blackKingPosition;
   vector<string> moves;
   bool lastMove;
   gameStatus gameStatusNow;
   vector<string> player1Captured;
   vector<string> player2Captured;
   






   


   public:
   chessGame();
   void startGame();
   void makeMove(int sourceX, int sourceY, int targetX, int targetY, bool white);
   void updateGameStatus(gameStatus status);
   gameStatus getGameStatus() const;
   void addMoves(int row, int col);
   void printMoveHistory();
   string getStringOfMove(int targetX, int targetY) const;
   bool moveSucess();
   void updateKingPosition(Color color, int x, int y);
   void updateCaptured(Color col, string piece);
   void printCapturedPieces(bool white);
   


};


#endif /* CHESSGAME_HPP */