#include <iostream>
#include "gtest/gtest.h"

#include "../piecesHeader/knight.hpp"
#include "../chessGameHeader/chessBoard.hpp"

//3 Constructor Tests
TEST(KnightTests, testConstructorWhite)
{
    Knight* knight1 = new Knight(Color::White);
    EXPECT_TRUE(knight1->getColor() == Color::White);
}

TEST(KnightTests, testConstructorBlack)
{
    Knight* knight1 = new Knight(Color::Black);
    EXPECT_EQ(knight1->getColor(), Color::Black);
}

TEST(KnightTests, testConstructorNone)
{
    Knight* knight1 = new Knight(Color::none);
    ASSERT_TRUE(knight1->getColor() == Color::none);
}

//canMove Tests
// TEST(KnightTests, testCanMoveRight)
// {
//     unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(7, 6).setPiece(move(knight1));

//     EXPECT_EQ(board->getSquare(7, 6).getPiece().canMoveTo(7, 6, 5, 7, *board), true);
// }

// TEST(KnightTests, testCanMoveLeft)
// {
//     unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(7, 6).setPiece(move(knight1));

//     ASSERT_TRUE(board->getSquare(7, 6).getPiece().canMoveTo(7, 6, 5, 5, *board) == true);
// }

// TEST(KnightTests, testCanMoveLeftBack)
// {
//     unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(5, 5).setPiece(move(knight1));

//     ASSERT_TRUE(board->getSquare(5, 5).getPiece().canMoveTo(5, 5, 7, 4, *board) == true);
// }

// TEST(KnightTests, testCanMoveRightBack)
// {
//     unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(5, 5).setPiece(move(knight1));

//     EXPECT_TRUE(board->getSquare(5, 5).getPiece().canMoveTo(5, 5, 7, 6, *board) == true);
// }

//Handeled by upper class 

// TEST(KnightTests, testCanMoveWithPieceInTheWay)
// {
//     unique_ptr<Piece> knightWhite = make_unique<Knight>(Color::White);
//     unique_ptr<Piece> knightWhite2 = make_unique<Knight>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(7, 6).setPiece(move(knightWhite));
//     board->getSquare(5, 7).setPiece(move(knightWhite2));

//     EXPECT_EQ(board->getSquare(7, 6).getPiece().canMoveTo(7, 6, 5, 7, *board), false);
// }

//getSymbol Tests
TEST(KnightTests, testGetSymbolWhite)
{
    Knight* knight1 = new Knight(Color::White);
    ASSERT_TRUE(knight1->getSymbol() == "N");
}

TEST(KnightTests, testGetSymbolBlack)
{
    Knight* knight1 = new Knight(Color::Black);
    EXPECT_EQ(knight1->getSymbol(), "n");
}

TEST(KnightTests, testGetSymbolWrongInput)
{
    Knight* knight1 = new Knight(Color::White);
    ASSERT_FALSE(knight1->getSymbol() == "n");
}