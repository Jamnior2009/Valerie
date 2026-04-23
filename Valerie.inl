#include <cstddef>
#include <initializer_list>
#include <stdexcept>

template <typename type>
    Jamn::Valerie<type>::Valerie()
    {
        size = 0;
        vector = nullptr;

        maxSize = 0;
        reserved = false;
    }

template <typename type>
    bool Jamn::Valerie<type>::isFull() const
    {
        return reserved && size == maxSize;
    }

template <typename type>
    bool Jamn::Valerie<type>::isEmpty() const
    {
        return size == 0;
    }

template <typename type>
    void Jamn::Valerie<type>::reserv(std::size_t newMaxSize)
    {
        reserved = true;
        type* temp = new type[newMaxSize];
        for (std::size_t i = 0; i < size; i++)
        {
            temp[i] = vector[i];
        }
        delete[] vector;
        maxSize = newMaxSize;
        vector = new type[maxSize];
        
        if(size > maxSize)
        {
            for(std::size_t i = 0; i < maxSize; i++)
            {
                vector[i] = temp[i];
            }
        }
        else
        {
            for(std::size_t i = 0; i < size; i++)
            {
                vector[i] = temp[i];
            }
        }

        delete[] temp;
    }

template <typename type>
    std::size_t Jamn::Valerie<type>::retSize() const
    {
        return size;
    }

template <typename type>
    void Jamn::Valerie<type>::pushBack(type value)
    {
        if (size == 0 && reserved && maxSize > 0)
        {
            size++;
            vector = new type[size];
            vector[0] = value;
        }
        else if(reserved && size <= maxSize)
        {
            type* temp = new type[size];
            for (std::size_t i = 0; i < size; i++)
            {
                temp[i] = vector[i];
            }
            delete[] vector;
            size++;
            vector = new type[size];
            for (std::size_t i = 0; i < size - 1; i++)
            {
                vector[i] = temp[i];
            }
            delete[] temp;
            vector[size - 1] = value;
        }
        else if(!reserved)
        {
            type* temp = new type[size];
            for (std::size_t i = 0; i < size; i++)
            {
                temp[i] = vector[i];
            }
            delete[] vector;
            size++;
            vector = new type[size];
            for (std::size_t i = 0; i < size - 1; i++)
            {
                vector[i] = temp[i];
            }
            delete[] temp;
            vector[size - 1] = value;
        }
        else
        {
            throw std::out_of_range("No more space | reserved size is full -> pushBack");
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
            throw std::out_of_range("Wrong index | out of range -> pushOut");
        }
    }

template <typename type>
    type Jamn::Valerie<type>::at(size_t index) const
    {
        return pushOut(index % size);
    }

template <typename type>
    void Jamn::Valerie<type>::remove(size_t index)
    {
        if (index < size && size > 0)
        {
            size--;

            type* temp = new type[size];
            for (std::size_t i = 0; i < size + 1; i++)
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
            for (std::size_t i = 0; i < size; i++)
            {
                vector[i] = temp[i];
            }

            delete[] temp;
        }
        else
        {
            throw std::out_of_range("Wrong index | out of range -> remove");
        }
    }

template <typename type>
    void Jamn::Valerie<type>::sort()
    {
        for (std::size_t i = 0; i < size - 2; i++)
        {
            bool end = false;
            for (std::size_t j = 0; j < size - 2 - i; j++)
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
            throw std::out_of_range("Wrong index | out of range -> replace");
        }
    }

template <typename type>
    void Jamn::Valerie<type>::clear()
    {
        delete[] vector;
        size = 0;
        vector = nullptr;

        reserved = false;
        maxSize = 0;
    }

