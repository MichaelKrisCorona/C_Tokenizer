CFLAGS= -g -O3


all:tester


#dependencies
tester.o:tokenizer.h
tester.o:history.h



#target
tester:tester.o
	cc -o $@ $^ $(CFLAGS)



clean:
	rm -f *.o tester
