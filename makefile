CC = clang++
TWIT_LIB_ROOT     = ./
BOOSTCONNECT_ROOT = ../BoostConnect/

CXXFLAGS = -std=c++11
INCDIR = -I$(BOOSTCONNECT_ROOT)include -I$(TWIT_LIB_ROOT)include
LIBDIR = -L$(BOOSTCONNECT_ROOT)lib -L$(TWIT_LIB_ROOT)lib
LIB = -lssl -lcrypto -lpthread -lboostconnect -ltwit-library -lssl -lcrypto -lboost_thread -lboost_system

all : target sample
target: ./lib/libtwit-library.a
sample: ./sample/sample.out
run : ./sample/sample.out
	$<

./lib/libtwit-library.a : ./src/twit-library.cpp
	cd $(BOOSTCONNECT_ROOT) && $(MAKE)
	$(CC) -c $(CXXFLAGS) -o $@ $< $(INCDIR)

./sample/sample.out : ./sample/sample.cpp
	$(CC) $(CXXFLAGS) -o $@ $< $(INCDIR) $(LIBDIR) $(LIB)

clean:
	rm ./lib/ltwit-library.a
	rm ./sample/sample.out
