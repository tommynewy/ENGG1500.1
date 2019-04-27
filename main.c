#include <stdio.h>

/*-----------------
Cipher algorithms (currently only rotation encoding & decoding)

User instructions: read & use the terminal using the below commands:
cd /projects/ENGG1500.1 
ls h
./a.out
------------------*/

int main() {
    char Imessage[1024];                        //initialise an array of length 1024, the string of the original 'Input', I message
    char Omessage[1024], temp;                  //initialise an array of length 1024, the srting of the resulting 'Output', O message. Also a temporary for keeping the character when working with it
    char alphabet[30];
    int n, key, i;                              //initialise three integers, a counter n, the rotation key, and the program function i (line 20)
    FILE *input = fopen("input.txt", "r");      //initialising a read only file as the input (input.txt)
    FILE *output = fopen("output.txt", "w");    //initialising a write only file as the output (output.txt)
    FILE *cue = fopen("key.txt", "r");          //initialising a read only file for function (i, line 20) and key (line 21). cue is random
    FILE *skey = fopen("Skey.txt", "r");
    
    printf("Function codes: Rotation Encyrption (1), Rotation Decryption (2), Substitution Encryption (3), Substitution Decryption(4)\nThis is to be used as the first character of key.txt\n");
    fscanf(cue, "%d %d", &i, &key);             //(above line is self explainitory) retrieve i & key from key.txt
    //fscanf(input,"%s\n", Imessage);           //terminal testing
    fgets(Imessage, sizeof Imessage, stdin);    //retrieve the input message from standard input (with a max size of Imessage)
    /*printf("Enter a key: \n");                //terminal testing
    scanf("%d", &key);*/                        //terminal testing
    //key = 2;                                    //hardcode of key 2 for desk checking & testing
    printf("The message is: %s\n", Imessage);   //printing the given message back (never works) for personal
    if (i == 1) {                               //if user wants rotation encyrption
        printf("Key: %d Function: %d\n", key, i);   //print key and function code for personal checking
        for (n = 0; Imessage[n] != '\0'; n++) {     //a loop starting the counter of n at 0, incrementing by 1 each loop, and until the character at Imessage[n] is NUL ie the string ends
            temp = Imessage[n];                     //temporary character is character of input at position n
            if (temp >= 'A' && temp <= 'Z') {       //if the character is a capital letter (between A and Z in the ASCII chart)
                temp = temp + key;                  //add the key to the character
                if (temp > 'Z') {                   //if this character is no longer a capital letter (beyond Z in the ASCII chart)
                    temp = temp - 'Z' + 'A' - 1;    //character - Z (90) results in a number from 1-24 (leftover from key) then added to A - 1 (to account for starting at 0)
                }
                Omessage[n] = temp;                 //output at position n is this character
            } else if (temp >= 'a' && temp <= 'z') {//or if character is lower case letter
                temp = temp + key;                  //add key to character
                if (temp > 'z') {                   
                    temp = temp - 'z' + 'a' - 1;
                }
                Omessage[n] = temp;                 //output at position n is this character
            } else {                                //if the character is anything else (spaces, punctuation)
                Omessage[n] = temp;                 //output at position n is this character
            }
        }
    } else if (i == 2) {
        printf("Key: %d Function: %d\n", key, i);   //print key and function code for personal checking
        for (n = 0; Imessage[n] != '\0'; n++) {     //a loop starting the counter of n at 0, incrementing by 1 each loop, and until the character at Imessage[n] is NUL ie the string ends
            temp = Imessage[n];                     //temporary character is character of input at position n
            if (temp >= 'A' && temp <= 'Z') {       //if the character is a capital letter (between A and Z in the ASCII chart)
                temp = temp - key;                  //add the key to the character
                if (temp < 'A') {                   //if this character is no longer a capital letter (beyond Z in the ASCII chart)
                    temp = temp + 'Z' - 'A' + 1;    //character 
                }
                Omessage[n] = temp;                 //output at position n is this character
            } else if (temp >= 'a' && temp <= 'z') {
                temp = temp - key;
                if (temp < 'a') {
                    temp = temp + 'z' - 'a' + 1;
                }
                Omessage[n] = temp;                 //output at position n is this character
            } else {                                //if the character is anything else (spaces, punctuation)
                Omessage[n] = temp;                 //output at position n is this character
            }
        }
    } else if (i == 3 || i ==4) {
        fscanf(skey, "%s", alphabet);
        //scanf(cue, "%d %s", &i, &alphabet);             //(above line is self explainitory) retrieve i & key from key.txt
        printf("Key: %s Function: %d\n", alphabet, i);   //print key and function code for personal checking
        if (i == 3) {
            for (n = 0; Imessage[n] != '\0'; n++) {
                temp = Imessage[n];
                if (temp == 'A' || temp == 'a') {
                    temp = alphabet[0];
                } else if (temp == 'B' || temp == 'b') {
                    temp = alphabet[1];
                } else if (temp == 'C' || temp == 'c') {
                    temp = alphabet[2];
                } else if (temp == 'D' || temp == 'd') {
                    temp = alphabet[3];
                } else if (temp == 'E' || temp == 'e') {
                    temp = alphabet[4];
                } else if (temp == 'F' || temp == 'f') {
                    temp = alphabet[5];
                } else if (temp == 'G' || temp == 'g') {
                    temp = alphabet[6];
                } else if (temp == 'H' || temp == 'h') {
                    temp = alphabet[7];
                } else if (temp == 'I' || temp == 'i') {
                    temp = alphabet[8];
                } else if (temp == 'J' || temp == 'j') {
                    temp = alphabet[9];
                } else if (temp == 'K' || temp == 'k') {
                    temp = alphabet[10];
                } else if (temp == 'L' || temp == 'l') {
                    temp = alphabet[11];
                } else if (temp == 'M' || temp == 'm') {
                    temp = alphabet[12];
                } else if (temp == 'N' || temp == 'n') {
                    temp = alphabet[13];
                } else if (temp == 'O' || temp == 'o') {
                    temp = alphabet[14];
                } else if (temp == 'P' || temp == 'p') {
                    temp = alphabet[15];
                } else if (temp == 'Q' || temp == 'q') {
                    temp = alphabet[16];
                } else if (temp == 'R' || temp == 'r') {
                    temp = alphabet[17];
                } else if (temp == 'S' || temp == 's') {
                    temp = alphabet[18];
                } else if (temp == 'T' || temp == 't') {
                    temp = alphabet[19];
                } else if (temp == 'U' || temp == 'u') {
                    temp = alphabet[20];
                } else if (temp == 'V' || temp == 'v') {
                    temp = alphabet[21];
                } else if (temp == 'W' || temp == 'w') {
                    temp = alphabet[22];
                } else if (temp == 'X' || temp == 'x') {
                    temp = alphabet[23];
                } else if (temp == 'Y' || temp == 'y') {
                    temp = alphabet[24];
                } else if (temp == 'Z' || temp == 'z') {
                    temp = alphabet[25];
                } else { 
                    temp = temp;
                }
                Omessage[n] = temp;
            }
        } else if (i == 4) {
            printf("lol 4");
        }
    } else {
        printf("Function selection error");
    }
    
    printf("Encryption is: %s\n", Omessage);       //print the resulting encyrption to the terminal (for personal testing use)
    fprintf(output, "%s\n", Omessage);          //write the resulting encyrption to the output file
    return 0;
}
