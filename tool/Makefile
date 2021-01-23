#目标对象：依赖对象
#制表符\t 执行指令
#目标对象：是要生成的可执行程序的名称
#依赖对象：是生成目标对象所需要的源码文件
#make在解释执行的时候会找到当前所在目录种的Makefile文件，在这个文件种找到第一个目标对象，执行这个目标对象对应的指令
#生成第一个目标对象后，make就会退出，不会继续生成第二个对象

#all:main main1

#main:c.c d.c
#	echo "hello"

src=$(wildcard ./*.c)#从当前目录下找到以.c结尾的文件名称，放到src变量中
#$src = c.c d.c
obj=$(patsubst %.c,%.o,$(src))#将src变量中的数据，后缀名由.c修改为.o将结果赋值给obj变量
#$obj=c.o d.o
main:$(obj)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
#makefile中的清理动作，这个对象是第二个目标对象，不会自动执行，需要我们指定执行
#声明伪对象，伪对象不管如何每次都要重新生成
.PHONY:clean
clean:
	rm -rf main $(obj)

#main:c.o d.o 
#	gcc $^ -o $@
#c.o:c.s
#	gcc -c $^ -o $@
#c.s: c.i
#	gcc -S $^ -o $@
#c.i:c.c
#	gcc -E $^ -o $@
#d.o:d.c
#	gcc -c $^ -o $@

#main1:c.c d.c 
#	gcc c.c d.c -o main1
