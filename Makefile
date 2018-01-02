FLAGS = -Wall -std=gnu99 -g

all: decode encode

decode: decode.c
	gcc ${FLAGS} -o $@ $^

encode: encode.c
	gcc ${FLAGS} -o $@ $^
