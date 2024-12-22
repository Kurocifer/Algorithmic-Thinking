#include <stdio.h>
#define MAX_LINES 100

// find the shortest line
int shortest_line(int lines[], int num_lines) {
	int shortest = 0;

	for(int i = 0; i < num_lines; i++) {
		if (lines[i] < lines[shortest])
			shortest = i;
	}
	return shortest;
}

void solve(int lines[], int num_lines, int new_ppl) {
	int shortest;
	for(int i = 0; i < new_ppl; i++) {
		shortest = shortest_line(lines, num_lines);
		printf("people in shortest line: %d\n", lines[shortest]);
		lines[shortest]++;
	}
}

int main(void) {
	int lines[MAX_LINES];
	int num_lines, new_ppl; // number of lines of number of new people.
 
	scanf("%d %d", &num_lines, &new_ppl);

	for(int i = 0; i < num_lines; i++) {
		printf("number of people in line %d: ", i + 1);
		scanf("%d", &lines[i]);
	}

	solve(lines, num_lines, new_ppl);
	return 0;
}
