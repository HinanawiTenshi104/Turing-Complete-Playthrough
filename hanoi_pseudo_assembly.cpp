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
    int disk_nr, source, dest, swap, x;
    cout << "Enter the No. of Disks: ";
    cin >> disk_nr;
    cout << "\nEnter the src_peg and the dest_peg: ";
	cin >> source >> dest;
	printf("\nsrc:%i, dest:%i", source, dest);
	
	//see if the src and the dest need to be swapped
	swap = 0;
	if (source == 0){
		x = disk_nr + dest;
		x = x & 0b00000001;
		swap = x xor 0b00000001;
	}
	if (source == 1){
		swap = disk_nr & 0b00000001;
		//if != 0, jmp to end
		if (dest == 0)
			swap = !swap;
	}
	if (source == 2){
		x = disk_nr + dest;
		swap = x & 0b00000001;
	}
	
	//prepare for the loop
	disk_nr = 1 << disk_nr;
	if (swap){
		//swap becomes the temp var
		x = disk_nr - 1;
		disk_nr = dest;
		//originally if x <= 0 the loop needs to stop, but since when complete the task the game will automaticly reset the program,
		//there's no need to check the end condition
		while (x > 0){
			swap = x - 1;
			swap = x | swap;
			swap = swap + 1;
			swap = swap + disk_nr;
			source = swap % 3;
			
			swap = x - 1;
			swap = x & swap;
			swap = swap + disk_nr;
			dest = swap % 3;
			
			printf("\nMove from Peg %i to Peg %i", source, dest);
			x--;
		}
	}
	else{
		//swap becomes the temp var
		x = 1;
		int temp = disk_nr;
		disk_nr = source;
		//the same reason as before, there's no need to check if x >= disk_nr
		while(x < temp){
			swap = x - 1;
			swap = x & swap;
			swap = swap + disk_nr;
			source = swap % 3;
			
			swap = x - 1;
			swap = x | swap;
			swap = swap + 1;
			swap = swap + disk_nr;
			dest = swap % 3;
			printf("\nMove from Peg %i to Peg %i", source, dest);
			x++;
	    }
	}
    cout<<"\n";
    getch();
}
