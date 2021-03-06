## Chapter 1


### Compilation

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Interpreted languages have dynamic types meaning that variables are stored in memory while the program is running and they are accessible by the program.

2) Name two advantages of static typing over dynamic typing.

Errors can be caught faster with static typing because checks can happen before the program starts running. Also, declaring types at the compile type saves space.

3) Give an example of a static semantic error.

An example of a static semantic error would be passing a float as the index of an array.

4) What are two reasons you might want to turn off code optimization?

It is probably a good idea to develop with optimization so that your code will be bug free even if the optimization would remove your bug. Also, optimization will make your program longer to compile.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

GCC is  designed to generate code for the machine that you are running it on. Therefore, if you are using gcc on a different computer architecture then you might get different results.

6) If you spell a variable name wrong, or if you spell a function name wrong, 
the error messages you get might look very different.  Why?

If you spell a variable wrong, you would get an error from the compiler because it is a syntax error. On the other hand, if you spell a function wrong, you would get an error from the linker.

7) What is a segmentation fault?

A segmentation fault is an error that occurs when you try to read or write an incorrect location in memory.

## Chapter 2


### Processes

1) Give a real-world example of virtualization (ideally not one of the ones in the book).

One example of virtualization is a flight simulator where your software is giving all the information that a real plane would, but you don't have a real plane that can crash if something goes wrong.

2) What is the difference between a program and a process?

A program is simply a set of instructions while a process  is a software object run by the operating system to represent the running program.

3) What is the primary purpose of the process abstraction?  What illusion does the process abstraction create?

The purpose of process abstraction is to ensure that multiple processes do not collide with each other and try to store data in the same location. The illusion that it creates is that each process has its own computer to run on. 

4) What is the kernel?

The kernel is the part of the operating system that is responsible for core capabilities like creating threads. 

5) What is a daemon?

A daemon is a process that runs in the background and provides operating system services. 

## Chapter 3


### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

Six bits are needed to specify all the values of the alphabet because 2^5 is only 32. 

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

2^32 characters or 4,294,967,296 characters ignoring the details of the encoding scheme.

3) What is the difference between "memory" and "storage" as defined in Think OS?

Storage is defined as non-volatile storage such as a hard drive or solid state drive, while memory is usually some kind of random access memory (RAM). When a computer is shut off, the contents of the RAM is lost, while the contents of the storage is not. 

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

GiB stands for gibibyte which is a binary unit and GB stands for gigabyte which is a decimal unit. One gibibyte is 2^30 bytes and one gigabyte is 10^9 bytes which is a %6.87 difference. 

5) How does the virtual memory system help isolate processes from each other?

Each process generates virtual addresses which are translated to physical addressess by the OS. Since each process manages its own virtual memory, they are inherently separated from each other.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

They are probably located at opposite ends so that they don't collide with each other as they grow. 

7) What Python data structure would you use to represent a sparse array?

I would probably use a dictionary over a list. 

8) What is a context switch?

A context switch is a mechanism that can interrupt a running process, save its state, and then run a different process. 

In this directory, you should find a subdirectory named `aspace` that contains `aspace.c`.  Run it on your computer and compare your results to mine.
  
My results were:
Address of main is 0x40057d
Address of global is 0x60104c
Address of local is 0x7ffd59b264f4
Address of p is 0x2009010

1) Add a second call to `malloc` and check whether the heap on your system grows up (toward larger addresses).  

Yes, the address of p increased. 

2) Add a function that prints the address of a local variable, and check whether the stack grows down.  

Yes, the stack grows down. The address of local is 0x7fff033a35fc and the address of the local print statement is lower at a value of 0x7fff033a35dc.

3) Choose a random number between 1 and 32, and allocate two chunks with that size.  
How much space is there between them?  Hint: Google knows how to subtract hexadecimal numbers.

I chose number 22. 
Address of chunk_1 is 0x10b4130
Address of chunk_2 is 0x10b4150
0x10b4150 - 0x10b4130 = 0x20 = 32. 

## Chapter 4


### Files and file systems

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

File systems provide a convient and consistent method of storing files. A file is a sequence of bytes, but persistent storage is block-based. 

2) What information do you imagine is stored in an `OpenFileTableEntry`?

The address of the file, if the file is open for reading/writing, and the current position in the file.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

They work to fill the gap between main memory and persistant storage by using block transfers, prefetching, buffering, and caching. 

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

The message was probably in a buffer, stored in RAM, so when the power cut occured, the data was lost.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

A FAT is probably easier to add/remove stuff from. An inode is probably more reliable in that it is less likely to lose the whole file if one block is corrupted.

6) What is overhead?  What is fragmentation?

Overhead is the space taken by the data structures used by the allocator. Fragmentation is the left over/unused space.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

It is good because it makes things simpler for using standard input/output for programming. It is bad because its not accurate(everything is bytes) and could abstract away useful information. 

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).


## Chapter 5


### Bits and bytes

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

4) Following the example in Section 5.4, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.



## Chapter 6


### Memory management

1) Which memory management functions would you expect to take constant time?  Which ones take time proportional to the size of the allocated chunk?

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

b) Writing to unallocated memory.

c) Reading from a freed chunk.

d) Writing to a freed chunk.

e) Failing to free a chunk that is no longer needed.


3) Run

    ps aux --sort rss

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)



## Chapter 7


### Caching

1) What happens if a program writes a new value into the program counter?

2) What is the fundamental problem caches are meant to solve?

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

Run the cache code on your laptop or another computer and see if you can infer the cache size and block size.  
If you can find the technical specifications for your computer, see if your inferences are right.

1) In this directory you should find a subdirectory named `cache` that contains `cache.c` and supporting files.  Read `cache.c`, then run `make` and `./cache`.

2) Run `python graph_data.py` to see the results.  What can you infer about the cache structure on your computer?


## Chapter 8


### Multitasking

1) What is the kernel's most basic task?

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

3) What is the difference between an interrupt and a context switch?

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

5) Why might a scheduler want to give higher priority to an I/O bound process?

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.  Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores" to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; this is really how I make French toast.)



## Chapter 9


### POSIX threads and mutexes

As you read Chapter 9, you should compile and run the example code.  By the nature of multi-threaded programs, you results will probably be different from mine, possibly in interesting ways.

1) Why does each thread have its own stack?

2) What does the `gcc flag -lpthread` do?

3) What does the argument of `pthread_exit` do?

4) Normally the same thread that created a thread also waits to join it.  What happens if another thread tries to join a thread it did not create?

5) What goes wrong if several threads try to increment a shared integer at the same time?

6) What does it mean to "lock a mutex"?



## Chapter 10


### Condition variables

1) What does it mean to say that a data structure is thread safe?

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

4) When a thread calls cond_wait, why does it have to unlock the mutex before blocking?

5) When a thread returns from cond_wait, what do we know is definitely true?  What do we think is probably true?

6) What happens if you signal a condition variable when there are no waiting threads?

7) Do you have to lock the mutex to signal a condition variable?

8) Does the condition have to be true when you signal a condition variable?


 
## Chapter 11


### Semaphores in C
