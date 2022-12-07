#include <stdio.h>
#include <stdlib.h>

#define CYLINDERS 5000
#define REQUESTS 1000

//head start position
int start = 0;

//list of requests
int request_list[REQUESTS];

int findHeadIndexAndSort(int *list, int size, int head){
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
    for (int i = 0; i < REQUESTS; i++)
    {
        if(start < list[i]){
            return i;
        }
    }
    
}

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

int sstf(int* request_list){
    int size = REQUESTS;
    sort(request_list, size);

    int head_movement = 0;      //Total amount of head movements
    int curr_list_pos;
    int next_list_pos;   
    
    int high_index, low_index;  //Indexes for higher and lower
    int high_dist, low_dist;

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

         //printf("Head pos: %d Head value: %d Low index: %d Low value %d High index: %d High value %d\n", curr_list_pos, request_list[curr_list_pos], low_index, request_list[low_index], high_index, request_list[high_index]);
         
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
                 low_index = size-1;
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

    //add last movement (doesnt matter if we check high or low index since they are the same)
    head_movement += abs(request_list[high_index] - request_list[curr_list_pos]);

    return head_movement;

}

int fcfs(int *request_array){

    int head_movement = 0;
    int oneWay;
    int anotherWay;
    if(abs(request_array[0] - start) > abs(start - request_array[0])){
        head_movement = abs(start - request_array[0]);
    }else{
        head_movement = abs(request_array[0] - start);
    }

   
    for (int i = 1; i < REQUESTS; i++){
    
    oneWay = abs(request_array[i-1] - request_array[i]);
    anotherWay = abs(request_array[i] - request_array[i-1]);
    
    if(anotherWay > oneWay){
         head_movement = head_movement + oneWay;
    }else{
            head_movement = head_movement + anotherWay;
        }
 
    }
    return head_movement;
}

int cscan(int * request_array) {  //should work
    int head_movement = 0;
    
    int indexToStart = findHeadIndexAndSort(request_array, REQUESTS, start);
    head_movement = request_array[indexToStart] - start;
    for (int i = start; i < REQUESTS; i++){
        head_movement = head_movement + request_array[i + 1] - request_array[i];
    }  
    head_movement = head_movement + (CYLINDERS - request_array[REQUESTS - 1]);
    head_movement = head_movement + CYLINDERS;
    for (int i = 0; i < indexToStart - 1; i++){
        head_movement = head_movement + request_array[i + 1] - request_array[i];
    }
  return head_movement;

}

int clook(int * request_array) {  //should work
    int head_movement = 0;
   
    int indexToStart = findHeadIndexAndSort(request_array, REQUESTS, start);
    head_movement = request_array[indexToStart] - start;
    for (int i = start; i < REQUESTS; i++){
        head_movement = head_movement + request_array[i + 1] - request_array[i];
    }  
    
    head_movement = head_movement + CYLINDERS - request_array[0];
    for (int i = 0; i < indexToStart - 1; i++){
        head_movement = head_movement + request_array[i + 1] - request_array[i];
    }
  return head_movement;
  

}

int look(int * request_array) { //Should work

    int head_movement = 0;
    
    int indexToStart = findHeadIndexAndSort(request_array, REQUESTS, start);
    head_movement = request_array[indexToStart] - start;
    for (int i = indexToStart; i < CYLINDERS; i++){
        head_movement = head_movement + request_array[i + 1] - request_array[i];
    }

    
    head_movement = head_movement + (CYLINDERS - request_array[indexToStart - 1]);
    for (int i = indexToStart - 1; i > 0; i--){
        head_movement = head_movement + request_array[i] - request_array[i - 1];
    }    
    return head_movement;

}

int scan(int * request_array) { //Should work

    int head_movement = 0;
    
    int indexToStart = findHeadIndexAndSort(request_array, REQUESTS, start);
    head_movement = request_array[indexToStart] - start;
    for (int i = indexToStart; i < CYLINDERS; i++){
        head_movement = head_movement + request_array[i + 1] - request_array[i];
    }

    head_movement = head_movement + (CYLINDERS - request_array[REQUESTS - 1]);
    head_movement = head_movement + (CYLINDERS - request_array[indexToStart - 1]);
    for (int i = indexToStart - 1; i > 0; i--){
        head_movement = head_movement + request_array[i] - request_array[i - 1];
    }    
    return head_movement;

}

void test1(){
    for(int i = 0; i < REQUESTS; i++) {
		request_list[i] = rand() % CYLINDERS;
	}
    printf("FCFS \thead movements: %d\n", fcfs(request_list));
    printf("SSTF \thead movements: %d\n", sstf(request_list));
    printf("C-SCAN \thead movements: %d\n", cscan(request_list));
    printf("C-LOOK \thead movements: %d\n", clook(request_list));
    printf("LOOK \thead movements: %d\n", look(request_list));
    printf("SCAN \thead movements: %d\n", scan(request_list));
    }

void test2(){
    //sorted we have     {14,37,65,67,98,122,124,183}
    int request_list[] = {98,183,37,122,14,124,65,67};
    printf("\nSSTF head movements: %d\n", sstf(request_list));
}

int main (int argc, char *argv[]) {
	
	if(argc < 2) {
		printf("Too few arguments");
		exit(-1);
	} else{
        start = atoi(argv[1]);
    }

    test1();
    //test2();

	return 0;
}