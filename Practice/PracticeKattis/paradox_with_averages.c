/*
i do get the right output, but i think that there is some small
formatation error which makes the test give 1/2 correct tests.
*/

#include <stdio.h>

double avarage(int* list, int size);
void test_case();

int main(){

    int test_cases;
    scanf("%d", &test_cases);
    while(test_cases--) test_case();
    
    return 0;
}

double avarage(int* list, int size){
    
    double sum = 0;

    for(int i = 0; i < size; i++){
        sum += list[i];
    }

    return sum/(double)size;
}

void test_case(){

    int sizeCS, sizeE;
    int count = 0;

    //get size of Computer Science college
    do
    {
        scanf("%d", &sizeCS);
    } while (!(sizeCS >= 2 && sizeCS <= 1000));
    
    //get size of Economics college
    do
    {
        scanf("%d", &sizeE);
    } while (!(sizeE >= 2 && sizeE <= 1000));

    int listCS[sizeCS];
    int listE[sizeE];

    int tmp;


    //get input for CS student IQs
    for(int i = 0; i < sizeCS; i++){
        do
        {
            scanf("%d", &tmp);
            listCS[i] = tmp;
        } while (!(listCS[i] > 0 && listCS[i] <= 100000));
    }
    
    //get input for E student IQs
    for(int i = 0; i < sizeE; i++){
        do
        {
            scanf("%d", &tmp);
            listE[i] = tmp;
        } while (!(listE[i] > 0 && listE[i] <= 100000));
    }

    //calculate both IQ avarages
    double avarageCS = avarage(listCS, sizeCS);
    double avarageE = avarage(listE, sizeE);

    //printf("%f : %f\n", avarageCS, avarageE);


    for(int i = 0; i < sizeCS; i++){
        if(listCS[i] < avarageCS && listCS[i] > avarageE){
            count++;
        }
    }

    printf("%d\n", count);
}

/*

1

5 5
100 101 102 103 104 ----- avarage 102
98 100 102 99 101   ----- avarage 100

*/