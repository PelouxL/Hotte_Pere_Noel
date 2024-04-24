CC= gcc
OPTION=  -W -Wall -std=c89 -pedantic -O2

main: main.c cadeaux.o tri.o interface.o interface_mlv.o save.o niveaux.o
	$(CC) $(OPTION) `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` $^ `pkg-config --libs-only-l MLV` -o $@

cadeaux.o: cadeaux.c
	$(CC) $(OPTION) -c $^

tri.o: tri.c
	$(CC) $(OPTION) -c $^

interface.o: interface.c
	$(CC) $(OPTION) -c $^

interface_mlv.o: interface_mlv.c
	$(CC) $(OPTION) -c $^

save.o: save.c
	$(CC) $(OPTION) -c $^

niveaux.p: niveaux.c
	$(CC) $(OPTION) -c $^

clean:
	rm -rf *.o *~ main 
