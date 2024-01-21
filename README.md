# n64-to-z64
Quick and dirty bulk N64 ROM converter for Mac and Linux users.

1. Made by someone who owns an Everdrive64 X7.

2. Motivated by all the romhack patches that require a z64 formatted (big-endian)
   ROM.

3. Used to automate the task of converting every game in the ROM directory from
   .n64 format (little-endian, 16-bit word size) into God's favorite ROM format.

4. Implemented as a shell command with very brief instructions, no installation
   required.

### Usage
Open up the terminal and run the following command, specifying which directory 
contains your ROMS:
```
./n64-to-z64.zsh [DIRECTORY]
```

Alternatively, you may naviagate to your "ROMs" directory and run the command with 
no arguments:
```
cd /my/rom/directory/
./n64-z64.zsh
```

All .z64 files are written into the same directory where the .n64 files were found, 
and upon success all .n64 files are moved into a subdirectory named 
```little-endian16``` .

### Comments
There is a way to do the entire C++ program's job with 1 line of sed. If you know
how, please send a request to add it to the documentation for BSD sed and GNU
sed. Alternatively, it could also likely be done with a single line of awk; 
likewise, please submit a doc pull request for the official awk repo (onetrueawk)
and/or GNU awk (gawk).
