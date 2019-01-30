CC = gcc
CFLAGS = -std=c11 -g

TARGET = lab2.c
exicutableName = lab2


.PHONY : build
build: 	$(TARGET) 
		@$(CC) $(CFLAGS) -o $(exicutableName) $(TARGET);
		@mv $(exicutableName) build

.PHONY : clean
		
clean: 
		@rm build/$(exicutableName)		
	
.PHONY : run
	
run: 
	./build/$(exicutableName)

.PHONY : debug
debug: 
	gdb build/$(exicutableName)
