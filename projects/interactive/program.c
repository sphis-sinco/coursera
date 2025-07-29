#include <stdio.h>

void gameLoop();

void cmd(char *command)
{
        printf(command);
}

int main(void)
{

        int running = 1;

        gameLoop();

        return 0;
}

void gameLoop()
{
        char command[100] = "";
        int recognized_command = 0;

        printf("Input your command (lowercase only!): ");
        scanf("%d", &command);

        if (command == "help")
                recognized_command = 1;

        if (recognized_command)
        {
                cmd(command);
                recognized_command = 0;
        }
        else
        {
                gameLoop();
        }
}