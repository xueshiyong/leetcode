target = run
cflags = -c
execute = g++
src = $(wildcard ./BackSearch/*.cpp) $(wildcard ./Dynamic/*.cpp) \
$(wildcard ./Greedy/*.cpp) $(wildcard ./HashSet/*.cpp) \
$(wildcard ./List/*.cpp) $(wildcard ./Mat/*.cpp) \
$(wildcard ./Math_fun/*.cpp) $(wildcard ./monotonic_stack/*.cpp) \
$(wildcard ./Sort/*.cpp) $(wildcard ./Stack/*.cpp) \
$(wildcard ./String/*.cpp) $(wildcard ./Test/*.cpp) \
$(wildcard ./Tree/*.cpp) $(wildcard ./Vector/*.cpp) \
$(wildcard ./*.cpp)

objs = $(patsubst *.cpp, *.o, $(src))


$(target):$(objs)
	$(execute) $^ -o $@ -g

%.o:%(src)%.cpp
	$(execute) $(cflags) $^ -o $@ -g

.PHONY:clean
clean:
	-rm $(target) -f


