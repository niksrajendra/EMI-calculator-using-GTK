CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = -lm `pkg-config --libs gtk+-3.0`
all:
	gcc -no-pie $(CFLAGS) -o EMI_calculator EMI_Calculator.c $(LIBS)
