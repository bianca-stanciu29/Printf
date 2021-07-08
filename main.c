#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

static int write_stdout(const char *token, int length) {
    int rc;
    int bytes_written = 0;

    do {
        rc = write(1, token + bytes_written, length - bytes_written);
        if (rc < 0)
            return rc;

        bytes_written += rc;
    } while (bytes_written < length);

    return bytes_written;
}
//function for calculating the module
int module(int n) {
    if (n < 0)
        return -n;
    return n;
}

int iocla_printf(const char *format, ...) {
    // initialize the arguments
    va_list arg;
    //to know where the variable arguments begin
    va_start(arg, format);
    //variable for traversing the string
    char *character;
    //vector in which I save the final result
    char result_string[20000];
    int size_result = 0;
    //reading string character by character
    for (character = (char *) format; *character != '\0'; character++) {
        //each specification is entered with the % character
        //test if character is %
        if (*character == '%') {

            if (*(character + 1) == 'd') {
                int number = va_arg(arg, int);
                int number_of_digits = 0;
                //boolean variable for sign
                int sign = 0;
                //testing if the number is negative
                if (number < 0) {
                    sign = 1;
                }
                //string in which I extract each digit from the number
                //and convert integer in char
                char convert_number[24];
                //as long as the number still has digits
                while (number != 0) {
                    //because the minus sign would appear each time the number was extracted
                    //I applied the number module
                    convert_number[number_of_digits] = module(number % 10) + '0';
                    number_of_digits++;
                    number = number / 10;
                }
                //adding the terminal character
                convert_number[number_of_digits] = '\0';

                if (sign == 1) {
                    //the first character in the resulting string is minus
                    result_string[size_result] = '-';
                    size_result++;
                }
                //adding in the result_string the digits
                // from the convert_number from tail to head
                for (int i = strlen(convert_number) - 1; i >= 0; i--) {
                    result_string[size_result] = convert_number[i];
                    size_result++;
                }
                character++;

            } else if (*(character + 1) == 'u') {

                unsigned number = va_arg(arg, unsigned);
                int number_of_digits = 0;
                char convert_number[20];
                while (number != 0) {
                    //because the transformation is without a sign
                    // the module function is no longer used
                    convert_number[number_of_digits] = (number % 10) + '0';
                    number_of_digits++;
                    number = number / 10;
                }
                //adding the terminal character
                convert_number[number_of_digits] = '\0';
                //adding in the result_string the digits
                for (int i = strlen(convert_number) - 1; i >= 0; i--) {
                    result_string[size_result] = convert_number[i];
                    size_result++;
                }
                character++;

            } else if (*(character + 1) == 'c') {

                char c = va_arg(arg, int);
                //the result_string takes on character
                result_string[size_result] = c;
                size_result++;
                character++;

            } else if (*(character + 1) == 's') {

                char *character_string = va_arg(arg, char *);
                //scrolling the character_string
                for (int i = 0; i < strlen(character_string); i++) {
                    //put in result each character
                    result_string[size_result] = character_string[i];
                    size_result++;
                }
                character++;

            } else if (*(character + 1) == '%') {
                //the result_string receives the character%
                result_string[size_result] = '%';
                size_result++;
                character++;

            } else if (*(character + 1) == 'x') {

                unsigned int number = va_arg(arg,unsigned int);
                //array to store hexadecimal number
                char hex_string[20];
                //counter for hexadecimal number array
                int hex_counter=0;
                //string of values for hexadecimal numbers
                char hexvalue_string[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
                //variable to retain the rest of the division
                int remainder = 0;

            while(number != 0)
            {
                remainder = number % 16;
                //to hex_string I assign the value
                //the corresponding value in the string of values
                hex_string[hex_counter] = hexvalue_string[remainder];
                hex_counter++;
                number = number / 16;
            }
            //put hex_string in reverse order in result string
                for(int j=hex_counter-1; j>=0; j--){
                    result_string[size_result] = hex_string[j];
                    size_result++;
                }
                character++;
            }
        } else {
            //if after % there are no more cases
            result_string[size_result] = *character;
            size_result++;
        }
    }
    //adding the terminal character
    result_string[size_result] = '\0';
    return write_stdout(result_string, size_result);
}
