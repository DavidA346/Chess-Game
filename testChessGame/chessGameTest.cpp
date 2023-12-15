#include <iostream>

#include "gtest/gtest.h"
#include "../chessGameHeader/square.hpp"
#include "../chessGameHeader/chessGame.hpp"

//makeMove & moveSuccess Tests
TEST(ChessGameTests, makeMoveCorrectly)
{
    chessGame game;
    game.startGame();

    // Test a valid move
    game.makeMove(1, 0, 3, 0, false);
    ASSERT_TRUE(game.moveSucess());
}

TEST(ChessGameTests, makeMoveIncorrectly)
{
    chessGame game;
    game.startGame();

    // Test a valid move
    game.makeMove(1, 0, 4, 0, false);
    ASSERT_FALSE(game.moveSucess());
}

TEST(ChessGameTests, makeTwoMoves)
{
    chessGame game;
    game.startGame();

    // Test a valid move
    game.makeMove(1, 3, 3, 3, false);
    ASSERT_TRUE(game.moveSucess());

    game.makeMove(1, 0, 3, 0, false);

    EXPECT_TRUE(game.moveSucess());
}

//updateGameStatus Tests
TEST(ChessGameTests, updateGameStatusCheckmate) {
    chessGame game;
    game.updateGameStatus(gameStatus::CHECKMATE);

    ASSERT_EQ(game.getGameStatus(), gameStatus::CHECKMATE);
}

TEST(ChessGameTests, updateGameStatusDraw) {
    chessGame game;
    game.updateGameStatus(gameStatus::DRAW);

    ASSERT_TRUE(game.getGameStatus() == gameStatus::DRAW);
}

TEST(ChessGameTests, updateGameStatusInProgress) {
    chessGame game;
    game.updateGameStatus(gameStatus::IN_PROGRESS);

    EXPECT_TRUE(game.getGameStatus() == gameStatus::IN_PROGRESS);
}

//getGameStatus Tests
TEST(ChessGameTests, getGameStatusCheckmate) {
    chessGame game;
    game.updateGameStatus(gameStatus::CHECKMATE);

    ASSERT_EQ(game.getGameStatus(), gameStatus::CHECKMATE);
}

TEST(ChessGameTests, getGameStatusDraw) {
    chessGame game;
    game.updateGameStatus(gameStatus::DRAW);

    ASSERT_TRUE(game.getGameStatus() == gameStatus::DRAW);
}

TEST(ChessGameTests, getGameStatusInProgress) {
    chessGame game;
    game.updateGameStatus(gameStatus::IN_PROGRESS);
    
    EXPECT_TRUE(game.getGameStatus() == gameStatus::IN_PROGRESS);
}

//getStringOf Tests
TEST(ChessGameTests, getStringOfMoveCorrectly) {
    chessGame game;

    ASSERT_TRUE(game.getStringOfMove(0, 0) == "a8");
}

TEST(ChessGameTests, getStringOfMoveIncorrectly) {
    chessGame game;

    ASSERT_FALSE(game.getStringOfMove(0, 0) == "d8");
}

TEST(ChessGameTests, getStringOfTwoMoves) {
    chessGame game;

    ASSERT_EQ(game.getStringOfMove(0, 0), "a8");

    EXPECT_EQ(game.getStringOfMove(7, 7), "h1");
}

//addMove & printMoveHistory Tests
TEST(ChessGameTests, moveHistory) {
    chessGame game;
    game.addMoves(1, 2);

    //Move printed correctly
    testing::internal::CaptureStdout();
    game.printMoveHistory();
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "c7 \n");
}

TEST(ChessGameTests, moveHistoryIncorrectly) {
    chessGame game;
    game.addMoves(1, 2);

    //Move printed correctly
    testing::internal::CaptureStdout();
    game.printMoveHistory();
    string output = testing::internal::GetCapturedStdout();

    ASSERT_FALSE(output == "c8 \n");
}

TEST(ChessGameTests, moveHistoryTwoTimes) {
    chessGame game;
    game.addMoves(1, 2);
    game.addMoves(3, 4);

    //Move printed correctly
    testing::internal::CaptureStdout();
    game.printMoveHistory();
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "c7 e5\n");
}

//printCapturedPieces & updateCaptured Tests
TEST(ChessGameTests, printCapturedPieces) {
    chessGame* game;
    game->updateCaptured(Color::White, "Rook");
    game->updateCaptured(Color::White, "Pawn");
    testing::internal::CaptureStdout(); 
    game->printCapturedPieces(true);
    string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, "Rook Pawn \n");
}