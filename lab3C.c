#include <stdio.h>
#include <string.h>

int firstUniqChar(char* s) {
    int count[26] = {0};
    int n = strlen(s);
    int queue[n], front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        queue[++rear] = i;
    }

    while (front <= rear) {
        int index = queue[front++];
        if (count[s[index] - 'a'] == 1) {
            return index;
        }
    }

    return -1;
}

int main() {
    char s[] = "leetcode";
    int result = firstUniqChar(s);
    printf("%d\n", result);
    return 0;
}
