char* restoreString(char *s, int *indices, int indicesSize)
{
    char tc;
    int ti;
    for (int i = 0; i < indicesSize; ) {
        if (i == indices[i])
            i++;
        else {
            tc = s[i];
            s[i] = s[indices[i]];
            s[indices[i]] = tc;
            ti = indices[i];
            indices[i] = indices[ti];
            indices[ti] = ti;
        }
    }
    return s;
}
