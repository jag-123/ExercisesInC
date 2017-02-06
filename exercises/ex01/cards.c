/*
A program for evaluating face values
Jeremy Garcia
*/

#include <stdio.h>
#include <stdlib.h>
/* 
User input is truncated to the first two characters.
input: buffer where result is stored
*/
char* get_card_name(char *input){
  puts("Enter the card_name: ");
  scanf("%2s", input);
  return input;
}

/*
Returns 1,-1, or 0 depending on the card value.
val: value of the input card
*/
int myCounter(int val){
	if ((val > 2) && (val < 7)) {
		return 1;
	} else if (val == 10) {
		return -1;
	}
	else{
		return 0;
	}
}

/*
main function that returns that count of the table based on user input
*/
int main()
{
  char card_name[3];
  get_card_name(card_name); 

  int count = 0;
  while ( card_name[0] != 'X') {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    int val = 0;
    switch(card_name[0]) {
      case 'K':
      case 'Q':
      case 'J':
        val = 10;
        break;
      case 'A':
        val = 11;
        break;
      case 'X':
        continue;
      default:
        val = atoi(card_name);
        if ((val < 1) || (val > 10)) {
          puts("I don't understand that value!");
          continue;
        }
      }

      count += myCounter(val);
      printf("Current count: %i\n", count);
  }
  return 0;
}
