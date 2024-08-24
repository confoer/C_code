int findPermutationDifference(char *s, char *t)
{
    int x = 0;
    int lens = strlen(s);
    int lent = strlen(t);
    int index[lent];
    for (int i = 0; i < lent; i++)
    {
        index[i] = -1;
    }
    for (int i = 0; i < lent; i++)
    {
        index[i] = strchr(t, s[i]) - t;
    }
    for (int i = 0; i < lens; i++)
    {
        int j = index[strchr(t, s[i]) - t];
        if (j != -1)
        {
            x += abs(i - j);
            index[j] = -1;
        }
    }
    return x;
}