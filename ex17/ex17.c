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

void Databe_load(struct Connection *conn){


  int rc = fread(conn->db, sizeof(struct Database, 1, conn->file));
  
  if(rc != 1){
    die("Failed to load database.");
  }
}




struct Connection *Database_open(const char *filename, char mode){
  
  struct Connection *conn = malloc(sizeof(struct Connection));

  if(!conn){
    die("Memory error");
  }

  conn->db= malloc(sizeof(struct Database));

  if(!conn->db){
    die("Memory error.");
  }
  if(mode == 'c'){
    conn->file = fopen(filename,"w");
  }
  else{
    
    conn->file = fopen(filename,"r+");
    if(conn->file){
      Database_load(conn);
    }
  }

  if(!conn->file){
    die("Failed to open the file");
  }

  return conn;
}

void Database_close(struct Connection *conn){

  if(conn){
    if(conn->file){
      fclose(conn->file);
    }

    if(conn->db){
      free(conn->db)
    }
    free(conn);
  }

}

void Database_write(Connection *conn){
  rewind(conn->file);
  int rc = fwrite(conn->db, sizeof(struct Databese), 1,conn->file);

  if(rc != 1){
    die("Failed to write database.");
  }

  rc =fflush(conn->file);
  if(rc == -1){
    die("Cannot flush database.");
  }
}


void Database_create(struct Connection *conn){
  int i =0;
  for(i =0; i < MAXA_ROWS; i++){
    // make a prototype to initialize int
    struct Address addr = {.id = i, .set = 0};
    //then just assign it 
    conn->db->rows[i] = addr;
  }
}







int main(int argc, char *argv[])
{

    


  return 0;

}






