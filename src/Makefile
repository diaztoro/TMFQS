#CC  =   icpc
CC  =   mpiicpc
#CFLAGS  = -g 
CFLAGS  = 
OTHERFLAGS = -c

testSim: testSim.o quantumRegister.o
	$(CC) $(CFLAGS)  testSim.o quantumRegister.o -o test

testSim.o: testSim.cpp
	$(CC)  $(CFLAGS) $(OTHERFLAGS) testSim.cpp

quantumRegister.o : quantumRegister.cpp
	$(CC)  $(CFLAGS) $(OTHERFLAGS) quantumRegister.cpp

clean: 
	rm -f *.o
