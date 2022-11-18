#include <stdio.h>

void test_case(){
    
    int nr_stores;
    scanf("%d", &nr_stores);

    int stores[nr_stores];
    int tmp;

    for(int i = 0; i < nr_stores; i++){
        scanf("%d", &tmp);
        stores[i] = tmp;
    }

}

int main(){

    int n;
    scanf("%d", &n);
    while (n--) test_case();

    return 0;
}