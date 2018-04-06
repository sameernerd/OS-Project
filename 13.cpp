#include<iostream>
#define MAX_SIZE 1000
using namespace std;

class Queue{
	int queue[MAX_SIZE];
    int front=-1,rear=-1;
    public:
    void push(int a){
    	if(front==0&&rear==MAX_SIZE-1||front==rear+1){
		cout<<"Queue is full"<<endl;
		}
		else{
		if(front==-1){
			front=0;
			rear=0;
		}
		else if(rear==MAX_SIZE-1)rear=0;
		else rear++;
		queue[rear]=a;
		}
	}
	int pop(){
		int a=INT_MIN;
		if(front==-1){
			cout<<"Queue is empty ";
		}
		else{
			a=queue[front];
			if(front==rear){ //Popped the last element of the queue
				front=-1;
				rear=-1;
		}
		else if(front==MAX_SIZE-1)front=0; //When front is at the end
		else front++;
		}
		return a;
	}
};

int main(){
	Queue *round_robin=new Queue();//0-9
	Queue *priority=new Queue();//10-19
	Queue *fcfs=new Queue();//20-30
	int n;
	cin>>n;
	int process[]=new int[n];
	for(int i=0;i<n;i++){
		cin>>process[i];
		if(process[i]>=0&&process[i]<=9)
			round_robin->push(process[i]);
		else if(process[i]>=10&&process[i]<=19)
			priority->push(process[i]);
		else fcfs->push(process[i]);
	}
}

/*
Thing inside my head
I have to transfer 
*/

