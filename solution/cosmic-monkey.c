#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * INSTRUCTIONS:
 * Note, you're going to need a C compiler to test your code. This is different
 * for each operating system, so feel free to ask a team member for help if
 * you're stuck.
 * ---------------------------------------------------------------------------*/

/**
 * int32_t system_call_perror(int return_val, char call_name[])
 *
 * \brief Prints to stderror if an error is encoutered in a system call
 *
 * Return_val is the return value of the system call we are handling, and
 * a name to indicate where the error occured. Usage:
 *
 * system_call_perror(write(STDERR_FILENO, "error message", 13),
 *                    "write to stderr");
 *
 * Essentially a wrapper around system calls that will write the error messages
 * corresponding to errno to standard error
 *
 * Parametres:
 * \param return_val : int, the return value of the system call being handled
 * \param call_name : a char array, some contextual information about the
 *                    system call
 *
 * Return:
 * \return int_32_t : the return value of the input system function call
 *
 * NOTE: This function is anally retentive. We expect some level of error
 * checking, but this is a bit excessive for the project
 */
inline int32_t system_call_perror(int return_val, char call_name[]) {
    if (return_val < 0) {
        perror(call_name);
    }
    return return_val;
}

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

int32_t cosmic_monkey(void *data, size_t size) {
    // cast data to char/uint8_t array to access individual bytes
    uint8_t *data_as_byte_array = (uint8_t *)data;

    // select random byte and bit to edit
    int32_t random_byte = rand() % (int32_t)size;
    int32_t random_bit = rand() % 8;

#ifdef DEBUG
    // Print which byte and bit are being flipped (for debugging purposes)
    printf("Flipping bit %d of byte %zu\n", random_bit, random_byte);
#endif

    // Flip the selected bit using XOR
    data_as_byte_array[random_byte] ^= (1 << random_bit);

    /* Explanation:
     * data_as_byte_array is cast to a uint8_t (unsigned single-byte-integer
     * array). We can access the random_byte-th byte by indexing into this
     * array, in the usual fashion.
     *
     * Any number XOR 0 (i.e., 0b000000000000...) is the number itself. Consider
     * a single bit, which can be either 0 or 1:
     * - if 0, we have 0 XOR 0 => 0 for the result number
     * - if 1, we have 0 XOR 1 => 1 for the result array.
     *
     * Thus, we can XOR the byte need be edited with a byte of all 0s except for
     * the bit need be edited. For the specific bit, consider XORing a bit with
     * 1:
     * - 0 XOR 1 = 1
     * - 1 XOR 1 = 0
     * Thus, we can flip that bit by putting a 1 in the corresponding bit mask.
     * Our mask is thus all 0s, except for a 1 at the appropriate bit. We can
     * create the corrext bit mask by left-bit-shifting 1 by random_bits.
     */
}

/**
 * int32_t print_bytes(void *data, size_t size);
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
