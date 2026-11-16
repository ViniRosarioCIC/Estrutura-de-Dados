#pragma once

typedef struct {

    int code;
    char name[30];
    float price;

} Product;

void allocate_vector (Product **vector, int quantity);

void read_data (Product *vector, int quantity);

void display_products(Product *vector, int quantity);
