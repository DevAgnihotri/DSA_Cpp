#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 25
#define MAX_NAME_LENGTH 50

int gameOver;
int score;
int x, y, fruitX, fruitY;
int tailX[200], tailY[200]; // tail capacity
int nTail;
int i, j, k, print;
char playerName[MAX_NAME_LENGTH];
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
enum eDirection dir;

// Function to position cursor at a specific position
void gotoxy(int x, int y)
{
    COORD coord; // COORD Struct from windows.h
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to hide the cursor
void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 100;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

// Function to show the cursor
void showCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 100;
    cursor.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void ClearScreen()
{
    system("cls");
}

void Setup()
{
    gameOver = 0;
    dir = RIGHT; // Start moving right
    x = WIDTH / 2;
    y = HEIGHT / 2;

    // Initialize fruit position away from snake
    fruitX = rand() % (WIDTH - 5) + 2;
    fruitY = rand() % (HEIGHT - 5) + 2;

    // Set initial score
    score = 0;

    // Set initial tail length to 3
    nTail = 3;

    // Initialize tail positions behind the head
    for (i = 0; i < nTail; i++)
    {
        tailX[i] = x - (i + 1);
        tailY[i] = y;
    }
}

void Draw()
{
    ClearScreen(); // Clear the entire screen before redrawing

    // Draw title and player name
    printf("Snake Game - Player: %s\n", playerName);

    // Draw top border
    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    // Draw middle part with snake, fruit and side borders
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (j == 0)
                printf("#");

            // Draw snake head based on direction
            if (i == y && j == x)
            {
                printf("@"); // Replace head with '@' symbol
            }
            else if (i == fruitY && j == fruitX)
                printf("F"); // Fruit
            else
            {
                print = 0;
                for (k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("*"); // Use * for snake body
                        print = 1;
                    }
                }
                if (!print)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    // Draw bottom border
    for (i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    // Display score and controls once after the game board
    printf("Score: %d\n", score);
    printf("Controls: W,A,S,D to move, X to quit\n");
}

void Input()
{
    if (_kbhit()) // kbhit returns a non-zero, and zero for no key pressed
    {
        switch (_getch())
        {
        case 'a':
            if (dir != RIGHT) // Prevent 180-degree turns
                dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void Logic()
{
    // Store the current position of the first segment of the tail
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    // Update the first segment of the tail to follow the head
    tailX[0] = x;
    tailY[0] = y;

    // Update the rest of the tail segments to follow the previous segment
    for (i = 1; i < nTail; i++)
    {
        // Store the current position of the current segment
        prev2X = tailX[i];
        prev2Y = tailY[i];

        // Update the current segment to the position of the previous segment
        tailX[i] = prevX;
        tailY[i] = prevY;

        // Move to the next segment
        prevX = prev2X;
        prevY = prev2Y;
    }

    /*
    Dry Run Example:
    Initial state:
    Head (x, y) = (5, 5)
    Tail: [(4, 5), (3, 5), (2, 5)]
    nTail = 3

    After moving head to (5, 5):
    Step 1: Store tailX[0] = 4, tailY[0] = 5 in prevX, prevY
    Step 2: Update tailX[0] = 5, tailY[0] = 5 (head's previous position)
    Step 3: For i = 1:
        Store tailX[1] = 3, tailY[1] = 5 in prev2X, prev2Y
        Update tailX[1] = 4, tailY[1] = 5 (prevX, prevY)
        Update prevX = 3, prevY = 5 (prev2X, prev2Y)
    Step 4: For i = 2:
        Store tailX[2] = 2, tailY[2] = 5 in prev2X, prev2Y
        Update tailX[2] = 3, tailY[2] = 5 (prevX, prevY)
        Update prevX = 2, prevY = 5 (prev2X, prev2Y)

    Final state:
    Head (x, y) = (6, 5)
    Tail: [(5, 5), (4, 5), (3, 5)]
    */

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    // Check for wall collision
    if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
        gameOver = 1;

    // Check for tail collision
    for (i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;

    // Check for fruit collision
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        // Generate new fruit position that's not on the snake
        int validPosition = 0;
        while (!validPosition)
        {
            validPosition = 1;
            fruitX = rand() % WIDTH;
            fruitY = rand() % HEIGHT;

            // Check if fruit position conflicts with snake
            if (x == fruitX && y == fruitY)
            {
                validPosition = 0;
                continue;
            }

            for (i = 0; i < nTail; i++)
            {
                if (tailX[i] == fruitX && tailY[i] == fruitY)
                {
                    validPosition = 0;
                    break;
                }
            }
        }
        nTail++;
    }
}

void getPlayerName()
{
    ClearScreen();
    showCursor();
    printf("Welcome to the Snake Game!\n");
    printf("Please enter your name: ");
    fgets(playerName, MAX_NAME_LENGTH, stdin);

    // Remove newline character if present
    size_t len = strlen(playerName);
    if (len > 0 && playerName[len - 1] == '\n')
    {
        playerName[len - 1] = '\0';
    }

    hideCursor();
}

int main()
{
    // Set console title
    SetConsoleTitle("Enhanced Snake Game");

    // Seed random number generator (keep gen rand nums)
    srand(time(NULL));

    // Get player name
    getPlayerName();

    // Clear the screen once at the beginning
    ClearScreen();

    // Hide the cursor for better visuals during gameplay
    hideCursor();

    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(80); // Adjusted sleep time for better game speed
    }

    // Show the final state of the snake before game over message
    Draw(); // Draw the final state one last time

    // Display game over message overlay
    gotoxy(WIDTH / 2 - 5, HEIGHT / 2);
    printf("GAME OVER!");
    gotoxy(WIDTH / 2 - 10, HEIGHT / 2 + 1);
    printf("Your final score: %d", score);
    gotoxy(0, HEIGHT + 5);

    // Wait for key press before exiting
    printf("\nPress any key to exit...");
    _getch();

    return 0;
}
