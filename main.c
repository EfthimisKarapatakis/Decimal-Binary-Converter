#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

void binaryof();
void decimalof();

int main() {
    int myNum, choice;
    printf("\n\nDo you want to convert into deximal(0) or binary(1)? ");
    scanf("%d", &choice);
    if (choice == 1) {
        binaryof();
    } else if (choice == 0) {
        decimalof();
    } else {
        printf("Invalid input!");
    }
}

void binaryof() {
    int myNum;
    printf("Enter a number in decimal (max: 4096): ");
    scanf("%d", &myNum);
    if (myNum <= 4096) {
        int binaryNumber[12] = {0};

        for (int something = 0; something < myNum; something++) {
            for (int i = 12; i > 0; i--) {
                if (binaryNumber[i] == 0) {
                    binaryNumber[i] = 1;
                    for (int j = i + 1; j < 12; j++) {
                        binaryNumber[j] = 0;
                    }
                    break;
                }
            }
        }
        printf("Binary value: ");
        for (int i = 0; i < 12; i++) {
            printf("%d", binaryNumber[i]);
        }
        printf("\n");
    } else {
        printf("Invalid input!\n");
    }
}


void decimalof() {
    char myNum[13];
    int decimalNumber = 0;

    printf("Enter a binary number (max: 12bits): ");
    scanf("%s", myNum);
    int length = strlen(myNum);

    for (int i = 0; i < length; i++) {
        int binaryDigit = myNum[i] - '0';
        if (binaryDigit != 0 && binaryDigit != 1) {
            printf("Invalid binary number.\n");
            return;
        }
        decimalNumber += binaryDigit * pow(2, length - 1 - i);
    }

    printf("Decimal value: %d\n", decimalNumber);
}