#include <bits/stdc++.h>

class PrivateCopy {

        public:
                int data;

                PrivateCopy(int _data) {

                        data = _data;
                }
        private:
                PrivateCopy(const PrivateCopy&) = default;
};

int main() {

        PrivateCopy pc(12);

        // PrivateCopy pc_cloned = pc;
        // error

        std::cout << pc.data << std::endl;

        return 0;
}
