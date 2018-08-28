---C---
Q:  Rate yourself in C and CPP. (7/6)
Q:  How process executes by system OR how main gets executes by system ?
Ans:
1.Preprocessing is the first pass of any C compilation. It processes include-files, conditional compilation instructions and macros.
2.Compilation is the second pass. It takes the output of the preprocessor, and the source code, and generates assembler source code.
3.Assembly is the third stage of compilation. It takes the assembly source code and produces an assembly listing with offsets. The assembler output is stored in an object file.
4.Linking is the final stage of compilation. It takes one or more object files or libraries as input and combines them to produce a single (usually executable) file. In doing so, it resolves references to external symbols, assigns final addresses to procedures/functions and variables, and revises code and data to reflect new addresses (a process called relocation).

gcc -v test.c ----- for all verbose output
gcc -E test.c ----- for preprocessing stage
gcc -S test.c ----- for assembly stage
gcc -o test.o test.c --- for linker stage 

test.o is an ELF 

ELF ? It's one of several object and executable file formats used on Unix systems. For our discussion, the interesting thing about ELF is its header format. Every ELF executable has ELF header

objdump -f test.o 

start address 0x080482d0
objdump --disassemble test.o
080482d0 <_start>:



Q: Can we replaced main fuction OR Is there any way to execute program without main fuction ?
Q: How process loader knows the main() function symbol address ?
Q: #define vs Const
Q: Count the no of 1s in decimal number and what is complexity of process. ( hint (O)n and (O)0)
Q: Did you used optimisation and what is (O)n optimisation. ?
Q: What are the optimisation techiques and list some of them 
Q: Take your first name and count each character occurence and arrange them in to A-Z order.
Q: Explain memory allocation in c and cpp.
Q: Did you faced malloc() failed ever ? if failed then give example.
Q: What is malloc max limit and how to modify.
Q: How to delete a single linked list node using single pointer?
Q: What are the oop's concept ?
Q: Explain any one oops concept and where you used ? How oops helps you to resolve your problem ?
Q: Loop optimization
Q: Macro vs inline 
Q: Camera pipeline 
Q: Inheritance 
Q: Thread sync.(condition variable, shared mem and other types)
Q: Thread deadlock and example and how to avoid it.
Q: Malloc free() call option. (Free allocated mem without free() call)
Q: ION memory 
Q: Binder IPC and it's alternate options in android
Q: Count bit set in unsinged char byte (hint lookup table)
Q: Consider 100 threads and a single function, threads calles function. So, how much stack frame created ? Is function stack frame is inside thread's stack frame ?
Q: Segmentation fault and page fault.
Q: Strace tool and valgrid tool
Q: Treble project in details with CTS and VTS
Q: Static and extern for function 
Q: Storage classess
Q: Little endian and Big indian 
Q: Output ? 
int main() {
int arr[2] = {1,2};
arr++;
}
  
Q: Complete boot process in details (PWR BUTTON PRESS, PBL,SBL,LK,KERNEL,DRIVERS PROBE,INIT,ZYGOATE, SYSTEM SERVER and APPLICATION)
Q: Android debugging procedure with example ( Native issue and app issue)
Q: Filesystem ( ext4, fat, jff2s, squasfs, etc)
Q: Qualcomm android partitions (all)
Q: mmap() system call
Q: const pointer and all const possiblities with pointer.

