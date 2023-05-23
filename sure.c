#include <stdio.h>

int main() {
    int list[10];
    int list_length = (sizeof(list)/sizeof(list[0]));
    printf("%d\n",list_length);
    for (int i = 0; i < 10; i++){
        int to_add = get_numbers();
        list[i] = to_add;
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",list[0],list[1],list[2],list[3],list[4],list[5],list[6],list[7],list[8],list[9]);
    return 0;}

int get_numbers(){
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    return number;
    }
