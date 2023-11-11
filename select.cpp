#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    initscr();                       // Initialize the screen
    start_color();                    // Initialize the color support
    curs_set(0);                       // Make the cursor invisible
    keypad(stdscr, TRUE);              // Enable special keys like F1, F2, arrow keys etc.
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    int choice = 0;
    int highlight = 1;
    int x = 15;
    int y = 5;
    char ch;

    while (1)
    {
        clear();
        attron(COLOR_PAIR(1));

        mvprintw(y, x, "Option 1"); y++;
        mvprintw(y, x, "Option 2"); y++;
        mvprintw(y, x, "Option 3"); y++;
        mvprintw(y, x, "Option 4"); y++;

        mvprintw(choice+5, x-5, "->");

        refresh();

        ch = getch();

        if (ch == KEY_DOWN)
        {
            if (highlight < 4)
            {
                highlight++;
                choice++;
            }
        }
        else if (ch == KEY_UP)
        {
            if (highlight > 1)
            {
                highlight--;
                choice--;
            }
        }
        else if (ch == KEY_ENTER || ch == 10)
        {
            break;
        }
    }

    endwin();                         // End the ncurses session
    clear();                          // Clear the terminal

    switch (choice)
    {
        case 0:
            printw("You selected Option 1.\n");
            break;
        case 1:
            printw("You selected Option 2.\n");
            break;
        case 2:
            printw("You selected Option 3.\n");
            break;
        case 3:
            printw("You selected Option 4.\n");
            break;
    }

    refresh();                         // Refresh the terminal
    getch();                           // Wait for a key press

    return 0;
}