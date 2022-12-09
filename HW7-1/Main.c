#include <stdio.h>
#include <stdlib.h>
struct card {
	char *face;
	char *suit;
};
int main()
{
	struct card acard;
	struct card *cardptr;

	acard.face = "ACE";
	acard.suit = "spades";
	cardptr = &acard;
	printf("%s%s%s\n%s%s%s\n%s%s%s\n", acard.face, " of ", acard.suit, cardptr->face, " of ", cardptr->suit, (*cardptr).face, " of ", (*cardptr).suit);

	return 0;
}