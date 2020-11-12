// Generated by gencpp from file cacc_msgs/CaccMpcParam.msg
// DO NOT EDIT!


#ifndef CACC_MSGS_MESSAGE_CACCMPCPARAM_H
#define CACC_MSGS_MESSAGE_CACCMPCPARAM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cacc_msgs
{
template <class ContainerAllocator>
struct CaccMpcParam_
{
  typedef CaccMpcParam_<ContainerAllocator> Type;

  CaccMpcParam_()
    : Ds(0.0)
    , Dmin(0.0)
    , umax(0.0)
    , umin(0.0)
    , sf0(0)
    , sf1(0)
    , sf2(0)
    , q0(0)
    , q1(0)
    , q2(0)
    , r(0)
    , su(0)
    , sd(0)
    , tf(0.0)
    , ht(0.0)
    , dv(0)
    , zeta(0)
    , kmax(0)  {
    }
  CaccMpcParam_(const ContainerAllocator& _alloc)
    : Ds(0.0)
    , Dmin(0.0)
    , umax(0.0)
    , umin(0.0)
    , sf0(0)
    , sf1(0)
    , sf2(0)
    , q0(0)
    , q1(0)
    , q2(0)
    , r(0)
    , su(0)
    , sd(0)
    , tf(0.0)
    , ht(0.0)
    , dv(0)
    , zeta(0)
    , kmax(0)  {
  (void)_alloc;
    }



   typedef float _Ds_type;
  _Ds_type Ds;

   typedef float _Dmin_type;
  _Dmin_type Dmin;

   typedef float _umax_type;
  _umax_type umax;

   typedef float _umin_type;
  _umin_type umin;

   typedef int32_t _sf0_type;
  _sf0_type sf0;

   typedef int32_t _sf1_type;
  _sf1_type sf1;

   typedef int32_t _sf2_type;
  _sf2_type sf2;

   typedef int32_t _q0_type;
  _q0_type q0;

   typedef int32_t _q1_type;
  _q1_type q1;

   typedef int32_t _q2_type;
  _q2_type q2;

   typedef int32_t _r_type;
  _r_type r;

   typedef int32_t _su_type;
  _su_type su;

   typedef int32_t _sd_type;
  _sd_type sd;

   typedef float _tf_type;
  _tf_type tf;

   typedef float _ht_type;
  _ht_type ht;

   typedef int16_t _dv_type;
  _dv_type dv;

   typedef int16_t _zeta_type;
  _zeta_type zeta;

   typedef int16_t _kmax_type;
  _kmax_type kmax;





  typedef boost::shared_ptr< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> const> ConstPtr;

}; // struct CaccMpcParam_

typedef ::cacc_msgs::CaccMpcParam_<std::allocator<void> > CaccMpcParam;

typedef boost::shared_ptr< ::cacc_msgs::CaccMpcParam > CaccMpcParamPtr;
typedef boost::shared_ptr< ::cacc_msgs::CaccMpcParam const> CaccMpcParamConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cacc_msgs::CaccMpcParam_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cacc_msgs::CaccMpcParam_<ContainerAllocator1> & lhs, const ::cacc_msgs::CaccMpcParam_<ContainerAllocator2> & rhs)
{
  return lhs.Ds == rhs.Ds &&
    lhs.Dmin == rhs.Dmin &&
    lhs.umax == rhs.umax &&
    lhs.umin == rhs.umin &&
    lhs.sf0 == rhs.sf0 &&
    lhs.sf1 == rhs.sf1 &&
    lhs.sf2 == rhs.sf2 &&
    lhs.q0 == rhs.q0 &&
    lhs.q1 == rhs.q1 &&
    lhs.q2 == rhs.q2 &&
    lhs.r == rhs.r &&
    lhs.su == rhs.su &&
    lhs.sd == rhs.sd &&
    lhs.tf == rhs.tf &&
    lhs.ht == rhs.ht &&
    lhs.dv == rhs.dv &&
    lhs.zeta == rhs.zeta &&
    lhs.kmax == rhs.kmax;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cacc_msgs::CaccMpcParam_<ContainerAllocator1> & lhs, const ::cacc_msgs::CaccMpcParam_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cacc_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
{
  static const char* value()
  {
    return "520e747c091a36b66d7fea5adeed4945";
  }

  static const char* value(const ::cacc_msgs::CaccMpcParam_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x520e747c091a36b6ULL;
  static const uint64_t static_value2 = 0x6d7fea5adeed4945ULL;
};

template<class ContainerAllocator>
struct DataType< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cacc_msgs/CaccMpcParam";
  }

  static const char* value(const ::cacc_msgs::CaccMpcParam_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 Ds\n"
"float32 Dmin\n"
"float32 umax\n"
"float32 umin\n"
"\n"
"int32   sf0\n"
"int32   sf1\n"
"int32   sf2\n"
"int32   q0\n"
"int32   q1\n"
"int32   q2\n"
"int32   r\n"
"int32   su\n"
"int32   sd\n"
"\n"
"float32 tf\n"
"float32 ht\n"
"int16   dv\n"
"int16   zeta\n"
"int16   kmax\n"
;
  }

  static const char* value(const ::cacc_msgs::CaccMpcParam_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Ds);
      stream.next(m.Dmin);
      stream.next(m.umax);
      stream.next(m.umin);
      stream.next(m.sf0);
      stream.next(m.sf1);
      stream.next(m.sf2);
      stream.next(m.q0);
      stream.next(m.q1);
      stream.next(m.q2);
      stream.next(m.r);
      stream.next(m.su);
      stream.next(m.sd);
      stream.next(m.tf);
      stream.next(m.ht);
      stream.next(m.dv);
      stream.next(m.zeta);
      stream.next(m.kmax);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CaccMpcParam_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cacc_msgs::CaccMpcParam_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cacc_msgs::CaccMpcParam_<ContainerAllocator>& v)
  {
    s << indent << "Ds: ";
    Printer<float>::stream(s, indent + "  ", v.Ds);
    s << indent << "Dmin: ";
    Printer<float>::stream(s, indent + "  ", v.Dmin);
    s << indent << "umax: ";
    Printer<float>::stream(s, indent + "  ", v.umax);
    s << indent << "umin: ";
    Printer<float>::stream(s, indent + "  ", v.umin);
    s << indent << "sf0: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sf0);
    s << indent << "sf1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sf1);
    s << indent << "sf2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sf2);
    s << indent << "q0: ";
    Printer<int32_t>::stream(s, indent + "  ", v.q0);
    s << indent << "q1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.q1);
    s << indent << "q2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.q2);
    s << indent << "r: ";
    Printer<int32_t>::stream(s, indent + "  ", v.r);
    s << indent << "su: ";
    Printer<int32_t>::stream(s, indent + "  ", v.su);
    s << indent << "sd: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sd);
    s << indent << "tf: ";
    Printer<float>::stream(s, indent + "  ", v.tf);
    s << indent << "ht: ";
    Printer<float>::stream(s, indent + "  ", v.ht);
    s << indent << "dv: ";
    Printer<int16_t>::stream(s, indent + "  ", v.dv);
    s << indent << "zeta: ";
    Printer<int16_t>::stream(s, indent + "  ", v.zeta);
    s << indent << "kmax: ";
    Printer<int16_t>::stream(s, indent + "  ", v.kmax);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CACC_MSGS_MESSAGE_CACCMPCPARAM_H