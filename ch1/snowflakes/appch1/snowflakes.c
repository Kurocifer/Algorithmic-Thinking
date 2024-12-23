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

