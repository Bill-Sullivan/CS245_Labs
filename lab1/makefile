CC = gcc
CFLAGS = -std=c11

TARGET = lab1.c
exicutableName = lab1

build: 	$(TARGET) 
		@$(CC) $(CFLAGS) -o $(exicutableName) $(TARGET);
		@mv $(exicutableName) build

.PHONY : clean
		
clean: 
		@rm build/$(exicutableName)
	
.PHONY : run
	
run: 
	@echo "Hello World";