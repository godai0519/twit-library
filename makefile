CC := clang++
TWIT_LIB_ROOT     := ./
BOOSTCONNECT_ROOT := ../BoostConnect/

CXXFLAGS = -std=c++11
CXX_DEBUG_FLAGS   = $(CXXFLAGS) -g
CXX_RELEASE_FLAGS = $(CXXFLAGS) -O2

CPPFLAGS = -I$(BOOSTCONNECT_ROOT)include -I$(TWIT_LIB_ROOT)include
LDFLAGS  = -L$(BOOSTCONNECT_ROOT)lib -L$(TWIT_LIB_ROOT)lib -lpthread -lssl -lcrypto -lboost_thread -lboost_system -lboostconnect -ltwit-library

TARGET = twit-library
DEBUG_TARGET   = ./lib/lib$(TARGET)d.a
RELEASE_TARGET = ./lib/lib$(TARGET).a

SRC_LIST := $(sort $(dir $(shell find . -name '*.hpp' -or -name '*.ipp')))
SAMPLES = ./sample/sample.out

all : debug release
debug :   $(DEBUG_TARGET)   $(SRC_LIST)
release : $(RELEASE_TARGET) $(SRC_LIST)
sample : release $(SAMPLES)

$(DEBUG_TARGET) : ./src/twit-library.cpp
	cd $(BOOSTCONNECT_ROOT) && $(MAKE) debug
	$(CC) -c $(CXX_DEBUG_FLAGS) -o $@ $< $(CPPFLAGS)

$(RELEASE_TARGET) : ./src/twit-library.cpp
	cd $(BOOSTCONNECT_ROOT) && $(MAKE) release
	$(CC) -c $(CXX_RELEASE_FLAGS) -o $@ $< $(CPPFLAGS)

./sample/sample.out : ./sample/sample.cpp
	$(CC) $(CXX_RELEASE_FLAGS) -o $@ $< $(CPPFLAGS) $(LDFLAGS)

clean:
	rm ./lib/libtwit-libraryd.a
	rm ./lib/libtwit-library.a
	rm ./sample/sample.out
