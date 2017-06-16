#include <bits/stdc++.h>
#include "string_blob.h"

int main()
{
    StringBlob fst_blob = {"fox", "quick", "static"};
    StringBlob snd_blob = fst_blob;
    snd_blob.push_back("alice");
    std::cout << fst_blob.size() << " " << snd_blob.size() << std::endl;
    return 0;
}
