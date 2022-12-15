#include "main.h"

int shl_exit(shl_t *data)
{
    int exit_num;

    if (data->argv[1])
    {
        exit_num = _erratoi(data->argv[1]);
        if (exit_num == -1)
        {
            data->status = 2;
            print_error(data, "Denied");
            _eputs(data->argv[1]);
            _eputchar('\n');
            return (1);
        }
        data->err_num = _erratoi(data->argv[1]);
        return (-2);
    }
    data->err_num = -1;
    return (-2);
}
int main(void)
{
    shl_t *data;

    shl_exit(data);

    return 0;
}