#include <bits/stdc++.h>

int main()
{
    const int n = 10;
    std::allocator<std::string> alloc_string;
    auto const string_set_begin = alloc_string.allocate(n);
    auto const string_set_end = string_set_begin + n;
    auto now = string_set_begin;
    std::string buffer;
    for (; std::cin >> buffer && now != string_set_end; )
    {
        std::cout << "construct\n";
        alloc_string.construct(now++, buffer);
    }
    const size_t size = now - string_set_begin;
    std::cout << size << " strings\n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << "destroy " << *(string_set_begin + i) << std::endl;
        alloc_string.destroy(string_set_begin + i);
    }
    alloc_string.deallocate(string_set_begin, n);
    return 0;
}
