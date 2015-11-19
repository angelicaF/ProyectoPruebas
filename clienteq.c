
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

 #include <time.h>
#include "bzlib.h"
#include "zlib.h"

#define SIZE 512
#define CHECK_ERR(err, msg) { \
    if (err != BZ_OK) { \
        fprintf(stderr, "%s error: %d\n", msg, err); \
        exit(1); \
    } \
}


int main(int argc, char *argv[]) {

      FILE *file;
      Byte  *buffer [512];
      Byte  *buff_dest [512];
      long filelen;
      int i, st;

      file = fopen(argv[1], "rw");         
      fseek(file, SEEK_SET, 0);

	unsigned  int destLen=100;
	unsigned  int sourceLen=100;
   
	/*uLong destLen = st; // "Hello, world!" + NULL delimiter.
      	uLong sourceLen = st;*/

	while (st = fread(buffer, 1, SIZE, file)) { // Send the file   
           printf("va a comprimir\n");
           if( BZ2_bzBuffToBuffCompress(buff_dest, &destLen, buffer, sourceLen, 1, 0,30 )!= BZ_OK ){
		printf(" error\n");
     	   }else{
	       printf(" correcto\n");
     	   }
         }   

/*if( BZ2_bzBuffToBuffCompress(buff_dest, &destLen, buffer, sourceLen, 1, 0,30 )!= BZ_OK ){
	printf(" error\n");
     }else{
	printf(" correcto\n");
     }*/
	 
   return 0;

}





