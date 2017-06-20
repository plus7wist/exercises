#include <bits/stdc++.h>

namespace _13_14 {

        struct Numbered {
                int id;

                Numbered() {
                        static int count = 0;
                        id = ++count;
                }
        };

        void f(Numbered n) {
                std::cout << n.id << std::endl;
        }

        void test() {
                Numbered a, b = a, c = b;
                f(a); f(b); f(c);
                // 使用了默認的合成拷貝，所以 b c 的 id 都拷貝自 a，三個 f
                // 都輸出 1
        }
}

namespace _13_15 {

        struct Numbered {

                int id;
                static int count;

                Numbered() {
                        id = ++count;
                }

                Numbered(const Numbered& n) {
                        id = ++count;
                }
        };

        int Numbered::count = 0;

        void f(Numbered n) {
                std::cout << n.id << std::endl;
        }

        void test() {
                Numbered a, b = a, c = b;
                f(a); f(b); f(c);
                // 正確實現了 Numbered，但是 f 的傳參使用了值拷貝，這導致輸出是
                // 4 5 6 而不是 1 2 3 
        }
}

namespace _13_16 {

        struct Numbered {

                int id;
                static int count;

                Numbered() {
                        id = ++count;
                }

                Numbered(const Numbered& n) {
                        id = ++count;
                }
        };

        int Numbered::count = 0;

        void f(const Numbered& n) {
                std::cout << n.id << std::endl;
        }

        void test() {
                Numbered a, b = a, c = b;
                f(a); f(b); f(c);
                // 輸出 1 2 3
        }
}

int main() {
        // _13_14::test();
        // _13_15::test();
        _13_16::test();
        return 0;
}

