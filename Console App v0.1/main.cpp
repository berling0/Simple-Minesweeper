#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <time.h>
#include <locale.h>

#include <stdlib.h>

using namespace std;

int megjelol, akna, jatekos, pont = 0;
char tomb[10] = { '-', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
bool jatekON = true;

void palya()//rendering the 3x3 board
{
    system("cls");
    cout << ".M.i.n.e." << endl;
    cout << "-Sweeper-" << endl;
    cout << "Points: " << pont << endl;
    cout << "---------" << endl;
    cout << "| " << tomb[1] << " " << tomb[2] << " " << tomb[3] << " |" << endl;
    cout << "| " << tomb[4] << " " << tomb[5] << " " << tomb[6] << " |" << endl;
    cout << "| " << tomb[7] << " " << tomb[8] << " " << tomb[9] << " |" << endl;
    cout << "---------" << endl;
}

void exit()
{
    cout << "\aYou hit a mine :P" << endl;
    cout << "You collected " << pont << " point";
    if (pont > 1)
    {
        cout <<"s";
    }
    this_thread::sleep_for(chrono::milliseconds(5000));
}

int aknakereso()//logics of the game
{
    akna = (rand() % 9) + 1;
    char jelol;
    do
    {
        palya();
        cout << "Enter a field number: ";
        cin >> megjelol;
        jelol = '+';
        switch (megjelol)
        {
        case 1:
            tomb[1] = jelol;
            break;
        case 2:
            tomb[2] = jelol;
            break;
        case 3:
            tomb[3] = jelol;
            break;
        case 4:
            tomb[4] = jelol;
            break;
        case 5:
            tomb[5] = jelol;
            break;
        case 6:
            tomb[6] = jelol;
            break;
        case 7:
            tomb[7] = jelol;
            break;
        case 8:
            tomb[8] = jelol;
            break;
        case 9:
            tomb[9] = jelol;
            break;
        default:
            pont = -1;
        }
        if (megjelol == akna)
        {
            jelol = '*';
            system("cls");
            jatekON = false;
            exit();
        }
        if (megjelol != akna)//gives 1 point for not hitting the mine
        {
            pont++;
        }
        if (megjelol > 9 || megjelol< 0)
        {
            cout << "This is not a valid field";
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    } while (jatekON == true);

    return 0;
}

int main()
{
    int asdd;
    setlocale(LC_ALL, "");
    srand((unsigned)time(NULL));
    system("Title GAMEZLEL");
    aknakereso();
}