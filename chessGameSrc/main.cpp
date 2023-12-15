#include <iostream>
#include <map>
#include <set>
#include <string>
#include <limits>


#include "../chessGameHeader/chessGame.hpp"

using namespace std;

string getIntof(string enteredMove) {
  char x = enteredMove[0];
  char y = enteredMove[1];

  // Convert the x from letter ('a' through 'h') to x-coordinate (0 through 7)
  int coordY = x - 'a';

  // Convert the y from number (1 through 8) to y-coordinate (7 through 0)
  // Since 'y' is a char, subtract '0' to convert it to int before
  // calculation

  int coordX = 8 - (y - '0');

  // Convert the coordinates to string format
 if (coordX < 0 || coordX >= 8) {
    return "Invalid";
}
if (coordY < 0 || coordY >= 8) {
    return "Invalid";
}

  string coordinates = to_string(coordX) + to_string(coordY);
  // cout << "Coordinate passed is " << coordinates << endl;

  return coordinates;

}

void playGame() {
  chessGame game1;
  int userMoveCounter;
  std::string sourcePiece1;
  string targetPiece1;
  int userPiece1;
  int userPiece2;
  int userMove1;
  int userMove2;
  game1.startGame();

  

  userMoveCounter = 1;
  while (gameStatus::IN_PROGRESS == game1.getGameStatus()) {
    {
      if (userMoveCounter % 2 == 1) {
          bool isValidInput = false;

        while (!isValidInput) {
          cout << "Player 1, enter the coordinate of white piece you want to move: ";
          // Check if the input length is exactly 2 characters
          cin >> sourcePiece1; 
          if (sourcePiece1.length() != 2) {
              cout << "Not Valid! The coordinate should be 2 characters long." << endl;
          } else {
              // Convert the input and check its validity
              sourcePiece1 = getIntof(sourcePiece1);
              if (sourcePiece1 == "Invalid") {
                  cout << "Not Valid! Please enter a valid coordinate." << endl;
              } else {
                  // Input is valid
                  isValidInput = true;
              }
          }
        }

        // cout << sourcePiece1;
        // cout << "Source piece is " << sourcePiece1 << endl;
        
        userPiece1 = int(sourcePiece1[0]) - '0';
        userPiece2 = int(sourcePiece1[1]) - '0';

        // cout << "Piese 1 x: " << userPiece1 << endl;
        // cout << "Piese 1 y: " <<userPiece2 << endl; 

        isValidInput = false;

        while (!isValidInput) {
          cout << "Player 1, enter the coordinate of where you want to move: ";
          cin >> targetPiece1;
          if (targetPiece1.length() != 2) {
              cout << "Not Valid! The coordinate should be 2 characters long." << endl;
          } else {
              // Convert the input and check its validity
              targetPiece1 = getIntof(targetPiece1);
              if (targetPiece1 == "Invalid") {
                  cout << "Not Valid! Please enter a valid coordinate." << endl;
              } else {
                  // Input is valid
                  isValidInput = true;
              }
          }
        }

        // cout << "Target piece is " << targetPiece1 << endl;
      

        userMove1 = int(targetPiece1[0]) - '0';
        userMove2 = int(targetPiece1[1]) - '0';
        // cout << "Piese 2 x: " << userMove1 << endl;
        // cout << "Piese 2 y: " << userMove2 << endl;

        game1.makeMove(userPiece1, userPiece2, userMove1, userMove2, true);

        // function prints updated board after user move, needs to check after
        // every move. Otherwise, player can make a move after a "checkmate" has
        // already happened
        if (game1.moveSucess()) {
          cout << "Wonderful! Now player 2. " << endl;
          userMoveCounter++;
        }
        else {
          cout << "Move wasn't valid, please enter your move again! " << endl;
          cout << endl; 
          cout << endl;
        }
      }

      if (userMoveCounter % 2 == 0) {
        bool isValidInput = false;
        do {
          cout << "Player 2, enter the coordinate of black piece you want to "
                  "move: ";
          cin >> sourcePiece1;

          // Check if the input length is exactly 2 characters
          if (sourcePiece1.length() != 2) {
            cout << "Not Valid! The coordinate should be 2 characters long."
                 << endl;
          } else {
            // Convert the input and check its validity
            sourcePiece1 = getIntof(sourcePiece1);
            if (sourcePiece1 == "Invalid") {
              cout << "Not Valid! Please enter a valid coordinate." << endl;
            } else {
              // Input is valid
              isValidInput = true;
            }
          }
        } while (!isValidInput);
        // cout << sourcePiece1;

        userPiece1 = int(sourcePiece1[0]) - '0';
        userPiece2 = int(sourcePiece1[1]) - '0';

        isValidInput = false;
        do {
          cout << "Player 2, enter the coordinate of where you want to move: ";
          cin >> targetPiece1;

          // Check if the input length is exactly 2 characters
          if (targetPiece1.length() != 2) {
            cout << "Not Valid! The coordinate should be 2 characters long."
                 << endl;
          } else {
            // Convert the input and check its validity
            targetPiece1 = getIntof(targetPiece1);
            if (targetPiece1 == "Invalid") {
              cout << "Not Valid! Please enter a valid coordinate." << endl;
            } else {
              // Input is valid
              isValidInput = true;
            }
          }
        } while (!isValidInput);

        userMove1 = int(targetPiece1[0]) - '0' ;
        userMove2 = int(targetPiece1[1]) - '0';

        game1.makeMove(userPiece1, userPiece2, userMove1, userMove2, false);

        // function prints updated board after user move, needs to check after
        // every move. Otherwise, player can make a move after a "checkmate" has
        // already happened
        if (game1.moveSucess()) {
          cout << "Awesome! Now player 1. " << endl;
          userMoveCounter++;
        }
        else {
          cout << "Move wasn't valid, please enter your move again! " << endl;
        }
      }
    }
  }
  game1.printMoveHistory();
}
// signals the game has not ended
// Print match history after match is over
// Reset for future games in the same terminal

