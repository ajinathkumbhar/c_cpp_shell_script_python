CC = g++
CPPFLAGS = -Wall
TARGET_LIST = \
	STL_sorting \
	template_class \
	template

all: $(TARGET_LIST) 

STL_sorting: STL_sorting.cpp 
	$(CC) $(CPPFLAGS) $@.cpp -lstldata -o $@	

template_class: template_class.cpp
	$(CC) $(CPPFLAGS) $@.cpp -o $@

template: template.cpp
	$(CC) $(CPPFLAGS) $@.cpp -o $@
clean:
	rm -rf $(TARGET_LIST)
