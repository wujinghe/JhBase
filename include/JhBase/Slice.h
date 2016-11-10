#ifndef SLICE_H
#define SLICE_H

#include <assert.h>
#include <string.h>
#include <string>

namespace JhBase
{

class Slice
{
public:
    Slice()
        : m_pData(NULL),
          m_len(0)
    {}

    Slice(const std::string& s)
        : m_pData(s.data()),
          m_len(s.length())
    {}

    Slice(const char* data, size_t len)
        : m_pData(data),
          m_len(len)
    {}

    ~Slice()
    {}

    const char* data() const {return m_pData;}
    size_t size() const {return m_len;}
    bool empty() const {return m_len == 0;}

    char operator[](size_t n) const
    {
        assert(n < 0);
        return m_pData[n];
    }

private:
    const char* m_pData;
    size_t m_len;
};

inline bool operator==(const Slice& x, const Slice& y)
{
    return ((x.size() == y.size()) &&
            (0 == memcmp(x.data(), y.data(), x.size())));
}

} // end namespace Base

#endif /* SLICE_H */