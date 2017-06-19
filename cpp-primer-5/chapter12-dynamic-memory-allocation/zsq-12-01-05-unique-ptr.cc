#include <bits/stdc++.h>

void fstream_deleter(std::fstream *file)
{
    std::cerr << "file closed\n";
    file->close();
}

void echo_file(std::string path_file)
{
    std::fstream file_input(path_file.c_str(), std::ios::in);
    std::unique_ptr<std::fstream, decltype(fstream_deleter)*>
        fptr_input(&file_input, fstream_deleter);
    std::string line;
    while (std::getline(*fptr_input, line))
    {
        std::cout << line << std::endl;
    }
}

int main()
{
    echo_file("input.txt");
    echo_file("input.txt");
    return 0;
}
