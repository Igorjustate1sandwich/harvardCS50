#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;     // where argc = num of arguments passed. Do -1 to remove the initial ./runoff command.
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            printf("Tie detected. \n");
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Compare string name with names in candidates[]
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Update preferences array to add candidate name as rank preference
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int preference = 0;

    for (int voter = 0; voter < voter_count; voter++)
    {
        // For the first voter, check his first preference (e.g. Alice)
        int pref = preferences[voter][preference];

        // If this candidate has not been eliminated...
        if (candidates[pref].eliminated == false)
        {
            // ...add a vote for his first preference candidate (Alice)
            candidates[pref].votes += 1;
        }

        // Otherwise, go to their next candidate preference and give them a vote instead
        else if (candidates[pref].eliminated == true)
        {
            int next_pref = preferences[voter][preference+1];

            // Again, check if the next candidate preference has also not been eliminated
            if (candidates[next_pref].eliminated == false)
            {
                candidates[next_pref].votes += 1;
            }
        }

        // Go to second voter and repeat.
    }
    preference++;
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Check if a candidates vote count is greater than half of the total votes
    for (int i = 0; i < candidate_count; i++)
    {
        int average = voter_count/2;
        if (candidates[i].votes > average)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Find the minimum number of votes any existing candidate has
    int minval = candidates[0].votes;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < minval && candidates[i].eliminated == false)
        {
            printf("min = %s with %i votes \n", candidates[i].name, candidates[i].votes);
            minval = candidates[i].votes;
        }
    }
    return minval;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int isTied = 0;

    // Loop through all remaining candidates and check whether their votes == min
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate is in the race but their votes are not equal to other candidates, then QUIT as there is no tie.
        if (candidates[i].votes != min && candidates[i].eliminated == false)
        {
            return false;
        }
        // Otherwise if candidate is in the race and their votes are equal to other candidates set isTied to 1.
        else if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            isTied = 1;
        }
    }

    if (isTied == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidiates) in last place
void eliminate(int min)
{
    // If any candidate has votes == min, set eliminated = true
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
