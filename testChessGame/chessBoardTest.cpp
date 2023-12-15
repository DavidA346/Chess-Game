#include <iostream>

#include "gtest/gtest.h"
#include "../chessGameHeader/square.hpp"
#include "../chessGameHeader/chessBoard.hpp"
#include "../piecesHeader/knight.hpp"

//Test Default Constructor
TEST(ChessBoardTests, testDefaultConstructorEmpty)
{
    chessBoard* board1 = new chessBoard();
    EXPECT_TRUE(board1->getSquare(3, 4).isEmpty() == true);
}

TEST(ChessBoardTests, testDefaultConstructorNotEmpty)
{
    chessBoard* board1 = new chessBoard();
    Square* square1 = &board1->getSquare(0, 0);
    unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
    square1->setPiece(move(knight1));

    EXPECT_EQ(board1->getSquare(0, 0).isEmpty(), false);
}

TEST(ChessBoardTests, testDefaultConstructorEmptyAfterClear)
{
    chessBoard* board1 = new chessBoard();
    Square* square1 = &board1->getSquare(0, 0);
    unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
    square1->setPiece(move(knight1));

    EXPECT_EQ(board1->getSquare(0, 0).isEmpty(), false);

    square1->clearSquare();

    ASSERT_TRUE(board1->getSquare(0, 0).isEmpty() == true);
}

//getSquare Tests
TEST(ChessBoardTests, testGetSquareEmpty)
{
    chessBoard* board1 = new chessBoard();
    EXPECT_FALSE(board1->getSquare(3, 4).isEmpty() == false);
}

TEST(ChessBoardTests, testGetSquareNotEmpty)
{
    chessBoard* board1 = new chessBoard();
    Square* square1 = &board1->getSquare(0, 0);
    unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
    square1->setPiece(move(knight1));

    EXPECT_EQ(board1->getSquare(0, 0).getPiece().getSymbol(), "N");
}

TEST(ChessBoardTests, testGetSquareEmptyAfterClear)
{
    chessBoard* board1 = new chessBoard();
    Square* square1 = &board1->getSquare(0, 0);
    unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
    square1->setPiece(move(knight1));

    EXPECT_EQ(board1->getSquare(0, 0).getPiece().getSymbol(), "N");

    square1->clearSquare();

    ASSERT_TRUE(board1->getSquare(0, 0).isEmpty() == true);
}

//setupBoard Tests
TEST(ChessBoardTests, testSetupBoardNotEmpty)
{
    chessBoard* board1 = new chessBoard();
    board1->setupBoard();
    
    EXPECT_EQ(board1->getSquare(0, 0).getPiece().getSymbol(), "r");
}

TEST(ChessBoardTests, testSetupBoardEmpty)
{
    chessBoard* board1 = new chessBoard();
    board1->setupBoard();
    
    EXPECT_TRUE(board1->getSquare(2, 0).isEmpty() == true);
}

TEST(ChessBoardTests, testSetupBoardWrongPiece)
{
    chessBoard* board1 = new chessBoard();
    board1->setupBoard();
    
    EXPECT_FALSE(board1->getSquare(1, 0).getPiece().getSymbol() == "r");
}

//displayBoard Tests
TEST(ChessBoardTests, testDisplayBoardCorrectly)
{
    chessBoard board1;
    board1.setupBoard();

    //Capture the output
    testing::internal::CaptureStdout();
    board1.displayBoard();

    //Save the output
    string output = testing::internal::GetCapturedStdout();

    //Save expected output
    string expectedOutput =
        "\n"
        "   a b c d e f g h\n"
        "\n"
        "8  ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜  8\n"
        "7  ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟  7\n"
        "6  . . . . . . . .  6\n"
        "5  . . . . . . . .  5\n"
        "4  . . . . . . . .  4\n"
        "3  . . . . . . . .  3\n"
        "2  ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙  2\n"
        "1  ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖  1\n"
        "\n"
        "   a b c d e f g h\n"
        "\n";


    EXPECT_EQ(output, expectedOutput);
}

TEST(ChessBoardTests, testDisplayBoardIncorrectly)
{
    chessBoard board1;
    board1.setupBoard();

    //Capture the output
    testing::internal::CaptureStdout();
    board1.displayBoard();

    //Save the output
    string output = testing::internal::GetCapturedStdout();

    //Save expected output
    string expectedOutput =
        "\n"
        "   a b c d e f g h\n"
        "\n"
        "8  r n b q k b n r  8\n"
        "7  p p p p p p p p  7\n"
        "6  x x x x x x x x  6\n"
        "5  x x x L x x x x  5\n"
        "4  x x x x x x x x  4\n"
        "3  x x x x x x x x  3\n"
        "2  P P P P P P P P  2\n"
        "1  R N B Q K B N R  1\n"
        "\n"
        "   a b c d e f g h\n"
        "\n";

    EXPECT_FALSE(output == expectedOutput);
}

