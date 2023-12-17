#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];
int line;

void htac(int fd){
 int n;
 int row=512;
 int count =0;
 int col= 512;

 // 배열  동적 할당 
 char **new;
 new = (char **)malloc(sizeof(char*)*row); // 행 

 for (int i=0; i<row ; i++){
	 new[i] = (char*)malloc(sizeof(char)*col); // 열 
 }

 while ((n = read(fd, buf, sizeof(buf))) > 0) { // 버퍼에서  읽어오기 
	for (int i = 0; i < n; i++) {

		if (buf[i] == '\n') {
			new[count][i] = '\n';
            		count++; 
        	} else {
            		new[count][i] = buf[i];

		}
	}
 }
 for (int num = count; num>= count-line; num--){
	 for ( int j =0; j<= col; j++){
		 printf(1,"%c", new[num][j]);
	 }
    }

 for ( int i =0; i< row ; i++){
	 free(new[i]);
 }
 free(new);
 }

void
cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      printf(1, "cat: write error\n");
      exit();
    }
  }
  if(n < 0){
    printf(1, "cat: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){

    cat(0);
    exit();
  }

  line = atoi(argv[1]); // line 받기 

  for(i = 2; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "htac: cannot open %s\n", argv[i]);
      exit();
    }
    
    htac(fd); // 호출 
    close(fd);
  }
  exit();
}			
