#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
using namespace  std;

char square [10] = {'f', '1', '2','3', '4', '5', '6', '7',  '8', '9'};

//Checking for winning conditions
int checkWin() {

    // Checking rows
    for (int i = 1; i <= 7; i += 3) {
        if (square[i] == square[i + 1] && square[i + 1] == square[i + 2])
            return 1;
    }
    // Checking columns
    for (int i = 1; i <= 3; ++i) {
        if (square[i] == square[i + 3] && square[i + 3] == square[i + 6])
            return 1;
    }
    // Checking diagonals
    if (square[1] == square[5] && square[5] == square[9])
        return 1;
    if (square[3] == square[5] && square[5] == square[7])
        return 1;

    return 0;
}

// Checking for tie conditions
int checkTie() {
    for(int i =1; i< 10; i++) {
        if(square[i] > '0' && square[i] <= '9') {
            return false;
        }
    }
    return true;
}


// Drawing board
void drawBoard() {
    std::cout << "\t\t     |     |     \n";
    for (int i = 1; i <= 9; i += 3) {
        std::cout << "\t\t  ";
        for (int j = i; j <= i + 2; ++j) {
            if (square[j] == 'X')
                std::cout << RED << square[j] << RESET << "  |  ";
            else if (square[j] == 'O')
                std::cout << GREEN << square[j] << RESET << "  |  ";
            else
                std::cout << square[j] << "  |  ";
        }
        std::cout << "\n";
        std::cout << "\t\t_____|_____|_____\n";
        std::cout << "\t\t     |     |     \n";
    }

}


int main()
{
    // Turn of current player
    int turn = 1;
    // Input of current player
    int input;

    while(!checkWin() && !checkTie()) {
        cout<<"PLAYER - 1 [X]\t PLAYER - 2 [O]\n";
        cout <<"\t\t  Player "<< turn<< "'s turn"<<endl;
        drawBoard();
        cin >> input;
        if(input < 0 || input >9 || square[input] < '0' || square[input]> '9') {
            cout << "Invalid input, please enter again";
            cin >> input;
        }

        char token = (turn == 1) ? 'X':'O';
        if(square[input] > '0' && square[input]<= '9')
            square[input] = token;
        turn = (turn==1)? 2:1;
    }
    drawBoard();
    if(checkWin())
        cout << ((turn == 1) ? "Player 2 won" : "Player 1 won");
    else
        cout << "It is a tie";

    return 0;
}
