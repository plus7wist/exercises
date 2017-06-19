#ifndef _STRING_BLOB_
#define _STRING_BLOB_

struct StringBlobBase
{
    using string_set = std::vector<std::string>;
    using size_type = string_set::size_type;
};

struct StringBlob : virtual StringBlobBase
{
    std::shared_ptr<string_set> _ptr;

    StringBlob(std::initializer_list<std::string> strings)
    {
        _ptr = std::make_shared<string_set>(strings);
    }

    size_type size() const
    {
        return _ptr->size();
    }

    bool empty() const
    {
        return _ptr->empty();
    }

    void push_back(const std::string& str)
    {
        _ptr->push_back(str);
    }

    void pop_back()
    {
        _check(0, "pop_back on empty StringBlob");
        _ptr->pop_back();
    }

    std::string& front()
    {
        _check(0, "front on empty StringBlob");
        return _ptr->front();
    }

    const std::string& front() const
    {
        _check(0, "front on empty StringBlob");
        return _ptr->front();
    }

    std::string& back()
    {
        _check(0, "back on empty StringBlob");
        return _ptr->back();
    }

    const std::string& back() const
    {
        _check(0, "back on empty StringBlob");
        return _ptr->back();
    }

    void _check(size_type i, const std::string& msg) const
    {
        // it is not necessary to check if i >= 0
        // for i must be a unsigned values
        if (i >= (_ptr->size()))
        {
            throw std::out_of_range(msg);
        }
    }
};

struct StringBlobPtr : StringBlobBase
{
    std::weak_ptr<string_set> wptr;
    size_type cur;

    StringBlobPtr() : cur(0)
    {
        // pass
    }

    StringBlobPtr(StringBolb& a, size_type sz = 0U)
        : wptr(a.data) , cur(sz)
    {
        // pass
    }

    const std::string& deref() const
    {
        auto p = check(cur, "dereference past end");
        return (*p)[cur];
    }

    StrBlobPtr& inc_left()
    {
        check(cur, "increment past end of StringBlobPtr");
        ++cur;
        return *this;
    }

    std::shared_ptr<string_set> check(size_type, const std::string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
        {
            throw std::runtime_error("unbound StringBlobPtr");
        }
        if (i > (ret->size()))
        {
            throw std::out_of_range(msg);
        }
        return ret;
    }
};

#endif
