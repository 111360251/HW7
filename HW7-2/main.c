#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
	const char *face;
	const char *suit;
};
typedef struct card Card;
void fd(Card * const wdeck, const char * wface[], const char * wsuit[]);
void s(Card * const wdeck);
void d(const Card * const wdeck);
int main()
{
	Card deck[52];
	const char *face[] = { "ACE", "Deuce", "There", "Four",
	 "Five", "Six", "Seven", "Eight",
	 "Nine", "Ten", "Jack", "Queen", "King" };

	const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	srand(time(NULL));
	fd(deck, face, suit);
	s(deck);
	d(deck);
	system("pause");
	return 0;
}

void fd(Card * const wdeck, const char * wface[], const char * wsuit[])
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		wdeck[i].face = wface[i % 13];
		wdeck[i].suit = wsuit[i / 13];
	}
}
void s(Card * const wdeck)
{
	int i;
	int j;
	Card temp;
	for (i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		temp = wdeck[i];
		wdeck[i] = wdeck[j];
		wdeck[j] = temp;
	}
}
void d(const Card * const wdeck)
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		printf("%5s of %-8s%s", wdeck[i].face, wdeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}
}

