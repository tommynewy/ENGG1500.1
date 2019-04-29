#include <stdio.h>

int main() {
    char Imessage[1024];        //initialise an array of length 1024, the string of the original 'Input', I message
    char Omessage[1024], temp;      //initialise an array of length 1024, the srting of the resulting 'Output', O message. Also a temporary for keeping the character when working with it
    char alphabet[26], sum[26];     //initialise two arrays of length 26 to hold the alphabet key for substitution cipher and the count of letters
    int n, key, i, y, max;          //initialise five integers, a counter (n), the rotation key, the program function (i) (line 12), a temporary integer (y) that acts as a pointer in keyless rotation decryption, and storage for the max count
    FILE *output = fopen("output.txt", "w");        //initialising a write only file as the output (output.txt)
    FILE *cue = fopen("key.txt", "r");              //initialising a read only file for key (key.txt). cue is random (couldn't be key)
    FILE *op = fopen("operation.txt", "r");         //initialising a read only file for program operation (i, line 12) described in README (operation.txt)
                                                    //END Initialising
    printf("Operation codes: Rotation Encyrption (1), Rotation Decryption (2), Substitution Encryption (3), Substitution Decryption (4)\nPlease use README first\n");
    fscanf(cue, "%d", &key);                        //(above line is self explainitory) key as integer from key.txt
    fgets(Imessage, sizeof Imessage, stdin);        //retrieve the input message from standard input (with a max size of Imessage)
    fscanf(op, "%d", &i);                           //retrieve operator code (explained in README)
    printf("The message is: %s\n", Imessage);       //printing the given message back for personal and user response
    fscanf(cue, "%s", alphabet);                    //retrieve the alphabet key as a char string
                                                    //END Set up
    if (i == 1) {                                   //if user wants rotation encyrption
        if (0 > key || key > 25) {                  //check key is within range (specified in README and project instructions)
            printf("Error with value of key. %d is not in the range 0-25", key);
            return 0;                               //(above; print error with given key) end program
        }                                           //ENDIF
        printf("Key: %d Operation: %d\n", key, i);  //print key and function code for personal checking
        for (n = 0; Imessage[n] != '\0'; n++) {     //a loop starting the counter of n at 0, incrementing by 1 each loop, and until the character at Imessage[n] is NUL (the string ends)
            temp = Imessage[n];                     //temporary character is character of input at position n
            if (temp >= 'A' && temp <= 'Z') {       //if the character is a capital letter (between A and Z in the ASCII chart)
                temp = temp + key;                  //add the key to the character
                if (temp > 'Z') {                   //if this character is no longer a capital letter (beyond Z in the ASCII chart)
                    temp = temp - 'Z' + 'A' - 1;    //character - Z (90) results in a number from 1-24 (leftover from key) then added to A - 1 (to account for starting at 0)
                }                                   //ENDIF
                Omessage[n] = temp;                 //output at position n is this character
            } else if (temp >= 'a' && temp <= 'z') {//or if character is lower case letter
                temp = temp + key;                  //add key to character
                if (temp > 'z') {                   //if new character is not a lteer (beyond z in the ASCII chart)
                    temp = temp - 'z' + 'a' - 1;    //character - z(122) results in a number leftover from key, then A is added - 1
                }                                   //ENDIF
                Omessage[n] = temp;                 //output at position n is this character
            } else {                                //if the character is anything else (spaces, punctuation)
                Omessage[n] = temp;                 //output at position n is this character
            }                                       //ENDIF
        }                                           //ENDLOOP
    } else if (i == 2) {                            //user wants rotation decyption
        int max2 = 0, max3 = 0, max4 = 0, max5 = 0, max6 = 0, x = 0;
        if (0 > key || key > 25) {   //check key is within range
            printf("Error with value of key. %d is not in the range 0-25", key);
            return 0;                               //print error & end program
        } else if (key == 0) {                   //if key is NULL (ie no key given)
            for (n = 0; Imessage[n] != '\0'; n++) { //loop starting counter n at zero, incrementing by 1 until string ends. this loop counts the occurence of all characters
                temp = Imessage[n];                 //temporary character
                if (temp >= 'A' && temp <= 'Z') {   //character is upper case letter
                    y = temp - 'A';                 //y is number of letters position in the alphabet
                    sum[y]++;                       //increment sum of element y by one
                } else if (temp >= 'a' && temp <= 'z') {    //character is lower case letter
                    y = temp - 'a';                         //letters position in alphabet
                    sum[y]++;                               //increment sum of letter
                }                                           //ENDIF
            }                                               //ENDLOOP
            max = 0;
            for (n = 0; n < 26; n++) {//find which letter occurs most
                if (sum[max] < sum[n]) {
                    max = n;
                } else if (sum[max2] < sum[n] && sum[max2] < sum[max]) {
                    max2 = n;
                } else if (sum[max3] < sum[n] && sum[max3] < sum[max2]) {
                    max3 = n;
                } else if (sum[max4] < sum[n] && sum[max4] < sum[max3]) {
                    max4 = n;
                } else if (sum[max5] < sum[n] && sum[max5] < sum[max4]) {
                    max5 = n;
                } else if (sum[max6] < sum[n] && sum[max6] < sum[max5]) {
                    max6 = n;
                }
            }
            printf("Operation is: %d\n", i);
            printf("In order: no key, 6 most likely keys, all posible\n");
            for (x = 0; x < 32; x++) {
                if (x == 0) {
                    key = 0;
                } else if (x == 1) {
                    key = max - 4;
                    if (key < 0) {
                        key = 26 + key;
                    }
                } else if (x == 2) {
                    key = max - 19;
                    if (key < 0) {
                        key = 26 + key;
                    }
                } else if (x == 3) {
                    key = max;
                    if (key < 0) {
                        key = 26 + key;
                    }
                } else if (x == 4) {
                    key = max - 14;
                    if (key < 0) {
                        key = 26 + key;
                    }
                } else if (x == 5) {
                    key = max - 8;
                    if (key < 0) {
                        key = 26 + key;
                    }
                } else if (x == 6) {
                    key = max - 13;
                    if (key < 0) {
                        key = 26 + key;
                    }
                } else {
                    key = x - 6;
                    if (key < 0) {
                        key = 26 + key;
                    }
                }
                printf("%d= Key: %d ", x + 1, key);  //print key and function code for personal checking
                n = 0;
                for (n = 0; Imessage[n] != '\0'; n++) {     //a loop starting the counter of n at 0, incrementing by 1 each loop, and until the character at Imessage[n] is NUL (the string ends)
                    temp = Imessage[n];                     //temporary character is character of input at position n
                    if (temp >= 'A' && temp <= 'Z') {       //if the character is a capital letter (between A and Z in the ASCII chart)
                        temp = temp - key;                  //take key from character
                        if (temp < 'A') {                   //if this character is no longer a capital letter (beyond A in the ASCII chart)
                            temp = temp + 'Z' - 'A' + 1;    //character + Z (90) - A (65) results in leftover from key (+1 for start at 0)
                        }                                   //ENDIF
                        Omessage[n] = temp;                 //output at position n is this character
                    } else if (temp >= 'a' && temp <= 'z') {//if the character is a lower case letter
                        temp = temp - key;                  //take key from character
                        if (temp < 'a') {                   //if this chracter is no longer a lower case letter
                            temp = temp + 'z' - 'a' + 1;    //character + z - a (leftover key) +1 (start at 0)
                        }                                   //ENDIF
                        Omessage[n] = temp;                 //output at position n is this character
                    } else {                                //if the character is anything else (spaces, punctuation)
                        Omessage[n] = temp;                 //output at position n is this character
                    }                                         //ENDIF
                }
                printf("Decryption is: %s\n", Omessage);            //print the resulting decryption
                if (x ==6) {
                    printf("\n");
                }
            }


        } else {                                           //ENDIF
            printf("Key: %d Operation: %d\n", key, i);  //print key and function code for personal checking
            n = 0;
            for (n = 0; Imessage[n] != '\0'; n++) {     //a loop starting the counter of n at 0, incrementing by 1 each loop, and until the character at Imessage[n] is NUL (the string ends)
                temp = Imessage[n];                     //temporary character is character of input at position n
                if (temp >= 'A' && temp <= 'Z') {       //if the character is a capital letter (between A and Z in the ASCII chart)
                    temp = temp - key;                  //take key from character
                    if (temp < 'A') {                   //if this character is no longer a capital letter (beyond A in the ASCII chart)
                        temp = temp + 'Z' - 'A' + 1;    //character + Z (90) - A (65) results in leftover from key (+1 for start at 0)
                    }                                   //ENDIF
                    Omessage[n] = temp;                 //output at position n is this character
                } else if (temp >= 'a' && temp <= 'z') {//if the character is a lower case letter
                    temp = temp - key;                  //take key from character
                    if (temp < 'a') {                   //if this chracter is no longer a lower case letter
                        temp = temp + 'z' - 'a' + 1;    //character + z - a (leftover key) +1 (start at 0)
                    }                                   //ENDIF
                    Omessage[n] = temp;                 //output at position n is this character
                } else {                                //if the character is anything else (spaces, punctuation)
                    Omessage[n] = temp;                 //output at position n is this character
                }                                         //ENDIF
            }
        }                                           //ENDLOOP
    } else if (i == 3 || i ==4) {                   //user wants something with substitution
        printf("Key: %s Operation: %d\n", alphabet, i);     //print key and function code for personal checking
        if (i == 3) {                                       //user wants substitution encoding
            for (n = 0; Imessage[n] != '\0'; n++) {         //loop starting a counter at 0 with increment of 1 until input value is NUL (end of string)
                temp = Imessage[n];                         //temporary character is input at position n
                if (temp == 'A' || temp == 'a') {           //character is letter a
                    temp = alphabet[0];                     //key alphabet at position
                } else if (temp == 'B' || temp == 'b') {    //character is letter b
                    temp = alphabet[1];                     //key alphabet at position
                } else if (temp == 'C' || temp == 'c') {    //character is letter c
                    temp = alphabet[2];                     //key alphabet at position
                } else if (temp == 'D' || temp == 'd') {    //character is letter d
                    temp = alphabet[3];                     //key alphabet at position
                } else if (temp == 'E' || temp == 'e') {    //character is letter e
                    temp = alphabet[4];                     //key alphabet at position
                } else if (temp == 'F' || temp == 'f') {    //character is letter f
                    temp = alphabet[5];                     //key alphabet at position
                } else if (temp == 'G' || temp == 'g') {    //character is letter g
                    temp = alphabet[6];                     //key alphabet at position
                } else if (temp == 'H' || temp == 'h') {    //character is letter h
                    temp = alphabet[7];                     //key alphabet at position
                } else if (temp == 'I' || temp == 'i') {    //character is letter i
                    temp = alphabet[8];                     //key alphabet at position
                } else if (temp == 'J' || temp == 'j') {    //character is letter j
                    temp = alphabet[9];                     //key alphabet at position
                } else if (temp == 'K' || temp == 'k') {    //character is letter k
                    temp = alphabet[10];                    //key alphabet at position
                } else if (temp == 'L' || temp == 'l') {    //character is letter l
                    temp = alphabet[11];                    //key alphabet at position
                } else if (temp == 'M' || temp == 'm') {    //character is letter m
                    temp = alphabet[12];                    //key alphabet at position
                } else if (temp == 'N' || temp == 'n') {    //character is letter n
                    temp = alphabet[13];                    //key alphabet at position
                } else if (temp == 'O' || temp == 'o') {    //character is letter o
                    temp = alphabet[14];                    //key alphabet at position
                } else if (temp == 'P' || temp == 'p') {    //character is letter p
                    temp = alphabet[15];                    //key alphabet at position
                } else if (temp == 'Q' || temp == 'q') {    //character is letter q
                    temp = alphabet[16];                    //key alphabet at position
                } else if (temp == 'R' || temp == 'r') {    //character is letter r
                    temp = alphabet[17];                    //key alphabet at position
                } else if (temp == 'S' || temp == 's') {    //character is letter s
                    temp = alphabet[18];                    //key alphabet at position
                } else if (temp == 'T' || temp == 't') {    //character is letter t
                    temp = alphabet[19];                    //key alphabet at position
                } else if (temp == 'U' || temp == 'u') {    //character is letter u
                    temp = alphabet[20];                    //key alphabet at position
                } else if (temp == 'V' || temp == 'v') {    //character is letter v
                    temp = alphabet[21];                    //key alphabet at position
                } else if (temp == 'W' || temp == 'w') {    //character is letter w
                    temp = alphabet[22];                    //key alphabet at position
                } else if (temp == 'X' || temp == 'x') {    //character is letter x
                    temp = alphabet[23];                    //key alphabet at position
                } else if (temp == 'Y' || temp == 'y') {    //character is letter y
                    temp = alphabet[24];                    //key alphabet at position
                } else if (temp == 'Z' || temp == 'z') {    //character is letter z
                    temp = alphabet[25];                    //key alphabet at position
                } else {                                    //character is anything else
                    temp = temp;                            //character is the same
                }                                           //ENDIF
                Omessage[n] = temp;                         //output at n is this character
            }                                               //ENDLOOP
        } else if (i == 4) {                                //user wants to decode substitution
            /*for () {
                for (n = 0; Imessage[n] != '\0'; n++) { //loop starting counter n at zero, incrementing by 1 until string ends. this loop counts the occurence of all characters
                    temp = Imessage[n];                 //temporary character
                    if (temp >= 'A' && temp <= 'Z') {   //character is upper case letter
                        y = temp - 'A';                 //y is number of letters position in the alphabet
                        sum[y]++;                       //increment sum of element y by one
                    } else if (temp >= 'a' && temp <= 'z') {    //character is lower case letter
                        y = temp - 'a';                         //letters position in alphabet
                        sum[y]++;                               //increment sum of letter
                    }                                           //ENDIF
                }                                               //ENDLOOP
                max = 0;
                int max2 = 0, max3 = 0, max4 = 0, max5 = 0, max6 = 0;
            //etaoin   ietl
                for (n = 0; n < 26; n++) {//find which letter occurs most
                    if (sum[max] < sum[n]) {
                        max = n;
                    } else if (sum[max2] < sum[n] && sum[max2] < sum[max]) {
                        max2 = n;
                    } else if (sum[max3] < sum[n] && sum[max3] < sum[max2]) {
                        max3 = n;
                    } else if (sum[max4] < sum[n] && sum[max4] < sum[max3]) {
                        max4 = n;
                    } else if (sum[max5] < sum[n] && sum[max5] < sum[max4]) {
                        max5 = n;
                    } else if (sum[max6] < sum[n] && sum[max6] < sum[max5]) {
                        max6 = n;
                    }
                }
                if (max2 - max == 14 || max2 - max == -14) {
                    key = max - 4;
                } else if (max2 - max == 3 || max2 - max == -3) {
                    key = max - 8;
                } else if (max2 - max == 18 || max2 - max == -18) {
                    key = max - 19;
                } else if (max2 - max == 9 || max2 - max == -9) {
                    key = max - 4;
                } else {
                    key = max - 4;//adjust key accordingly e = 4
                }
            }*/

            for (n = 0; Imessage[n] != '\0'; n++) {         //loop starting a counter at 0 with increment of 1 until input value is NUL (end of string)
                temp = Imessage[n];                         //temporary character is input at position n
                if (temp == alphabet[0]) {                  //character is same at key position 1
                    temp = 'A';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[1]) {           //character is same at key position 2
                    temp = 'B';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[2]) {           //character is same at key position 3
                    temp = 'C';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[3]) {           //character is same at key position 4
                    temp = 'D';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[4]) {           //character is same at key position 5
                    temp = 'E';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[5]) {           //character is same at key position 6
                    temp = 'F';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[6]) {           //character is same at key position 7
                    temp = 'G';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[7]) {           //character is same at key position 8
                    temp = 'H';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[8]) {           //character is same at key position 9
                    temp = 'I';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[9]) {           //character is same at key position 10
                    temp = 'J';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[10]) {          //character is same at key position 11
                    temp = 'K';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[11]) {          //character is same at key position 12
                    temp = 'L';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[12]) {          //character is same at key position 13
                    temp = 'M';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[13]) {          //character is same at key position 14
                    temp = 'N';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[14]) {          //character is same at key position 15
                    temp = 'O';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[15]) {          //character is same at key position 16
                    temp = 'P';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[16]) {          //character is same at key position 17
                    temp = 'Q';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[17]) {          //character is same at key position 18
                    temp = 'R';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[18]) {          //character is same at key position 19
                    temp = 'S';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[19]) {          //character is same at key position 20
                    temp = 'T';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[20]) {          //character is same at key position 21
                    temp = 'U';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[21]) {          //character is same at key position 22
                    temp = 'V';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[22]) {          //character is same at key position 23
                    temp = 'W';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[23]) {          //character is same at key position 24
                    temp = 'X';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[24]) {          //character is same at key position 25
                    temp = 'Y';                             //corresponding letter in the alphabet
                } else if (temp == alphabet[25]) {          //character is same at key position 26
                    temp = 'Z';                             //corresponding letter in the alphabet
                } else {                                    //character is anything else
                    temp = temp;                            //character is the same
                }                                           //ENDIF
                Omessage[n] = temp;                         //output at n is this character
            }                                               //ENDLOOP
        }                                                   //ENDIF
    } else {                                                //if no operator matches
        printf("Operation selection error");                //error message for user
        return 0;                                           //end program
    }                                                       //ENDIF
                                                            //END Operations
    if (i == 1 || i == 3) {                                 //either rotation or subtitution encryption
        printf("Encryption is: %s\n", Omessage);            //print the resulting encyrption to the terminal (for personal testing use)
    } else if (i == 2 || i == 4) {                          //either roation or subtitution decryption
        printf("Decryption is: %s\n", Omessage);            //print the resulting decryption
    }                                                       //ENDIF
    fprintf(output, "%s\n", Omessage);                      //write the resulting encyrption to the output file
    return 0;                                               //end program
}