#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
void handleFileError(const char* functionName) {
    perror(functionName);
    exit(EXIT_FAILURE);
}

int main() {
    FILE* textFile = fopen("myTextFile.txt", "w");
    if (textFile == NULL) {
        handleFileError("fopen");
    }
    fprintf(textFile, "This is line 1.\n");
    fprintf(textFile, "This is line 1.\n");
   
    if (fclose(textFile) !=0) {
        handleFileError("fclose");
    }

    FILE* binaryFile = fopen("myBinaryFile.data", "wb");
    if (binaryFile == NULL) {
        handleFileError("fopen");
    }

    size_t elementsWritten = fwrite(kBinaryData, sizeof(unsigned short), sizeof(kBinaryData) / sizeof(unsigned short), binaryFile);
    if (elementsWritten != sizeof(kBinaryData) / sizeof(unsigned short)) {
        handleFileError("fwrite");
    }
 
    if (fclose(binaryFile) !=0) {
        handleFileError("fclose");
    }

    return 0;
}
