//完成十进制，向二进制的转换
int itoa_bin(unsigned int data, char *str) {
    if (str == NULL)
        return -1;

    char *start = str;

    while (data) {
        if (data & 0x1)
            *str++ = 0x31;
        else
            *str++ = 0x30;

        data >>= 1;
    }

    *str = 0;

    //reverse the order
    char *low, *high, temp;
    low = start, high = str - 1;

    while (low < high) {
        temp = *low;
        *low = *high;
        *high = temp;

        ++low;
        --high;
    }

    return 0;
}