CC       = g++
PIC	 = -fPIC 
CPPFLAGS = -Wall
SRC	 = STL_data.cpp
INCLUDE	 = STL_data.h 
CPPFLAGS_LIB = -shared -Wl,-soname,
 

libstldata: STL_data_obj
	$(CC) $(CPPFLAGS) $(CPPFLAGS_LIB)$@.so -o $@.so *.o

STL_data_obj: $(SRC)
	$(CC) $(CPPFLAGS) $(PIC) -c $(SRC)

#.PHONY: libstldata 
install: libstldata   
	$(shell sudo cp libstldata.so /usr/lib/)
	$(shell sudo cp *.h /usr/include/)

#clean:
#	rm -rf *.o libstldata*


