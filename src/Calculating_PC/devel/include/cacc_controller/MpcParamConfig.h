//#line 2 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the cacc_controller package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __cacc_controller__MPCPARAMCONFIG_H__
#define __cacc_controller__MPCPARAMCONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace cacc_controller
{
  class MpcParamConfigStatics;

  class MpcParamConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(MpcParamConfig &config, const MpcParamConfig &max, const MpcParamConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const MpcParamConfig &config1, const MpcParamConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, MpcParamConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const MpcParamConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, MpcParamConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const MpcParamConfig &config) const = 0;
      virtual void getValue(const MpcParamConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T MpcParamConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T MpcParamConfig::* field;

      virtual void clamp(MpcParamConfig &config, const MpcParamConfig &max, const MpcParamConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const MpcParamConfig &config1, const MpcParamConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, MpcParamConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const MpcParamConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, MpcParamConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const MpcParamConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const MpcParamConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, MpcParamConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, MpcParamConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<MpcParamConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(MpcParamConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("vel_ref"==(*_i)->name){vel_ref = boost::any_cast<double>(val);}
        if("ds"==(*_i)->name){ds = boost::any_cast<double>(val);}
        if("dmin"==(*_i)->name){dmin = boost::any_cast<double>(val);}
        if("umax"==(*_i)->name){umax = boost::any_cast<double>(val);}
        if("umin"==(*_i)->name){umin = boost::any_cast<double>(val);}
        if("q0"==(*_i)->name){q0 = boost::any_cast<int>(val);}
        if("q1"==(*_i)->name){q1 = boost::any_cast<int>(val);}
        if("q2"==(*_i)->name){q2 = boost::any_cast<int>(val);}
        if("r"==(*_i)->name){r = boost::any_cast<int>(val);}
        if("sf"==(*_i)->name){sf = boost::any_cast<int>(val);}
        if("su"==(*_i)->name){su = boost::any_cast<int>(val);}
        if("sd"==(*_i)->name){sd = boost::any_cast<int>(val);}
      }
    }

    double vel_ref;
double ds;
double dmin;
double umax;
double umin;
int q0;
int q1;
int q2;
int r;
int sf;
int su;
int sd;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double vel_ref;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double ds;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double dmin;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double umax;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double umin;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int q0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int q1;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int q2;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int r;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int sf;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int su;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int sd;
//#line 228 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("MpcParamConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const MpcParamConfig &__max__ = __getMax__();
      const MpcParamConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const MpcParamConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const MpcParamConfig &__getDefault__();
    static const MpcParamConfig &__getMax__();
    static const MpcParamConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const MpcParamConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void MpcParamConfig::ParamDescription<std::string>::clamp(MpcParamConfig &config, const MpcParamConfig &max, const MpcParamConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class MpcParamConfigStatics
  {
    friend class MpcParamConfig;

    MpcParamConfigStatics()
    {
MpcParamConfig::GroupDescription<MpcParamConfig::DEFAULT, MpcParamConfig> Default("Default", "", 0, 0, true, &MpcParamConfig::groups);
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.vel_ref = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.vel_ref = 20.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.vel_ref = 1.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("vel_ref", "double", 0, "Reference speed in mps", "", &MpcParamConfig::vel_ref)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("vel_ref", "double", 0, "Reference speed in mps", "", &MpcParamConfig::vel_ref)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.ds = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.ds = 20.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.ds = 0.5;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("ds", "double", 0, "Ds", "", &MpcParamConfig::ds)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("ds", "double", 0, "Ds", "", &MpcParamConfig::ds)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.dmin = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.dmin = 20.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.dmin = 0.3;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("dmin", "double", 0, "Dmin", "", &MpcParamConfig::dmin)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("dmin", "double", 0, "Dmin", "", &MpcParamConfig::dmin)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.umax = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.umax = 3.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.umax = 1.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("umax", "double", 0, "Umax", "", &MpcParamConfig::umax)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("umax", "double", 0, "Umax", "", &MpcParamConfig::umax)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.umin = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.umin = 6.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.umin = 3.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("umin", "double", 0, "Umin", "", &MpcParamConfig::umin)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<double>("umin", "double", 0, "Umin", "", &MpcParamConfig::umin)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.q0 = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.q0 = 100;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.q0 = 30;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("q0", "int", 0, "Q0", "", &MpcParamConfig::q0)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("q0", "int", 0, "Q0", "", &MpcParamConfig::q0)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.q1 = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.q1 = 100;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.q1 = 1;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("q1", "int", 0, "Q1", "", &MpcParamConfig::q1)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("q1", "int", 0, "Q1", "", &MpcParamConfig::q1)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.q2 = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.q2 = 100;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.q2 = 1;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("q2", "int", 0, "Q2", "", &MpcParamConfig::q2)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("q2", "int", 0, "Q2", "", &MpcParamConfig::q2)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.r = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.r = 2000;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.r = 800;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("r", "int", 0, "R", "", &MpcParamConfig::r)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("r", "int", 0, "R", "", &MpcParamConfig::r)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.sf = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.sf = 1000;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.sf = 100;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("sf", "int", 0, "Sf", "", &MpcParamConfig::sf)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("sf", "int", 0, "Sf", "", &MpcParamConfig::sf)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.su = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.su = 1000;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.su = 1000;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("su", "int", 0, "Su", "", &MpcParamConfig::su)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("su", "int", 0, "Su", "", &MpcParamConfig::su)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.sd = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.sd = 1000;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.sd = 1000;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("sd", "int", 0, "Sd", "", &MpcParamConfig::sd)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(MpcParamConfig::AbstractParamDescriptionConstPtr(new MpcParamConfig::ParamDescription<int>("sd", "int", 0, "Sd", "", &MpcParamConfig::sd)));
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(MpcParamConfig::AbstractGroupDescriptionConstPtr(new MpcParamConfig::GroupDescription<MpcParamConfig::DEFAULT, MpcParamConfig>(Default)));
//#line 366 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<MpcParamConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<MpcParamConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<MpcParamConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    MpcParamConfig __max__;
    MpcParamConfig __min__;
    MpcParamConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const MpcParamConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static MpcParamConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &MpcParamConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const MpcParamConfig &MpcParamConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const MpcParamConfig &MpcParamConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const MpcParamConfig &MpcParamConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<MpcParamConfig::AbstractParamDescriptionConstPtr> &MpcParamConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<MpcParamConfig::AbstractGroupDescriptionConstPtr> &MpcParamConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const MpcParamConfigStatics *MpcParamConfig::__get_statics__()
  {
    const static MpcParamConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = MpcParamConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __MPCPARAMRECONFIGURATOR_H__