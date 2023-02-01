char* decodeMessage(char* key, char* message)
{
    char cur = 'a', mapping[26] = { 0 };
    for (int i = 0; key[i]; i++)
        if (key[i] != ' ' && !mapping[key[i] - 'a'])
            mapping[key[i] - 'a'] = cur++;
    for (int i = 0; message[i]; i++)
        if (message[i] != ' ')
            message[i] = mapping[message[i] - 'a'];
    return message;
}
