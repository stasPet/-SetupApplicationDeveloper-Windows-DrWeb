#ifndef DEFINE_NOT_FOUND_EXCEPTION
#define DEFINE_NOT_FOUND_EXCEPTION

#include "NotFoundException.h"

template <class TKey>
class MyNotFoundException: public NotFoundException<TKey>
{
private:
    TKey key;

public:
    inline MyNotFoundException(TKey const&) noexcept;
    ~MyNotFoundException() = default;

    virtual const TKey& GetKey() const noexcept;
};

template <class TKey>
inline MyNotFoundException<TKey>::MyNotFoundException(TKey const& k) noexcept:
    key{k}
{

}

template<class TKey>
inline TKey const& MyNotFoundException<TKey>::GetKey() const noexcept
{
    return key;
}

#endif