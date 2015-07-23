# makefile to build IAM Library

BIN	=   bin
SRC	=   src
LIB	=   lib
INCLUDE	=   include
OBJ	=   obj
SOURCES	=   $(wildcard $(SRC)/*.cpp)
OBJS	=   $(addprefix $(OBJ)/, $(notdir $(SOURCES:.cpp=.o)))

LOGGER_LIB_SHARED = liblogger.dylib
LOGGER_LIB_STATIC = liblogger.a

CD	=   cd
CC	=   gcc
CXX	=   g++
AR	=   ar -rv
LD	=   g++ -dynamiclib -arch x86_64
MV	=   mv
RM	=   rm
MAKE	=   make
MD	=   mkdir -p

CFLAGS	=   -Wall -O3 -c
CPPFLAGS=   -Wall -g -ansi -I$(INCLUDE)
#LDFLAGS	=   -L$(LIB) -liam

#
all : dirs $(LOGGER_LIB_STATIC) $(LOGGER_LIB_SHARED) test

dirs :
	if [ ! -d "./$(LIB)" ]; then	\
	    $(MD) $(LIB);		\
	fi
	if [ ! -d "./$(OBJ)" ]; then	\
	    $(MD) $(OBJ);		\
	fi
	
$(LOGGER_LIB_STATIC) : $(OBJS)
	$(AR) $(LOGGER_LIB_STATIC) $(OBJS)
	$(MV) $(LOGGER_LIB_STATIC) $(LIB)

$(LOGGER_LIB_SHARED) : $(OBJS)
	$(LD)  -o $(LOGGER_LIB_SHARED) $(OBJS)
	$(MV) $(LOGGER_LIB_SHARED) $(LIB)

$(OBJ)/%.o : $(SRC)/%.c
	@echo Creating $@ with $^
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	@echo Creating $@ with $^
	$(CXX) -c $(CPPFLAGS) $< -o $@

test:
	$(CXX) -o test test.cpp -Iinclude -Llib -llogger

# **************** Clean **********************
.PHONY: clean_objects

clean:
	@echo Cleaning all objects...
	$(RM) $(OBJS)
	$(RM) $(LIB)/$(LOGGER_LIB_STATIC)
	$(RM) $(LIB)/$(LOGGER_LIB_SHARED)
	$(RM) test

clean_objects:
	$(RM) $(OBJ)/*
	$(RM) $(OBJ)/*.*~

#
#LDFLAGS=$(OPENCV_LIB) $(XIMEA_LIB)
#
#ifeq ($(OS),Windows_NT)
#    CCFLAGS += -D WIN32
#    ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
#    	CFLAGS += -D AMD64
#    endif
#    ifeq ($(PROCESSOR_ARCHITECTURE),x86)
#    	CFLAGS += -D IA32
#    endif
#else
#    UNAME_S := $(shell uname -s)
#    ifeq ($(UNAME_S),Linux)
#	CFLAGS += -D LINUX -fPIC
#	OPENCV_LIB=-lopencv_core \
#		    -lopencv_highgui
#	
#	UNAME_P := $(shell uname -p)
#	ifeq ($(UNAME_P),x86_64)
#	    CFLAGS += -D AMD64
#	    XIMEA_LIB=-L/opt/XIMEA/api/X64
#	endif
#	ifneq ($(filter %86,$(UNAME_P)),)
#	    CFLAGS += -D IA32
#	    XIMEA_LIB=-L/opt/XIMEA/api/X32
#	endif
#	ifneq ($(filter arm%,$(UNAME_P)),)
#	    CFLAGS += -D ARM
#	    XIMEA_LIB=-L/opt/XIMEA/api/ARM
#	endif
#	XIMEA_LIB += -lm3api
#	VIDEO_LIB = libiam.so
#	LD=g++ -shared
#    endif
#    ifeq ($(UNAME_S),Darwin)
#	CFLAGS += -D OSX
#	XIMEA_LIB=-framework m3api
#	OPENCV_LIB=-lopencv_core \
#		    -lopencv_highgui
#	VIDEO_LIB = libiam.dylib
#	LD=g++ -dynamiclib -arch x86_64
#    endif
#endif