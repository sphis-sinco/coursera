#include <stdio.h>
#include <stdlib.h>

// FILE READING. WHAT.

int main() {
    FILE *file;
    float weight;
    float total = 0.0;
    int count = 0;

    file = fopen("elephant_seal_data.txt", "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return 1;
    }

    // Read each number from the file and add it to the total
    while (fscanf(file, "%f", &weight) == 1) {
        total += weight;
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No data found.\n");
        return 1;
    }

    float average = total / count;
    printf("A total of %d elephant seals were recorded.\n", count);
    printf("Average weight of the elephant seals: %.2f kg\n", average);

    return 0;
}
