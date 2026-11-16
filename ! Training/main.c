#include <stdio.h>
#include <stdlib.h>
#include "product.h"

int main (){

    printf("========== PRODUCT REGISTRATION ===========\n");
    int q_products = 0;
    printf("Enter the number of products to be registered:  ");
    scanf("%d", &q_products);

    Product *vector = NULL;
    
    allocate_vector (&vector, q_products);

    read_data (vector, q_products);

    display_products(vector, q_products);

    free(vector);

    return 0;
}