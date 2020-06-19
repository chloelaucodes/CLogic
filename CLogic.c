#include "extension_lib/ext_decode.c"
#include "extension_lib/ext_execute.c"

int main(int argc, char **argv) {
    FILE *file;

    if (argc < 2) {
        printf("Incorrect number of arguments provided, command format: Command <file path>\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Could not open file %s", argv[1]);
        return EXIT_FAILURE;   
    }
    
    logic_node **inputs = (logic_node **)malloc(sizeof(*inputs) * MAX_NUMBER_GATES);
    int num_inputs = 0;
    logic_node **output = read_file(file, inputs, &num_inputs);
    
    for(int i = 0; i < (1 << num_inputs); i++){
        printf("<-START->\n");
        for(int j = 0; j < num_inputs; j++){
            inputs[j]->input_value = (1 << j) & i;
            printf("Input Gate: %s Value: %d\n", inputs[j]->name, inputs[j]->input_value);
        }
        for(int i = 0; output[i]; i++){
            execute(output[i]);
        }
        printf("<- END ->\n\n");
    }
    return EXIT_SUCCESS;
}
