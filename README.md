
# Chess Game
 
 Authors: \[Martin De Guzman](https://github.com/KuYuh02),  \[David Aispuro](https://github.com/DavidA346),  \[Michael Mihalovich](https://github.com/michaelm015),  \[Sarik Raj Karki](https://github.com/Eros846)

## Project Description
 * One of the reasons this project is interesting is it exposes us to working with back end development. We also love the fact that despite chess being a simple game, there is a lot of features we can implement features to make it more convenenient, entertaining, etc. Features that are not possible to implement in real life chess. 
 * We plan to code our backend/the main game in C++ and the game will run two local players in the console.
 * The project will take many different inputs. For example, when in the create profile menu option, it will take user login inforomation such as username and password. As for the game itself, the user will type the piece they want to move and where on the board to move it.  
 * The project an in console main menu which has options to make an account, learn the rules of chess, and host the main game. The main chess game will have the same rules of chess.
 * The backend of the project will take care of the logic of the chess game. This includes setting up and displaying the pieces and board, creating both a black and white player and determining the legal moves for each piece and whether or not the move can be completed. Finally, it will display the outcome of the game and ask the user to play again or exit to main menu.
 * The input for this project will be accomplished through the user keyboard. The user will also need to input for every turn they wish to complete and the output will be that move displayed on the screen. (see diagram below for more details)


## User Interface Specification

### Navigation Diagram
![image](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/ce02b2b2-6e1e-413f-971a-e8707f7c6376)

# Screen Layouts

## Main Menu
![image](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/c412f5b8-75ba-4602-9312-e846b35e1133)

Key Features:
- The whole program will run from the console.
- The menu will keep running until the user specifies to exit.
- All inputs will validated.

## Create profile
![image](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/e7678b79-f094-4033-9a46-ba14727394dd)
- Here the user can make a profile. 
- The console will validate to make sure the passwords match, the username does not already exist, etc.
- Before a match, the console will also ask for the users to login using an existing profile. 

## Game page
![image](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/d96b4937-5120-4036-be20-99957058056d)
- After both players successfully login to their profile, they can begin playing a match. 
- User can make moves by typing it, the console will validate if it is a valid move. 
- The board is labeled on all sides to help the user make the correct move. 
- At the end, the console will as to play another game or go back to main menu. 

## Class Diagram
 Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
![IMG_0117](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/88258745/718ebf95-f786-4772-aeab-d52006fc5d8c)


# Updated Class Diagram and SOLID Principles

### Revised Class Diagram
 ![Phase3UML](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/146981459/4cd6eaff-4242-4b31-b2a4-f7163a8ca2ef)
 <br> There are a number of changes made to our UML as a reflection of the combination of feedback and implementation. The major change is the removal of the "PieceType" class. From feedback during our last meeting, we concluded was redundant and unnecessary. There are various minor additions and changes to the classes. The causes for the rest of these changes are ease of implementation, and oversights during the earlier phases before we started building our program. We have identified the key characteristics of each of our classes and how we want them to interact, so we have more functions and more accurate detail in this updated Class Diagram. To summarize our changes in a quantifiable way; the ChessBoard class should operate around the general rules of chess itself, while the individual piece types will have their own unique set of legal moves that operate within the bounds of the game as monitored in ChessBoard.

### SOLID Design Principles
 We redesigned our classes with the Open-Closed Principle in mind, because of the complexity of the chess game. This is evident in the Pieces class and the 6 types of pieces that inherit Pieces. Many different objects are dependent on this class but are unable to modify the Pieces classes. 
 Another principle we kept in mind was the Liskov Substitution Principle. This principle helped us stay focused when redesigning all the different pieces. Now all the subclass types of pieces will behave according to the Piece superclass. The changes made to the subclass pieces caused us to move functions around, creating a new idea and plan for the classes as stated above.
 The Interface Segregation Principle is one that does not impact our development very much but is very helpful to keep in mind. We understand chess very well, and the visual simplicity on the client side of the program is a theme we are trying to uphold.
 The Dependency Inversion Principle also helped with the redesign process of our class diagram. keeping abstractions and implementations separate is something we did not fully consider when making the original class diagram, which we worked out through feedback and changes during our coding process.

# Final Project Update

 ### Final Class Diagram
 ![FinalUMLDiagram](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/146981459/8c1dcf7b-5803-4ccd-843c-a7951699ea54)
 <br> This final UML includes everything we have implemented up to this point in our project.
 <br> With the planned sprint and the features that come with it, this UML is subject to change.
 <br>
 ### Project Status
 We completed most of what we originally planned for the project, but some features ended up out of scope. The login takes username and password, the player can play a game of chess in the console, all inputs are correctly validated, and the move history is shown to both players after the game. However, being able to undo moves ended up out of scope during our allotted time. We included several customization and accessibility issues we want to address in the future planned sprint. We are aware the game may have bugs or possible leaks, and those would be caught and addressed given the opportunity to continue development.
 
 ## Screenshots
![image](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/344595b1-5d71-4859-b8f3-2cee791f11bb)
![image](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/d49f27a5-d835-4acb-aa2b-9ed49bc86f59)
![image](https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/554ced92-4f7c-4eed-b695-ae0be570de2b)
<br>
<img width="346" alt="image" src="https://github.com/cs100/final-project-mdeg011-skark010-daisp002-mmiha004/assets/57105334/bd5d7560-7d49-446c-95e4-2cdc51e73956">

 ## Installation/Usage
 ### Installation
 ### Windows/Linux
  Download a C++ code editor such as Visual Studio Code or Eclipse.
 <br> Git clone this repository onto your desired code editor.  
  After this, you should have everything installed to run our chess game. 
 ### Running
 To run our chess game, be sure you are in the final-project directory and run:
 <br> cmake .
 <br> make
 <br> ./playChess
 <br> After this, the menu will tell you everything you need to play the game. Have fun!
 ## Testing/Validation
 For validation, every input from the user is validated. From the choice in the main menu to checking if the user made a valid move with the piece they chose. 
 <br> To test our functions, we used the Googletest framework. This public framework developed by google allows us to test internal functions in our program. The main tests we implemented check whether the pieces move correctly, correctly show/give error based on input, and make sure the prints accurately reflect the board/move history. Ultimately, the tests correctly passed and failed when needed showing correct implementation of our class methods. 
 
