cc=g++
args=-O2
src=$(wildcard *.cpp)
objs=$(src:.cpp=.o)

output=manticore

.cpp.o:
	@echo "CC" $<
	@$(cc) $(args) -c $< -o $@

make: $(objs)
	@echo "CC" $(output)
	@$(cc) $(args) *.o -o $(output)

clean:
	rm -f *.o
	rm -f $(output)
