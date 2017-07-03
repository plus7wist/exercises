#include <bits/stdc++.h>

struct matrix_base
{
    using value_type = int;
    using size_type = size_t;

    std::unique_ptr<value_type[]> _data;

    virtual value_type& operator()(size_type i, size_type j) = 0;
    virtual const value_type& operator()(size_type i, size_type j) const = 0;
};

struct matrix: matrix_base
{
    int _row;
    int _col;

    matrix(int row, int col)
        : _row(row), _col(col), _data(new value_type[row * col])
    {
    }

    matrix(const matrix& mat)
    {
        _row = mat._row;
        _col = mat._col;
        _data = new value_type[_row * _col];
        memcpy(_data.get(), mat._data.get(), sizeof(value_type) * _row * _col);
    }

    matrix operator=(const matrix& mat)
    {
        if (this != &mat) {
            _row = mat._row;
            _col = mat._col;
            _data = new value_type[_row * _col];
        }
        return *this;
    }

    matrix(matrix&& mat)
    {
        _row = mat._row;
        _col = mat._col;
        _data = mat._data.release();
    }

    matrix operator=(matrix&& mat)
    {
        if (this != &mat) {
            _row = mat._row;
            _col = mat._col;
            _data = mat._data.release();
        }
        return *this;
    }
};

int main()
{
    return 0;
}
