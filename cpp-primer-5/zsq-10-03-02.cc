#include "local_util.h"

void biggies(std::vector<std::string> &words,
        std::vector<std::string>::size_type sz)
{
    std::sort(words.begin(), words.end());
    words.erase(std::unique(words.begin(), words.end()), words.end());
    std::stable_sort(words.begin(), words.end(),
            [](const std::string& fst, const std::string& snd)
            { return fst.size() < snd.size(); });
    auto it = std::find_if(words.begin(), words.end(),
            [sz](const std::string& str)
            { return str.size() >= sz; });
    auto count = words.end() - it;
    std::cout << count << " word(s) of length " << sz << " or no longer " << std::endl;
}

int main()
{
    auto sum2 = [](int fst, int sec) { return fst + sec; };
    std::cout << sum2(12, 2) << std::endl;
    int local_integer = 13;
    auto sum1 = [local_integer](int i) { return local_integer + i; };
    std::cout << sum1(7) << std::endl;
    return 0;
}
