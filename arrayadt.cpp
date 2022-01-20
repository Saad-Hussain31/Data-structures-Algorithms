#include <iostream>
using namespace std;

//a control block using structure
struct arrayADT {
	int capacity;
	int lastIndex;
	int* ptr;//its int cox I want to store int type vals.
};

struct arrayADT* createArray(int capacity) 
{
	struct arrayADT* arr;
	arr = (struct arrayADT*)malloc(sizeof(struct arrayADT));
	arr->capacity = capacity;
	arr->lastIndex = -1;
	arr->ptr = (int*)malloc(arr->capacity*sizeof(int));//20bytes block.
	return (arr);
}

int getItem(struct arrayADT* arr, int index)
{
	if(arr->lastIndex < index || index < 0){
		cout << "Invalid index \n";
		return -1;
	}
	else 
		return (arr->ptr[index]);
}

int setItem(struct arrayADT* arr, int index, int value)
{
	if (arr->lastIndex == arr->capacity-1){
		cout << "Overflow \n";
		return 0;
	}

	if (index < 0 || index > arr->lastIndex + 1 ) {
		cout << "Invalid index \n";
		return 0;
	}
	if (index <= arr->lastIndex){
		arr->lastIndex = arr->lastIndex++;
		int i = arr->lastIndex;
		while (i!= index){
			arr->ptr[i] = arr->ptr[i-1];
			i--;
		}
		return 1;
	}
	if (index == arr->lastIndex + 1) {
		arr->lastIndex = arr->lastIndex + 1;
		arr->ptr[arr->lastIndex] = value;
		return 1;
	}
}

int editItem(struct arrayADT* arr, int index, int value)
{
	if (index < 0 || index >> arr->lastIndex){
		cout << "Invalid Index!\n";
		return 0;
	}

	else{
		arr->ptr[index] = value;
		return 1;
	}
}

int countItems(struct arrayADT* arr)
{
	return arr->lastIndex + 1;
}

int removeItem(struct arrayADT* arr, int index) {
	if (index < 0 || index > arr->lastIndex){//empty arr cond also catered
		cout << "Invalid index \n";
		return 0;
	}

	if (index == arr->lastIndex){
		arr->lastIndex = arr->lastIndex - 1;
		return 1;
	}

	if (index < arr->lastIndex){
		int i = index;
		while (i != arr->lastIndex - 1){
			arr->ptr[i] = arr->ptr[i + 1];
			i++;
		}
		arr->lastIndex = arr->lastIndex - 1;
		return 1;
	}
}

int search(struct arrayADT* arr, int item)
{
	int i;
	if (arr->lastIndex == -1){
		cout <<"Array is empty \n";
		return -1;
	}
	
	for (i = 0; i <= arr->lastIndex; i++)
		if(arr->ptr[i] == item)
			return i;
	return -1;
}

void sort(struct arrayADT* arr)
{
	int r, n, i, t;
	n = arr->lastIndex + 1;
	for (r = 1; r < n-1; r++){
		for(i = 0; i <= n-1-r;i++){
			if(arr->ptr[i] > arr->ptr[i+1]){
				t = arr->ptr[i];
				arr->ptr[i] = arr->ptr[i+1];
				arr->ptr[i+1] = t;
			}
		}
	}
}

int main()
{
        int i;
        struct arrayADT* arr;
        arr = createArray(1);
        setItem(arr,0,10);
        setItem(arr,1,20);
        setItem(arr,2,30);
        for (i = 0; i < countItems(arr); i++)
                printf("%d ",  getItem(arr,i)) ;

}






