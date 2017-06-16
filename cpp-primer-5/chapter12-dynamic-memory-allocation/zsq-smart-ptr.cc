#include <bits/stdc++.h>

struct Point
{
    int x;
    int y;

    Point(int _x, int _y) {
        x = _x;
        y = _y;
        std::cerr << ">> " << __func__ << std::endl;
    }

    ~Point() {
        std::cerr << ">> " << __func__ << std::endl;
    }
};

int main()
{
    std::cerr << std::string(20, '=') << std::endl;
    {
        std::shared_ptr<Point> p_point = std::make_shared<Point>(12, 3);
        std::cout << p_point->x << " " << p_point->y << std::endl;
    }
    std::cerr << std::string(20, '=') << std::endl;
    {
        auto get_point_ptr = []() {
            std::cerr << ">> line = " << __LINE__ << std::endl;
            auto ptr = std::make_shared<Point>(3, 2);
            std::cerr << ">> line = " << __LINE__ << std::endl;
            return ptr;
        };
        std::cerr << ">> line = " << __LINE__ << std::endl;
        auto ptr_point = get_point_ptr();
        std::cerr << ">> line = " << __LINE__ << std::endl;
    }
    std::cerr << std::string(20, '=') << std::endl;
    return 0;
}
