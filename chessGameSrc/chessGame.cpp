    #include "../chessGameHeader/chessGame.hpp"

    #include <iostream>

    #include <cctype>

    #include <stdio.h>


    chessGame::chessGame(): board(std::make_unique < chessBoard > ()) {

      whiteKingPosition.first = 7;
      whiteKingPosition.second = 4;

      blackKingPosition.first = 0;
      blackKingPosition.second = 4;

    }

    void chessGame::startGame() {
      board.get() -> setupBoard();
      board.get()->displayBoard();
    }


    void chessGame::makeMove(int sourceX, int sourceY, int targetX, int targetY, bool white) {

      //Check coordinates in bound
      if (sourceX < 0 || sourceX > 7 || sourceY < 0 || sourceY > 7 ||
        targetX < 0 || targetX > 7 || targetY < 0 || targetY > 7) {
        lastMove =false; 
        return;
    }
      
      //The two pieces that we are dealing with
      Piece * sourcePiece;
      Piece * targetPiece;

      
      Square* sourceSquare = &board.get()->getSquare(sourceX, sourceY);

      //Checking if the source is empty
      if(sourceSquare->isEmpty()){
        cout << "There is no piece on the source square! ";
        lastMove =false; 
        return;
      }

      //Checking that the player is moving it's own piece
      else{
          sourcePiece = &board.get()->getSquare(sourceX, sourceY).getPiece();
          // char symbolSP = sourcePiece -> getSymbol()[0];

          if(white){
            if (sourcePiece->getColor() != Color::White) {
            cout << "Please move your own piece! ";
            lastMove = false;
            return;
            }
          }
          else {
             if (sourcePiece->getColor() != Color::Black) {
              cout << "Please move your own piece! ";
              lastMove = false;
              return;
            }
          }
          }

      //Checking if the target square is of same color

     bool capturePiece = false;  
      Square* targetSquare = &board.get()->getSquare(targetX, targetY);
        if(!targetSquare->isEmpty()){
            targetPiece = &board.get()->getSquare(targetX, targetY).getPiece();
            if(white){
              if(targetPiece->getColor() != Color::Black){
                cout << "You cannot attack your own piece! ";
                lastMove = false;
                return;
              }
            }
            else {
              if(targetPiece->getColor() != Color::White){
                cout << "You cannot attack your own piece, ";
                lastMove = false; 
                return;
              }
            }
            capturePiece = true;
      }

       

      bool validMove = sourcePiece->canMoveTo(sourceX,sourceY, targetX, targetY, *board);

      if(!validMove){
        cout << "Your piece " << sourcePiece->getSymbol() << " cannot move there. ";
        lastMove = false;
        return;
      }

      //Check if king is currently on check 
      //If it is does it remove the check

      if(white){
        if(board.get()->isKingChecked(sourceX,sourceY, targetX, targetY, whiteKingPosition.first, whiteKingPosition.second)){
          if(!board.get()->willRemoveCheck(sourceX,sourceY, targetX, targetY, whiteKingPosition.first, whiteKingPosition.second)){
            cout << "Your piece " << sourcePiece->getSymbol() << " cannot move there because your king is in Check. ";
            lastMove = false; 
            return;
          }
        }
      }
      else {
        if(board.get()->isKingChecked(sourceX,sourceY, targetX, targetY, blackKingPosition.first, blackKingPosition.second)){
          if(!board.get()->willRemoveCheck(sourceX,sourceY, targetX, targetY, blackKingPosition.first, blackKingPosition.second)){
            cout << "Your piece " << sourcePiece->getSymbol() << " cannot move there because your king is in Check. ";
            lastMove = false; 
              return;
          }
        }

      }


        
      //Check if the player is trying to move king
      if(white){
        if(whiteKingPosition.first == sourceX && whiteKingPosition.second == sourceY){
          //King cannot move to a place where other players attack directly afterwards
          if(board.get()->willKingGetChecked(sourceX,sourceY, targetX, targetY, whiteKingPosition.first, whiteKingPosition.second)){
            cout << "Your piece " << sourcePiece->getSymbol() << " cannot move there because your king will get in Check. ";
            lastMove = false; 
            return; 
          }
          //Save the move
          addMoves(targetX, targetY);
          lastMove = true; 

          //If capture then invoke capture logic 
          if(capturePiece){
              player1Captured.push_back(getStringOfMove(targetX, targetY));
              board.get()->capture(sourceX, sourceY,  targetX,  targetY);

              // printCapturedPieces(white);
              updateKingPosition(Color::White, targetX, targetY);
              this->board.get()->displayBoardFromBlackSide();
              return;
          }
          //Move the piece and return 
            board.get()->movePiece(sourceX, sourceY,  targetX,  targetY);
            // printCapturedPieces(white);
            printMoveHistory();
            this->board.get()->displayBoardFromBlackSide();
            updateKingPosition(Color::White, targetX, targetY);
          return; 
          }
        }

        else{
            if(blackKingPosition.first == sourceX && blackKingPosition.second == sourceY){
          //King cannot move to a place where other players attack directly afterwards
          if(board.get()->willKingGetChecked(sourceX,sourceY, targetX, targetY, blackKingPosition.first, blackKingPosition.second)){
            cout << "Your piece " << sourcePiece->getSymbol() << " cannot move there because your king will get in Check. ";
            lastMove = false; 
            return; 
          }
          //Save the move
          addMoves(targetX, targetY);
          lastMove = true; 

          //If capture then invoke capture logic 
          if(capturePiece){
              player2Captured.push_back(getStringOfMove(targetX, targetY));
              board.get()->capture(sourceX, sourceY,  targetX,  targetY);

              // printCapturedPieces(white);
              printMoveHistory();
              updateKingPosition(Color::Black, targetX, targetY);
              this->board.get()->displayBoard();
              return;
          }
          //Move the piece and return 
            board.get()->movePiece(sourceX, sourceY,  targetX,  targetY);
            // printCapturedPieces(white);
            printMoveHistory();
            updateKingPosition(Color::Black, targetX, targetY);
            this->board.get()->displayBoard();
          return; 
          }
        }
      

      if (sourcePiece -> getSymbol() == "P" || sourcePiece -> getSymbol() == "p") {
        if (board.get() -> EnPassantPossible(sourceX, sourceY, targetX, targetY)) {
          board.get() -> perfomEnPassant(sourceX, sourceY, targetX, targetY);
          addMoves(targetX, targetY);
          if(white){
            player1Captured.push_back(getStringOfMove(targetX, targetY));
          }
          else{
            player2Captured.push_back(getStringOfMove(targetX, targetY));
          }
          lastMove = true;
          addMoves(targetX, targetY);
          printMoveHistory();

          if(white){
            this->board.get()->displayBoardFromBlackSide();
            
            }
          else {
            this->board.get()->displayBoard();
          }
          return;
        }

        if (board.get() -> pawnPromotionPossible(sourceX, sourceY, targetX, targetY)) {
          board.get() -> performPawnPromotion(sourceX, sourceY, targetX, targetY);
          lastMove = true;
          addMoves(targetX, targetY);
          printMoveHistory();

          if(white){
            this->board.get()->displayBoardFromBlackSide();
            
            }
          else {
            this->board.get()->displayBoard();
          }
          return;
        }
      }

      if(capturePiece){
        // board.get()->capture(sourceX, sourceY, targetX, targetY;
        if(white){
          player1Captured.push_back(getStringOfMove(targetX, targetY));
        }
        else{
          player2Captured.push_back(getStringOfMove(targetX, targetY));
        }
        lastMove = true;
        addMoves(targetX, targetY);
        board.get()->capture(sourceX, sourceY,  targetX,  targetY);
        printMoveHistory();
        if(white){
          this->board.get()->displayBoardFromBlackSide();
          
        }
        else {
          this->board.get()->displayBoard();
        }
      return;
      }



      lastMove = true;
      addMoves(targetX, targetY);
      board.get()->movePiece(sourceX, sourceY,  targetX,  targetY);
      printMoveHistory();
      // printCapturedPieces(white);
        if(white){
          this->board.get()->displayBoardFromBlackSide();
          
        }
        else {
          this->board.get()->displayBoard();
        }

    }

    void chessGame::updateGameStatus(gameStatus status) {
        gameStatusNow = status;
    }

    gameStatus chessGame::getGameStatus() const {
      return gameStatusNow;
    }

    string chessGame::getStringOfMove(int targetX, int targetY) const {
      // Convert the y-coordinate to a file character ('a' through 'h')
      char charX = 'a' + targetY;
      // Convert the x-coordinate to a rank number (8 through 1)
      // Since targetX ranges from 0 (representing rank 8) to 7 (representing rank 1)
      int positionY = 8 - targetX;

      // Construct the string representing the move
      string moveString = charX + to_string(positionY);
      return moveString;
    }

    //     void addMoves(int col, int row);
    void chessGame::addMoves(int row, int col) {
      string moveName = getStringOfMove(row, col);
      moves.push_back(moveName);
    }

    //     void printMoveHistory();
    void chessGame::printMoveHistory() {
      for (int i = 0; i < moves.size(); ++i) {
        cout << moves[i];
        // Print a space if it's the first move in a pair, or a newline if it's the second
        if (i % 2 == 0) {
          std::cout << " ";
        } else {
          cout << endl;
        }
      }

      // If there's an odd number of moves, add a newline at the end
      if (moves.size() % 2 != 0) {
        cout << endl;
      }

    }

    bool chessGame::moveSucess() {
      return this -> lastMove;
    }

    void chessGame::updateKingPosition(Color col, int x, int y) {
       if(Color::Black == col){
        blackKingPosition.first = x;
        blackKingPosition.second = y;
       }
       else if(Color::White == col) {
        whiteKingPosition.first = x;
        whiteKingPosition.second = x;
       }
    }

    void chessGame::updateCaptured(Color col ,string piece){
      //Passed in what was in the target piece;
      if(col == Color::White){
        player2Captured.push_back(piece);
      }
      else if(col == Color::Black) {
        player1Captured.push_back(piece);
      }
    }

    void chessGame::printCapturedPieces(bool white){
      vector<string> toPrint;
      if(white){
        toPrint = player1Captured;
      }
      else {
        toPrint =player2Captured;
      }

      for (int i = 0; i < toPrint.size(); ++i) {
        cout << toPrint[i];
        cout << " "; 
    }
    cout << endl;
    }
