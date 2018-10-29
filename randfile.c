# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int * generate_randoms(int * array_int){
  int file = open("/dev/random", O_RDONLY);

  int num;
  for (num = 0; num < 10; num++){
    read(file, &array_int[num], sizeof(int));
  }

  close(file);
  return array_int;
}

int main() {
  int * array_int = calloc(10, sizeof(int));
  generate_randoms(array_int);

  int num;
  for (num = 0; num < 10; num++){
    printf("Random number %d: %d\n", num, array_int[num]);
  }
  printf("Writing into file...\n");

  //creates the file if it doesn't exist, otherwise reads it
  int file = open("./storage.txt", O_WRONLY);
  printf("%d\n", file);
  write(file, array_int, 10 * sizeof(int));
  close(file);

  printf("Reading from file...\n");
  file = open("./storage.txt", O_RDONLY);
  int * second_array_int = calloc(10, sizeof(int));
  read(file, second_array_int, 10 * sizeof(int));
  for (num = 0; num < 10; num++){
    printf("Random number %d: %d\n", num, second_array_int[num]);
  }



  return 0;
}
