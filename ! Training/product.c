#include <stdio.h>
#include <stdlib.h>
#include "product.h"

void allocate_vector (Product **vector, int quantity){

    if(quantity <= 0){
        *vector = NULL;
        return;
    }

    *vector = malloc(sizeof(Product) * quantity);
    if(*vector == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void read_data (Product *vector, int quantity){

    if(vector == NULL || quantity <= 0){
        return;
    }

    printf("\nRegistering Products---------\n");
        for(int i = 0; i < quantity; i++){
            printf("Product [%d]", i+1);
            printf("\nEnter the code: ");
            scanf("%d", &vector[i].code);
            printf("\nEnter the name: ");
            scanf(" %29[^\n]", vector[i].name);
            printf("\nEnter the price: ");
            scanf("%f", &vector[i].price);
        }

}

void display_products (Product *vector, int quantity){

    if (vector == NULL || quantity <= 0){
        return;
    }

    printf("\nDisplaying Products: ------------\n");
    for(int i = 0; i < quantity; i++){
        printf("Product[%d] | Code: %d | Name: %s | Price: %.2f |\n",i+1, vector[i].code, vector[i].name, vector[i].price);
    }

}