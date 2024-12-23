#include <stdio.h>

#define SIZE 10000

int identical_right(int snow1[], int snow2[], int start) {
    for(int offset = 0; offset < 6; offset++) {
        if(snow1[offset] != snow2[(start + offset) % 6])
            return 0;
    }

    return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
    int snow2_index;

    for(int offset = 0; offset < 6; offset++) {
        snow2_index = start - offset;

        if(snow2_index < 0)
            snow2_index = snow2_index + 6;
        if(snow1[offset] != snow2[snow2_index])
            return 0;
    }
    return 1;
}

int are_identical(int snow1[], int snow2[]) {
    int start;

    for(start = 0; start < 6; start++) {
        if(identical_left(snow1, snow2, start))
            return 1;
        if(identical_right(snow1, snow2, start))
            return 1;
    } 
    return 0;
}

void identify_idetical(int snowflakes[][6], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(are_identical(snowflakes[i], snowflakes[j])) {
                printf("Twin snowflakes found.\n");
                return;
            }
        }
    }
    printf("No two snowflakes are alike.\n");
}

void main(void) {
  static int snowflakes[SIZE][6];
  int n, i, j; // n: number of snowflakes.

  printf("number of snowlakes: ");
  scanf("%d", &n);

  for(i = 0; i < n; i++) {
    printf("snowflake %d\n", i + 1);

    for(j = 0; j < 6; j++)
      scanf("%d", &snowflakes[i][j]);
  }
  identify_idetical(snowflakes, n);
}