TEST(ChessBoardTests, testDisplayBoardWithMultipleErrors)
{
    chessBoard board1;
    board1.setupBoard();

    //Capture the output
    testing::internal::CaptureStdout();
    board1.displayBoard();

    //Save the output
    string output = testing::internal::GetCapturedStdout();

    //Save expected output
    string expectedOutput =
        "\n"
        "   a b c d e f g h\n"
        "\n"
        "8  r n b q k b n r  8\n"
        "7  p p p p p p p p  7\n"
        "6  x x x x x x x x  6\n"
        "5  x x x L x x L x  5\n"
        "4  x L x x x x x x  4\n"
        "3  x x x x x x x x  3\n"
        "2  P P P P P P P P  2\n"
        "1  R N B Q Y B N R  1\n"
        "\n"
        "   a b c d e f g h\n"
        "\n";

    ASSERT_FALSE(output == expectedOutput);
}

//displayBoardFromBlackSide Tests
TEST(ChessBoardTests, testDisplayBoardFromBlackSideCorrectly)
{
    chessBoard board1;
    board1.setupBoard();

    //Capture the output
    testing::internal::CaptureStdout();
    board1.displayBoardFromBlackSide();

    //Save the output
    string output = testing::internal::GetCapturedStdout();

    //Save expected output
    std::string expectedOutput =
       "\n"
        "   h g f e d c b a\n"
        "\n"
        "1  ♖ ♘ ♗ ♔ ♕ ♗ ♘ ♖  1\n"
        "2  ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙  2\n"
        "3  . . . . . . . .  3\n"
        "4  . . . . . . . .  4\n"
        "5  . . . . . . . .  5\n"
        "6  . . . . . . . .  6\n"
        "7  ♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟  7\n"
        "8  ♜ ♞ ♝ ♚ ♛ ♝ ♞ ♜  8\n"
        "\n"
        "   h g f e d c b a\n"
        "\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST(ChessBoardTests, testDisplayBoardFromBlackSideIncorrectly)
{
    chessBoard board1;
    board1.setupBoard();

    //Capture the output
    testing::internal::CaptureStdout();
    board1.displayBoardFromBlackSide();

    //Save the output
    string output = testing::internal::GetCapturedStdout();

    //Save expected output
    std::string expectedOutput =
        "\n"
        "   h g f e d c b a\n"
        "\n"
        "8  R N B K Q B N R  8\n"
        "7  P P P P P P P P  7\n"
        "6  x x x x x x x x  6\n"
        "5  x x x L x x x x  5\n"
        "4  x x x x x x x x  4\n"
        "3  x x x x x x x x  3\n"
        "2  p p p p p p p p  2\n"
        "1  r n b k q b n r  1\n"
        "\n"
        "   h g f e d c b a\n"
        "\n";

    EXPECT_FALSE(output == expectedOutput);
}

TEST(ChessBoardTests, testDisplayBoardFromBlackSideWithMultipleErrors)
{
    chessBoard board1;
    board1.setupBoard();

    //Capture the output
    testing::internal::CaptureStdout();
    board1.displayBoardFromBlackSide();

    //Save the output
    string output = testing::internal::GetCapturedStdout();

    //Save expected output
    std::string expectedOutput =
        "\n"
        "   h g f e d c b a\n"
        "\n"
        "8  R N B K Q B N R  8\n"
        "7  P P P P P P P P  7\n"
        "6  x x x L x x x x  6\n"
        "5  x x x x x x m x  5\n"
        "4  x x x x x x x x  4\n"
        "3  x p x x x x x x  3\n"
        "2  p p p p p p p p  2\n"
        "1  r n b k k b n r  1\n"
        "\n"
        "   h g f e d c b a\n"
        "\n";

    ASSERT_FALSE(output == expectedOutput);
}

//movePieces Tests
TEST(ChessBoardTests, testMovePiecesCorrectly)
{
    chessBoard* board1 = new chessBoard();
    Square* square1 = &board1->getSquare(0, 0);
    unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
    square1->setPiece(move(knight1));

    board1->movePiece(0, 0, 2, 1);

    EXPECT_EQ(board1->getSquare(2, 1).isEmpty(), false);
}

//This condition should be tested in chessGame class because chessGame validates move before the coordinate is passed
//Inother words this never recives wrong coordinate. 
// TEST(ChessBoardTests, testMovePiecesIncorrectly)
// {
//     chessBoard* board1 = new chessBoard();
//     Square* square1 = &board1->getSquare(0, 0);
//     unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
//     square1->setPiece(move(knight1));
//     board1->movePiece(0, 0, 3, 1);

//     EXPECT_TRUE(board1->getSquare(3, 1).isEmpty() == true);
// }

TEST(ChessBoardTests, testMovePiecesMutlipleTimes)
{
    chessBoard* board1 = new chessBoard();
    Square* square1 = &board1->getSquare(0, 0);
    unique_ptr<Piece> knight1 = make_unique<Knight>(Color::White);
    square1->setPiece(move(knight1));

    board1->movePiece(0, 0, 2, 1);

    EXPECT_EQ(board1->getSquare(2, 1).isEmpty(), false);

    board1->movePiece(2, 1, 4, 2);

    ASSERT_TRUE(board1->getSquare(4, 2).getPiece().getSymbol() == "N");
}