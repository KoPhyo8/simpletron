#include <stdio.h>
#include <stdlib.h>

#define READ    10
#define WRITE   11
#define LOAD    20
#define STORE   21
#define ADD 30
#define SUBTRACT    31
#define DIVIDE  32
#define MULTIPLY    33
#define BRANCH  40
#define BRANCHNEG   41
#define BRANCHZERO  42
#define HALT    43
int i, j, height = 32,width = 32;
int main() 
{
    int memory[100] = {0};
    int accumulator = 0;
    int instruction_counter = 0; //boot address 0000
    int instruction_register = 0;
    int operation_code = 0;
    int operand = 0;
    //LOAD PROGRAM INTO MEMORY
    memory[0] = 1050; //Read
    memory[1] = 2050; //Load
    memory[2] = 1051; //Read
    memory[3] = 3351; //Operation
    memory[4] = 2152; //Store
    memory[5] = 1152; //Write
    memory[6] = 4300; //Halt
    printf("Welcome to SimpleTron Virtual Machine\n");
    printf("Enter a number to simulate:\n");
    while(1)
    {
        instruction_register = memory[instruction_counter++];
        operation_code = instruction_register / 100;
        operand = instruction_register % 100;
        switch (operation_code)
        {
            case 10:
                scanf("%d",&memory[operand]);
                break;
            case 11:
                printf("Result : %d\n\n",memory[operand]);
                break;
            case 20:
                accumulator = memory[operand];
                break;
            case 21:
                memory[operand] = accumulator;
                break;
            case 30:
                accumulator += memory[operand];
                break;
            case 31:
                accumulator -= memory[operand];
                break;
            case 32:
                accumulator /= memory[operand];
                break;
            case 33:
                accumulator *= memory[operand];
                break;
            case 40:
                instruction_counter = operand;
                break;
            case 41:
                if(accumulator < 0)
                {
                    instruction_counter = operand;
                }
                break;
            case 42:
                if(accumulator == 0)
                {
                    instruction_counter = operand;
                }
                break;
            case 43:
                printf("Program is terminated!");
                exit(0);
                break;
            default:
                printf("Err! No such instruction!!!.Program is terminated!");
                exit(0);
                break;
        }
    return 0;
}

    return 0;
}
