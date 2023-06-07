#include <stdio.h>
#include <stdlib.h>
#include "error_handling.h"

void handleError(const char *errorMessage)
{
    fprintf(stderr, "Blad: %s\n", errorMessage);
    exit(1);
}
