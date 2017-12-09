#include <stdio.h>
#include <string.h>

int
main( int argc, char **argv )
{
  int freq[26];
  int nSamples;
  char str[1001];

  scanf("%d", &nSamples);
  for( int i=0; i<nSamples; i++ ) {
    memset(freq, 0, 26*sizeof(int));
    scanf("%s", str);
    for( int j=0; j<strlen(str); j++ )
      freq[str[j]-'a'] ++;

    int max = 0;
    for( int i=0; i<26; i++ )
      if(freq[i]>freq[max])
        max = i;
    printf("%c %d\n", 'a'+max, freq[max]);
  }

  return 0;
}
