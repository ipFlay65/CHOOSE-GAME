#include <iostream>
#include "mathOperators.h" //My library.
#include <time.h> // Library for time.
//#include <stdlib.h> //Library for _sleep(millis).
#include<windows.h> //Library for Sleep(millis).

bool guessTheNumber(std::string who,int numOfPlayer, int secretNumber);
void announceTheWinner(std::string who, int numOfPlayer);

int guessNumber = 0;
int score[2] = {0,0};

int choose = 0;
std::string player[3] = {"You", "Computer", "Player"};

int roundNumber = 1;
int range;

bool haveWinner = false;

//How many wins you need for wining.
int winNeed = 3;

//---------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    //Welcome the player.
    std::cout << "Hello to GUESS GAME!!! \n \n";
    //Rules of game.
    std::cout << "The goal of this game is to first guess the number between 0 and number you choose. \n";
    std::cout << "The winner of this game is player who first get 3 wins. \n \n";

    std::cout << "Enter the range of guessing numbers: ";
    std::cin >> range;
    range++;
    std::cout << "\n";
    std::cout << "If you want to play against computer press 1 \n";
    std::cout << "If you want to play against other player press 2 \n";
    std::cout << "If you want to watch between computers press 3 \n";

    //Get his choice.
    std::cout << "Your choose is: ";
    std::cin >> choose;
    if(choose < 1 || choose > 3){
        std::cout << "Wrong choice please try again!" << std::endl;
    }
    while(haveWinner == false){
        //Start sequence.
        std::cout << "\n";
        std::cout << "ROUND NUMBER " << roundNumber << "\n";
        guessNumber = random()%range;
        std::cout << "Computer has CHOOSE the guess number. \n";
        std::cout << "Game will star in:......";
        Sleep(1000);
        std::cout << "Three......";
        Sleep(1000);
        std::cout << "Two......";
        Sleep(1000);
        std::cout << "One......";
        Sleep(1000);
        std::cout << "GAME STARTED!!!\n";

        //For tracking witch player is on the turn:
        int pTurn = 0;
        int pSwitch = 1;
        //Mode switch
        bool numberCorrect = false;
        switch(choose){
        case 1:
            while(numberCorrect != true){
                numberCorrect = guessTheNumber(player[pTurn], 0, guessNumber);
                pTurn += pSwitch;
                pSwitch *= -1;
            }
            break;
        case 2:
            while(numberCorrect != true){
                numberCorrect = guessTheNumber(player[2], pTurn+1, guessNumber);
                pTurn += pSwitch;
                pSwitch *= -1;
            }
            break;
        case 3:
            while(numberCorrect != true){
                numberCorrect = guessTheNumber(player[1], pTurn+1, guessNumber);
                pTurn += pSwitch;
                pSwitch *= -1;
            }
            break;
        }
        //Adding score to winner and checking if some player win.
        pTurn += pSwitch;
        pSwitch *= -1;
        score[pTurn]++;
        //If the winner is first player
        if(score[0] == winNeed){
            haveWinner = true;
            switch(choose){
            case 1:
                announceTheWinner(player[0],0);
                break;
            case 2:
                announceTheWinner(player[2],pTurn+1);
                break;
            case 3:
                announceTheWinner(player[1],pTurn+1);
                break;
            }
        }
        //If the winner is second player
        if(score[1] == winNeed){
            haveWinner = true;
            switch(choose){
            case 1:
                announceTheWinner(player[0],0);
                break;
            case 2:
                announceTheWinner(player[2],pTurn);
                break;
            case 3:
                announceTheWinner(player[1],pTurn);
                break;
            }
        }
        //If we don't have a winner program tell the score and increase the round number.
        if(haveWinner == false){
            std::cout << "THE ROUND HAS ENDED!!! \n";
            std::cout << "SCORE: " << score[0] << ":" << score[1] << "\n \n";
            roundNumber++;
        }
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//Function witch choose the number for person or computer "who",
//next parameter is serial number of player or computer "numOfPlayer" and the last one is number witch should be guessed "secretNumber".
int pInput;
bool guessTheNumber(std::string who,int numOfPlayer, int secretNumber){
    //In case there is match between you and computer.
    if(numOfPlayer == 0){
        std::cout << who << ": ";
        if(who == "Computer"){
            Sleep(500);
            pInput = rand()%range;
            std::cout << pInput << "\n";
        }else std::cin >> pInput;
    }
    //In case there is match between computers or between players.
    else{
        std::cout << who << " " << numOfPlayer <<": ";
        if(who == "Computer"){
            Sleep(500);
            pInput = rand()%range;
            std::cout << pInput << "\n";
        }else std::cin >> pInput;
    }
    if(pInput == secretNumber)return true;
    else return false;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------
//This function announce the winner you need to enter the name of player "who" and the serial number of player "numOfPlayer".
void announceTheWinner(std::string who, int numOfPlayer){
   if(numOfPlayer == 0) std::cout << who << " WIN THE GAME!!!! \n";
   else std::cout << who << " " << numOfPlayer << " WIN THE GAME!!!! \n";
}
