#include <stdio.h>

void clear_screen(void){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void clear_input_buffer (void){
    while ( getchar() != '\n' );
}

void get_response(char temp_input){
    char affirmation = 'Y';
    printf("(Y/n) : ");
    clear_input_buffer();
    scanf("%c", &affirmation);
    if(affirmation > 96 && affirmation < 123){
        affirmation = affirmation - 32;
    }
    if(affirmation == 'Y'){
        printf("Please insert your temperature: ");
        float temp_value = 0;
        clear_input_buffer();
        scanf("%f", &temp_value);

        float result = 0;
        if(temp_input == 'C'){
            result = temp_value * 1.8f + 32;
            printf("%.2f Celsius is %.2f Fahrenheit\n", temp_value, result);
        }else{
            result = (temp_value - 32) / 1.8f;
            printf("%.2f Fahrenheit is %.2f Celsius\n", temp_value, result);
        }
    }else if(affirmation == 'N'){
        clear_screen();
        get_input();
    }else{
        printf("I'm sorry, I didn't understand that.\n");
        printf("Could you please repeat if you want to convert?\n");
        get_response(temp_input);
    }
}

void get_input(void){
    printf("What are you trying to convert? (Fahrenheit - F ; Celsius - C)\n");
    printf("(Only the first character inserted will be taken into consideration.)\n");
    char temp_input = 0;
    scanf("%c", &temp_input);
    if(temp_input > 96 && temp_input < 123){
        temp_input = temp_input - 32;
    }
    if(temp_input == 'C'){
        printf("Do you want to convert Celsius to Fahrenheit?\n");
    }
    else if(temp_input == 'F'){
        printf("Do you want to convert Fahrenheit to Celsius?\n");
    }
    else{
        clear_screen();
        printf("I'm sorry, I couldn't read that right.\n");
        get_input();
        return;
    }
    get_response(temp_input);
}

int main(void){
    get_input();
    return 0;
}