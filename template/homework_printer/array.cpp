#include <array>
#include <iostream>

void PrintArray(/* Type */ array) {
  // your code here...
}

int main() {
  std::array x = {3, 2, 1};
  std::array y = {std::string{"hello "}, std::string{"world!"}};
  PrintArray(x); // > 3 2 1
  PrintArray(y); // > hello world!
}