template <typename type>
    Jamn::Valerie<type>& Jamn::Valerie<type>::operator+(Valerie const& v)
    {
        if(reserved)
        {
            if(size + v.size <= maxSize)
            {
                for (std::size_t i = 0; i < v.size; i++)
                {
                    vector[size + i] = v.vector[i];
                }
                size = size + v.size;
            }
            else
            {
                type* temp = new type[size + v.size];
                for (std::size_t i = 0; i < size; i++)
                {
                    temp[i] = vector[i];
                }
                delete[] vector;
                for (std::size_t i = 0; i < v.size; i++)
                {
                    temp[size + i] = v.vector[i];
                }
                
                size = maxSize;
                vector = new type[size];
                for (std::size_t i = 0; i < size; i++)
                {
                    vector[i] = temp[i];
                }
                delete[] temp;
            }
        }
        else
        {
            type* temp = new type[size + v.size];
            for (std::size_t i = 0; i < size; i++)
            {
                temp[i] = vector[i];
            }
            delete[] vector;
            for (std::size_t i = 0; i < v.size; i++)
            {
                temp[size + i] = v.vector[i];
            }
            size = size + v.size;
            vector = new type[size];
            for (std::size_t i = 0; i < size; i++)
            {
                vector[i] = temp[i];
            }
            delete[] temp;
        }
        return *this;
    }

template <typename type>
    Jamn::Valerie<type>& Jamn::Valerie<type>::operator+(std::initializer_list<type> list)
    {
        if(reserved)
        {
            if(size + list.size() <= maxSize)
            {
                for (std::size_t i = 0; i < list.size(); i++)
                {
                    vector[size + i] = list.begin()[i];
                }
                size = size + list.size();
                return *this;
            }
            else
            {
                type* temp = new type[size + list.size()];
                for (std::size_t i = 0; i < size; i++)
                {
                    temp[i] = vector[i];
                }
                delete[] vector;
                for (std::size_t i = 0; i < list.size(); i++)
                {
                    temp[size + i] = list.begin()[i];
                }
                
                vector = new type[maxSize];
                for (std::size_t i = 0; i < maxSize; i++)
                {
                    vector[i] = temp[i];
                }
                delete[] temp;
                return *this;
            }
        }
        else
        {
            type* temp = new type[size + list.size()];
            for (std::size_t i = 0; i < size; i++)
            {
                temp[i] = vector[i];
            }
            delete[] vector;
            for (std::size_t i = 0; i < list.size(); i++)
            {
                temp[size + i] = list.begin()[i];
            }
            size = size + list.size();
            vector = new type[size];
            for (std::size_t i = 0; i < size; i++)
            {
                vector[i] = temp[i];
            }
            delete[] temp;
            return *this;
        }
    }

template <typename type>
    Jamn::Valerie<type>& Jamn::Valerie<type>::operator=(Valerie const& v)
    {
        if (size == v.size)
        {
            for (std::size_t i = 0; i < size; i++)
            {
                if (vector[i] != v.vector[i] || reserved != v.reserved || maxSize != v.maxSize)
                {
                    delete[] vector;
                    size = v.size;
                    reserved = v.reserved;
                    maxSize = v.maxSize;
                    vector = new type[size];
                    for (std::size_t i = 0; i < size; i++)
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
            reserved = v.reserved;
            maxSize = v.maxSize;
            vector = new type[size];
            for (std::size_t i = 0; i < size; i++)
            {
                vector[i] = v.vector[i];
            }
            return *this;
        }
    }

template <typename type>
    Jamn::Valerie<type>& Jamn::Valerie<type>::operator=(std::initializer_list<type> list)
    {
        if(reserved)
        {
            if(list.size() <= maxSize)
            {
                delete[] vector;
                size = list.size();
                vector = new type[size];
                for (std::size_t i = 0; i < list.size(); i++)
                {
                    vector[i] = (type)list.begin()[i];
                }
            }
            else
            {
                delete[] vector;
                size = maxSize;
                vector = new type[size];
                for (std::size_t i = 0; i < size; i++)
                {
                    vector[i] = (type)list.begin()[i];
                }
            }
        }
        else
        {
            delete[] vector;
            size = list.size();
            vector = new type[size];
            for(std::size_t i = 0; i < size; i++)
            {
                vector[i] = (type)list.begin()[i];
            }
        }
        return *this;
    }

template <typename type>
    type& Jamn::Valerie<type>::operator[](std::size_t index)
    {
        if (index < size && size > 0)
        {
            return vector[index];
        }
        else
        {
            throw std::out_of_range("Wrong index | out of range -> operator[]");
        }
    }

template <typename type>
    Jamn::Valerie<type>::~Valerie()
    {
        delete[] vector;
    }
