# include <sys/shm.h>
# include <sys/ipc.h>
# include <sys/types.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

int main() {
  char * data;
  char answer[256];
  int len;
  int shmid = shmget(0, 200, 0644 | IPC_CREAT);
  printf("ptr: %d\n", shmid);
  data = shmat(shmid, (void *)0, 0);
  if (strcmp(data, "") == 0){
    printf("Shared memory created!\n\n");
  }

  printf("Printing data: %s\n\n", data);
  // while()

  while (1){
    printf("Would you like to edit (Y/N)? ");
    fgets(answer, 200, stdin);
    len = strlen(answer);
    answer[len-1] = 0;
    // if yees
    if (!strcmp(answer, "Y") | !strcmp(answer, "y")){
      printf("Please type in your edit: ");

      fgets(answer, 200, stdin);
      len = strlen(answer);
      answer[len-1] = 0;
      strcpy(data,answer);
      printf("Data successfully inputted!\n\n");

      printf("Printing data: %s\n\n", data);
    }
    // if nein
    else if (!strcmp(answer, "N") | !strcmp(answer, "n")){
      break;
    }
    // if user is sh*tposting or inputs wrong
    else{
      printf("\nWai u do dis\n\n");
    }
  }
  printf("Okie, goodbye!\n");
  // destroy memory
  shmctl(shmid, IPC_RMID, NULL);
  exit(0);
  return 0;
}
