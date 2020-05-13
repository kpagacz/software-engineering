#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct ItineraryItem {
    char weekday[10], time_start[7], time_end[7], subject[20], lecturer[50];
    int room_no; 
};

struct ItineraryItem createItem(void) {
    printf("Input weekday, time start and end (HH:MM), subject, lecturer and room number:\n");
    struct ItineraryItem new_item;
    scanf("%s %s %s %s %s %i", &new_item.weekday, &new_item.time_start, &new_item.time_end,
            &new_item.subject, &new_item.lecturer, &new_item.room_no);

    return new_item;
}

void printItem(struct ItineraryItem item) {
    printf("Day: %s  Start time: %s  End time: %s  Subject: %s  Lecturer: %s  Room number: %i\n",
            item.weekday, item.time_start, item.time_end, item.subject, item.lecturer, item.room_no);
}

void printDay(char day[10], struct ItineraryItem* itinerary, int itinerary_length) {
    for(int i = 0; i < itinerary_length; i++) {
        if(strcmp(day, itinerary[i].weekday) == 0) {
            printItem(itinerary[i]);
        }
    }
}

void printSubject(char subject[20], struct ItineraryItem* itinerary, int itinerary_length) {
    for(int i = 0; i < itinerary_length; i++) {
        if(strcmp(subject, itinerary[i].subject) == 0) {
            printItem(itinerary[i]);
        }
    }
}

void printStartingAt8(struct ItineraryItem* itinerary, int itinerary_length) {
    for(int i = 0; i < itinerary_length; i++) {
        int hours, minutes;
        sscanf(itinerary[i].time_start, "%2d:%2d", &hours, &minutes);
        if(hours == 8) {
            printItem(itinerary[i]);
        }
    }
}

int main() {
    int items_no;
    printf("Input number of items on itinerary: ");
    scanf("%i", &items_no);

    struct ItineraryItem* itinerary = malloc(items_no * sizeof(struct ItineraryItem));
    for(int i = 0; i < items_no; i++) {
        itinerary[i] = createItem();
    }

    printf("Input day to show (monday, tuesday, wednesday, thursday, friday, saturday, sunday): ");
    char day[10];
    scanf("%s", &day);
    printDay(day, itinerary, items_no);

    printf("Input subject to show: ");
    char subject[20];
    scanf("%s", &subject);
    printSubject(subject, itinerary, items_no);

    printf("Starting from 8 to 9 AM:\n");
    printStartingAt8(itinerary, items_no);

    return 0;
}