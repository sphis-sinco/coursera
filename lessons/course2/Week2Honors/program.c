#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 7
#define SIMULATIONS 1000000

typedef enum
{
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
} Suit;

typedef struct
{
        Suit suit;
        short pips; // 2 to 14
} Card;

void initDeck(Card deck[])
{
        int index = 0;
        for (int s = 0; s < 4; s++)
        {
                for (int p = 2; p <= 14; p++)
                {
                        deck[index].suit = (Suit)s;
                        deck[index].pips = p;
                        index++;
                }
        }
}

void shuffleDeck(Card deck[])
{
        for (int i = DECK_SIZE - 1; i > 0; i--)
        {
                int j = rand() % (i + 1);
                Card temp = deck[i];
                deck[i] = deck[j];
                deck[j] = temp;
        }
}

void countRanks(Card hand[], int rankCount[])
{
        for (int i = 0; i < HAND_SIZE; i++)
        {
                rankCount[hand[i].pips]++;
        }
}

int evaluateHand(Card hand[])
{
        int rankCount[15] = {0}; // 2 through 14
        countRanks(hand, rankCount);

        int pairs = 0, trips = 0, quads = 0;

        for (int i = 2; i <= 14; i++)
        {
                if (rankCount[i] == 4)
                        quads++;
                else if (rankCount[i] == 3)
                        trips++;
                else if (rankCount[i] == 2)
                        pairs++;
        }

        if (quads)
                return 5; // Four of a kind
        if (trips && pairs)
                return 4; // Full house
        if (trips)
                return 3; // Three of a kind
        if (pairs == 2)
                return 2; // Two pair
        if (pairs == 1)
                return 1; // One pair
        return 0;         // No pair (Ace high or less)
}

int main()
{
        srand((unsigned int)time(NULL));

        Card deck[DECK_SIZE];
        Card hand[HAND_SIZE];
        long counts[6] = {0}; // 0=no pair, 1=pair, ..., 5=four of a kind

        // Simulate
        for (int sim = 0; sim < SIMULATIONS; sim++)
        {
                initDeck(deck);
                shuffleDeck(deck);

                for (int i = 0; i < HAND_SIZE; i++)
                {
                        hand[i] = deck[i];
                }

                int result = evaluateHand(hand);
                counts[result]++;
        }

        // Official probabilities from table
        double official[6] = {
            0.17411920, // Ace high or less (no pair)
            0.43822546, // One pair
            0.23495536, // Two pair
            0.04829870, // Three of a kind
            0.02596102, // Full house
            0.00168067  // Four of a kind
        };

        const char *handNames[] = {
            "Ace high or less", "One Pair", "Two Pair",
            "Three of a Kind", "Full House", "Four of a Kind"};

        printf("Monte Carlo Simulation of %d 7-card hands:\n\n", SIMULATIONS);
        printf("%-18s | %-12s | %-12s | %-8s\n", "Hand", "Simulated %", "Official %", "Error %");
        printf("--------------------+--------------+--------------+----------\n");

        for (int i = 0; i < 6; i++)
        {
                double sim_prob = (double)counts[i] / SIMULATIONS;
                double error = (sim_prob - official[i]);
                printf("%-18s | %11.5f%% | %11.5f%% | %+7.3f%%\n",
                       handNames[i], 100.0 * sim_prob, 100.0 * official[i], 100.0 * error);
        }

        return 0;
}
