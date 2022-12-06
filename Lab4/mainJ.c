#include <stdio.h>
#include <stdlib.h>

#define CYLINDERS 5000
#define REQUESTS 1000

//head start position
int start = 0;

//list of requests
int request_list[REQUESTS];

void sort(int *list, int size){
    //i starts on the 2nd element
	for(int i = 1; i < size; i++) {
		int current = list[i];
		//System.out.println("Current: " + current);
		
		//j starts on the element to the left i
		int j = i-1;
		
		//while the current item is less than j, move j one step to the right.
		while(j >= 0 && list[j] > current) {
			list[j + 1] = list[j]; //move the element on j one step to the right
			j--;
		}
		
		list[j+1] = current; //place current in the right slot
	}
}

int sstf(int* request_list, int size){
    sort(request_list, size);

    int head_movement = 0;      //Total amount of head movements
    int curr_list_pos;
    int next_list_pos;   
    
    int high_index, low_index;  //Indexes for higher and lower
    int high_dist, low_dist;

    int remaining_requests = size;

    //find closest request to start 
    next_list_pos = 0;
    for(int i = 1; i < size; i++){
        if(abs(request_list[i]-start) < abs(request_list[next_list_pos]-start)){
            next_list_pos = i;
        }
    }
    
    //take care of first case
    head_movement += abs(start-request_list[next_list_pos]);
    curr_list_pos = next_list_pos;
    high_index = curr_list_pos + 1;
    low_index = curr_list_pos - 1;

    //loop through all the remaining requests
    while(high_index != low_index){

         high_dist  = abs(request_list[high_index] - request_list[curr_list_pos]);
         low_dist   = abs(request_list[low_index] - request_list[curr_list_pos]);
         
        //if the distance to the left is less than distance to the right
         if( low_dist < high_dist){

             //set left index as next position and increment head_movement with the distance
             next_list_pos = low_index;
             head_movement += low_dist;

             //assert that the lower bound index is less then
             if(low_index > 0){
                 low_index--;
             }
             else{
                 low_index = size;
             }    
         }

         //if distance to right is less than distance to left
         else{
             //set high index to next step
             next_list_pos = high_index;
             head_movement += high_dist;

             //assert that the lower bound index is less then
             if(high_index < size){
                 high_index++;
             }
             else{
                 high_index = 0;
             }
         }
        curr_list_pos = next_list_pos;
    }

    return head_movement;

}

void test1(){
    for(int i = 0; i < REQUESTS; i++) {
		request_list[i] = rand() % CYLINDERS;
	}
    printf("SSTF head movements: %d\n", sstf(request_list, REQUESTS));
}

void test2(){
    int request_list[] = {98,183,37,122,14,124,65,67};
    printf("SSTF head movements: %d\n", sstf(request_list, 8));
}

int main (int argc, char *argv[]) {
	
	if(argc < 2) {
		printf("Too few arguments");
		exit(-1);
	} else{
        start = atoi(argv[1]);
    }

    //test1();
    test2();

	return 0;
}