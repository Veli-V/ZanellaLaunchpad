'''
Joystick Module - LucasZanella.com - 18/06/2014
This module integrates your joystick (or HID) to the MIDI environment created 
in my project, but it can also work alone (together with the proper MIDI modules) 
if you don't want to use arduino in your project. 
'''

#This module allows you to create buttons and assign it to the timeline module

class button:
    def __init__(self):
        self.type = 'fixed'
        self.state = 0
        self.
