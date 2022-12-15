#include "main.h"

int shl_help(shl_t *data)
{
    int i;

    _puts("Ayobami and David shell help page\n");

    _puts("Please use the man command for more info\n");

    return (0);
}

int main(void)
{
    shl_t *data;

    shl_help(data);

    return 0;
}
