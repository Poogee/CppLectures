#include <iostream>
#include <stdexcept>
#include <cassert>
#include <format>

// Implement vector
static_assert(sizeof(bool) == 1);
template <typename T>
class Vectorochek
{
public:
    // Constructor
    Vectorochek(size_t size = 0) : vec_size(size), vec_capacity(size)
    {
        data = new T[size];
        std::fill(data, data + size, T());
    }

    Vectorochek(const Vectorochek &other) : vec_size(other.vec_size), vec_capacity(other.vec_capacity)
    {
        data = new T[vec_capacity];
        for (size_t i = 0; i < vec_size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~Vectorochek()
    {
        delete[] data;
    }

    // Return the current size of the vector
    size_t size() const
    {
        return vec_size;
    }

    // Return the current capacity of the vector
    size_t capacity() const
    {
        return vec_capacity;
    }
    // Add an element to the end of the vector
    void push_back(const T &element)
    {
        if (vec_capacity == vec_size)
        {
            resize(vec_capacity ? vec_capacity * 2 : 1);
        }

        data[vec_size] = element;
        ++vec_size;
    }

    // Access elements by index
    T &operator[](size_t index)
    {
        if (index >= vec_size)
        {
            throw std::out_of_range("yikes");
        }
        return data[index];
    }
    const T &operator[](size_t index) const
    {
        if (index >= vec_size)
        {
            throw std::out_of_range("yikes");
        }
        return data[index];
    }

    void resize(size_t new_capacity)
    {
        T *new_data = new T[new_capacity];
        std::fill(new_data, new_data + new_capacity, T());

        for (size_t i = 0; i < vec_size; ++i)
            new_data[i] = data[i];
        delete[] data;

        data = new_data;
        vec_capacity = new_capacity;
    }

    template <typename K>
    class IteratorBase
    {
    public:
        IteratorBase(K *ptr) : ptr(ptr) {}
        K &operator*()
        {
            return *ptr;
        }
        K *operator->()
        {
            return ptr;
        }
        K operator++()
        {
            ++ptr;
            return *ptr;
        }

        auto operator<=>(const IteratorBase &) const = default;

    private:
        K *ptr;
    };

    using Iterator = IteratorBase<T>;
    using ConstIterator = IteratorBase<const T>;

    Iterator begin()
    {
        return Iterator(data);
    }

    Iterator end()
    {
        return Iterator(data + vec_size);
    }

    ConstIterator begin() const
    {
        return ConstIterator(data);
    }

    ConstIterator end() const
    {
        return ConstIterator(data + vec_size);
    }

private:
    T *data;
    size_t vec_size;
    size_t vec_capacity;
};

// Implement specialization for bool
// Because of bit-shenanigans, i've already implemented resize and get_bit for you <3
template <>
class Vectorochek<bool>
{
public:
    static constexpr size_t bits_per_byte = 8;

    // Constructor
    Vectorochek(size_t size = 0) : vec_size(size)
    {
        vec_capacity = (size - 1 + bits_per_byte) / bits_per_byte;
        data = new std::byte[vec_capacity];
        std::fill(data, data + vec_capacity, std::byte(0));
    }

    // Destructor
    ~Vectorochek()
    {
        delete[] data;
    }

    // Return the current size of the vector
    size_t size() const
    {
        return vec_size;
    }

    // Return the current capacity of the vector
    size_t capacity() const
    {
        return vec_capacity;
    }
    // Add an element to the end of the vector
    void push_back(const bool element)
    {
        if (vec_capacity == vec_size)
        {
            resize(vec_capacity ? vec_capacity * 2 : 1);
        }

        element ? set_bit(data, vec_size) : clear_bit(data, vec_size);
        ++vec_size;
    }

    struct BoolRef
    {
        BoolRef(std::byte *data, uint16_t index) : data(data), index(index) {}
        operator bool() const
        {
            return static_cast<bool>(data[index / bits_per_byte] &
                                     (std::byte(1) << (index % bits_per_byte)));
        }
        BoolRef &operator=(bool value)
        {
            value ? data[index / bits_per_byte] |= (std::byte(1) << (index % bits_per_byte)) : data[index / bits_per_byte] &= ~(std::byte(1) << (index % bits_per_byte));
            return *this;
        }

    private:
        std::byte *data;
        uint16_t index;
    };

    // Access elements by index
    BoolRef operator[](size_t index)
    {
        if (index >= vec_size)
        {
            throw std::out_of_range("yikes");
        }
        return BoolRef(data, index);
    }

    const BoolRef operator[](size_t index) const
    {
        if (index >= vec_size)
        {
            throw std::out_of_range("yikes");
        }
        return BoolRef(data, index);
    }

    void resize(size_t new_capacity)
    {
        // Allocate new memory for the resized vector
        std::byte *new_data =
            new std::byte[(new_capacity + bits_per_byte - 1) / bits_per_byte];

        // Initialize the new memory with zeros
        std::memset(new_data, 0,
                    (new_capacity + bits_per_byte - 1) / bits_per_byte);

        // Copy the existing bits to the new memory
        for (size_t i = 0; i < vec_size; ++i)
        {
            if (get_bit(data, i))
            {
                set_bit(new_data, i);
            }
        }

        // Deallocate the old memory
        delete[] data;

        // Update the data pointer and capacity
        data = new_data;
        vec_capacity = new_capacity;
    }

private:
    std::byte *data;
    size_t vec_size;
    size_t vec_capacity;

    bool get_bit(const std::byte *data, size_t index) const
    {
        return static_cast<bool>(data[index / bits_per_byte] &
                                 (std::byte(1) << (index % bits_per_byte)));
    }

    void set_bit(std::byte *data, size_t index)
    {
        data[index / bits_per_byte] |= (std::byte(1) << (index % bits_per_byte));
    }

    void clear_bit(std::byte *data, size_t index)
    {
        data[index / bits_per_byte] &= ~(std::byte(1) << (index % bits_per_byte));
    }
};

int main()
{
    Vectorochek<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // Test Iterator
    for (auto &x : v)
    {
        x += 1;
        std::cout << std::format("{} {} {}\n", v[0], v[1], v[2]);
    }

    // Test ConstIterator
    for (const auto &x : v)
    {
        x += 1; //* Does not compile
        std::cout << std::format("{} {} {}\n", v[0], v[1], v[2]);
    }
}
