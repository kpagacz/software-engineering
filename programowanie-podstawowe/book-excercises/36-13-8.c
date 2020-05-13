#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Address {
    char street[40];
    int building, appartment;
};

struct Answer {
    char name[20], surname[20];
    struct Address address;
    char sex;
    int age;
};

struct Answer createAnswer(void) {
    struct Answer new_answer;
    struct Address new_address;
    printf("Input name, surname, street, building number, appartment number, sex(M or F), age:\n");
    scanf("%s %s %s %i %i %c %i", &new_answer.name, &new_answer.surname, &new_address.street,
            &new_address.building, &new_address.appartment, &new_answer.sex, &new_answer.age);
    new_answer.address = new_address;
    return new_answer;
}

void printSexNumbers(char street[40], int building, struct Answer* quizz, int quizz_length) {
    int men = 0, women = 0;
    for(int i = 0; i < quizz_length; i++) {
        if(strcmp(quizz[i].address.street, street) == 0 && quizz[i].address.building == building) {
            quizz[i].sex == 'M' ? men++ : women++;
        }
    }

    printf("Living at %i %s:\nMen: %i  Women: %i\n", building, street, men, women);
};

void printAdultMenAtStreet(char street[40], struct Answer* quizz, int quizz_length) {
    int adult_men_count = 0;
    for(int i = 0; i < quizz_length; i++) {
        if(strcmp(quizz[i].address.street, street) == 0 && quizz[i].sex == 'M' && quizz[i].age <= 60 && quizz[i].age >= 18) {
            adult_men_count++;
        }
    }

    printf("Number of adult men living on %s street: %i\n", street, adult_men_count);
};

int main(void) {
    int answers_no;
    printf("Input number of answers to the questionnaire: ");
    scanf("%i", &answers_no);

    struct Answer* quizz = malloc(answers_no * sizeof(struct Answer));
    for(int i = 0; i < answers_no; i++) {
        quizz[i] = createAnswer(); 
    }

    printf("Input street and building number: ");
    char street[40];
    int no;
    scanf("%s %i", &street, &no);
    printSexNumbers(street, no, quizz, answers_no);

    printf("Input street name: ");
    scanf("%s", &street);
    printAdultMenAtStreet(street, quizz, answers_no);

    return 0;
}