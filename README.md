# n64-to-z64
Quick and dirty bulk N64 ROM converter for Mac and Linux users.

1. Made by someone who owns an Everdrive64 X7.

2. Motivated by all the romhack patches that require a z64 formatted (big-endian)
ROM.

3. Used to automate converting every game in the ROM directory to God's favorite
ROM format.

### Usage (no args)
```
n64-to-z64.zsh [DIRECTORY]
```
If no directory is specified, the default is the current directory.

All .z64 files are written into the same directory, and all .n64 files are moved
into a subdirectory named little-endian16.

### Comments
There is a way to do the entire C++ program's job with 1 line of sed. If you know
how, please send a request to add it to the documentation for BSD sed and GNU
sed.
