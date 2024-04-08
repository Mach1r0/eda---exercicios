#include <stdio.h>
#include <string.h>

int map_choice_to_number(char *choice) {
    if (strcmp(choice, "pedra") == 0) {
        return 0;
    } else if (strcmp(choice, "papel") == 0) {
        return 1;
    } else if (strcmp(choice, "tesoura") == 0) {
        return 2;
    } else if (strcmp(choice, "lagarto") == 0) {
        return 3;
    } else if (strcmp(choice, "Spock") == 0) {
        return 4;
    }
    return -1; //Invalid choice
}

int main(){
    char sheldon_choice_str[10], raj_choice_str[10]; 
    scanf("%s %s", sheldon_choice_str, raj_choice_str) ; // read choice of sheldon and raj 

    int sheldon_choice = map_choice_to_number(sheldon_choice_str);
    int raj_choice = map_choice_to_number(raj_choice_str);

    int game_rules[5][5];

    // Assume that -1 means Sheldon wins, 1 means Raj wins, and 0 means a tie
    // Rules where Sheldon chooses "pedra"
    game_rules[0][0] = 0; // pedra vs pedra
    game_rules[0][1] = 1; // pedra vs papel
    game_rules[0][2] = -1; // pedra vs tesoura
    game_rules[0][3] = -1; // pedra vs lagarto
    game_rules[0][4] = 1; // pedra vs Spock

    // Rules where Sheldon chooses "papel"
    game_rules[1][0] = -1; // papel vs pedra
    game_rules[1][1] = 0; // papel vs papel
    game_rules[1][2] = 1; // papel vs tesoura
    game_rules[1][3] = 1; // papel vs lagarto
    game_rules[1][4] = -1; // papel vs Spock

    // Rules where Sheldon chooses "tesoura"
    game_rules[2][0] = 1; // tesoura vs pedra
    game_rules[2][1] = -1; // tesoura vs papel
    game_rules[2][2] = 0; // tesoura vs tesoura
    game_rules[2][3] = -1; // tesoura vs lagarto
    game_rules[2][4] = 1; // tesoura vs Spock

    // Rules where Sheldon chooses "lagarto"
    game_rules[3][0] = 1; // lagarto vs pedra
    game_rules[3][1] = -1; // lagarto vs papel
    game_rules[3][2] = 1; // lagarto vs tesoura
    game_rules[3][3] = 0; // lagarto vs lagarto
    game_rules[3][4] = -1; // lagarto vs Spock

    // Rules where Sheldon chooses "Spock"
    game_rules[4][0] = -1; // Spock vs pedra
    game_rules[4][1] = 1; // Spock vs papel
    game_rules[4][2] = -1; // Spock vs tesoura
    game_rules[4][3] = 1; // Spock vs lagarto
    game_rules[4][4] = 0; // Spock vs Spock    

    int result = game_rules[sheldon_choice][raj_choice];
    if (result == -1) {
        printf("Bazinga!\n");
    } else if (result == 0) {
        printf("De novo!\n");
    } else if (result == 1) {
        printf("Raj trapaceou!\n");
    }
    return 0;
}
