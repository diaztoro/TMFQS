#CC  =   icpc
CC  =   mpiicpc
DEBUG_FLAG  = -g 
#DEBUG_FLAG  = 
CXXFLAGS  = -c
INCS  = -I /usr/local/zfp/include
LIBS = -L /usr/local/zfp/lib64 -lzfp

testSim: testSim.o quantumRegister.o utils.o
	$(CC) $(INCS) $(LIBS) $(DEBUG_FLAG) testSim.o quantumRegister.o utils.o -o execTest

testSim.o: testSim.cpp
	$(CC) $(INCS) $(CXXFLAGS) $(DEBUG_FLAG) testSim.cpp

quantumRegister.o : quantumRegister.cpp
	$(CC) $(INCS) $(CXXFLAGS) $(DEBUG_FLAG) quantumRegister.cpp

utils.o : utils.cpp
	$(CC) $(INCS) $(CXXFLAGS) $(DEBUG_FLAG) utils.cpp

clean: 
	rm -f *.o test
