# https://www.softwaretestinghelp.com/cpp-makefile-tutorial/

# the compiler: gcc for C program, define as g++ for C++
  CC = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  CFLAGS  = -g -Wall -Wuninitialized -Werror
 
  # The build target 
  TARGET = generator
 
  all: $(TARGET)
 
  $(TARGET): $(TARGET).cpp
		$(CC) $(CFLAGS) -o out $(TARGET).cpp
 
  clean:
		$(RM) out