int main() {
  string chessRules =
      "Pawn The pawn can move only in a forward direction. From its starting "
      "position the pawn may be moved one or two squares. However, after that "
      "it may be moved only one square at a time. Since the pawn cannot leap "
      "over any piece, any chessman directly in front of it blocks further "
      "advance of the pawn. A pawn may only capture an enemy piece that is on "
      "the square in front of it diagonally. If your pawn is able to reach the "
      "end row on the board, you may replace it with any piece (except a "
      "king). \nROOK \nThe rook can move either horizontally or vertically "
      "(but not both on the same move). \nQUEEN \nThe queen is the strongest "
      "piece in the game. It may move in eight directions-commanding all the "
      "squares in any of these various directions. It cannot jump over another "
      "piece. \nBISHOP \nThe bishop can only move diagonally and in one "
      "direction at a move. Each bishop is on a different color and commands "
      "that color only. \nCASTLING \nThe only move in the game that allows two "
      "pieces to move at once is castling. The two pieces that partake in this "
      "are the king and rook. However, there are a few rules that govern this "
      "move. A player may 'castle' if: \nA. All the squares between the king "
      "and rook are unoccupied. \nB. Neither the rook or king has been moved "
      "previously. \nC. None of the opponent's places command the squares "
      "between the king and the rook. \nKNIGHT \nThe knight is the only "
      "chessman that can move over its own or opponent's pieces. The Knight "
      "moves two spaces in a row and one over. \nKING \nThe king may move in "
      "any direction-to either color. However, unlike the queen, the king "
      "moves \nonly one square at a time. Since the object of the game is to "
      "capture the king, the king is not allowed to be moved to a square where "
      "he would be liable to be captured by an opposing piece. \nCHECKMATE "
      "\nTo win the game of chess, a player must capture the opponent's king. "
      "This is known as 'Checkmating' the king. Whenever the king is attacked, "
      "he is in check and must be so warned by the opponent. To get out of "
      "check the player may either: capture the attacking piece; move the king "
      "out of danger; or put another piece\nbetween the attacking chessman and "
      "his king. \nDRAWN GAME \nA game is drawn when: \nA. One player cannot "
      "'Checkmate' the other. \nB. There is a 'stalemate.' This happens when a "
      "king is not in check, but when his \nonly move (with the king) puts him "
      "into check. This differs from a 'checkmate,' where the king is already "
      "in check before moving.";
  char userOption = 0;
  bool userValid = false;

  set<string> userUsernames;
  map<string, string> userProfiles;
  string userUsername = " ";
  string userPassword = " ";
  bool usernameValid = false;
  bool passwordValid = false;

  string player1Username = " ";
  string player1Password = " ";
  string player2Username = " ";
  string player2Password = " ";
  bool user1Valid = false;
  bool user2Valid = false;

  // bool user1PValid = false;
  // bool user1MValid = false;
  // bool user2PValid = false;
  // bool user2MValid = false;

  cout << "Hello, welcome to our chess game!" << endl << endl;
  while (userValid ==
         false)  // while user input is invalid, keep asking for valid input
  {
    cout << "1. Rules of Chess. \n2. Create profile. \n3. Play a two player "
            "match. \n4. Play as guest. \n5. Exit program."
         << endl;
    cout << "Select an option:";
    cin >> userOption;  // Get user input
    cin.ignore(256, '\n');
    if (userOption != '1' && userOption != '2' && userOption != '3' &&
        userOption != '4' && userOption != '5')  // Validate user input
    {
      cout << "Please enter a valid input" << endl;
    } else  // If invalid, repeat while loop, if valid continue
    {
      if (userOption == '1') {
        cout << "Rules of Chess:" << endl;
        cout << chessRules << endl << endl;
      }

      if (userOption == '2') {
        cout << "You entered option 2." << endl;

        while (usernameValid == false) {
          cout << "Enter a username between 4 and 20 characters (Duplicates "
                  "will be deleted): "
               << endl;
          cin >> userUsername;  // Get user input
          cin.ignore(256, '\n');
          if (userUsername.length() < 4 ||
              userUsername.length() > 20)  // if less than four or greater than
                                           // 20, stop. if betweem, continue
          {
            cout << "Please enter a valid username!" << endl;
          } else {
            usernameValid = true;
            userUsernames.insert(
                userUsername);  // once validated,  insert to set
            cout << "Your username is " << userUsername
                 << ". Write it down if you need." << endl;
          }
        }

        while (passwordValid == false) {
          cout << "Enter a password that is different that your username and "
                  "between 12 and 20 characters:"
               << endl;
          cin >> userPassword;  // Get user input
          cin.ignore(256, '\n');
          if (userPassword.length() < 12 || userPassword.length() > 20 ||
              userPassword == userUsername)  // if less than 12 or greater than
                                             // 20, stop. if between, continue
          {
            cout << "Please enter a valid password!" << endl;
          } else {
            passwordValid = true;
            userProfiles.insert(
                pair<string, string>(userUsername, userPassword));
            cout << "Your password is " << userPassword
                 << ". Write it down if you need." << endl;
          }
        }
        
        usernameValid = false;  // Reset to validate future usernames
        passwordValid = false;
      }

      if (userOption == '3') {
        cout << "You entered option 3." << endl;

        while (user1Valid == false) {
          cout << "Player 1, Enter an existing username: ";
          cin >> player1Username;
          cin.ignore(256, '\n');
          
            cout << "Player 1, Enter the password for the username: ";
            cin >> player1Password;
            cin.ignore(256, '\n');
            if (userProfiles[player1Username] == player1Password) {
              user1Valid = true;
            } 
            else {
              cout << "Invalid username or password! Try again." << endl;

            }
        }

        while (user2Valid == false) {
          cout << "Player 2, Enter an existing username: ";
          cin >> player2Username;
          cin.ignore(256, '\n');
          
            cout << "Player 2, Enter the password for the username: ";
            cin >> player2Password;
            cin.ignore(256, '\n');
            if (userProfiles[player2Username] == player2Password && player2Username != player1Username) {
              user2Valid = true;
            } else {
              cout << "Invalid username or password! Try again." << endl;
            }
          
        }
        playGame();
        user1Valid = false;
        user2Valid = false;
      }

      if (userOption == '4') {
        cout << "You've enter to play as guest." << endl;
        playGame();
        user1Valid = false;
        user2Valid = false;
      }

      if (userOption == '5') {
        cout << "You entered option 5." << endl;
        return 0;
      }
    
      continue;
    }
  }
  return 0;
}
