#include <iostream>
#include "Valerie.hpp"

template <typename type>
    Jamn::Valerie<type>::Valerie()
    {
        this->size = 1;
        this->vector = new type[size];
    }

template <typename type>
    size_t Jamn::Valerie<type>::retSize() const
    {
        return this->size - 1;
    }

template <typename type>
    void Jamn::Valerie<type>::pushBack(type value)
    {
        type* temp = new type[this->size + 1];
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->vector[i];
        }
        delete[] this->vector;
        temp[this->size - 1] = value;
        this->size++;
        this->vector = new type[size];
        for (int i = 0; i < this->size; i++)
        {
            this->vector[i] = temp[i];
        }
        delete[] temp;
    }
    
template <typename type>
    type Jamn::Valerie<type>::pushOut(size_t index) const
    {
        if (index < this->size)
        {
            return this->vector[index];
        }
        else
        {
            throw;
            return -1.0;
        }
    }
    
template <typename type>
    void Jamn::Valerie<type>::del(size_t index)
    {
        if (index < this->size)
        {
            type* temp = new type[this->size - 1];
            for (int i = 0; i < this->size - 1; i++)
            {
                if (i < index)
                {
                    temp[i] = this->vector[i];
                }
                else if (i == index) {}
                else if (i > index)
                {
                    temp[i - 1] = this->vector[i];
                }
            }
            delete[] this->vector;
            this->size--;
            this->vector = new type[this->size];
            for (int i = 0; i < this->size; i++)
            {
                this->vector[i] = temp[i];
            }
            delete[] temp;
        }
        else
        {
            throw;
        }
    }
    
template <typename type>
    void Jamn::Valerie<type>::sort()
    {
        for (int i = 0; i < this->size - 2; i++)
        {
            bool end = false;
            for (int j = 0; j < this->size - 2 - i; j++)
            {
                if (this->vector[j] > this->vector[j + 1])
                {
                    type temp = this->vector[j];
                    this->vector[j] = this->vector[j + 1];
                    this->vector[j + 1] = temp;

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
        if (index < this->size)
        {
            this->vector[index] = (type)value;
        }
        else
        {
            throw;
        }
    }

template <typename type>
    void Jamn::Valerie<type>::clear()
    {
        delete[] this->vector;
        this->size = 1;
        this->vector = new type[this->size];
    }

template <typename type>
    Jamn::Valerie<type> Jamn::Valerie<type>::operator+(Valerie const& v)
    {
        type* temp = new type[this->size + v.size - 1];
        for (int i = 0; i < this->size - 1; i++)
        {
            temp[i] = this->vector[i];
        }
        delete[] this->vector;
        for (int i = 0; i < v.size - 1; i++)
        {
            temp[this->size + i - 1] = v.vector[i];
        }
        this->size = this->size + v.size - 1;
        this->vector = new type[this->size];
        for (int i = 0; i < this->size - 1; i++)
        {
            this->vector[i] = temp[i];
        }
        delete[] temp;
        return *this;
    }
    
template <typename type>
    Jamn::Valerie<type> Jamn::Valerie<type>::operator=(Valerie const& v)
    {
        if(this->size == v.size)
        {
            for(int i = 0; i < this->size - 1; i++)
            {
                if(this->vector[i] != v.vector[i])
                {
                    delete[] this->vector;
                    this->size = v.size;
                    this->vector = new type[this->size];
                    for (int i = 0; i < this->size - 1; i++)
                    {
                        this->vector[i] = v.vector[i];
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
            delete[] this->vector;
            this->size = v.size;
            this->vector = new type[this->size];
            for (int i = 0; i < this->size - 1; i++)
            {
                this->vector[i] = v.vector[i];
            }
            return *this;
        }
    }

template <typename type>
    Jamn::Valerie<type> Jamn::Valerie<type>::operator=(std::initializer_list<type> const& list)
    {
        delete[] this->vector;
        this->size = list.size() + 1;
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
        delete[] this->vector;
    }