/* for numbers run "./generic_merge_sort -n"for strings run "./generic_merge_sort".*/

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

int numcmp(char *s1, char *s2);

void mergeSort(void *ptr[], int left, int right, int (*comp)(void *, void *));

int main(int argc, char *argv[]){
    char *numArr[] = {"9","1","8","2","7","3","6","4","5"};
    char *strArr[] = {"Diego", "Alberto", "Juan", "David", "Mario", "Brian", "Pablo", "Rafael", "Santiago"};

    int elements = 9;

    if(argc > 1 && strcmp(argv[1], "-n") == 0){
        mergeSort(numArr, 0, elements-1, numcmp);

        for(int i = 0; i < elements; i++){
            printf("%s, ", numArr[i]);
        }
        printf("\n");


    } else {
        mergeSort(strArr, 0, elements-1, strcmp);
        for(int i = 0; i < elements; i++){
            printf("%s, ", strArr[i]);
        }
        printf("\n");
    }
    return 0;
}

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2){
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

void mergeSort(void *ptr[], int lft, int rigth, int (*comp)(void *, void *)) {
    
    int i, 
        j, 
        k; 
    
    if (lft < rigth) { 
        int mid = lft+(rigth-lft)/2; 
        mergeSort(ptr, lft, mid, comp); 
        mergeSort(ptr, mid+1, rigth, comp); 
        
        int one = mid - lft + 1; 
        int two = rigth - mid; 

        void *lftArr[one], *rigthArr[two]; 
        for (i = 0; i < one; i++) 
            lftArr[i] = ptr[lft + i]; 
        for (j = 0; j < two; j++) 
            rigthArr[j] = ptr[mid + 1+ j]; 
        i = 0;
        j = 0;
        k = lft;
        while (i < one && j < two) { 
            if(comp(lftArr[i],rigthArr[j]) < 1 || comp(lftArr[i], rigthArr[j]) == 0) { 
                ptr[k] = lftArr[i]; 
                i++; 
            } else { 
                ptr[k] = rigthArr[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i < one) { 
            ptr[k] = lftArr[i]; 
            i++; 
            k++; 
        } 
        while (j < two) { 
            ptr[k] = rigthArr[j]; 
            j++; 
            k++; 
        } 
    }
}


