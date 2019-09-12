//This code takes an input and returns a hamming code
//Collin Scott; 10/10/17; 

#include <iostream>
#include <bitset>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <math.h>
using namespace std;


int hamming(int val){
  //initializing variables
  int b[17];         
  int p1, p2, p4, p8, p16;
  char r[17];
  //converting the given number into a binary string for later use 
  //(I only use this for keeping the leading zeros during later conversion processes)
  string binary = bitset<16>(val).to_string();

  //copying the string into a char array
  strncpy(r,binary.c_str(),sizeof(r));
  r[sizeof(r)-1] = 0;

  //copying the char array into an int array
  for (int i = 0; i < 16; i++){
    b[i] = r[i] - '0';
  }
  cout <<"The binary form of the hexadecimal is: " << r << endl;

  //calculating parity bits
  p1 = (b[0]+b[1]+b[3]+b[4]+b[6]+b[8]+b[10]+b[11]+b[13]+b[15]) %2;

  p2 = (b[0]+b[2]+b[3]+b[5]+b[6]+b[9]+b[10]+b[12]+b[13])%2;

  p4 = (b[1]+b[2]+b[3]+b[7]+b[8]+b[9]+b[10]+b[14]+b[15])%2;

  p8 =( b[4]+b[5]+b[6]+b[7]+b[8]+b[9]+b[10])%2;

  p16 = (b[11]+b[12]+b[13]+b[14]+b[15])%2;

  int pa1 = p1;
  int pa2 = p2, pa4 = p4, pa8= p8, pa16 = p16;

  if (pa1  == 0)
    pa1 = 0;
  else
    pa1 = 1;
  
  if (pa2 == 0)
    pa2 = 0;
  else
    pa2 = 1;
  
  if (pa4 == 0)
    pa4 = 0;
  else
    pa4 = 1;
  
  if (pa8 == 0)
    pa8 = 0;
  else
    pa8 = 1; 
  
  if (pa16 == 0)
    pa16 = 0;
  else
    pa16 = 1;

  //placing the variables and creating the hamming code
  int parray[21] = {pa1, pa2, b[0], pa4, b[1],b[2],b[3],pa8,b[4],b[5],b[6],b[7],b[8],b[9],b[10],pa16,b[11],b[12],b[13],b[14],b[15]};

  cout << "The hamming code is: ";
  for (int  i = 0; i < 21; i++) {
    cout << parray[i];
  }
  cout << endl;
  long result = 0;
  for (long i = 20, j = 0; i >= 0;j++, i--) {
    result += parray[j] * pow(2,i);
  }
  cout << "The decimal form of the Hamming code is: ";
  cout << result << endl;

  cout << "The new hexadecimal is: ";
  cout << hex << result << endl;

  }; 
 

int main(){
  int a;

  //this section allows the tester to enter a hexadecimal for the program to use
  cout << "Please enter a 4-digit hexadecimal" << endl;
  cin >> hex >> a;
  hamming(a);
  
  return 0;

}
  
