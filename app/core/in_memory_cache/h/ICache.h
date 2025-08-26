#pragma once

template<typename Key, typename Data>
class ICache
{
    virtual ~ICache() = 0;
    virtual void addItem(Key key, Data item) = 0;
    virtual void updateItem(Key key, Data item) = 0;
    virtual Data getItem(Key key, Data item) const = 0;
    virtual bool deleteItem(Key key) = 0;
};