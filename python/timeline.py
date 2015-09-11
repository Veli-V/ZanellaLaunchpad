'''
timeline.py module by LucasZanella.com - 13/06/2014

With this module you can create a live sequence of notes that repeats like a loop, until
you press some button that will turn this loop off. Each timeline is a loop, and can be 
creted or destroyed. It's you who define wich button will create and destroy each timeline.
The structure of a timeline is the following list
['moment that was created', midi_message_1, midi_message_2, ..., END_OF_TIMELINE]
Each timeline is contained in the timelines[] list.
'''


import serial
#import json 
import keys_manager
import time

END_OF_TIMELINE = 'end'

#time function
ms = lambda: int(round(time.time() * 1000))#get the current time in milisseconds

timelines = []

#create a new timeline
def create_timeline(time):
    timelines.append([ms()])

#add an MIDI message to some timeline:
def record_note(n,timeline, time, status, byte1, byte2):
    timelines[n].append([time, status, byte1, byte2])

#verify if there's a note in current_timeline for the given time in milisseconds:
def correspond(time, current_timeline):
    if time in current_timeline:
        return True
    elif END_OF_TIMELINE in current_timeline:
        return END
    else:
        return False

def is_active(timeline):
    return True #check if the current timeline is in active mode
    
#SIMULTION AREA
create_timeline(ms())

record_note(0,timelines[0], ms()+1000, 0x90, 0x8080, 0x8071)
record_note(0,timelines[0], ms()+2000, 0x91, 0x8240, 0x8271)
record_note(0,timelines[0], ms()+3000, 0x95, 0x8410, 0x8111)
record_note(0,timelines[0], ms()+3000, END_OF_TIMELINE, 0x8410, 0x8111)
#END

#loop that take care of the timelines
while True:
    #check something in all existent timelines
    for r in range(0, len(timelines)):
        if is_active(timelines[r]):
            if correspond(ms(), timelines[r]) and correspond(ms(), timelines[r])!=END_OF_TIMELINE:
                pass #launch this note
            elif correspond(ms(), timelines[r]) == END_OF_TIMELINE:
                pass #reset timeline r
