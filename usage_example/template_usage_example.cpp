#include <array>

template <class UnderlyingType, size_t size, class EnumType>
class EnumArray : public std::array<UnderlyingType, size> {
public:
  std::array<UnderlyingType, size>::reference operator[](EnumType pos) {
    return std::array<UnderlyingType, size>::operator[](
        static_cast<size_t>(pos));
  }

  std::array<UnderlyingType, size>::const_reference
  operator[](EnumType pos) const {
    return std::array<UnderlyingType, size>::operator[](
        static_cast<size_t>(pos));
  }
};

int main() {
  enum class test { A, B };

  EnumArray<int, 2, test> en_arr = {3, 5};
  std::array<int, 2> arr = {3, 5};
  en_arr[test::A] = 2;
  // en_arr[0] = 0;
  // arr[test::A] = 2;
  arr[0] = 0;
}