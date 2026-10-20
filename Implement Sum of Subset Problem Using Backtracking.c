#include <stdio.h>

#define MAX 100

int arr[MAX];
int subset[MAX];
int result[MAX][MAX];
int resultSize[MAX];
int count = 0;

void storeSubset(int len) {
    resultSize[count] = len;
    for (int i = 0; i < len; i++)
        result[count][i] = subset[i];
    count++;
}

void findSubsets(int index, int n, int target, int sum, int len) {
    if (sum == target) {
        storeSubset(len);
        return;
    }

    if (index >= n || sum > target)
        return;

    subset[len] = arr[index];
    findSubsets(index + 1, n, target, sum + arr[index], len + 1);

    findSubsets(index + 1, n, target, sum, len);
}

int main() {
    int n, target;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &target);

    findSubsets(0, n, target, 0, 0);

    if (count == 0) {
        printf("-1");
    } else {
        for (int i = count - 1; i >= 0; i--) {
            for (int j = 0; j < resultSize[i]; j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
    }

    return 0;
}