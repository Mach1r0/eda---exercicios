#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold an instruction
typedef struct
{
    int key;
    char value[30];
} Instruction;

#define InstructionType Instruction
#define LESS(a, b) a.key < b.key
#define SWAP(a, b) \
    InstructionType temp = a;       \
    a = b;         \
    b = temp;

// Function to sort an array of instructions
void sort(InstructionType *instructions, int size)
{
    // Iterate over the array from the end to the start
    for (int i = size - 1; i > 0; i--)
        // If the current instruction's key is less than the first instruction's key
        if (LESS(instructions[i], instructions[0]))
        {
            // Swap the current instruction with the first instruction
            SWAP(instructions[0], instructions[i]);
        }
    // Iterate over the array from the second element to the end
    for (int i = 2, j; i < size; i++)
    {
        // Store the current instruction in a temporary variable
        InstructionType temp = instructions[i];
        // Shift the elements of the array to the right until the correct position for the current instruction is found
        for (j = i; LESS(temp, instructions[j - 1]); j--)
            instructions[j] = instructions[j - 1];
        // Insert the current instruction at the correct position
        instructions[j] = temp;
    }
}

// Function to find an instruction by key in a sorted array of instructions
char *find(InstructionType *instructions, int size, int key)
{
    int left = 0, right = size - 1;
    // While the search space is not empty
    while (left <= right)
    {
        // Calculate the middle index
        int middle = (left + right) / 2;
        // If the key of the middle instruction is equal to the target key
        if (instructions[middle].key == key)
            // Return the value of the middle instruction
            return instructions[middle].value;

        // If the key of the middle instruction is greater than the target key
        if (instructions[middle].key > key)
            // Narrow the search space to the left half
            right = middle - 1;
        else
            // Narrow the search space to the right half
            left = middle + 1;
    }
    // If the target key is not found
    return "undefined";
}

int main()
{
    int numInstructions;
    // Read the number of instructions from the input
    scanf(" %d", &numInstructions);
    // Allocate memory for the array of instructions
    InstructionType *instructions = (InstructionType *)malloc(numInstructions * sizeof(InstructionType));

    // Read the instructions from the input
    for (int i = 0; i < numInstructions; i++)
        scanf("%d %s", &instructions[i].key, instructions[i].value);

    // Sort the array of instructions
    sort(instructions, numInstructions);

    // For each code in the input
    for (int code; scanf(" %d", &code) == 1;)
        // Print the value of the instruction with the given code
        printf("%s\n", find(instructions, numInstructions, code));

    return 0;
}