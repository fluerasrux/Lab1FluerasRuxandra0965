
--- three functions
rux@RuxiFuxi:~/lab1_clean$ gcc -c util_file.c util_net.c util_math.c 
rux@RuxiFuxi:~/lab1_clean$ ar rc libutil.a util_file.o util_net.o util_math.o
rux@RuxiFuxi:~/lab1_clean$ ranlib libutil.a 
rux@RuxiFuxi:~/lab1_clean$ gcc -c main1.c 
rux@RuxiFuxi:~/lab1_clean$ gcc main1.o -L. -l
-l         -lang-asm  -list      
rux@RuxiFuxi:~/lab1_clean$ gcc main1.o -L. -lutil -o prog
rux@RuxiFuxi:~/lab1_clean$ ./prog
Inside main()
Inside util_file()
Inside util_net()
Inside util_math()

--- add util_power and gcd 
rux@RuxiFuxi:~/lab1_clean$ gcc -c util_power.c 
rux@RuxiFuxi:~/lab1_clean$ ar r libutil.a util_power.o
rux@RuxiFuxi:~/lab1_clean$ ranlib libutil.a 
rux@RuxiFuxi:~/lab1_clean$ gcc -c main1.c
rux@RuxiFuxi:~/lab1_clean$ gcc main1.o -L -lutil -o prog 
/usr/bin/x86_64-linux-gnu-ld.bfd: main1.o: in function `main':
main1.c:(.text+0x18): undefined reference to `util_file'
/usr/bin/x86_64-linux-gnu-ld.bfd: main1.c:(.text+0x1d): undefined reference to `util_net'
/usr/bin/x86_64-linux-gnu-ld.bfd: main1.c:(.text+0x22): undefined reference to `util_math'
collect2: error: ld returned 1 exit status
rux@RuxiFuxi:~/lab1_clean$ gcc main1.o -L. -lutil -o prog 
rux@RuxiFuxi:~/lab1_clean$ ./prog 
Inside main()
Inside util_file()
Inside util_net()
Inside util_math()
rux@RuxiFuxi:~/lab1_clean$ gcc -c gcd.c
rux@RuxiFuxi:~/lab1_clean$ ar r libutil.a gcd.o
rux@RuxiFuxi:~/lab1_clean$ ranlib libutil.a
rux@RuxiFuxi:~/lab1_clean$ gcc -c main1.c
rux@RuxiFuxi:~/lab1_clean$ gcc main1.o -L. -lutil -o prog
rux@RuxiFuxi:~/lab1_clean$ ./prog
Inside main()
Inside util_file()
Inside util_net()
Inside util_math()
Inside util_power(): 2^3 = 8
gcd(48, 18) = 6

--- check archive contents
rux@RuxiFuxi:~/lab1_clean$ ar t libutil.a
util_file.o
util_net.o
util_math.o
util_power.o
gcd.o

--- static and shared
rux@RuxiFuxi:~/lab1_clean$ 
rux@RuxiFuxi:~/lab1_clean$ gcc -fPIC -c libcalc.c
rux@RuxiFuxi:~/lab1_clean$ gcc -shared -o libcalc.so libcalc.o
rux@RuxiFuxi:~/lab1_clean$ ar rc lib
libcalc.c   libcalc.o   libcalc.so  libutil.a   
rux@RuxiFuxi:~/lab1_clean$ ar rc libcalc.a libcalc.o
rux@RuxiFuxi:~/lab1_clean$ ranlib libcalc.a
rux@RuxiFuxi:~/lab1_clean$ ls -la libcalc.a libcalc.so
-rw-r--r-- 1 rux rux  1808 Sep  9 20:26 libcalc.a
-rwxr-xr-x 1 rux rux 15208 Sep  9 20:26 libcalc.so
rux@RuxiFuxi:~/lab1_clean$ gcc -c main.c
rux@RuxiFuxi:~/lab1_clean$ gcc main.o -ldl -o calcprog
/usr/bin/x86_64-linux-gnu-ld.bfd: /usr/lib/gcc/x86_64-linux-gnu/15/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
(.text+0x1b): undefined reference to `main'
collect2: error: ld returned 1 exit status
rux@RuxiFuxi:~/lab1_clean$ gcc -c main.c
rux@RuxiFuxi:~/lab1_clean$ gcc main.o -ldl -o calcprog
rux@RuxiFuxi:~/lab1_clean$ ./calcprog
calc_add(10, 4) = 14.00
calc_sub(10, 4) = 6.00
calc_mul(10, 4) = 40.00
calc_div(10, 4) = 2.50
calc_div(10, 0) = 0.00  /* cant divide by zero */
rux@RuxiFuxi:~/lab1_clean$ 