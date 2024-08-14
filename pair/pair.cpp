#include <iostream>
#include <string>
#include <format>
#include <cassert>

template <class T1, class T2>
class Pair
{
public:
    Pair(T1 first, T2 second) : first(first), second(second) {};
    void display() const
    {
        try
        {
            std::cout << std::format("First: {}, Second: {}\n", first, second);
        }
        catch (const std::exception &error)
        {
            std::cerr << std::format("Failed to stringify the pair: {} \n", error.what());
        }
    }

    T1 first;
    T2 second;
};

int main()
{
    Pair<int, std::string> p(1, "example");
    p.display(); // Output: First: 1, Second: example

    assert(p.first == 1);
    assert(p.second == "example");

    Pair<double, char> p2(3.14, 'P');
    p2.display(); // Output: First: 3.14, Second: P

    return 0;
}