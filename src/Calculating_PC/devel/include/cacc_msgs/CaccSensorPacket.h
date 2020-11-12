// Generated by gencpp from file cacc_msgs/CaccSensorPacket.msg
// DO NOT EDIT!


#ifndef CACC_MSGS_MESSAGE_CACCSENSORPACKET_H
#define CACC_MSGS_MESSAGE_CACCSENSORPACKET_H


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
struct CaccSensorPacket_
{
  typedef CaccSensorPacket_<ContainerAllocator> Type;

  CaccSensorPacket_()
    : id(0)
    , manual(false)
    , thw(0.0)
    , alpha(0.0)
    , beta(0.0)
    , sensor2frontbumper(0.0)
    , sensor2rearbumper(0.0)
    , vel_gain(0)
    , vel_gain_low(0)
    , vel_gain_dec(0)
    , x(0.0)
    , y(0.0)
    , u(0.0)
    , v(0.0)
    , yaw(0.0)
    , speed(0.0)
    , acceleration(0.0)
    , front_x(0.0)
    , front_y(0.0)
    , front_u(0.0)
    , front_v(0.0)
    , front_yaw(0.0)
    , front_speed(0.0)
    , front_acceleration(0.0)
    , front_distance(0.0)
    , rear_x(0.0)
    , rear_y(0.0)
    , rear_u(0.0)
    , rear_v(0.0)
    , rear_yaw(0.0)
    , rear_speed(0.0)
    , rear_acceleration(0.0)
    , rear_distance(0.0)
    , checksum(0)  {
    }
  CaccSensorPacket_(const ContainerAllocator& _alloc)
    : id(0)
    , manual(false)
    , thw(0.0)
    , alpha(0.0)
    , beta(0.0)
    , sensor2frontbumper(0.0)
    , sensor2rearbumper(0.0)
    , vel_gain(0)
    , vel_gain_low(0)
    , vel_gain_dec(0)
    , x(0.0)
    , y(0.0)
    , u(0.0)
    , v(0.0)
    , yaw(0.0)
    , speed(0.0)
    , acceleration(0.0)
    , front_x(0.0)
    , front_y(0.0)
    , front_u(0.0)
    , front_v(0.0)
    , front_yaw(0.0)
    , front_speed(0.0)
    , front_acceleration(0.0)
    , front_distance(0.0)
    , rear_x(0.0)
    , rear_y(0.0)
    , rear_u(0.0)
    , rear_v(0.0)
    , rear_yaw(0.0)
    , rear_speed(0.0)
    , rear_acceleration(0.0)
    , rear_distance(0.0)
    , checksum(0)  {
  (void)_alloc;
    }



   typedef int16_t _id_type;
  _id_type id;

   typedef uint8_t _manual_type;
  _manual_type manual;

   typedef float _thw_type;
  _thw_type thw;

   typedef float _alpha_type;
  _alpha_type alpha;

   typedef float _beta_type;
  _beta_type beta;

   typedef float _sensor2frontbumper_type;
  _sensor2frontbumper_type sensor2frontbumper;

   typedef float _sensor2rearbumper_type;
  _sensor2rearbumper_type sensor2rearbumper;

   typedef int16_t _vel_gain_type;
  _vel_gain_type vel_gain;

   typedef int16_t _vel_gain_low_type;
  _vel_gain_low_type vel_gain_low;

   typedef int16_t _vel_gain_dec_type;
  _vel_gain_dec_type vel_gain_dec;

   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _u_type;
  _u_type u;

   typedef float _v_type;
  _v_type v;

   typedef float _yaw_type;
  _yaw_type yaw;

   typedef float _speed_type;
  _speed_type speed;

   typedef float _acceleration_type;
  _acceleration_type acceleration;

   typedef float _front_x_type;
  _front_x_type front_x;

   typedef float _front_y_type;
  _front_y_type front_y;

   typedef float _front_u_type;
  _front_u_type front_u;

   typedef float _front_v_type;
  _front_v_type front_v;

   typedef float _front_yaw_type;
  _front_yaw_type front_yaw;

   typedef float _front_speed_type;
  _front_speed_type front_speed;

   typedef float _front_acceleration_type;
  _front_acceleration_type front_acceleration;

   typedef float _front_distance_type;
  _front_distance_type front_distance;

   typedef float _rear_x_type;
  _rear_x_type rear_x;

