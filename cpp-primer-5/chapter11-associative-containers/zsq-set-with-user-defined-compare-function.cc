#include <bits/stdc++.h>

struct BigInteger
{
    uint64_t upper;
    uint64_t lower;

    explicit BigInteger(uint64_t upper, uint64_t lower)
    {
        this->upper = upper;
        this->lower = lower;
    }
};

bool big_integer_lesser(const BigInteger& fst, const BigInteger& snd)
{
    if (fst.upper == snd.upper) {
        return fst.lower < snd.lower;
    }
    return fst.upper < snd.upper;
}

int main()
{
    std::multiset<BigInteger, std::function<bool(const BigInteger&, const
            BigInteger)>> number_set(big_integer_lesser);
    number_set.insert(BigInteger(12, 3));
    number_set.insert(BigInteger(2, 13));
    number_set.insert(BigInteger(12, 0));
    number_set.insert(BigInteger(1, 13));
    for (auto& b: number_set) {
        std::cout << b.upper << " " << b.lower << std::endl;
    }
    return 0;
}
