#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double calc(char *op, double *args)
{
    if (strcmp(op, "+") == 0) {
        return args[0] + args[1];
    }
    if (strcmp(op, "-") == 0) {
        return args[0] - args[1];
    }
    if (strcmp(op, "*") == 0) {
        return args[0] * args[1];
    }
    if (strcmp(op, "/") == 0) {
        return args[0] / args[1];
    }
    if (strcmp(op, "sqrt") == 0) {
        return sqrt(args[0]);
    }
    if (strcmp(op, "log10") == 0) {
        return log10(args[0]);
    }
    return 0;
}

char *next(char **s)
{
    char *orig = *s;
    while (**s != ' ' && **s != '\n')
    {
        ++(*s);
    }
    **s = '\0';
    ++(*s);
    return orig;
}

int main()
{
    FILE *in = fopen("input.csv", "r");
    FILE *out = fopen("output_clang.csv", "w");

    size_t len;
    char *line = NULL;

    while (getline(&line, &len, in) != -1)
    {
        char *op = next(&line);
        size_t arg_size = strtoul(next(&line), NULL, 10);

        double *args = malloc(arg_size * sizeof(double));
        for (int i = 0; i < arg_size; ++i)
        {
            args[i] = strtod(next(&line), NULL);
        }

        line = NULL;

        double c = calc(op, args);
        fprintf(out, "%.100f\n", c);

        free(args);
    }

    fclose(in);
    fclose(out);

    return 0;
}