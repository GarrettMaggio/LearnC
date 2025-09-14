#include <stdio.h>
#include <string.h>

void userInput() {
    //There are no strings in C so every phrase is a character array
    char user_input[50];

    printf ("Please enter your name. ");
    fgets(user_input, 50, stdin);

    printf ("Your name is:\t");

    for (int i = 0; i < strlen(user_input); i++) {
        printf("%c", user_input[i]);
    }
    printf("\n");
}

void functionExample() {
    char phrase[] = "Hello World";

    for (int i = 0 ; i < strlen(phrase) ; i++) {
        printf("%c", phrase[i]);
    }
    printf("\n");
}
// structs are similar to classes except there are no methods.
// with structs there are only members(related variables).
// structs can be accessed by their name.
struct Player {
    // members of the Player struct
    int player_id;
    char player_name[50];
    int player_level;
    int player_score;
};

int main() {

    userInput();
    functionExample();

    // C allows you to assign integer to decimals and vice versa.
    // be careful when mixing data types as some of the value may be lost.
    int var1 = 40;
    double var2 = 20.5, var3;

    var3 = var1 + var2;
    var1 = var1 + var2;

    printf( "The decimal value is:\t");
    printf("%f\n", var3);
    printf( "The integer value is:\t");
    printf("%d\n", var1);
    printf("\n");

    struct Player player1;
    struct Player player2;

    // . is the member access operator.
    strcpy(player1.player_name, "John" );
    player1.player_id = 1;
    player1.player_level = 10;
    player1.player_score = 200;

    strcpy(player2.player_name, "Lisa");
    player2.player_id = 2;
    player2.player_level = 10;
    player2.player_score = 220;

    printf( "Player Name:\t");
    printf("%s\n", player1.player_name);
    printf("Player Id:\t");
    printf("%d\n", player1.player_id);
    printf("Player Level:\t");
    printf("%d\n", player1.player_level);
    printf("Player Score:\t");
    printf("%d\n", player1.player_score);
    printf("\n");

    printf("Player Name:\t");
    printf("%s\n", player2.player_name);
    printf("Player Id:\t");
    printf("%d\n", player2.player_id);
    printf("Player Level:\t");
    printf("%d\n", player2.player_level);
    printf("Player Score:\t");
    printf("%d\n", player2.player_score);
    printf("\n");



    int number = 20;

    // * is known as the de-reference.
    // & is known as the reference.
    int *pointer = &number; // the pointer is assigned the address of number.
    // when the pointer is dereferenced it will use the value of the variable that it is pointing to.

    printf("The value of number is: %d\n", *pointer);
    printf("The address of number is: %p\n", &number);
    printf("The address of the pointer is %p\n", &pointer);

    return 0;

}