char* intToRoman(int num) {
     static char result[100] = "";
     result[0]='\0';

    char *roman[] = {
        "M","CM","D","CD",
        "C","XC","L","XL",
        "X","IX","V","IV","I"
    };

    int values[] = {
        1000,900,500,400,
        100,90,50,40,
        10,9,5,4,1
    };

    int i = 0;

    while(num > 0) {

        while(num >= values[i]) {

            strcat(result, roman[i]);

            num -= values[i];
        }

        i++;
    }

    return result;
    
}
