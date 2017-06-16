#ifndef _STRING_BLOB_
#define _STRING_BLOB_

struct StringBlob
{
    using string_set = std::vector<std::string>;
    using size_type = string_set::size_type;

    std::shared_ptr<string_set> _ptr;

    StringBlob(std::initializer_list<std::string> strings) {
        _ptr = std::make_shared<string_set>(strings);
    }

    size_type size() const { return _ptr->size(); }

    bool empty() const { return _ptr->empty(); }

    void push_back(const std::string &str) { _ptr->push_back(str); }
    
    void pop_back() {
        _check(0, "pop_back on empty StringBlob");
        _ptr->pop_back();
    }

    std::string& front() {
        _check(0, "front on empty StringBlob");
        return _ptr->front();
    }

    const std::string& front() const {
        _check(0, "front on empty StringBlob");
        return _ptr->front();
    }

    std::string& back() {
        _check(0, "back on empty StringBlob");
        return _ptr->back();
    }

    const std::string& back() const {
        _check(0, "back on empty StringBlob");
        return _ptr->back();
    }

    void _check(size_type i, const std::string &msg) const {
        // it is not necessary to check if i >= 0
        // for i must be a unsigned values
        if (i >= (_ptr->size())) {
            throw std::domain_error(msg);
        }
    }
};

#endif
