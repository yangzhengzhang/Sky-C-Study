#include <stdio.h>
#include <stdlib.h>
#include "bridge.h"

int main(void)
{
    CardList list;
    initList(&list);
    insertCard(list);
    Traverse(&list);
    printf("H");
    return 0;
}