   typedef float _rear_y_type;
  _rear_y_type rear_y;

   typedef float _rear_u_type;
  _rear_u_type rear_u;

   typedef float _rear_v_type;
  _rear_v_type rear_v;

   typedef float _rear_yaw_type;
  _rear_yaw_type rear_yaw;

   typedef float _rear_speed_type;
  _rear_speed_type rear_speed;

   typedef float _rear_acceleration_type;
  _rear_acceleration_type rear_acceleration;

   typedef float _rear_distance_type;
  _rear_distance_type rear_distance;

   typedef uint32_t _checksum_type;
  _checksum_type checksum;





  typedef boost::shared_ptr< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> const> ConstPtr;

}; // struct CaccSensorPacket_

typedef ::cacc_msgs::CaccSensorPacket_<std::allocator<void> > CaccSensorPacket;

typedef boost::shared_ptr< ::cacc_msgs::CaccSensorPacket > CaccSensorPacketPtr;
typedef boost::shared_ptr< ::cacc_msgs::CaccSensorPacket const> CaccSensorPacketConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator1> & lhs, const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.manual == rhs.manual &&
    lhs.thw == rhs.thw &&
    lhs.alpha == rhs.alpha &&
    lhs.beta == rhs.beta &&
    lhs.sensor2frontbumper == rhs.sensor2frontbumper &&
    lhs.sensor2rearbumper == rhs.sensor2rearbumper &&
    lhs.vel_gain == rhs.vel_gain &&
    lhs.vel_gain_low == rhs.vel_gain_low &&
    lhs.vel_gain_dec == rhs.vel_gain_dec &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.u == rhs.u &&
    lhs.v == rhs.v &&
    lhs.yaw == rhs.yaw &&
    lhs.speed == rhs.speed &&
    lhs.acceleration == rhs.acceleration &&
    lhs.front_x == rhs.front_x &&
    lhs.front_y == rhs.front_y &&
    lhs.front_u == rhs.front_u &&
    lhs.front_v == rhs.front_v &&
    lhs.front_yaw == rhs.front_yaw &&
    lhs.front_speed == rhs.front_speed &&
    lhs.front_acceleration == rhs.front_acceleration &&
    lhs.front_distance == rhs.front_distance &&
    lhs.rear_x == rhs.rear_x &&
    lhs.rear_y == rhs.rear_y &&
    lhs.rear_u == rhs.rear_u &&
    lhs.rear_v == rhs.rear_v &&
    lhs.rear_yaw == rhs.rear_yaw &&
    lhs.rear_speed == rhs.rear_speed &&
    lhs.rear_acceleration == rhs.rear_acceleration &&
    lhs.rear_distance == rhs.rear_distance &&
    lhs.checksum == rhs.checksum;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator1> & lhs, const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cacc_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
{
  static const char* value()
  {
    return "53f6fd0b756b85940b07ea746c26c901";
  }

  static const char* value(const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x53f6fd0b756b8594ULL;
  static const uint64_t static_value2 = 0x0b07ea746c26c901ULL;
};

template<class ContainerAllocator>
struct DataType< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cacc_msgs/CaccSensorPacket";
  }

  static const char* value(const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#Header Header\n"
"\n"
"int16 id\n"
"bool manual #1: manual. 0: automated\n"
"float32 thw\n"
"float32 alpha\n"
"float32 beta\n"
"float32 sensor2frontbumper\n"
"float32 sensor2rearbumper\n"
"int16 vel_gain\n"
"int16 vel_gain_low\n"
"int16 vel_gain_dec\n"
"\n"
"#ego car\n"
"float32 x\n"
"float32 y\n"
"float32 u\n"
"float32 v\n"
"float32 yaw\n"
"float32 speed\n"
"float32 acceleration\n"
"\n"
"#front car\n"
"float32 front_x\n"
"float32 front_y\n"
"float32 front_u\n"
"float32 front_v\n"
"float32 front_yaw\n"
"float32 front_speed\n"
"float32 front_acceleration\n"
"float32 front_distance\n"
"\n"
"#rear car\n"
"float32 rear_x\n"
"float32 rear_y\n"
"float32 rear_u\n"
"float32 rear_v\n"
"float32 rear_yaw\n"
"float32 rear_speed\n"
"float32 rear_acceleration\n"
"float32 rear_distance\n"
"\n"
"uint32 checksum\n"
;
  }

  static const char* value(const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.manual);
      stream.next(m.thw);
      stream.next(m.alpha);
      stream.next(m.beta);
      stream.next(m.sensor2frontbumper);
      stream.next(m.sensor2rearbumper);
      stream.next(m.vel_gain);
      stream.next(m.vel_gain_low);
      stream.next(m.vel_gain_dec);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.u);
      stream.next(m.v);
      stream.next(m.yaw);
      stream.next(m.speed);
      stream.next(m.acceleration);
      stream.next(m.front_x);
      stream.next(m.front_y);
      stream.next(m.front_u);
      stream.next(m.front_v);
      stream.next(m.front_yaw);
      stream.next(m.front_speed);
      stream.next(m.front_acceleration);
      stream.next(m.front_distance);
      stream.next(m.rear_x);
      stream.next(m.rear_y);
      stream.next(m.rear_u);
      stream.next(m.rear_v);
      stream.next(m.rear_yaw);
      stream.next(m.rear_speed);
      stream.next(m.rear_acceleration);
      stream.next(m.rear_distance);
      stream.next(m.checksum);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CaccSensorPacket_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cacc_msgs::CaccSensorPacket_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cacc_msgs::CaccSensorPacket_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int16_t>::stream(s, indent + "  ", v.id);
    s << indent << "manual: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.manual);
    s << indent << "thw: ";
    Printer<float>::stream(s, indent + "  ", v.thw);
    s << indent << "alpha: ";
    Printer<float>::stream(s, indent + "  ", v.alpha);
    s << indent << "beta: ";
    Printer<float>::stream(s, indent + "  ", v.beta);
    s << indent << "sensor2frontbumper: ";
    Printer<float>::stream(s, indent + "  ", v.sensor2frontbumper);
    s << indent << "sensor2rearbumper: ";
    Printer<float>::stream(s, indent + "  ", v.sensor2rearbumper);
    s << indent << "vel_gain: ";
    Printer<int16_t>::stream(s, indent + "  ", v.vel_gain);
    s << indent << "vel_gain_low: ";
    Printer<int16_t>::stream(s, indent + "  ", v.vel_gain_low);
    s << indent << "vel_gain_dec: ";
    Printer<int16_t>::stream(s, indent + "  ", v.vel_gain_dec);
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "u: ";
    Printer<float>::stream(s, indent + "  ", v.u);
    s << indent << "v: ";
    Printer<float>::stream(s, indent + "  ", v.v);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "acceleration: ";
    Printer<float>::stream(s, indent + "  ", v.acceleration);
    s << indent << "front_x: ";
    Printer<float>::stream(s, indent + "  ", v.front_x);
    s << indent << "front_y: ";
    Printer<float>::stream(s, indent + "  ", v.front_y);
    s << indent << "front_u: ";
    Printer<float>::stream(s, indent + "  ", v.front_u);
    s << indent << "front_v: ";
    Printer<float>::stream(s, indent + "  ", v.front_v);
    s << indent << "front_yaw: ";
    Printer<float>::stream(s, indent + "  ", v.front_yaw);
    s << indent << "front_speed: ";
    Printer<float>::stream(s, indent + "  ", v.front_speed);
    s << indent << "front_acceleration: ";
    Printer<float>::stream(s, indent + "  ", v.front_acceleration);
    s << indent << "front_distance: ";
    Printer<float>::stream(s, indent + "  ", v.front_distance);
    s << indent << "rear_x: ";
    Printer<float>::stream(s, indent + "  ", v.rear_x);
    s << indent << "rear_y: ";
    Printer<float>::stream(s, indent + "  ", v.rear_y);
    s << indent << "rear_u: ";
    Printer<float>::stream(s, indent + "  ", v.rear_u);
    s << indent << "rear_v: ";
    Printer<float>::stream(s, indent + "  ", v.rear_v);
    s << indent << "rear_yaw: ";
    Printer<float>::stream(s, indent + "  ", v.rear_yaw);
    s << indent << "rear_speed: ";
    Printer<float>::stream(s, indent + "  ", v.rear_speed);
    s << indent << "rear_acceleration: ";
    Printer<float>::stream(s, indent + "  ", v.rear_acceleration);
    s << indent << "rear_distance: ";
    Printer<float>::stream(s, indent + "  ", v.rear_distance);
    s << indent << "checksum: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.checksum);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CACC_MSGS_MESSAGE_CACCSENSORPACKET_H
