#!/usr/bin/env python

import numpy as np
import rospy as rp
from sensor_msgs.msg import Joy
from joy_to_raspberrypi.msg import Controller

class JoyConvert(object):

  def __init__(self):
    self._joy_sub=rp.Subscriber('Joy',Joy,self.joyCallback,queue_size=100)
    self._joy_pub=rp.Publisher('joy_cont',Controller,queue_size=100)
    self.state=[0,0,0,0,0]

  def joyCallback(self,joy_msg):
    self.state[0]=int((joy_msg.axes[0])*100)
    self.state[1]=int((joy_msg.axes[1])*100)
    self.state[2]=int((joy_msg.axes[2])*100)
    self.state[3]=int((joy_msg.axes[3])*100)
    for i in range(12):
      if(joy_msg.buttons[i]):
        self.state[4]|=1<<i
      else:
        self.state[4]&=~(1<<i)
#上下キー
    if joy_msg.axes[4]>0:
      self.state[4]|=1<<12
    else:
      self.state[4]&=~(1<<12)

    if joy_msg.axes[4]<0:
      self.state[4]|=1<<13
    else:
      self.state[4]&=~(1<<13)

    if joy_msg.axes[5]>0:
      self.state[4]|=1<<14
    else:
      self.state[4]&=~(1<<14)

    if joy_msg.axes[5]<0:
      self.state[4]|=1<<15
    else:
      self.state[4]&=~(1<<15)

if __name__=='__main__':
  rp.init_node('joy_cont')
  rate=rp.Rate(10)
  joy_cont=JoyConvert()
  cont=Controller()
  while not rp.is_shutdown():
      cont.analog[0]=joy_cont.state[0]
      cont.analog[1]=joy_cont.state[1]
      cont.analog[2]=joy_cont.state[2]
      cont.analog[3]=joy_cont.state[3]
      cont.buttons=joy_cont.state[4]
      rp.loginfo(cont)
      joy_cont._joy_pub.publish(cont)
      rate.sleep()

