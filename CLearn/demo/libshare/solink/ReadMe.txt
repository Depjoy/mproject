make denamic libary
    gcc stime.c -o libstime.so -shared -fPIC

1.use denamic libary to make executable file
        gcc link.c -L./ -lstime -o link
    three ways to denamicly link denamic libary

    the first: copy the denamic libary to /usr/lib or /lib
        sudo cp libstime.so  /usr/lib
        ./link
    the second: add environment variables manually
        export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH  --- set environment variables  
        ./link
    the third: denamicly install the libary in other directories
        cd /etc/ld.so.conf.d/
        sudo touch mylib.conf
        sudo vi mylib.conf
        cat mylib.conf
        sudo ldconfig
        cd the path put code
       ./link
2.use static libary to make executable file
     gcc -c stime.c  -o stime.o
     ar -cr libstime.a stime.o
     gcc -static link.c -L. -lstime -o link  // -static -- force to link static libary
     ./link
