#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

struct Candy {
    char name[50], company[50], production_date[11], expiry_date[11];
    float price_per_kilo, quantity;
};

struct Candy createCandy(void) {
    struct Candy new_candy;
    printf("Input Candy information: name, company, production date (DD/MM/YYYY), expiry date (DD/MM/YYYY), price per kilogram and quantity (in kg)\n");
    scanf("%s %s %s %s %f %f", &new_candy.name, &new_candy.company,
            &new_candy.production_date, &new_candy.expiry_date, &new_candy.price_per_kilo, &new_candy.quantity);

    return new_candy;
};

void printCandy(struct Candy candy) {
    printf("%s  %s  %s  %s  Price per kilo:%f  Kilograms:%f\n", candy.name, candy.company,
            candy.production_date, candy.expiry_date, candy.price_per_kilo, candy.quantity);
}

void outputInPriceRange(float lower_bound, float upper_bound, char producent[], struct Candy candies[], int no) {
    printf("Candies of producent %s with cost in <%.2f %.2f> range:\n", producent, lower_bound, upper_bound);
    for(int i = 0; i < no; i++) {
        if(strcmp(candies[i].company, producent) == 0 && candies[i].price_per_kilo >= lower_bound && 
                candies[i].price_per_kilo <= upper_bound) {
            printCandy(candies[i]);
        }
    }
}

void outputExpired(struct Candy* candies, int no) {
    time_t now = time(NULL);
    char date[11];
    struct tm expiry = {0};
    for(int i = 0; i < no; i++) {
        sscanf(candies[i].expiry_date, "%2d/%2d/%4d", &expiry.tm_mday, &expiry.tm_mon, &expiry.tm_year);
        expiry.tm_mon--;
        expiry.tm_year -= 1900;
        if(difftime(now, mktime(&expiry)) > 0) {
            printf("Name:%s  Kilograms:%.2f\n", candies[i].name, candies[i].quantity);
        }
    }
}


int main() {
    printf("Input Number of candies: ");
    int no;
    scanf("%i", &no);

    struct Candy* candies = malloc(no * sizeof(struct Candy));
    for(int i = 0; i < no; i++) {
        candies[i] = createCandy();
    }

    printf("Input producent name, lower and upper bound of price per kilo: ");
    char producent[50];
    float lower_bound, upper_bound;
    scanf("%s %f %f", &producent, &lower_bound, &upper_bound);

    outputInPriceRange(lower_bound, upper_bound, producent, candies, no);

    printf("Expired candies:\n");
    outputExpired(candies, no);


    return 0;
}