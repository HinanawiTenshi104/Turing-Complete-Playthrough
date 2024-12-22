#include<stdio.h> 
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	//always start from peg 0
	//if n is odd, end up on peg 2; if even, end up on peg 1
	//but from the digram, we can see if we swap the direction of the move and the (src, dest) pair, we can change the parity of the process
	
	//after coding it up, i test it with all the 6 possible (src, dest) pair, and the parity of the disk_count (=3 or =4)
	//total of 12 test examples.
    int n;
    cout<<"Enter the No. of Disks: ";
    cin>>n;
    int src, dest;
    cout<<"\nEnter the src_peg and the dest_peg: ";
	cin>>src>>dest;
	printf("\nsrc:%i, dest:%i", src, dest);
	int move_count = 1 << n;
	bool swap = 0;
	
	//see if the src and the dest need to be swapped
	if (src == 0){
		swap = !((n + dest) % 2);
	}
	if (src == 1){
		swap = n % 2;
		if (dest == 0)
			swap = !swap;
	}
	if (src == 2){
		swap = (n + dest) % 2;
	}
	
	//main loop
	if (swap){
		int temp = src;
		src = dest;
		dest = temp;
		
		for (int x = move_count - 1; x > 0; x--){
			printf("\nMove from Peg %i to Peg %i", ((x|(x-1))+1+src)%3, ((x&(x-1))+src)%3);
		}
	}
	else
	    for (int x = 1; x < move_count; x++)
	    {
			printf("\nMove from Peg %i to Peg %i", ((x&(x-1))+src)%3, ((x|(x-1))+1+src)%3);
	    }
    cout<<"\n";
    getch();
}
