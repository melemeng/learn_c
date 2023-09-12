#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


# define MAXA_DATA 512
# define MAXA_ROWS 100



struct Address{
  int id;
  int set;
  char name[MAXA_DATA];
  char email[MAXA_DATA];
};


struct Database {
  struct Address row[MAXA_ROWS];
};



// help to point or connect to aa hole databe 
struct Connection{
  FILE *file;
  struct Database *db;
};


void die(const char *message){
  if(errno){
    perror(message);
  } else{
    printf("ERROR: %s\n", message);
  }

 exit(1);
}


void print_Address(struct Address *addr){
  printf("%d %s %s\n", addr->id, addr->name, addr->email);

}

struct Connection *Database_open(const char *filename, char mode){
  
  struct Connection *conn = malloc(sizeof(struct Connection));

  if(!conn){
    die("Memory error");
  }
}





int main(int argc, char *argv[])
{

    


  return 0;

}






