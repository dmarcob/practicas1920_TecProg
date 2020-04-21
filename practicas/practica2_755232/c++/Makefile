PROG:=main
SRCS:=main.cc expression.cc ramaSuma.cc ramaResta.cc ramaMult.cc ramaDivi.cc prioridad.cc hojaVariable.cc hojaConstante.cc rama.cc

CXX:=g++ -std=c++11

OBJS:=$(SRCS:.cc=.o)
DEPS:=$(SRCS:.cc=.d)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cc
	$(CXX) -MMD -c $<

.PHONY: edit go

edit:
	@geany -s -i $(SRCS) *.h &

clean:
	@rm -f $(PROG) *.o *.d core tags

-include $(DEPS)
