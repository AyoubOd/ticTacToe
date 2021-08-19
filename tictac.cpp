#include <iostream>
#include <vector>
using namespace std;

char matrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int a;
char player = 'X';
bool gameOver = false;
vector<char> previous_a(1, 0);

void Draw()
{
    cout << "welcome to Tic Tac Toe Game" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << matrix[i][j];
        }

        if (i != 2)
            cout << "\n-------" << endl;
    }
}

void Input()
{
    cout << "\nplayer: " << player << ", enter the number that you want: ";
    cin >> a;
    for (int i = 0; i < previous_a.size(); i++)
    {
        while (previous_a[i] == a)
        {
            cout << "enter a number of an empty case: ";
            cin >> a;
        }
    }
    previous_a.push_back(a);
}

void checkWinner()
{
    if ((matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) ||
        (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player))
    {
        cout << "player: " << player << " win!";
        gameOver = true;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (
                (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) ||
                (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player))
            {
                cout << "player: " << player << " win!";
                gameOver = true;
                break;
            }
        }
    }
}

void logic()
{
    switch (a)
    {
    case 1:
        matrix[0][0] = player;
        break;
    case 2:
        matrix[0][1] = player;
        break;
    case 3:
        matrix[0][2] = player;
        break;
    case 4:
        matrix[1][0] = player;
        break;
    case 5:
        matrix[1][1] = player;
        break;
    case 6:
        matrix[1][2] = player;
        break;
    case 7:
        matrix[2][0] = player;
        break;
    case 8:
        matrix[2][1] = player;
        break;
    case 9:
        matrix[2][2] = player;
        break;
    }
}

void toggleplayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}
int main()
{
    while (!gameOver)
    {
        system("cls");
        Draw();
        Input();
        logic();
        checkWinner();
        toggleplayer();
    }
}
