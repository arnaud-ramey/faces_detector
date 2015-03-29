/*!
 * compressed_rounded_image_transport is an image_transport plugin for float images.
 * \author Arnaud Ramey ( arnaud.a.ramey@gmail.com )
            -- Robotics Lab, University Carlos III of Madrid
 * \date Jan. 2012
  */

#ifndef TIMER_ROS_H
#define TIMER_ROS_H

#include <ros/ros.h>

class TimerRos {
public:
  typedef float Time;
  const static Time NOTIME = -1;

  TimerRos() {
    if (!ros::Time::isValid()) {
      was_reset = false;
    }
    else
      reset();
  }
  ~TimerRos() {}

  //! reset time to 0
  inline void reset() {
    _begin = ros::Time::now();
    was_reset = true;
  }

  //! get the time since ctor or last reset (seconds)
  inline Time getTimeSeconds() {
    if (!was_reset) {
      ROS_WARN("TimerRos: Could not initiate the timer in constructor. "
               "This is first call of time(), doing it now. "
               "You should call reset() when you start using your timer.");
      reset();
    }
    return (ros::Time::now() - _begin).toSec();
  }

  //! get the time since ctor or last reset (milliseconds)
  inline Time getTimeMilliseconds() {
    return getTimeSeconds() * 1000.f;
  }

  //! get the time since ctor or last reset (milliseconds)
  inline Time time() {
    return getTimeMilliseconds();
  }

  //! print time needed for a task identified by its string
  inline void printTime(const char* msg) {
    ROS_INFO("Time for %s : %g ms.", msg, getTimeMilliseconds());
  }

  //! print time needed for a task identified by its string
  inline void printTime_factor(const char* msg, const int times) {
    ROS_INFO("Time for %s (%i times) : %g ms.",
             msg, times, getTimeMilliseconds() / times);
  }

private:
  ros::Time _begin;
  bool was_reset;
}; // end class TimerRos

#endif // TIMER_ROS_H
