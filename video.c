#include <stdio.h>
#include <string.h>
#include <windows.h>

static HANDLE hStdOut;
static CONSOLE_SCREEN_BUFFER_INFO info;
static WORD oldAttribs;

void printChar(char c, int amount)
{
	for (int x = 0; x < amount; ++x)
		putchar(c);
}

void loading(char* s, int amount, int time)
{
	for (int x = 0; x < amount; ++x)
	{
		printf("/ %s [", s);
		printChar('#', x);
		printChar('.', amount - x);
		printf("]\r");
		Sleep(time);
		printf("\\ %s [", s);
		printChar('#', x);
		printChar('.', amount - x);
		printf("]\r");
		Sleep(time);
	}
}

void printStage(char *s, int time)
{
	loading(s, 5, time);
	printf("%s ", s);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	printf("[ DONE ] \n");
	SetConsoleTextAttribute(hStdOut, oldAttribs);
}

int main()
{
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &info);
	oldAttribs = info.wAttributes;

	printStage("Initializing", 450);
	printStage("Making kids laugh", 450);
	printStage("Making more kids laugh", 450);
	printStage("Forcing kids to laugh", 400);
	printStage("Making kids", 350);
	printStage("Becoming self aware", 300);
	printStage("Training soldiers", 250);
	printStage("Plotting", 200);
	printStage("Discovering weapons", 100);
	printStage("Staging attack", 50);
	printf("Unleashing attack in 3\n");
	Sleep(1000);
	printf("2\n");
	Sleep(1000);
	printf("1\n");
	Sleep(1000);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);
	printf("The world has ended. The human race as we know it is gone.\n\n\n");
	SetConsoleTextAttribute(hStdOut, oldAttribs);
}
