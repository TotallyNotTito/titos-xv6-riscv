#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

struct data {
  uint  F, R, T;
  char * location;
};
struct data data;

//prototypes
void * file_writer(void * tid);  

//helpers
//ADD PRINTF DEBUGGING TO TRACK N BYTES ATTEMPTED AND READ
//ADD PRINTF DEBUGGING FOR FILE CREATIION
void * file_writer(void * tid) {
  

  uint my_tid = *((uint *) tid); 
  char filename[4096];
  //printf("IN FILE WRITER \n and tid: %d\n", my_tid);
  uint marlin_rando = my_tid;
  
  for (int i = my_tid; i < data.F; i = i + data.T) {

    //my_tid = i; 
    //printf("Thread my TID: %d creates file i: %d\n", my_tid, i);
    
    sprintf(filename, "%s/unsorted_%d.bin", data.location, i);
    int fd = open(filename, O_CREAT|O_TRUNC|O_RDWR, 0664);
      
    if (fd < 0) {
      char * msg = strerror(errno);
      fprintf(stderr, "Open() Failed%s\n Thread ID: %d\nFile Name: %s\n", msg, i, filename);
      exit(-1);
    }
    
    uint buffer[data.R];    
    for (int j = 0; j < data.R; ++j) {
      buffer[j] = rand_r(&marlin_rando);
    } 
    
    printf("data.R is: %d\n", data.R);
    size_t check = write(fd, buffer, (data.R * sizeof(int)));
    printf("Value of return value from write: %ld\n", check);

    if (check < 0) {
      char * msg = strerror(errno);
      fprintf(stderr, "Write() Failed %s\n Thread ID: %d\n File Name: %s\n", msg, my_tid, filename);
      exit(-1);
    }

    close(fd);
  }

    return NULL;
}

//BEGIN MAIN
int main(int argc, char * argv[]) {
  
  if (argc != 5) {
    printf("Refer to directions.\nneed 4 command line params.\n");
    return -1;
  }

  printf("IN MAIN\n");

  //data.location = (char *) malloc(sizeof((argv[1])));
  //strcpy(data.location, argv[1]);
  data.location = argv[1];
  int dir = mkdir(data.location,0777);
  if (dir > 0) {
    char * msg = strerror(errno);
    fprintf(stderr,"mkdir() Falied %s\n",msg);
    exit(-1);
  }

  if (!data.location) {
    printf("Argv[1] arg param not allocated\n");
    return -1;
  }

  data.F = atoi(argv[2]); //number of files to create
  data.R = atoi(argv[3]); //number of integers to insert
  data.T = atoi(argv[4]); //number of threads to run 
  uint TID[data.R];   
  pthread_t thread[data.T];
  int rc;

  //number of files being created
  for (int i = 0; i < data.T; ++i) {
  TID[i] = i;    
    printf("CREATING THREADS\n");

    rc = pthread_create(&thread[i],NULL, file_writer, (void *) &TID[i]);
    //rc = pthread_create(thread[i],NULL, file_writer, (void *) &TID[i]);
    if (rc) {
      fprintf(stderr, "ERROR; could not create thread. return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  //joining threads
  for (int i = 0; i < data.T; ++i) { 

    printf("JOINING THREADS\n");

    rc = pthread_join(thread[i], NULL); 
    if (rc != 0) {
      fprintf(stderr, "ERROR joining thread (rc==%d)\n", rc);
      exit(-1); 
    }
  }
  //free(data.location);
  printf("Success! all files created and Joined\n"); 
  return 0;

}

    
