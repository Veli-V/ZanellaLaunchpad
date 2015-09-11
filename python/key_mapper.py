'''
key_mapper.py - LucasZanella.com - 18/06/2014

This module is not necessary for the project, I just created it as a tool for
generating new .json files if you needs... This will allow you to create your
own MIDI mapping for your instrument. You just have to create a rule and then
the module will create the .json entries for you.
Each .json file is a >mode<, this module will create one of all the infinite modes
you can have. It means that you can change between various modes, so you don't need 
to map all your keys to this mode, just the ones you need for this current mode. 
'''

#if you run this without modifying anything, it will create the mode1.json file of the novation launchpad

#number of keys your mode will use
nkeys = 64
key_info = ''
for k in range(0, nkeys):
    status_byte = "\"0x90\""
    data_byte_1 = "\"0x71\""
    data_byte_2 = "\"0x76\""
    add_data = "\"type\":\"hit\",\n\u0009\u0009\u0009\u0009\"color\":\"blue\""
    comma = ","
    if k==nkeys-1:
        comma = ""
    key_info = key_info + ('''\u0009\u0009\"%s\": {
                \n\u0009\u0009\u0009\"status_byte\": %s,
                \n\u0009\u0009\u0009\"data_byte_1\": %s,
                \n\u0009\u0009\u0009\"data_byte_2\": %s,
                \n\u0009\u0009\u0009\"additional_data\": {\n\u0009\u0009\u0009\u0009%s \n\u0009\u0009\u0009}
                \n\u0009\u0009}%s\n'''
                % (k,status_byte, data_byte_1, data_byte_2, add_data, comma)
                )
text_file = open("mode1.json", "w")
text_file.write("{\n\u0009\"launchpad\": {\n %s \n\u0009}\n}" % (key_info))
text_file.close()
print('file saved')
