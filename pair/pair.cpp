#include <iostream>
#include <string>
#include <format>
#include <cassert>
#include <functional>

template <class T1, class T2>
class Pair
{
public:
    Pair(T1 first, T2 second) : first(std::move(first)), second(std::move(second)) {};
    Pair(const Pair &other) : first(other.first), second(other.second) {};
    void display() const
    {
        try
        {
            std::cout << std::format("First: {}, Second: {}\n", std::cref(first).get(), std::cref(second).get());
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