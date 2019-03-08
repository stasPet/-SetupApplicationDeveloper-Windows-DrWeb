#ifndef DEFINE_NOTFOUNDEXCEPTION
#define DEFINE_NOTFOUNDEXCEPTION

template<class TKey>
class NotFoundException : public std::exception
{
public:
    virtual const TKey& GetKey() const noexcept = 0;
};

#endif