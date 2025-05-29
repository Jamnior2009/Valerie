#pragma once

#ifndef VALERIE_HPP
#define VALERIE_HPP

namespace Jamn
{
    template <typename type>

    class Valerie
    {
    public:

        size_t size;
        type* vector;
        //type* temp;

        Valerie();

        size_t retSize() const;

        void pushBack(type value);

        type pushOut(size_t index) const;

        void del(size_t index);

        void sort();

        void replace(size_t index, type value);

        void clear();

        Valerie operator+(Valerie const& v);

        Valerie operator=(Valerie const& v);

        Valerie operator=(std::initializer_list<type> const& list);

        ~Valerie();
    };

    #include "Valerie.inl"
}

#endif