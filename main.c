
#include"stdio.h"
#include"item.h"
#include"stdlib.h"
#include"string.h"



void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index){
    item_list[index].price = price;

    item_list[index].sku = malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);

    item_list[index].category = malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);

    item_list[index].name = malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
    

}
void free_items(Item *item_list, int size){
    for (int i = 0; i < size; i++) {
        free(item_list[i].category);
        free(item_list[i].sku);
        free(item_list[i].name);

    }
    free(item_list);
    
}
double average_price(Item *item_list, int size){
    
    double avg_price;
    for (int i = 0; i < size; i++) {
        avg_price += item_list[i].price;
    }
    avg_price = avg_price/size;
    return avg_price;
}
void print_items(Item *item_list, int size){
    for (int i = 0; i < size; i++) {
        printf("Item %s, Price: %f, Category: %s, SKU: %s \n", item_list[i].name, item_list[i].price, item_list[i].category, item_list[i].sku);
        printf("###############\n");
    }
}
void find_item_by_sku(Item *item_list, int size, const char *sku)
{
    int found = 0;
    int i = 0;

    while (i < size)
    {
        if (strcmp(item_list[i].sku, sku) == 0)
        {
            printf("###############\n");
            printf("item name = %s\n", item_list[i].name);
            printf("item sku = %s\n", item_list[i].sku);
            printf("item category = %s\n", item_list[i].category);
            printf("item price = %f\n", item_list[i].price);
            printf("###############\n");
            found = 1;
            break;
        }
        i++;
    }

    if (found != 1)
    {
        printf("Item with SKU %s not found.\n", sku);
    }
}

int main(int argc, char const *argv[])
{
    printf("code started \n");
    Item *item_List = (Item *)calloc(5, sizeof(Item));

    if( argc == 2){
        printf("two args detected \n");
        find_item_by_sku(item_List, 5, argv[1]);
    }
    printf("making list... \n ");
    add_item(item_List, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_List, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_List, 10.00, "33222", "frozen", "frozen pizza", 2);
    add_item(item_List, 7.45, "14512", "candy", "chocolate bar", 3);
    add_item(item_List, 4.90, "88888", "beverage", "orange juice", 4);
    printf("printing... \n");
    print_items(item_List, 5);
    printf("the average price is: %f \n",average_price(item_List, 5));


    return 0;
}
