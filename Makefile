NAME = WahWM
CXXFLAGS = -Iinclude
LDFLAGS = -lxcb

all: ${NAME}

${NAME}: wm.cpp include/${NAME}.hpp
	g++ -o ${NAME} ${LDFLAGS} ${CXXFLAGS} wm.cpp

clean:
	rm -rf WahWM
