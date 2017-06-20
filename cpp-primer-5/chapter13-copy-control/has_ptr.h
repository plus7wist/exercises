#ifndef _HAS_PTR_
#define _HAS_PTR_

#include <bits/stdc++.h>

struct HasPtr {

        std::string *pstring;
        std::size_t *use;
        int i;

        HasPtr(const std::string& s = std::string()) : pstring(new
                        std::string(s)), use(new std::size_t(1)), i(0) {
        }

        HasPtr(const HasPtr& p) : pstring(p.pstring), i(p.i), use(p.use) {
                ++(*use);
        }

        std::string& get_string() const {
                return *pstring;
        }

        ~HasPtr() {
                std::cerr << "deconstruct\n";
                if (--(*use) == 0) {
                        std::cerr << "deleted\n";

                        delete pstring;
                        delete use;
                }
        }
};

#endif
