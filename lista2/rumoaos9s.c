    #include <stdio.h>

    // Function to calculate the sum of digits of a number
    int sum_of_digits(char num[]) { // recive a char of numbers how to paratemer
        int sum = 0; // inicialize the sum = 0, This variable will be used to accumulate the sum of the digits.
        for (int i = 0; num[i] != '\0'; i++) { //this run all the string, \0 means the end of the string
            sum += num[i] - '0'; //Adds the integer value of the digit to the sum variable. 
            //This accumulates the sum of all digits encountered in the string. 
        }
        return sum; // return the sum total of de function  
    }

    // Function to calculate the degree of nine
    int degree_of_9(char num[]) { // this function recive a char of numbers how to paratemer
        int degree = 0; // inicialize the degree = 0, This variable will be used to accumulate the degree of the number.
        while (num[1] != '\0' || num[0] != '9') {// the first condition is to check if the number is 9, 
        //the second condition is to check if the number is 0, the loop end when the two coditions are false
            int sum = sum_of_digits(num); // calulate the sum of the digits of the number
            sprintf(num, "%d", sum);//this update the value of the number, 
            //the function sprintf() is used to convert the sum to a string
            degree++; // increment to knew how many sum of operations was made 
        }
        return degree; // return the degree total of de function
    }

    int main() {
        char number9s[1001]; // aloccate of the max operation of the array

        while (1) { // infinity loop
            scanf("%s", number9s); // read the number 
            
            if (number9s[0] == '0' && number9s[1] == '\0') // Check if '0' is the only character in the input
                break;
            
            int degree = degree_of_9(number9s); // call the function to calculate the degree of 9
            
            if (degree == 0) { 
                printf("%s is not a multiple of 9.\n", number9s);
            } else {
                printf("%s is a multiple of 9 and has 9-degree %d.\n", number9s, degree); // orint the number was multple of 9 and the total of interations
            }
        }

        return 0;
    }
