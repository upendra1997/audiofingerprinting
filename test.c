#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "sub_reader.h"
#include "av_decoder.h"
#include "lsh_db.h"
#include "config.h"

// Test program for testing of all functions
void test_reader(char *file_name)
{
  reader(file_name);
  printf("%s complete\n",__FUNCTION__);
  return;
}

void test_pts_to_mseconds(char *input_str)
{
  LLONG pts = 0;
  pts = pts_to_mseconds(input_str);
  printf("PTS:%lu\n",pts); 
  if(pts == 0)  
    fprintf(stdout,"%s failed\n",__FUNCTION__);
  else
    fprintf(stdout,"%s successful\n",__FUNCTION__);
  
}

void test_av_decoder(char *filename,float frame_pts)
{
  fprintf(stderr,"%s received params %s %f\n",__FUNCTION__,filename,frame_pts);
  //  int ret = init_decoder(filename);
  create_fingerprint_by_pts(0,frame_pts);
} 

void test_database()
{
  fprintf(stderr,"Testing database\n");
  initialise_database();
}
int main(int argc, char *argv[])
{
  int i,j,k,temp_len;
  char *input_str=NULL,*temp=NULL;
  if(argc<3)
    {
      printf("Usage: ./test flags <input>\n-f:\ttest reader, -f followed by file name\n-t:\ttest pts_to_seconds\n-d:\ttest avdecoder, -d <input video file> <time>\n-b:\t test database\n");
      return -1;
    }
  
  if(strcmp(argv[1],"-f") == 0){
    input_str = argv[2];
    test_reader(input_str);
  }
  else if(strcmp(argv[1],"-t") == 0)
    test_pts_to_mseconds(input_str);
  else if(strcmp(argv[1],"-d") == 0 && argv[3] != NULL)
    test_av_decoder(input_str,atoi(argv[3]));
  else if(strcmp(argv[1],"-b") == 0)
    test_database();
  else
    printf("Usage: ./test flags <input>\n-f:\ttest reader, -f followed by file name\n-t:\ttest pts_to_seconds\n-d:\ttest avdecoder, -d <input video file> <time>\n");

  return 0;
}
