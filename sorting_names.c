#include <stdio.h>
#include <string.h>

#define NUM_NAMES 20
#define MAX_NAME_LENGTH 100

void bubbleSort(char names[][MAX_NAME_LENGTH], int n, int ascending);


/**
 * main - provides list and call bubble sort function
 *
 * Return: 0 on success
 */
int main(void)
{
    char names[NUM_NAMES][MAX_NAME_LENGTH] = {
        "Alice Johnson", "Bob Smith", "Charlie Brown", "David Wilson",
        "Eve Davis", "Frank Miller", "Grace Lee", "Hank Moore",
        "Ivy Taylor", "Jack Anderson", "Karen Thomas", "Larry Harris",
        "Mona Clark", "Nancy Lewis", "Oscar Walker", "Paul Hall",
        "Quincy Allen", "Rachel Young", "Sam King", "Tina Scott"
    };
    char order[5];
    int ascending;

    // Get the desired order from the user
    printf("Enter 'asc' for ascending or 'desc' for descending order: ");
    scanf("%4s", order);

    if (strcmp(order, "asc") == 0)
    {
        ascending = 1;
    }
    else if (strcmp(order, "desc") == 0)
    {
        ascending = 0;
    }
    else
    {
        printf("Invalid input. Please enter 'asc' or 'desc'.\n");
        return 1;
    }

    bubbleSort(names, NUM_NAMES, ascending);

    printf("Sorted names:\n");
    for (int i = 0; i < NUM_NAMES; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}

/**
 * bubbleSort - sorts list of names by input order
 */
void bubbleSort(char names[][MAX_NAME_LENGTH], int n, int ascending)
{
    int swapped;
    char temp[MAX_NAME_LENGTH];

    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if ((ascending && strcmp(names[j], names[j + 1]) > 0) ||
                (!ascending && strcmp(names[j], names[j + 1]) < 0))
            {
                // Swap names[j] and names[j + 1]
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}
