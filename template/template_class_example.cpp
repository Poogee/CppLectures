#include <algorithm>

template <typename Type> class Interval {
public:
  Interval(Type inStart, Type inEnd) : start(inStart), end(inEnd) {}

  Type getStart() const { return start; }

  Type getEnd() const { return end; }

  Type getSize() const { return (end - start); }

  // Метод для получения интервала пересечения данного интервала с другим
  Interval<Type> intersection(const Interval<Type> &inOther) const {
    return Interval<Type>{std::max(start, inOther.start),
                          std::min(end, inOther.end)};
  }

private:
  Type start;
  Type end;
};

int main() {
  // Тестируем для подстановки типа "int"
  const Interval<int> intervalA{1, 3};
  const Interval<int> intervalB{2, 4};

  const Interval<int> intersection{intervalA.intersection(intervalB)};
  const int intersectionStart = intersection.getStart();
  const int intersectionEnd = intersection.getEnd();
  const int intersectionSize = intersection.getSize();

  // Тестируем для подстановки типа "char"
  const Interval<char> intervalAChar{'a', 'c'};
  const Interval<char> intervalBChar{'b', 'd'};

  const Interval<char> intersectionChar{
      intervalAChar.intersection(intervalBChar)};
  const char intersectionStartChar = intersectionChar.getStart();
  const char intersectionEndChar = intersectionChar.getEnd();
  const char intersectionSizeChar = intersectionChar.getSize();

  return 0;
}