#include <iostream>
#include<climits>

void merge_tables(int arr1[], int length1, int arr2[], int length2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < length1 && j < length2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        }
        else {
            merged[k++] = arr2[j++];
        }
    }

    // Remainder of the first array
    while (i < length1) {
        merged[k++] = arr1[i++];
    }

    // Remainder of the second array
    while (j < length2) {
        merged[k++] = arr2[j++];
    }
}

void Scal(int tab[], int s1, int s2, int s3, int pomoc[]) {
    for (int i = s1; i <= s3; i++) {
        pomoc[i] = tab[i];
    }

    int i = s1, j = s2, k = s1;
    while (i < s2 && j <= s3) {
        if (pomoc[i] <= pomoc[j]) {
            tab[k++] = pomoc[i++];
        }
        else {
            tab[k++] = pomoc[j++];
        }
    }

    // Remainder of the first array
    while (i < s2) {
        tab[k++] = pomoc[i++];
    }

    // Remainder of the second array
    while (j <= s3) {
        tab[k++] = pomoc[j++];
    }
}

void Scal2(int tab[], int s1, int s2, int s3, int pomoc[]) {
    for (int i = s1; i < s2; i++) {
        pomoc[i] = tab[i];
    }
    pomoc[s2] = INT_MAX;
    for (int i = s2 + 1; s2 < s3 + 2; i++) {
        pomoc[i] = tab[i];
    }
    pomoc[s3 + 2] = INT_MAX;

    int i = s1, j = s2 + 1, k = s1;
    while (k <= s3) {
        if (pomoc[i] <= pomoc[j]) {
            tab[k++] = pomoc[i++];
        }
        else {
            tab[k++] = pomoc[j++];
        }
    }
}

void MergeSortUtil(int tab[], int s1, int s3, int pomoc[]) {
    if (s1 == s3) {
        return;
    }

    int s2 = (s1 + s3 + 1) / 2;

    MergeSortUtil(tab, s1, s2 - 1, pomoc);
    MergeSortUtil(tab, s2, s3, pomoc);
    Scal(tab, s1, s2, s3, pomoc);
}

void MergeSort(int tab[], int length) {
    int* helper = new int[length + 2];
    MergeSortUtil(tab, 0, length - 1, helper);
}

void insertionSort2(int tab[], unsigned int size) {
    int temp;

    int min = 0;
    for (int i = 1; i < size; i++) {
        if (tab[i] < tab[min]) {
            min = i;
        }
    }
    std::swap(tab[0], tab[min]);

    for (int i = 0; i < size; i++) {
        temp = tab[i];
        int j = i - 1;
        while (temp < tab[j]) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = temp;
    }
}

auto ScalTablice = merge_tables;

int main()
{
    // ScalTablice
    //int t1[20], t2[20], t3[40];

    //t2[0] = t1[0] = 3;
    //for (int i = 1; i < 20; i++)
    //{
    //    t1[i] = t1[i - 1] + rand() % 7;
    //    t2[i] = t2[i - 1] + rand() % 5;
    //}

    //for (int i = 0; i < 40; i++) t3[i] = 0;



    //for (int i = 0; i < 20; i++)
    //{
    //    std::cout << t1[i] << "    " << t2[i] << std::endl;
    //}

    //for (int i = 0; i < 40; i++)
    //{
    //    std::cout << t3[i] << ", ";
    //}

    //ScalTablice(t1, 20, t2, 20, t3);

    //for (int i = 0; i < 40; i++)
    //{
    //    std::cout << t3[i] << ", ";
    //}

    // Scal
    //int t1[35], t3[35];
    //for (int i = 0; i < 35; i++) t1[i] = 0;

    //for (int i = 0; i < 35; i++) t3[i] = 9;


    //for (int i = 10; i < 18; i++) t1[i] = t1[i - 1] + rand() % 7;

    //for (int i = 19; i < 30; i++) t1[i] = t1[i - 1] + rand() % 4;

    //for (int i = 0; i < 35; i++) std::cout << t1[i] << ", ";

    //std::cout << std::endl << std::endl;

    //Scal(t1, 9, 18, 29, t3);

    //for (int i = 0; i < 35; i++) std::cout << t1[i] << ", ";

    // MergeSortUtil
    int size = 30;
    int* t1 = new int[size];
    for (int i = 0; i < size; i++) t1[i] = rand() % 1000;
    //for (int i = 0; i < 10000; i++) std::cout << t1[i] << " ";
    std::cout << "\n\n";
    MergeSort(t1, size);
    for (int i = 0; i < size; i++) std::cout << t1[i] << " ";


    return 0;
}


