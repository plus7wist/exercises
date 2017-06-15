#include <bits/stdc++.h>

int main()
{
  std::map<int, std::string> number_name = {
    {1, "one"}, {2, "two"}, {10, "ten"}
  };
  for (const auto& kv: number_name) {
    std::cout << kv.first << " " << kv.second << std::endl;
  }
  return 0;
}
