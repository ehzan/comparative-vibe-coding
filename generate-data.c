#include <stdio.h>
#include <stdlib.h>

/* Function to generate random numbers and store them in a file */
void generate_numbers(const char *filename, const int n, const char *type)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    double random_number;
    for (int i = 0; i < n; i++)
    {
        random_number = rand() + (double)rand() / (RAND_MAX + 1.0);
        if (rand() % 2 == 0)
            random_number = -random_number;

        if (type == "int" || type == "integer")
            fprintf(file, "%d\n", (int)random_number);
        else
            fprintf(file, "%f\n", random_number);
    }

    fclose(file);
    printf("%d %s numbers successfully stored in '%s'\n", n, type, filename);
}

int main()
{
    generate_numbers("data/integers_100.txt", 100, "int");
    generate_numbers("data/integers_100k.txt", 100000, "int");
    // generate_numbers("data/integers_1m.txt", 1000000, "int");
    generate_numbers("data/real_numbers_100.txt", 100, "real");
    generate_numbers("data/real_numbers_100k.txt", 100000, "real");
    // generate_numbers("data/real_numbers_1m.txt", 1000000, "real");

    return 0;
}