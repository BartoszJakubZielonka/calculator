# Makefile

SOURCES=$(wildcard source/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

main:	$(OBJECTS)
	gcc $^ -o $@

$(OBJECTS): source/%.o : source/%.c
	gcc -g -c $< -o $@

clean:
	rm -rf source/*.o main