
// Updated: 4th May 2005

#include <iterator>

namespace stlsoft
{

    template<   ss_typename_param_k I
            >
    class indexed_iterator
    {
    private:
        typedef ::std::iterator_traits<I>                           iterator_traits_type;
    public:
        typedef I                                                   iterator_type;
        typedef indexed_iterator<I>                                 class_type;
        typedef ss_typename_type_k iterator_traits_type::value_type value_type;
    //  typedef ss_typename_type_k iterator_type::value_type        value_type;
        typedef ss_size_t                                           size_type;

    public:
        indexed_iterator()
            : m_i(I())
            , m_index(0)
        {}
        ss_explicit_k indexed_iterator(I i, size_type index_ = 0)
            : m_i(i)
            , m_index(index_)
        {}
#if 0
        ss_explicit_k indexed_iterator(I i, size_type index_)
            : m_i(i)
            , m_index(index_)
        {}
#endif /* 0 */
        indexed_iterator(class_type const &rhs)
            : m_i(rhs.m_i)
            , m_index(rhs.m_index)
        {}

    public:
        class_type &operator ++()
        {
            ++m_i;
            ++m_index;

            return *this;
        }

        class_type operator ++(int)
        {
            class_type  r(*this);

            operator ++();

            return r;
        }

        value_type &operator *()
        {
            return *m_i;
        }

        value_type const &operator *() const
        {
            return *m_i;
        }

        value_type *operator ->()
        {
            return m_i.operator ->();
        }

        value_type const *operator ->() const
        {
            return m_i.operator ->();
        }

    public:
        size_type index() const
        {
            return m_index;
        }

    public:
        ss_bool_t equal(class_type const &rhs) const
        {
            return m_i == rhs.m_i;
        }

    private:
        I           m_i;
        size_type   m_index;
    };

    template<   ss_typename_param_k I
            >
    inline ss_bool_t operator ==(indexed_iterator<I> const &lhs, indexed_iterator<I> const &rhs)
    {
        return lhs.equal(rhs);
    }

    template<   ss_typename_param_k I
            >
    inline ss_bool_t operator !=(indexed_iterator<I> const &lhs, indexed_iterator<I> const &rhs)
    {
        return !lhs.equal(rhs);
    }

} // namespace stlsoft
