'''
keys_manager.py  - LucasZanella.com - 18/06/2014
This module deals with the type of keys. Arduino can be unstable while
sensing your input (it can trigger on/off messages while you're holding
the key with your finger, for example) so this module deals with this
'noise', by filtering the 'signal' and making it 'continuous'.
'''

keytypes = ['hit', 'hold', 'var'] #types of keys in the instrument (intuitive names, 'var' means variable keys)
keys = [] #list of all the keys you're gonna use in your project (each key is an object of the class 'Key')

#simulated area
nkeys = [20, 30, 40] #simulation
nkeys_total = 90 #make this the sum of all nkeys elements
##

class Key: #class that stores information about each individual button
    #each key (or button) has a type, value and hold state
    def __init__(self, key_type):
        self.type = key_type
        self.value = 0
        self.hold = False
    def hit(self):
        self.value = 0
    def hold(self):
        if hold:
            hold = False
        else:
            hold = True
    def var(self, new_value): #this method allows you to change the 'var' property
        self.value = new_value
    
for i in range(0, len(keytypes)):
    for k in range(0, nkeys[i]):
        x  = Key(keytypes[i])
        keys.append(x)
