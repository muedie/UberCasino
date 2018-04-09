

OSPL_LIBS = -lpthread -lddskernel -ldcpssacpp
LIBS=-L${OSPL_HOME}/lib ${OSPL_LIBS} -lboost_system -lboost_thread

CFLAGS = -Wall -O0 -g -I. -I./include -I${OSPL_HOME}/include/dcps/C++/SACPP -I${OSPL_HOME}/include/sys
CXXFLAGS = -std=c++11


FL_COMP_FLAGS=$(shell fltk-config --cflags --cxxflags)
FL_LINK_FLAGS=$(shell fltk-config --use-images --ldstaticflags)

all: Player


IDL_GENERATED_H= \
                 ccpp_UberCasino.h \
                 UberCasinoDcps.h \
                 UberCasinoDcps_impl.h \
                 UberCasino.h \
                 UberCasinoSplDcps.h

IDL_GENERATED_CPP=\
                 UberCasino.cpp \
                 UberCasinoDcps.cpp \
                 UberCasinoDcps_impl.cpp \
                 UberCasinoSplDcps.cpp

IDL_GENERATED=${IDL_GENERATED_H} ${IDL_GENERATED_CPP}

${IDL_GENERATED}: idl/UberCasino.idl
	${OSPL_HOME}/bin/idlpp -l cpp idl/UberCasino.idl

PLAYER_FILES = src/*.cpp
PLAYER_H_FILES = include/*.h


Player: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} src/main.cpp ${PLAYER_FILES} ${PLAYER_H_FILES}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LIBS} ${FL_COMP_FLAGS} ${FL_LINK_FLAGS}


clean:
	-rm -f Player
	-rm -f ${IDL_GENERATED_H} ${IDL_GENERATED_CPP}
	-rm -f ospl-error.log ospl-info.log
