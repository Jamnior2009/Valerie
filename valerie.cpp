export module Valerie;

import std;

export namespace Jamn
{
    template <typename type>

    class Valerie
    {
    private:
        size_t size;
        type* vector;

    public:
        Valerie();

        size_t retSize() const;

        void pushBack(type value);

        type pushOut(size_t index) const;

        void del(size_t index);

        void sort();

        void replace(size_t index, type value);

        void clear();

        Valerie& operator+(Valerie const& v);

        Valerie& operator=(Valerie const& v);

        Valerie& operator=(std::initializer_list<type> list);

        ~Valerie();
    };
}

template <typename type>
    Jamn::Valerie<type>::Valerie()
    {
        size = 0;
        vector = nullptr;
    }

template <typename type>
    size_t Jamn::Valerie<type>::retSize() const
    {
        return size;
    }

template <typename type>
    void Jamn::Valerie<type>::pushBack(type value)
    {
        if (size == 0)
        {
            size++;
            vector = new type[size];
            vector[0] = value;
        }
        else
        {
            type* temp = new type[size];
            for (int i = 0; i < size; i++)
            {
                temp[i] = vector[i];
            }
            delete[] vector;
            size++;
            vector = new type[size];
            for (int i = 0; i < size - 1; i++)
            {
                vector[i] = temp[i];
            }
            delete[] temp;
            vector[size - 1] = value;
        }
    }

template <typename type>
    type Jamn::Valerie<type>::pushOut(size_t index) const
    {
        if (index < size && size > 0)
        {
            return vector[index];
        }
        else
        {
            throw std::out_of_range("Wrong index | out of range");
        }
    }

template <typename type>
    void Jamn::Valerie<type>::del(size_t index)
    {
        if (index < size && size > 0)
        {
            size--;

            type* temp = new type[size];
            for (int i = 0; i < size + 1; i++)
            {
                if (i < index)
                {
                    temp[i] = vector[i];
                }
                else if (i == index) {}
                else if (i > index)
                {
                    temp[i - 1] = vector[i];
                }
            }
            delete[] vector;
            vector = new type[size];
            for (int i = 0; i < size; i++)
            {
                vector[i] = temp[i];
            }

            delete[] temp;
        }
        else
        {
            throw std::out_of_range("Wrong index | out of range");
        }
    }

template <typename type>
    void Jamn::Valerie<type>::sort()
    {
        for (int i = 0; i < size - 2; i++)
        {
            bool end = false;
            for (int j = 0; j < size - 2 - i; j++)
            {
                if (vector[j] > vector[j + 1])
                {
                    type temp = vector[j];
                    vector[j] = vector[j + 1];
                    vector[j + 1] = temp;

                    end = true;
                }
            }

            if (!end)
            {
                break;
            }
        }
    }

template <typename type>
    void Jamn::Valerie<type>::replace(size_t index, type value)
    {
        if (index < size && size > 0)
        {
            vector[index] = (type)value;
        }
        else
        {
            throw std::out_of_range("Wrong index | out of range");
        }
    }

template <typename type>
    void Jamn::Valerie<type>::clear()
    {
        delete[] vector;
        size = 0;
        vector = nullptr;
    }

template <typename type>
    Jamn::Valerie<type>& Jamn::Valerie<type>::operator+(Valerie const& v)
    {
        type* temp = new type[size + v.size];
        for (int i = 0; i < size; i++)
        {
            temp[i] = vector[i];
        }
        delete[] vector;
        for (int i = 0; i < v.size; i++)
        {
            temp[size + i] = v.vector[i];
        }
        size = size + v.size;
        vector = new type[size];
        for (int i = 0; i < size; i++)
        {
            vector[i] = temp[i];
        }
        delete[] temp;
        return *this;
    }

template <typename type>
    Jamn::Valerie<type>& Jamn::Valerie<type>::operator=(Valerie const& v)
    {
        if (size == v.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (vector[i] != v.vector[i])
                {
                    delete[] vector;
                    size = v.size;
                    vector = new type[size];
                    for (int i = 0; i < size; i++)
                    {
                        vector[i] = v.vector[i];
                    }
                    return *this;
                }
                else
                {
                    continue;
                }
            }

            return *this;
        }
        else
        {
            delete[] vector;
            size = v.size;
            vector = new type[size];
            for (int i = 0; i < size; i++)
            {
                vector[i] = v.vector[i];
            }
            return *this;
        }
    }

template <typename type>
    Jamn::Valerie<type>& Jamn::Valerie<type>::operator=(std::initializer_list<type> list)
    {
        delete[] this->vector;
        this->size = list.size();
        this->vector = new type[this->size];
        for (int i = 0; i < list.size(); i++)
        {
            this->vector[i] = (type)list.begin()[i];
        }
        return *this;
    }

template <typename type>
    Jamn::Valerie<type>::~Valerie()
    {
        delete[] vector;
    }