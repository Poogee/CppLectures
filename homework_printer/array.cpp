#include <array>
#include <iostream>

template <typename T, std::size_t S>
void PrintArray(const std::array<T, S> &array)
{
  for (const auto &element : array)
  {
    std::cout << element << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::array x = {3, 2, 1};
  std::array y = {std::string{"hello "}, std::string{"world!"}};
  PrintArray(x); // > 3 2 1
  PrintArray(y); // > hello world!
}