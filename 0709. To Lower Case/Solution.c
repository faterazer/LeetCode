char* toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = 'a' + str[i] - 'A';
    }
    return str;
}
