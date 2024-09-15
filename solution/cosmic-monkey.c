#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * INSTRUCTIONS:
 * Note, you're going to need a C compiler to test your code. This is different
 * for each operating system, so feel free to ask a team member for help if
 * you're stuck.
 * -----------------------------------------------------------------------------------------------*/

/**
 * int cosmic_monkey(void* data, size_t size)
 *
 * \brief Randomly selects a bit within `data` to flip, and flips the bit.
 *
 * The function should:
 *    - Randomly select a byte and a bit within that byte to flip (using rand()
 * seeded by srand()).
 *    - Print which byte and bit are being flipped (for debugging purposes).
 *    - Flip the selected bit using XOR.
 *
 * Prarametres:
 * \param data : The pointer to the data block to be mutated.
 * \param size : The size of the data block in bytes.
 *
 * Returns:
 * \return int8_t : 0 upon success
 */

uint8_t cosmic_monkey(void *data, size_t size) {
    // TODO :
    //  Implement the cosmic_monkey function, which should flip random bits in
    //  the input data block. Feel free to use the internet(and ChatGPT) to
    //  learn about the necessary operations.
}

/**
 * void print_bytes(void *data, size_t size);
 *
 * \brief Given a pointer to arbitrary data and a size, prints the data as a hex
 * array
 *
 * Parametres:
 * \param data : The pointer to the data block to be printed.
 * \param size : The size of the data block in bytes.
 *
 * Returns:
 * \return int32_t : a status code, int32_t to comply with status codes returned
 *                  by printf
 */

int32_t print_bytes(void *data, size_t size) {
    // TODO:
    //  Implement the print_bytes function to visualize the data in
    //  hexadecimal format before and after the mutation.
    // HINT: `man 3 printf` in the terminal
}

/**
 * int main(void)
 *
 * \brief Program entry point; runs cosmic monkey program
 *
 * Parametres:
 * N/A
 *
 * Return:
 * \return int : 0 upon success, +ve status code otherwise.
 *
 * NOTE: the use of int here as a return type is only to comply with the current
 * Linux standard. Use of ambiguous/unsized `int` types is *strongly*
 * discouraged in PVDXos
 */
int main(void) {
    // Example data for testing the Cosmic Monkey
    unsigned char data[] = {0xFF, 0x00, 0xAA, 0x55};

    // Print original data
    printf("Original data:\n");
    print_bytes(data, sizeof(data));

    // Seed random number generator
    srand((unsigned int)time(NULL));

    // Run the Cosmic Monkey to flip random bits
    cosmic_monkey(data, sizeof(data));

    // Print mutated data
    printf("Mutated data:\n");
    print_bytes(data, sizeof(data));

    return 0;
}
