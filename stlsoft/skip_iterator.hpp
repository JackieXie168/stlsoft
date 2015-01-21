
// Created: 17th September 2005
// Updated: 13th December 2005

/* /////////////////////////////////////////////////////////////////////////////
 * Auto-generation and compatibility
 */

/*
[<[STLSOFT-AUTO:NO-UNITTEST]>]
*/



namespace stlsoft
{

    // R is required only because 

    template<   typename I
#if 0
            ,   typename R = ss_typename_type_def_k std::iterator_traits<I>::reference
#else /* ? 0 */
            ,   typename R = ss_typename_type_def_k I::reference
#endif /* 0 */
            >
    class skip_iterator
    {
    /// \name Types
    /// @{
    public:
        typedef I                                           adapted_iterator_type;
        typedef R                                           reference;
        typedef skip_iterator<I, R>                         class_type;
    /// @}

    /// \name Construction
    /// @{
    public:
        skip_iterator(adapted_iterator_type i, size_t n, size_t m)
            : m_i(i)
            , m_end(adapted_iterator_type())
            , m_n(n)
            , m_m(m)
            , m_pos(0)
        {
            STLSOFT_ASSERT(m_n < m_m);
            STLSOFT_ASSERT(m_pos < m_m);

            init_pos_();
        }
        skip_iterator(adapted_iterator_type i, size_t n, size_t m, size_t p)
            : m_i(i)
            , m_end(adapted_iterator_type())
            , m_n(n)
            , m_m(m)
            , m_pos(p)
        {
            STLSOFT_ASSERT(m_n < m_m);
            STLSOFT_ASSERT(m_pos < m_m);

            init_pos_();
        }
        skip_iterator(adapted_iterator_type i, size_t n, size_t m, adapted_iterator_type end)
            : m_i(i)
            , m_end(end)
            , m_n(n)
            , m_m(m)
            , m_pos(0)
        {
            STLSOFT_ASSERT(m_n < m_m);
            STLSOFT_ASSERT(m_pos < m_m);

            init_pos_();

            STLSOFT_ASSERT(is_valid());
        }
        skip_iterator(adapted_iterator_type i, size_t n, size_t m, size_t p, adapted_iterator_type end)
            : m_i(i)
            , m_end(end)
            , m_n(n)
            , m_m(m)
            , m_pos(p)
        {
            STLSOFT_ASSERT(m_n < m_m);
            STLSOFT_ASSERT(m_pos < m_m);

            init_pos_();

            STLSOFT_ASSERT(is_valid());
        }
    /// @}

    /// \name Iteration
    /// @{
    public:
        class_type &operator ++()
        {
            STLSOFT_ASSERT(is_valid());
            STLSOFT_ASSERT(m_i != m_end);

            ++m_i;
            m_pos = (m_pos + 1) % m_m;

            for(; m_i != m_end && m_pos < m_n; ++m_i, ++m_pos)
            {}

            STLSOFT_ASSERT(is_valid());

            return *this;
        }
        class_type operator ++(int)
        {
            class_type r(*this);

            operator ++();

            return r;
        }
#if 1
        reference operator *() const
#else /* ? 0 */
        char const *operator *() const
#endif /* 0 */
        {
            STLSOFT_ASSERT(is_valid());

            return *m_i;
        }
    /// @}

    /// \name Comparison
    /// @{
    public:
        bool equal(class_type const &rhs) const
        {
            STLSOFT_ASSERT(is_valid());

            return equal(rhs.base());
        }
        bool equal(adapted_iterator_type const &rhs) const
        {
            STLSOFT_ASSERT(is_valid());

            return base() == rhs;
        }
    /// @}

    /// \name Attributes
    /// @{
    public:
#if 0
        adapted_iterator_type base() const
        {
            STLSOFT_ASSERT(is_valid());

            return m_i;
        }
#else /* ? 0 */
        // More efficient this way
        adapted_iterator_type const &base() const
        {
            STLSOFT_ASSERT(is_valid());

            return m_i;
        }
#endif /* 0 */
    /// @}

