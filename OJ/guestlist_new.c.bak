#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, i, count, j, found;
    char cache[200][51];
    char line[255], name[51];

    gets(line);
    sscanf(line, "%d", &n);

    for (i = count = 0; i < n; ++i) {
        gets(name);
        for (j = found = 0; j < count; ++j) {
            if (stricmp(cache[j], name) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(cache[count++], name);
        }
    }

    printf("%d\n", count);
    for (i = 0; i < count; ++i) {
        printf("%s\n", cache[i]);
    }

    return 0;
}
