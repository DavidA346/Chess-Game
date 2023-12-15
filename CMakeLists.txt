CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(chessGame)
add_subdirectory(googletest)


ADD_EXECUTABLE(playChess

    piecesSrc/bishop.cpp
    chessGameSrc/chessBoard.cpp
    piecesSrc/king.cpp
    piecesSrc/knight.cpp
    chessGameSrc/main.cpp
    piecesSrc/pawn.cpp
    piecesSrc/piece.cpp
    piecesSrc/queen.cpp
    piecesSrc/rook.cpp
    chessGameSrc/square.cpp
    chessGameSrc/chessGame.cpp 
    
)

ADD_EXECUTABLE(runPiecesTest
    
#     #Add test file from piecesFolder here to test
      testPieces/rookTest.cpp
      testPieces/bishopTest.cpp
      testPieces/kingTest.cpp
      testPieces/knightTest.cpp
      testPieces/pawnTest.cpp
      testPieces/queenTest.cpp

#     #Don't change this 
    piecesSrc/bishop.cpp
    chessGameSrc/chessBoard.cpp
    piecesSrc/king.cpp
    piecesSrc/knight.cpp
    piecesSrc/pawn.cpp
    piecesSrc/piece.cpp
    piecesSrc/queen.cpp
    piecesSrc/rook.cpp
    chessGameSrc/square.cpp
    chessGameSrc/chessGame.cpp 
    
) 

ADD_EXECUTABLE(runChessGameTest
    #Add test file from testChessGame here to test
    testChessGame/squareTest.cpp
    testChessGame/chessBoardTest.cpp
    testChessGame/chessGameTest.cpp

    #Don't change this 
    piecesSrc/bishop.cpp
    chessGameSrc/chessBoard.cpp
    piecesSrc/king.cpp
    piecesSrc/knight.cpp
    piecesSrc/pawn.cpp
    piecesSrc/piece.cpp
    piecesSrc/queen.cpp
    piecesSrc/rook.cpp
    chessGameSrc/square.cpp
    chessGameSrc/chessGame.cpp 

) 


target_link_libraries(runChessGameTest gmock gtest gtest_main)
target_link_libraries(runPiecesTest gmock gtest gtest_main)





