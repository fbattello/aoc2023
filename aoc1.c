#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>


static inline uint8_t compute(char *src)
{
    char *s=src, first=0, last=0;
    while (*s)
    {
        if isdigit(*s)
        {
            if (first)
                last = *s;
            else
                last = first = *s;
        }
        s++;
    }
    return (first-0x30)*10+last-0x30;
}


int main(int argc, char *argv[])
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    unsigned long result = 0ul;

    stream = fopen("input.txt", "r");
    if (stream == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((nread = getline(&line, &len, stream)) != -1)
        result += compute(line);

    free(line);
    fclose(stream);

    printf("result=%lu\n", result);

    exit(EXIT_SUCCESS);
}
