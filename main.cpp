#include <iostream>
#include "mathOperators.h" //My library.
#include <time.h> // Library for time.
//#include <stdlib.h> //Library for _sleep(millis).
#include<windows.h> //Library for Sleep(millis).

int guessNumber = 0;
int score[2] = {0,0};

int choose = 0;
int order = 0;
std::string player[2] = {"Computer", "Player"};

int roundNumber = 1;
int range;

int pInput;
int chPlayer = 1;

//How many wins you need for wining.
int winNeed = 1;

int main()
{
    //Welcome the player.
    std::cout << "Hello to GUESS GAME!!! \n \n";
    //Rules of game.
    std::cout << "The goal of this game is to first guess the number between 0 and number you choose. \n";
    std::cout << "The winner of this game is player who first get 3 wins. \n \n";

    std::cout << "Enter the range of guessing numbers:  ";
    std::cin >> range;
    std::cout << "\n";
    std::cout << "If you want to play against computer press 1 \n";
    std::cout << "If you want to play against other player press 2 \n";

    //Get his choice.
    std::cout << "Your choose is: ";
    std::cin >> choose;
    if(choose < 1 || choose > 2){
        std::cout << "Wrong choice please try again!" << std::endl;
    }

    return 0;
}

