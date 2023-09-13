
// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define SENTENCE_LEN 81
#define DEBUG 0   // set to 0 to disable debug output

// reads words from the file
// into wl and trims the whitespace off of the end of each word
// DO NOT MODIFY THIS Prototype
int readWords(char* wl[MAXWORDS], char* filename);

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS Prototype
void trimws(char* s);

int drawWords(char* wl[MAXWORDS], int numWords);

int addSent(char sentence[SENTENCE_LEN], char add[WORDLEN]);

int main(int argc, char* argv[])
{
	char* wordlist[MAXWORDS];
	int wordCount;
	int i;

	wordCount = readWords(wordlist, argv[1]);

	if (DEBUG)
	{
		printf("Read %d words from %s \n", wordCount, argv[1]);
		// add code to print the words to the screen here for part 1 
		for (i = 0; i < wordCount; i++)
		{
			printf("%s\n", wordlist[i]);
		}
	}

	// most of your code for part 2 goes here. Don't forget to include the ncurses library 

	int t, tri, cir, x, sq;
	int rb, lb, bb;
	int lx, ly, rx, ry;

	initscr();
	refresh();

	char sent[81] = "";
	int capNext = 0;
	int curAt = 0;

	int changed = 0;

	mvaddch(0, 0, '*');
	int row = drawWords(wordlist, wordCount);
	int lastMov = 0;

	int undo[80] = { 0 };
	int undoAt = 0;

	/*
	The position of the cursor is determined by the spot in the array. Moving the joystick sideways moves
	the position forward or backwards 1, if there is an element in the array in that direction. Moving
	the joystick up or down moves the spot forward or bakwards 5 since each line contains 5 elements.
	this is a logical way to move the cursor since it appears to move the cursor in the direction of the joystick.
	*/

	do
	{
		scanf("%d, %d,%d,%d,%d, %d,%d,%d,%d,%d,%d,%d,%d, %d, %d, %d, %d", &t, &tri, &cir, &x, &sq, &rb, &lb, &bb, &bb, &bb, &bb, &bb, &bb, &lx, &ly, &rx, &ry);

		int oldAt = curAt;

		if (0 == changed)
		{
			changed = 1;

			if (1 == tri)
			{
				int added = addSent(sent, " ");
				if (added > 0)
				{
					undo[undoAt] = added;
					undoAt++;
				}
			}
			else if (1 == cir)
			{
				capNext = 1;
			}
			else if (1 == x)
			{
				if (undoAt > 0)
				{
					sent[strlen(sent) - undo[undoAt - 1]] = '\0';
					undoAt--;
				}
			}
			else if (1 == sq)
			{
				if (1 == capNext)
				{
					wordlist[curAt][0] = toupper(wordlist[curAt][0]);
					int added = addSent(sent, wordlist[curAt]);
					if (added > 0)
					{
						undo[undoAt] = added;
						undoAt++;
					}
					wordlist[curAt][0] = tolower(wordlist[curAt][0]);
					capNext = 0;
				}
				else
				{
					int added = addSent(sent, wordlist[curAt]);
					if (added > 0)
					{
						undo[undoAt] = added;
						undoAt++;
					}
					undoAt++;
				}
			}
			else if (1 == lb)
			{
				sent[0] = '\0';
			}
			else
			{
				changed = 0;
			}
		}
		else if (0 == tri && 0 == sq && 0 == x && 0 == lb)
		{
			changed = 0;
		}

		if (t - lastMov > 500)
		{
			lastMov = t;
			if (lx > 100)
			{
				if (curAt < wordCount - 1)
				{
					curAt++;
					changed = 1;
				}
			}
			else if (lx < -100)
			{
				if (curAt > 0)
				{
					curAt--;
					changed = 1;
				}
			}
			else if (ly > 100)
			{
				if (curAt < wordCount - 6)
				{
					curAt += 5;
					changed = 1;
				}
			}
			else if (ly < -100)
			{
				if (curAt > 4)
				{
					curAt -= 5;
					changed = 1;
				}
			}
			else
			{
				t = 0;
			}
		}
		else if (lx > -100 && lx < 100 && ly > -100 && ly < 100)
		{
			t = 0;
		}

		if (1 == changed)
		{
			mvprintw(row, 0, "%s", "                                                                                ");
			mvprintw(row, 0, "%s", sent);

			if (oldAt != curAt)
			{
				mvaddch(oldAt / 5, (oldAt % 5) * 15, ' ');
				mvaddch(curAt / 5, (curAt % 5) * 15, '*');
			}

			refresh();
		}
	} while (1);

	return 0;
}

int addSent(char sentence[SENTENCE_LEN], char add[WORDLEN])
{
	if (strlen(sentence) + strlen(add) < SENTENCE_LEN - 1)
	{
		strcat(sentence, add);
		return strlen(add);
	}

	return 0;
}

int drawWords(char* wl[MAXWORDS], int numWords)
{
	int at = 0;
	while (at < numWords)
	{
		mvprintw(at / 5, (at % 5) * 15 + 1, "%s", wl[at]);
		at++;
	}
	refresh();

	return at / 5 + 1;
}

/*
This scans a word from the file and stores it in a buffer. Each time it reads a word, it removes any white space at the end then adds it to
the list of words. To add it to the list of words, it allocates memory for the length of the string plus 1 for the null
character. The buffer string is then copied into the memory spot allocated in the word list.
Getting use to allocating memory and how that works took a while to figure out and understand.
*/
int readWords(char* wl[MAXWORDS], char* filename)
{
	FILE* f = fopen(filename, "r");
	int at = 0;
	char buf[WORDLEN];
	while (1 == fscanf(f, "%s", buf))
	{
		trimws(buf);
		wl[at] = malloc(strlen(buf) + 1);
		strcpy(wl[at], buf);
		at++;
	}

	return at;
}

void trimws(char* s)
{
	int len = strlen(s);

	int i = len - 1;
	while (0 <= i && 1 == isspace(s[i]))
	{
		s[i] = '\0';
		i--;
	}
}

