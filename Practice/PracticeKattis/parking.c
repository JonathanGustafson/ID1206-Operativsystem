#include <stdio.h>

void test_case();
int sum(int* list, int size);

int main(){

    int n;
    scanf("%d", &n);
    while (n--) test_case();

    return 0;
}

int sum(int* list, int size){
    
    int sum = 0;

    for(int i = 0; i < size; i++){
        if(list[i] < 0){
            list[i] *= -1;
        }
        sum += list[i];
    }

    return sum;
}

void test_case(){
    
    int nr_stores;
    scanf("%d", &nr_stores);

    int stores[nr_stores];
    int tmp;

    for(int i = 0; i < nr_stores; i++){
        scanf("%d", &tmp);
        stores[i] = tmp;
    }

    int distances[100][nr_stores];

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < nr_stores; j++){
            distances[i][j] = stores[i] - i;
        }
    }

    int minDistance = sum(distances[0], nr_stores);
    int temp_sum;

    for(int i = 1; i < nr_stores; i++){
        temp_sum = sum(distances[100], nr_stores);
        if(temp_sum < minDistance){
            minDistance = temp_sum;
        }
    }

    printf("%d\n", minDistance);

}