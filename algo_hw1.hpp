// change this to your id
static const char* student_id = "0416001" ;
#include <iostream>
using namespace std;
//
// do your homework here
//
//


void min_heapify(int * input_array, int size, int position) {
	// I'll give you an array without ordered
	// please adjust the subtree which root is position
	//
	// Example:
	//      input : { 7, 14, 6, 5, 1, 3, 8 } ,7, 2
	//   expected : { 7, 14, 3, 5, 1, 6, 8 }
    int l = 2*position+1 ;
    int r = 2*position+2 ;
    int minimum ;
    if(l < size && input_array[l] < input_array[position])
        minimum = l;
    else
        minimum = position;
    if(r < size && input_array[r] < input_array[minimum])
        minimum = r;
    if(minimum != position)
    {
        int tmp = input_array[minimum] ;
        input_array[minimum] = input_array[position];
        input_array[position] = tmp;
        min_heapify(input_array , size , minimum);
    }
}

void min_heap_build(int * input_array, int size) {
	// I'll give you an array without ordered
	// please make this whole array as a min-heap tree
	//
	// Example:
	//      input : { 7, 14, 6, 5, 1, 3, 8 } ,7
	//   expected : { 1, 5, 3, 7, 14, 6, 8 }
	if(size%2)
    {
        for(int i = size/2 ; i >=0 ; i--)
            min_heapify(input_array , size , i);
    }
    else
    {
        for(int i = size/2-1 ; i >= 0 ; i--)
            min_heapify(input_array , size , i);
    }
}

void min_heap_insert(int * input_heap, int size, int key) {
	// I'll give you an array which is a min heap has one more space
	// (finally value 999 is not a true value)
	// please change the 999 into key
	// and make this array as a min-heap tree
	//
	// Example:
	//      input : { 1, 5, 3, 7, 14, 6, 8, 999 }, 8, 4
	//   expected : { 1, 4, 3, 5, 14, 6, 8 ,7}
    input_heap[size-1] = key;
    for(int i = size-1 ; i >=0 ; i--)
        min_heapify(input_heap , size , i);

}

void min_heap_minimum(int * input_heap, int size, int * output_key) {
	// I'll give you an array which is a min heap
	// please show the smallest value
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} , 8, &output_key
	//   expected : output_key == 1
    *output_key = input_heap[0];
}

void min_heap_extract(int * input_heap, int size, int * output_key) {
	// I'll give you an array which is a min heap
	// please tell me which is the smallest value
	// and delete that value , then adjust as heap
	// (make the final value 999 as fake)
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} , 8, &output_key
	//   expected : { 3, 4, 6, 5, 14, 7, 8, 999} ,output_key == 1
    *output_key = input_heap[0];
    input_heap[0] = input_heap[size-1];
    input_heap[size-1] = 999;
    if(size%2)
    {
        for(int i = size/2 ; i >=0 ; i--)
            min_heapify(input_heap , size , i);
    }
    else
    {
        for(int i = size/2-1 ; i >= 0 ; i--)
            min_heapify(input_heap , size , i);
    }
}

void min_heap_sort(int* input_heap, int size) {
	//
	// you cannot use library sort function!
	//
	// I'll give you an array which is a min heap
	// please sort it
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8 ,7} ,8
	//   expected : { 1, 3, 4, 5, 6, 7, 8, 14}
	int *temp = new int [size];
	for(int i = 0 ; i < size ;i++ )
        temp[i] = input_heap[i];

    for(int temp_size = size-1 ; temp_size > 0 ; temp_size--)
    {
        int tmp = temp[temp_size];
        temp[temp_size] = temp[0];
        temp[0] = tmp;
        if(temp_size%2)
        {
            for(int i = temp_size/2 ; i >= 0 ; i--)
                min_heapify(temp , temp_size , i);
        }
        else
        {
            for(int i = temp_size/2-1 ; i >= 0 ; i--)
                min_heapify(temp , temp_size , i);
        }
    }
    for(int i = 0 ; i<size ; i++)
    {
        input_heap[i] = temp[size-i-1];
    }
}


void min_heap_decrease_key(int * input_heap, int size, int position, int decrease) {
	// I'll give you an array which is a min heap
	// the position need to be decrease by a value
	// please adjust the result as a min-heap
	//
	// Example:
	//      input : { 1, 4, 3, 5, 14, 6, 8, 7}, 8, 3, 5
	//   expected : { 0, 1, 3, 4, 14, 6, 8, 7}
    input_heap[position]-=decrease;
    for(int i = position ; i >=0 ; i--)
        min_heapify(input_heap , size , i);
}

