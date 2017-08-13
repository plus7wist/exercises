#include <stdio.h>
#include <string.h>

int min(int lhs, int rhs)
{
    if (lhs > rhs)
    {
        return rhs;
    }
    return lhs;
}

void string_copy_n(char dst[], const char src[], int n)
{
    int i, m;
    m = min(strlen(src), n);
    for (i = 0; i < m; ++i)
    {
        dst[i] = src[i];
    }
    for (i = m; i < n; ++i)
    {
        dst[i] = '\0';
    }
}

int main()
{
    char buffer[12];
    int i;
    
    string_copy_n(buffer, "hello", 12);
    for (i = 0; i < 12; ++i)
    {
        printf("%d %c\n", (int) buffer[i], buffer[i]);
    }
    return 0;
}

/*
104 h
101 e
108 l
108 l
111 o
0 
0 
0 
0 
0 
0 
0 
*/
