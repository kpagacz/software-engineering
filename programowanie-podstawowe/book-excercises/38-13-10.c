#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct Book {
    char title[100], year[5], author[50];
    int pages;
};

struct Newspaper {
    char title[100], date[12], head[30];
    int pages;
};

struct Magazine {
    char title[100], date[12];
    int council_members_no;
    char council[50][100];
    int pages;
};

struct Book createBook(void) {
    struct Book new_book;
    printf("Input title, year (YYYY), author(no spaces), pages:\n");
    scanf("%s %s %s %i", &new_book.title, &new_book.year, &new_book.author, &new_book.pages);
    return new_book;
};

struct Newspaper createNewspaper(void) {
    struct Newspaper new;
    printf("Input title, date (YYYY/MM/DD), head redactor(no spaces), pages:\n");
    scanf("%s %s %s %i", &new.title, &new.date, &new.head, &new.pages);
    return new;
};

struct Magazine createMagazine(void) {
    struct Magazine new;
    printf("Input title, date(YYYY/MM/DD), number of council member, council members (no spaces in names), pages:\n");
    scanf("%s %s %i ", &new.title, &new.date, &new.council_members_no);
    for(int i = 0; i < new.council_members_no; i++ ){
        scanf("%s", &new.council[i]);
    }
    scanf("%i", &new.pages);
    return new;
};

union Position {
    struct Magazine magazine;
    struct Newspaper newspaper;
    struct Book book;
};

struct Item {
    int item_type;
    union Position item;
};

void printBook(struct Book book) {
    printf("Title: %s  Year: %s  Author: %s  Pages: %i\n", book.title, book.year, book.author, book.pages);
};

void printNewspaper(struct Newspaper news) {
    printf("Title: %s  Date: %s  Head: %s  Pages: %i\n", news.title, news.date, news.head, news.pages);
};

void printMagazine(struct Magazine magazine) {
    printf("Title: %s  Date: %s  ", magazine.title, magazine.date);
    for(int i = 0; i < magazine.council_members_no; i++ ){
        printf("%s ", magazine.council[i]);
    }
    printf(" Pages: %i\n", magazine.pages);
};

void printItem(struct Item item) {
    switch(item.item_type) {
        case 0:
            printBook(item.item.book);
            break;
        case 1:
            printNewspaper(item.item.newspaper);
            break;
        case 2:
            printMagazine(item.item.magazine);
            break;
        default:
            break;
    }
}

struct Item createItem(void) {
    printf("Input type of the item (0-book, 1-newspaper, 2-magazine: ");
    struct Item new_item;
    scanf("%i", &new_item.item_type);

    union Position new_position;
    switch(new_item.item_type) {
        case 0:
            new_position.book = createBook();
            break;
        case 1:
            new_position.newspaper = createNewspaper();
            break;
        case 2:
            new_position.magazine = createMagazine();
            break;
        default:
            break;
    }

    new_item.item = new_position;
    return new_item;
};


void printItemsFromYear(char year[5], struct Item* library, int library_length) {
    char item_year[5];
    for(int i = 0; i < library_length; i++) {
        switch(library[i].item_type) {
            case 0:
                sscanf(library[i].item.book.year, "%s", &item_year);
                break;
            case 1:
                sscanf(library[i].item.newspaper.date, "%4s/%*2s/%*2s", &item_year);
                break;
            case 2:
                sscanf(library[i].item.magazine.date, "%4s/%*2s/%*2s", &item_year);
                break;
            default:
                break;
        }

        if(strcmp(item_year, year) == 0) {
            printItem(library[i]);
        }
    }
}
int main(void) {
    int items_no;
    printf("Input number of items in the library: ");
    scanf("%i", &items_no);

    struct Item* library = malloc(items_no * sizeof(struct Item));
    for(int i = 0; i < items_no; i++) {
        library[i] = createItem();
    }

    printf("Input year of items to output: ");
    char year[5];
    scanf("%s", &year);
    printf("Positions from the year %s:\n", year);
    printItemsFromYear(year, library, items_no);

    return 0;
}