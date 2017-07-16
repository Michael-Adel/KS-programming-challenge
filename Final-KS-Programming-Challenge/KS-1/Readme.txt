Note: These files are made to be built on Linux 

========================
BUILDING THE FILE STEPS:
========================

1) Open the Terminal and go to the directory where you have the files

2) write the command: make

3) Then write the command: ./print

a message will appear saying "hello from the source code"
To add a new platform you just have to define it in "printAPI.h" and change the "PLATFORM" definition in "printConsole.h" from "0" to the new platform number. "0" is for "PLATFORM A".

4) After finishing you can type : 'make clean' to make everything return as it was 
