#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include <stdlib.h>


using namespace std;

#define MARKED_CELL '+'
#define MINE_CELL '*'

int point = 0;
char grid[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-'};
bool is_running = true;


void clear_screen()
{
    system("cls || clear");
}

void draw_grid()
{
    clear_screen();
    cout << ".M.i.n.e." << endl;
    cout << "-Sweeper-" << endl;
    cout << "Points: " << point << endl;
    cout << "---------" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << grid[3 * i + j] << ' ';
        }
        cout << '|' << endl;
    }

    cout << "---------" << endl;
}

void game_over()
{
    cout << "\aYou hit a mine :P" << endl;
    cout << "You collected " << point << " point";

    if (point > 1)
    {
        cout << "s";
    }

    cout << endl;
    // this_thread::sleep_for(chrono::milliseconds(5000));
    exit(0);
}

void game()
{
    int mine = (rand() % 9) + 1;
    int marked = -1;

    do
    {
        draw_grid();

        cout << "Enter a field number: ";
        cin >> marked;

        if (marked > 9 || marked <= 0)
        {
            cout << "'" << marked << "' is is not a valid field" << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
        }
        else
        {
            if (marked == mine)
            {
                grid[marked - 1] = MINE_CELL;
                draw_grid();
                game_over();
            }
            if (marked != mine && grid[marked - 1] != MARKED_CELL)
            {
                point++;
            }
            if (point == 8)
            {
                clear_screen();
                cout << "You found all the correct fields "<< endl << "You won the game!" << endl;
                // this_thread::sleep_for(chrono::milliseconds(5000));
                break;
            }
        
            grid[marked - 1] = MARKED_CELL;
        }
    } while (is_running);
}

int main()
{
    srand((unsigned) time(NULL));
    game();
}
