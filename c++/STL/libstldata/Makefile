CC       = g++
PIC	 = -fPIC 
CPPFLAGS = -Wall
SRC	 = STL_data.cpp
INCLUDE	 = STL_data.h 
CPPFLAGS_LIB = -shared -Wl,-soname,
	     
all: libstldata

STL_data_obj: $(SRC)
	$(CC) $(CPPFLAGS) $(PIC) -c $(SRC)

libstldata: STL_data_obj
	$(CC) $(CPPFLAGS) $(CPPFLAGS_LIB)$@.so.1 -o $@.so.1.0 *.o

clean:
	rm -rf *.o libstldata*


#g++ -shared -Wall -Wl,-soname,libstl.so.1 -o libstl.so.1.0 STL_data.o