    /// \name Contract
    /// @{
    private:
        bool is_valid() const
        {
            if(m_pos >= m_m)
            {
#ifdef STLSOFT_UNITTEST
                fprintf(stderr, "skip_iterator m_pos (%lu) >= m_m (%lu)\n", static_cast<unsigned long>(m_pos), static_cast<unsigned long>(m_m));
#endif /* STLSOFT_UNITTEST */

                return false;
            }
            if(m_pos > m_n)
            {
#ifdef STLSOFT_UNITTEST
                fprintf(stderr, "skip_iterator m_pos (%lu) > m_n (%lu)\n", static_cast<unsigned long>(m_pos), static_cast<unsigned long>(m_n));
#endif /* STLSOFT_UNITTEST */

                return false;
            }
            if(m_n >= m_m)
            {
#ifdef STLSOFT_UNITTEST
                fprintf(stderr, "skip_iterator m_n (%lu) >= m_m (%lu)\n", static_cast<unsigned long>(m_n), static_cast<unsigned long>(m_m));
#endif /* STLSOFT_UNITTEST */

                return false;
            }

            return true;
        }
    /// @}

    /// \name Implementation
    /// @{
    private:
        void init_pos_()
        {
            for(; m_i != m_end && m_pos < m_n; ++m_i, ++m_pos)
            {}
            m_pos = m_pos % m_m;
        }
    /// @}

    /// \name Members
    /// @{
    private:
        adapted_iterator_type   m_i;
        adapted_iterator_type   m_end;
        size_t                  m_n;
        size_t                  m_m;
        size_t                  m_pos;
    /// @}
    };

    template<   typename I
            ,   typename R
            >
    inline bool operator ==(skip_iterator<I, R> const &lhs, skip_iterator<I, R> const &rhs)
    {
        return lhs.equal(rhs);
    }

    template<   typename I
            ,   typename R
            >
    inline bool operator ==(skip_iterator<I, R> const &lhs, I const &rhs)
    {
        return lhs.equal(rhs);
    }

    template<   typename I
            ,   typename R
            >
    inline bool operator ==(I const &lhs, skip_iterator<I, R> const &rhs)
    {
        return rhs.equal(lhs);
    }

    template<   typename I
            ,   typename R
            >
    inline bool operator !=(skip_iterator<I, R> const &lhs, skip_iterator<I, R> const &rhs)
    {
        return !lhs.equal(rhs);
    }

    template<   typename I
            ,   typename R
            >
    inline bool operator !=(skip_iterator<I, R> const &lhs, I const &rhs)
    {
        return !lhs.equal(rhs);
    }

    template<   typename I
            ,   typename R
            >
    inline bool operator !=(I const &lhs, skip_iterator<I, R> const &rhs)
    {
        return !rhs.equal(lhs);
    }






#ifndef USE_GLOB_SEQUENCE
    template <typename I>
    inline skip_iterator<I> skip(I i, size_t n, size_t m)
    {
        return skip_iterator<I>(i, n, m);
    }

    template <typename I>
    inline skip_iterator<I> skip(I i, size_t n, size_t m, size_t p)
    {
        return skip_iterator<I>(i, n, m, p);
    }

    template <typename I>
    inline skip_iterator<I> skip(I i, size_t n, size_t m, I end)
    {
        return skip_iterator<I>(i, n, m, end);
    }

    template <typename I>
    inline skip_iterator<I> skip(I i, size_t n, size_t m, size_t p, I end)
    {
        return skip_iterator<I>(i, n, m, p, end);
    }
#else /* ? USE_GLOB_SEQUENCE */

//  template <typename T>
//  inline skip_iterator<T*, T&> skip(T *i, size_t n, size_t m, size_t p, T *end)
//  {
//      return skip_iterator<T*, T&>(i, n, m, p, end);
//  }

    template <typename T>
    inline skip_iterator<T const*, T const&> skip(T const *i, size_t n, size_t m, size_t p, T const *end)
    {
        return skip_iterator<T const*, T const&>(i, n, m, p, end);
    }

#endif /* ? USE_GLOB_SEQUENCE */

} // namespace stlsoft
