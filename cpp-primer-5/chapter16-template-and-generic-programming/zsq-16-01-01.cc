#include <bits/stdc++.h>

template<size_t N, size_t M>
int compare(const char (&str1)[N], const char (&str2)[M])
{
    return strcmp(str1, str2);
}

template<typename T>
int compare(const T &fst, const T &snd)
{
    if (std::less<T>(fst, snd))
    {
        return -1;
    }
    if (std::less<T>(snd, fst))
    {
        return 1;
    }
    return 0;
}


