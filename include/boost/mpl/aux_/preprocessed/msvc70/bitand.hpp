
// Copyright Aleksey Gurtovoy 2000-2004
// Copyright Jaap Suter 2003
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/bitand.hpp" header
// -- DO NOT modify by hand!

namespace boost { namespace mpl {

template<
      typename Tag1
    , typename Tag2

    , int tag1_ = Tag1::value
    , int tag2_ = Tag2::value
    >
struct bitand_impl
    : if_c<
          ( tag1_ > tag2_ )

        , aux::cast2nd_impl< bitand_impl< Tag1,Tag2 >,Tag1, Tag2 >
        , aux::cast1st_impl< bitand_impl< Tag1,Tag2 >,Tag1, Tag2 >
        >
{
};

/// for Digital Mars C++/compilers with no CTPS support
template<> struct bitand_impl< na,na >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
    };
};

template<> struct bitand_impl< na,integral_c_tag >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
    };
};

template<> struct bitand_impl< integral_c_tag,na >
{
    template< typename U1, typename U2 > struct apply
    {
        typedef apply type;
    };
};

template< typename T > struct bitand_tag
    : tag< T,na >
{
};

template<
      typename BOOST_MPL_AUX_NA_PARAM(N1)
    , typename BOOST_MPL_AUX_NA_PARAM(N2)
    >
struct bitand_
    : aux::msvc_eti_base< typename apply_wrap2<
          bitand_impl<
              typename bitand_tag<N1>::type
            , typename bitand_tag<N2>::type
            >
        , N1
        , N2
        >::type >::type

{
    BOOST_MPL_AUX_LAMBDA_SUPPORT(2, bitand_, (N1, N2))

};

BOOST_MPL_AUX_NA_SPEC2(2, 2, bitand_)

}}

namespace boost { namespace mpl {

namespace aux {
template< typename T, T n1, T n2 >
struct msvc_bitand_impl
{
  enum msvc_wknd { value = (n1 & n2) };
    typedef integral_c< T,value > type;
};

}

template<>
struct bitand_impl< integral_c_tag,integral_c_tag >
{
    template< typename N1, typename N2 > struct apply
        : aux::msvc_bitand_impl<
              typename aux::largest_int<
                  typename N1::value_type
                , typename N2::value_type
                >::type
            , N1::value
            , N2::value
            >::type

    {
    };
};

}}