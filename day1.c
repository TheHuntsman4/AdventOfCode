#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char line[200];
    int numberArr[10] = {0};
    int j = 0;
    int sum = 0;
    FILE *inputFile = fopen("input1.txt", "r");

    if (inputFile == NULL)
    {
        perror("Error opening the file");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        for (int i = 0; i < strlen(line); i++)
        {
            if (isdigit(line[i]))
            {
                numberArr[j] = line[i] - '0';
                j = j + 1;
            }
        }
        printf("\n");

        if (j >= 2)
        {
            int number = numberArr[0] * 10 + numberArr[j - 1];
            sum += number;
            printf("%d\n", number);
        }
        else
        {
            int number = numberArr[0] * 10 + numberArr[0];
            sum += number;
            printf("%d\n", number);
        }

        j = 0;
    }

    fclose(inputFile);
    printf("Sum: %d\n", sum);

    return 0;
}
