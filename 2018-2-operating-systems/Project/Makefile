obj-m += kmalloc_vs_vmalloc.o

all: kmalloc_vs_vmalloc

kmalloc_vs_vmalloc:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	
	
clean:
	./c_clean
