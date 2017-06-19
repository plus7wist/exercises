#include <bits/stdc++.h>

/**
 * delete p 
 * 當 p 是 nullptr，這是一種正確的行爲：當然什麼都不做；
 * 當 p 指向局部變量，或者某個已經被釋放內存的地址，行爲是未定義的。
 **/

void test()
{
    const int *ptr_const_int = new const int(12);
    int *ptr_int = new (std::nothrow) int(21);
    delete ptr_const_int;
    delete ptr_int;
}

namespace task1
{
    using vector = std::vector<int>;

    vector* new_vector() {
        return new vector();
    }

    void input(vector* ptr) {
        std::istream_iterator<int> cin_iter(std::cin), eof;
        std::copy(cin_iter, eof, std::back_inserter<vector>(*ptr));
    }

    void output(std::vector<int>* ptr) {
        std::ostream_iterator<int> cout_iter(std::cout, " ");
        std::copy(ptr->begin(), ptr->end(), cout_iter);
        std::cout << std::endl;
    }

    void test() {
        auto ptr = new_vector();
        input(ptr);
        output(ptr);
        delete ptr;
    }
}

namespace task2
{
    using vector = std::vector<int>;
    using vector_ptr = std::shared_ptr<vector>;

    void delete_vector(vector* ptr) {
        std::cout << "delete vector\n";
        delete ptr;
    }

    vector_ptr new_vector() {
        vector *v = new vector();
        std::shared_ptr<vector> ptr(v, delete_vector);
        return ptr;
    }

    void input(vector_ptr ptr) {
        std::istream_iterator<int> cin_iter(std::cin), eof;
        std::copy(cin_iter, eof, std::back_inserter<vector>(*ptr));
    }

    void output(vector_ptr ptr) {
        std::ostream_iterator<int> cout_iter(std::cout, " ");
        std::copy(ptr->begin(), ptr->end(), cout_iter);
        std::cout << std::endl;
    }

    void test() {
        auto ptr = new_vector();
        input(ptr);
        output(ptr);
    }
}

int main()
{
    // task1::test();
    task2::test();
    return 0;
}
