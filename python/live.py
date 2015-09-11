'''
live.py module - LucasZanella.com - 14/06/2014
Concepts needed to understand this file:
keysStructure is the var that holds the name of the .json file used in this program
structure is the var that holds the data of the json file
listOfKeysInConfigFile is the var that holds the keys of the 'launchpad' node of the json file
numberOfKeysInConfigFile is the number of keys provided in the configuration file
'''

import json 
import keys_manager

keysStructure = "mode1.json" #name of the file that contais the map for each key
structure = json.loads(open(keysStructure).read()) #loads the file
listOfKeysInConfigFile = structure['launchpad'] #enters the keys node on the .json file. Now, listOfKeysInConfigFile[0], for example, is the 0th key.

numberOfKeysInConfigFile = len(listOfKeysInConfigFile) #calculates the number of keys we have in that structure


print(numberOfKeysInConfigFile)