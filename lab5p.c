#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct worker {
    char familia[30];
    long int number; // +7998655446
    int bday[3];
};
int main () {
    FILE* file = fopen("worker.dat", "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    };
    
    struct worker w[3] = {
                        { .bday = {1,1,2020}, .familia = "Chon S.G.", .number = 89831275645},
                        { .bday= {3,8,1987}, .familia= "Kim Y.R.", .number = 89831357744},
                        { .bday={24,5,2024}, .familia= "Yang K.H.", .number=88005353535}
    };
    fwrite(w, sizeof(struct worker), 3,  file);

    fclose(file);
    
    printf("Записано в файл Worker.dat\n");

    file = fopen("worker.dat", "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    };

   // fread(w, sizeof(struct worker), 3,  file);
    struct worker print_workers;
    while (fread(&print_workers, sizeof(struct worker), 1,  file) == 1) {
        printf("%s.%ld.%d.%d.%d\n", print_workers.familia, print_workers.number, print_workers.bday[0], print_workers.bday[1], print_workers.bday[2]);

    }


    fclose(file);



    return 0;



};

