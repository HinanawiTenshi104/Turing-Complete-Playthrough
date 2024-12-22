#include<stdio.h> 
#include<conio.h>
#include<iostream>
using namespace std;

uint8_t fastmod3(uint8_t n){
	/*the maxium value is 31 + 5 + 1*/
	uint8_t t1;
	t1 = 1;
	t1 = n & 0b0011;
	n = n >> 2;
	n = n + t1;
	t1 = n & 0b0011;
	n = n >> 2;
	n = n + t1;
	if (n > 2) n = n - 3;
	
	return n;
}

int main(){
	/*original code
	uint8_t n;
	for (n = 0; n < 38; n++){
		uint8_t a = n;
		a = (a >> 4) + (a & 0b1111); //a<=30
		a = (a >> 2) + (a & 0b0011); //a<=9
		a = (a >> 2) + (a & 0b0011); //a<=3
		if (a > 2) a -= 3;
		printf("a:%d, n mod 3:%d\n", a, n%3);
	}*/
	/*pseudo assembly code
	uint8_t n, t1, t2;
	t1 = n >> 4;
	t2 = n & 0b1111;
	n = t1 + t2;
	t1 = n >> 2;
	t2 = n & 0b0011;
	n = t1 + t2;
	t1 = n >> 2;
	t2 = n & 0b0011;
	n = t1 + t2;
	if (n > 2) n = n - 3;*/

	/*for (uint8_t n = 0; n < 38; n++){
		printf("fastmod3:%d, n mod 3:%d\n", fastmod3(n), n%3);
	}*/
	fastmod3(33);
}
