#pragma once

#ifndef VALERIE_HPP
#define VALERIE_HPP

namespace Jamn
{
    template <typename type>

    class Valerie
    {
    private:
        std::size_t size;
        type* vector;

        bool reserved;
        std::size_t maxSize;

    public:
        Valerie();

        bool isFull() const;

        bool isEmpty() const;

        void reserv(std::size_t newMaxSize);

        std::size_t retSize() const;

        void pushBack(type value);

        type pushOut(std::size_t index) const;

        type at(std::size_t index) const;

        void remove(std::size_t index);

        void sort();

        void replace(std::size_t index, type value);

        void clear();

        Valerie& operator+(Valerie const& v);

        Valerie& operator=(Valerie const& v);

        Valerie& operator+(std::initializer_list<type> list);

        Valerie& operator=(std::initializer_list<type> list);

        type& operator[](std::size_t index);

        ~Valerie();
    };

    #include "Valerie.inl"
}

#endif
