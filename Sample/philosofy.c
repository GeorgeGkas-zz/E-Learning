#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int sum_array(const int* array, int cnt)
{
    int res;
    for ( res = 0; cnt; --cnt)
        res += *array++;
    return res;
}

int *fetch(int *N)
{
    FILE* input = fopen("share.in","r");

    *N = 0;
    fscanf(input,"%d",N);

    int *array = malloc(*N * sizeof(int));
    if (array != NULL) {
        for (int i = 0; i < *N; i++) {
            fscanf(input,"%d",&array[i]);
        }
    }
    fclose(input);
    return array;
}

struct Partition {
    const int *begin;
    const int *end;
    int sum;
};

int indexOfMax(const struct Partition *p, int partcount)
{
    int i, maxIndex;
    for (i = maxIndex = 0; i < partcount; ++i) {
        if (p[i].sum > p[maxIndex].sum)
            maxIndex = i;
    }
    return maxIndex;
}

// give a number to the partition to the right of t if possible
// and return the max of the two adjusted sums
int giveRight(struct Partition *p, int partcount, int t)
{
    if (t >= partcount || t < 0)
        return INT_MAX;
    // only adjust if there is a right partition and we have more than one element
    if (t+1 >= partcount || (p[t].end - p[t].begin == 1))
        return p[t].sum;
    p[t+1].begin = --p[t].end;
    // n is the number we're moving
    int n = *p[t+1].begin;
    p[t].sum -= n;
    p[t+1].sum += n;
    if (p[t].sum > p[t+1].sum) 
        return p[t].sum;
    return p[t+1].sum;
}

// give a number to the partition to the left of t if possible
// and return the new sum
int giveLeft(struct Partition *p, int partcount, int t)
{
    if (t >= partcount || t < 0)
        return INT_MAX;
    // only adjust if there is a left partition and we have more than one element
    if (t-1 < 0 || (p[t].end - p[t].begin == 1))
        return p[t].sum;
    // n is the number we're moving
    int n = *p[t].begin;
    p[t-1].end = ++p[t].begin;
    p[t].sum -= n;
    p[t-1].sum += n;
    if (p[t].sum > p[t-1].sum) 
        return p[t].sum;
    return p[t-1].sum;
}
#define PART_COUNT 3

int minmax(const int *array, int N)
{
    const int sum = sum_array(array, N);
    struct Partition p[PART_COUNT] = {
        {&array[0], &array[1], array[0]},
        {&array[1], &array[2], array[1]},
        {&array[2], &array[N], sum - array[0] - array[1]}
    };
    int max, maxIndex, test;
    do {
        maxIndex = indexOfMax(p, PART_COUNT);
        max = p[maxIndex].sum;
        test = giveLeft(p, PART_COUNT, maxIndex);
        if (test >= max) {
            // not improved, but try one more
            giveLeft(p, PART_COUNT, maxIndex-1);
            test = p[indexOfMax(p, PART_COUNT)].sum;
            if (test >= max) {
                // not improved so reverse this move
                giveRight(p, PART_COUNT, maxIndex-2);
                giveRight(p, PART_COUNT, maxIndex-1);
                // and try the right
                test = giveRight(p, PART_COUNT, maxIndex);
                if (test >= max) {
                    // not improved but try one more
                    giveRight(p, PART_COUNT, maxIndex+1);
                    test = p[indexOfMax(p, PART_COUNT)].sum;
                    if (test >= max) {
                        // not improved, so reverse this move
                        giveLeft(p, PART_COUNT, maxIndex+2);
                        giveLeft(p, PART_COUNT, maxIndex+1);
                    }
                }
            }
        }
    } while (test < max);
    return max;
}

int main()
{
    int N;
    int *array = fetch(&N);
    printf("%d\n", minmax(array, N));
    free(array);
}
