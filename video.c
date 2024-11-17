#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of the movie (colored image)
//   durationCredits: duration in seconds of credits (black/white image)
//   unit: Unit of the output value. It could be 'bt' for bytes, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits
// Return value
//   colored video size (based on the unit passed parameter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Bits per pixel for colored image (24 bits)
    int bitsPerPixel = 24;

    // Calculate total bits for the colored section
    int totalBitsIC = w * h * bitsPerPixel; // Total bits per frame
    int totalImagesC = durationMovie * fps; // Total frames in colored section
    float sizeInBits = totalImagesC * totalBitsIC; // Total size in bits

    // Calculate total bits for the black-and-white section
    // Each pixel in black-and-white is 8 bits (1 byte)
    int totalBitsBW = w * h * (durationCredits * fps); // Total bits for black-and-white section
    sizeInBits += totalBitsBW; // Add to total size in bits

    // Convert size based on the requested unit
    if (strcmp(unit, "bt") == 0) {
        return sizeInBits / 8; // Convert to bytes
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBits / 1024; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBits / (1024 * 1024); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBits / (1024 * 1024 * 1024); // Convert to gigabits
    } else {
        // If the unit is not recognized, return -1 or some error value
        return -1.0f;
    }
}