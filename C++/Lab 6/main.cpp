/*******************************************
           Author: Carlos Vergara
               Lab 6: Nim Game
*******************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    //Variables are declared and time is seeded
    bool winner = false;
    int num, player = 1, sticks = 11;
    char game_type;

    srand(time(0));

    //Game is initiated
    cout << "Welcome to NIM! \n\nPlayers will take turns removing 1, 2, or 3 sticks from the initial 11. \n\nThe player removing the last stick wins!" << endl;
    cout << "\nDo you wish to play against the computer? (Y/N): ";
    cin >> game_type;

    while (game_type != 'Y' && game_type != 'y' && game_type != 'N' && game_type != 'n'){
        cout << "ERROR: Please enter a valid answer (Y or N): ";
        cin >> game_type;
    }

    //Game option against another player
    if (game_type == 'N' || game_type == 'n'){
        do{
            cout << "\nPlayer " << player << ", it's your turn! \n" << endl;
            cout << "The game currently looks like this:\n" << endl;

            for (int i = 0; i < sticks; i++){ //Remaining sticks are displayed
                char a = '|';
                cout << a;
            }

            cout << "\n\nHow many sticks would you like to remove? (1, 2, or 3): ";
            cin >> num;

            while(num > 3 || num < 1){
                cout << "\nThat choice is invalid" << endl;
                cout << "\nHow many sticks would you like to remove? (1, 2, or 3): ";
                cin  >> num;
            }

            while ((sticks - num) < 0 && winner == false){
                cout << "\nOops! Can't take more sticks than there are left.\n" << endl;
                cout << "How many sticks would you like to remove? (1, 2, or 3): ";
                cin >> num;
            }

            if (num > 0 && num < 4){
                sticks -= num;
            }

            if (sticks == 0){
                winner = true;
                cout << "\nCONGRATULATIONS PLAYER " << player << ", YOU WIN!" << endl;
            }

            player = (player == 1) ? 2:1;
        } while (!winner);
    } else

    //Game option against the computer
    if (game_type == 'Y' || game_type == 'y'){
        do{
            if (player == 1){
                cout << "\nPlayer " << player << ", it's your turn! \n" << endl;
                cout << "The game currently looks like this:\n" << endl;

                for (int i = 0; i < sticks; i++){ //Remaining sticks are displayed
                    char a = '|';
                    cout << a;
                }

                cout << "\n\nHow many sticks would you like to remove? (1, 2, or 3): ";
                cin >> num;
            } else {
                cout << "\nIt's the computers turn! \n" << endl;
                cout << "The game currently looks like this:\n" << endl;

                for (int i = 0; i < sticks; i++){ //Remaining sticks are displayed
                    char a = '|';
                    cout << a;
                }

                cout << "\n\nHow many sticks would you like to remove? (1, 2, or 3): ";
                Sleep(3000); //Delays the computer's answer by 3 seconds
                if (sticks >= 3){
                    num = rand() % 3 + 1;
                } else
                if (sticks == 2){
                    num = rand() % 2 + 1;
                } else
                if (sticks ==1){
                    num = rand() % 1 + 1;
                }
                cout << num << endl;
            }

            while(num > 3 || num < 1){
                cout << "\nThat choice is invalid" << endl;
                cout << "\nHow many sticks would you like to remove? (1, 2, or 3): ";
                cin  >> num;
            }

            while ((sticks - num) < 0 && winner == false){
                cout << "\nOops! Can't take more sticks than there are left.\n" << endl;
                cout << "How many sticks would you like to remove? (1, 2, or 3): ";
                cin >> num;
            }

            if (num > 0 && num < 4){
                sticks -= num;
            }

            if (sticks == 0){
                winner = true;
                if (player == 1)
                    cout << "\nCONGRATULATIONS PLAYER " << player << ", YOU WIN!" << endl;
                else
                    cout << "\nSORRY PLAYER " << player << ", YOU LOSE!" << endl;
            }

            player = (player == 1) ? 2:1;
        } while (!winner);
    }

    return 0;
}
