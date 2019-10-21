/*
Alexander Arbuckle
Professor Michael Essmyer
CS201 : Program 01
29 August 2019
*/

#include <iostream> // gives input and output of information
#include <ctime> // gives assembler access to library of time
#include <cstdlib> // standard c library includes access to such things as random
#include <string> // gives us access to 'getline()'
using namespace std; // assembler becomes aware of unique variables with scopes

int main() { // where program is being written

	int gameAI = 0; // the AI's score integer value decleration and assignment statement
	int gameDie; // the decleration for the die being used
	int gamePlayer = 0; // the decleration and assignment statement for the player's score
	int gameSpam = 0; // if the AI outputs too much, this will increment and stop the AI from repeatedly doing so
	string gameEnter; // a string value used to get through the game properly
	bool gameTurn = true; // built to switch around from true and false to alternate playing time properly to save both space and time

	srand(time(0)); // seeding random with 'time(0)' so it includes every second from January 1st, 1970 to present
	while (true) { // the encasing while statement that will ultimately ask the user if they would like to play again

		cout << endl << "Score\tYou :\t" << gamePlayer << "\tAI :\t" << gameAI << endl << endl; // score

		if ((gameTurn == true) && (gameAI < 50) && (gamePlayer < 50)) { // if (true) it's player's turn. all scores must ALSO be below 50.

			cout << "Player\'s Turn\t<Press Enter>";
			getline(cin, gameEnter); // allows user to press enter to move onto the next step
			cout << endl;
			while (true) { // the while statement that will send the user into a loop until they win, hold, or get 1

				gameDie = ((rand() % 6) + 1); // generates pseudo-random integer between 1 and 6. can't be zero.

				if (gameTurn == false) { // this being false means it needs to ultimately break out of the given while statements, loop again, and go to AI branch

					break;

				}

				else if (gameDie == 1) { // should the game die be 1 branch

					cout << "Dice Roll :\t" << gameDie << "\tBUST" << endl << endl; // outputs the dice rolled and tells them that they BUST
					gamePlayer = 0; // sets player score back to zero.
					gameTurn = !gameTurn; // sets the opposite of the boolean statement to be true so the other player can play
					break; // soon after breaks out of the loop to go to AI branch

				}

				else { // should the value not equal 1 or just, in general, be false

					gamePlayer += gameDie; /// adding value to player's pot

					if (gamePlayer >= 50) { // if the player's pot is equal to or over 50

						cout << endl << "WINNER :\tPlayer at with " << gamePlayer << " points!" << endl; // winning statement with how many points they got
						gameTurn = !gameTurn; // sets the opposite boolean to be true, built should they desire to play another game, the opposite starts
						break; // breaking out of loop

					}

					else if (gamePlayer < 50) { // branch should the player's value be less than 50

						while (true) { // encasing statement to continuously ask if they want to roll or hold

							cout << "Dice Roll :\t" << gameDie << "\tPot :\t" << gamePlayer; // outputs dice roll and pot value
							cout << "\t<(R)oll or (H)old?> "; // asks user if they would like to roll or hold, (still on the same line)
							getline(cin, gameEnter); // gets user input on what they want to do

							if ((gameEnter == "H") || (gameEnter == "h")) { // should the input be hold

								gameTurn = !gameTurn; // turns to the opposite boolean statement for the other player to play
								break; // then exits given loop and will conditionally leave the following loops because of the new boolean

							}

							else if ((gameEnter == "R") || (gameEnter == "r")) { // should the input be roll

								break; // exit the closest loop

							}

							else { // should the input be neither H nor R

								cout << "Input is invalid." << endl; // error message

							}

						}

					}

				}

			}

		}

		else if ((gameTurn == false) && (gameAI < 50) && (gamePlayer < 50)) { // should the game be false (for the AI to play) and both scores less than 50

			cout << "AI\'s Turn\t<Press Enter>";
			getline(cin, gameEnter); // user presses enter to proceed and acknowledges that it is AI's turn
			cout << endl;
			while (true) { // while statement for AI to continuously loop through until it reaches a given condition

				gameDie = ((rand() % 6) + 1); // die, same as last die variable

				if (gameTurn == true) { // should the game's turn be true, it will go to the player's turn then after breaking out of existing loops

					break; // breaks out of existing loops

				}

				while (true) { // while statement to continuously give the option for the AI to play under given circumstances

					if (gameDie == 1) { // should the game die value be equal to one

						cout << "Dice Roll :\t" << gameDie << "\tBUST" << endl << endl; // you BUST statement
						gameAI = 0; // because BUST you are set back to zero according to the rules
						gameTurn = !gameTurn; // opposite boolean statement for other person's turn
						break; // exit current loop now

					}

					else { // should the die value not be one

						gameAI += gameDie; // die value is added to the AI's pot

						if (gameAI >= 50) { // branch that covers should the AI have a winning score over, or equal to, 50

							cout << endl << "WINNER :\tAI with " << gameAI << " points!" << endl; // WINNER statement
							gameTurn = !gameTurn; // opposite player's turn should they decide to play again
							break;

						}

						else if (gameAI < 50) { // should the game be under 50 points currently

							int gameMind = rand() % 3;
							/* ^
							instead of telling the program to stop once it reaches 20, i decided to pseudo-randomly produce
							 a number between 0-2, should it equal 0, it will decide to hold. however, there are existing chances
							 of it rarely inputting 0, should that happen 'gameSpam' notes every turn that isn't a 'hold' value
							 so the AI doesn't go an extended amount of time and confuse the player. Once it reaches an integer value
							 of 9, the program stops the AI and automatically tells the program to choose hold making it the player's
							 turn. This procedure seemed more authentic and entertaining compared to constantly stopping the AI after
							 it reached 20.
							*/

							cout << "Dice Roll :\t" << gameDie << "\tPot :\t" << gameAI; // outputs who's dice roll it is
							cout << "\t<(R)oll or (H)old?> " << gameMind << endl; // asks if AI wants to hold or roll to appear authentic to user

							if ((gameMind == 0) || (gameSpam == 9)) { // should the input value be 0 or 'gameSpam' has reached a value of 9

								gameSpam = 0; // resets such value so AI doesn't automatically hold every turn thereafter
								gameTurn = !gameTurn; // turns to opposite boolean
								break;

							}

							else {

								gameSpam += 1; // program taking note of every input that's not '0', also known as 'hold' for safety of the user

							}

						}

					}

				}

			}

		}

		else { // should the existing conditions not qualify and someone has a integer value of over 50

			while (true) { // statement that asks user for correct input

				cout << "Play again?\t<(Y)es or (N)o?> "; // if they would like to restart the game
				getline(cin, gameEnter); // the user's choice one what they would like to do

				if ((gameEnter == "Y") || (gameEnter == "y")) { // yes branch

					gameAI = 0; // resetting all these values so the new game isnt starting with prexisting values
					gamePlayer = 0;
					gameSpam = 0;
					break; // breaks and goes back to the very top of the program to repeat the loop, thus the game

				}

				else if ((gameEnter == "N") || (gameEnter == "n")) { // no branch

					break; // breaks out of current loop and moves onto the 'if' branch below to see if it qualifies, it will

				}

				else { // should it be neither yes or no branch

					cout << "Input is invalid." << endl; // notifies that input was neither yes nor no

				}

			}

			if ((gameEnter == "n") || (gameEnter == "N")) { // should the user input no branch

				cout << endl << "Thanks for playing!" << endl;
				break; // exit the program entirely

			}

		}

	}

}