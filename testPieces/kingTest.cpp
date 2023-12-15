#include <iostream>
#include "gtest/gtest.h"

#include "../piecesHeader/king.hpp"
#include "../piecesHeader/bishop.hpp"
#include "../chessGameHeader/chessBoard.hpp"

//3 Constructor Tests
TEST(KingTests, testConstructorWhite)
{
    King* king1 = new King(Color::White);
    EXPECT_TRUE(king1->getColor() == Color::White);
}

TEST(KingTests, testConstructorBlack)
{
    King* king1 = new King(Color::Black);
    EXPECT_EQ(king1->getColor(), Color::Black);
}

TEST(KingTests, testConstructorNone)
{
    King* king1 = new King(Color::none);
    ASSERT_TRUE(king1->getColor() == Color::none);
}

//canMove Tests
// TEST(KingTests, testCanMoveForward)
// {
//     unique_ptr<Piece> king1 = make_unique<King>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(7, 4).setPiece(move(king1));

//     EXPECT_EQ(board->getSquare(7, 4).getPiece().canMoveTo(7, 4, 6, 4, *board), true);
// }

// TEST(KingTests, testCanMoveRight)
// {
//     unique_ptr<Piece> king1 = make_unique<King>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(7, 4).setPiece(move(king1));

//     ASSERT_TRUE(board->getSquare(7, 4).getPiece().canMoveTo(7, 4, 7, 5, *board) == true);
// }

// TEST(KingTests, testCanMoveLeft)
// {
//     unique_ptr<Piece> king1 = make_unique<King>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(7, 4).setPiece(move(king1));

//     EXPECT_EQ(board->getSquare(7, 4).getPiece().canMoveTo(7, 4, 7, 3, *board), true);
// }

// TEST(KingTests, testCanMoveBackward)
// {
//     unique_ptr<Piece> king1 = make_unique<King>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(6, 4).setPiece(move(king1));

//     ASSERT_TRUE(board->getSquare(6, 4).getPiece().canMoveTo(6, 4, 7, 4, *board) == true);
// }

TEST(KingTests, testCannotMoveBackwardMultipleSpaces)
{
    unique_ptr<Piece> king1 = make_unique<King>(Color::White);
    chessBoard* board = new chessBoard();
    board->getSquare(5, 4).setPiece(move(king1));

    ASSERT_FALSE(board->getSquare(5, 4).getPiece().canMoveTo(5, 4, 7, 4, *board) == true);
}
//Handeled by chessGame class 
// TEST(KingTests, testCanMoveWithPieceInTheWay)
// {
//     unique_ptr<Piece> kingWhite = make_unique<King>(Color::White);
//     unique_ptr<Piece> bishopWhite = make_unique<Bishop>(Color::White);
//     chessBoard* board = new chessBoard();
//     board->getSquare(7, 4).setPiece(move(kingWhite));
//     board->getSquare(7, 5).setPiece(move(bishopWhite));

//     EXPECT_EQ(board->getSquare(7, 4).getPiece().canMoveTo(7, 4, 7, 5, *board), false);
// }

//getSymbol Tests
TEST(KingTests, testGetSymbolWhite)
{
    King* king1 = new King(Color::White);
    ASSERT_TRUE(king1->getSymbol() == "K");
}

TEST(KingTests, testGetSymbolBlack)
{
    King* king1 = new King(Color::Black);
    EXPECT_EQ(king1->getSymbol(), "k");
}

TEST(KingTests, testGetSymbolWrongInput)
{
    King* king1 = new King(Color::White);
    ASSERT_FALSE(king1->getSymbol() == "k");
}