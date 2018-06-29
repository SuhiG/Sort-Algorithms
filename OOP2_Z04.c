#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define swap(type, x, y) do { type t = x; x = y; y = t; }while(0)
#define THRESHOLD 20

int *init1(int n);
int *init2(int n);
int *init3(int n);
void print(int *a, int n);
void bubble(int *a, int n);
void bubble_t(int *a, int n);
void bubble_c(int *a, int n);
void bubble_u(int *a, int n);
void selection(int *a, int n);
void selection_c(int *a, int n);
void selection_t(int *a, int n);
void insertion_c(int *a, int n);
void insertion(int *a, int n);
void insertion_t(int *a, int n);
void shell(int *a, int n);
void shell_c(int *a, int n);
void shell_t(int *a, int n);
void quick(int *a, int left, int right);
void quick_c(int *a, int left, int right);
void quick_t(int *a, int left, int right,int n);
void check(int *a, int n);
int int_cmp(const int *a, const int *b);

typedef unsigned long long ULL;
ULL ncomp = 0, nswap = 0, nasgn = 0;

int main(int argc, char *argv[]){
    int na;
    int *a;
    clock_t t1, t2;
    if(argc <= 2){
        printf("function is incomplete：%s <Algorithm> <Source number>\n", argv[0]);
        exit(1);
    }
    na = atoi(argv[2]);
    if(argc > 3){
        if(strcmp(argv[3], "init1") == 0) a = init1(na);
        else if(strcmp(argv[3], "init2") == 0) a = init2(na);
        else if(strcmp(argv[3], "init3") == 0) a = init3(na);
    } else {
        a = init1(na);
}
t1 = clock();
    if(strcmp(argv[1], "bubble") == 0) bubble(a, na);
    else if(strcmp(argv[1], "bubble_t") == 0) bubble_t(a, na);
    else if(strcmp(argv[1], "bubble_c") == 0) bubble_c(a, na);
    else if(strcmp(argv[1], "bubble_u") == 0) bubble_u(a, na);        
    else if(strcmp(argv[1], "selection") == 0) selection(a, na);   
    else if(strcmp(argv[1], "selection_c") == 0) selection_c(a, na);    
    else if(strcmp(argv[1], "selection_t") == 0) selection_t(a, na);
    else if(strcmp(argv[1], "insertion") == 0) insertion(a, na);
    else if(strcmp(argv[1], "insertion_c") == 0) insertion_c(a, na);
    else if(strcmp(argv[1], "insertion_t") == 0) insertion_t(a, na);
    else if(strcmp(argv[1], "shell") == 0) shell(a, na);
    else if(strcmp(argv[1], "shell_c") == 0) shell_c(a, na);
    else if(strcmp(argv[1], "shell_t") == 0) shell_t(a, na);
    else if(strcmp(argv[1], "quick") == 0) quick(a, 0, na - 1);
    else if(strcmp(argv[1], "quick_c") == 0) quick_c(a, 0, na - 1);
    else if(strcmp(argv[1], "quick_t") == 0) quick_t(a, 0, na - 1,na);
    else if(strcmp(argv[1], "qsort") == 0) qsort(a,na,sizeof(int),int_cmp);
    
    else{
        printf("algorithm %s is not supporting\n",
            argv[1]);
    }

t2 = clock();
check(a, na);
    printf("%ditems Algorithm:%s %.3fseconds\n",
    na, argv[1],(t2 - t1)/1000.0);
    if(ncomp != 0){
        printf("比較回数：%llu回 ", ncomp);
    }
    if(nswap != 0){
        printf("交換回数：%llu回 ", nswap);
    }
    if(nasgn != 0){
    printf("代入回数：%llu回 ", nasgn);
    }
// check(a, na);
//     printf("%ditems Algorithm:%s %.3fseconds\n",
//     na, argv[1], (t2 - t1)/1000.0);
}
int int_cmp(const void *a, const void *b){
	int aa = *(int *)a;
	int bb = *(int *)b;
	if (aa < bb)
		return -1;
	else if (aa > bb)
		return 1;
	else
		return 0;
}

int *init1(int n){
    int *a;
    int i;
    a = (int *)calloc(n, sizeof(int));
    if(n < THRESHOLD){
        srand((unsigned)time(NULL));
        for(i = 0; i < n; i++){
            a[i] = rand() % 100;
        }
        printf("%*s", 16, ""); print(a, n);
    } else {
        for(i = 0; i < n; i++){
            a[i] = rand()*32768 + rand();
        }
    }
return a;
}

int *init2(int n){
    int *a;
    int i;
    a = (int *)calloc(n, sizeof(int));
    for(i = 0; i < n; i++){
        a[i] = i;
    }
return a;
}

int *init3(int n){
    int *a;
    int i;
    a = (int *)calloc(n, sizeof(int));
    for(i = 0; i < n; i++){
        a[i] = n - i;
    }
return a;
}


void print(int *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf(" %2d", a[i]);
        }
    printf("\n");
    }

void bubble(int *a, int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = n-1; j > i; j--){
            if(a[j-1] > a[j]){
                swap(int, a[j-1], a[j]);
                }
            }
        }
    }

void bubble_t(int *a, int n)
{
    int i, j;
    if(n >= THRESHOLD){
    printf("件数が多すぎるので（%d件）、処理を中止します\n", n);
    exit(3);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--){
            if (a[j - 1] > a[j]){
                swap(int, a[j - 1], a[j]);
        }
        printf("i = %2d, j = %2d: ", i, j);
    print(a, n);
        }
    }
}

void bubble_c(int *a, int n){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = n-1; j > i; j--){
            ncomp++;
            if(a[j-1] > a[j]){
                nswap++;
                swap(int, a[j-1], a[j]);
            }
        }
    }
}

void bubble_u(int a[], int n){
    int i, j, m;
    for (i = 0; i < n - 1; i++) {
        printf("パス%d：\n", i + 1);
        for (j = n - 1; j > i; j--) {
            for (m = 0; m < n - 1; m++)
                printf("%3d %c" , a[m], (m != j-1) ? ' ' :
                    (a[j - 1] > a[j]) ? '+' : '-');
                printf("%3d\n", a[n - 1]);
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
            }
        }
        for (m = 0; m < n; m++)
            printf("%3d " , a[m]);
        putchar('\n');
    }
}
void selection(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
            }
        swap(int, a[i], a[min]);
    }
}

void selection_c(int a[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++) {
            ncomp++;
            if (a[j] < a[min])
                min = j;
            }
        nswap++;
        swap(int, a[i], a[min]);
    }
}

void selection_t(int a[], int n){
    int i, j, m;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        for (m = 0; m < n; m++)
            printf((m == i) ? " * " : (m == min) ? " + " : " ");
        putchar("\n");
        for (m = 0; m < n; m++)
            printf("%3d ", a[m]);
        putchar("\n");
        swap(int, a[i], a[min]);
    }
    putchar("\n");
    for (m = 0; m < n; m++)
        printf("%3d ", a[m]);
    putchar("\n");
}
void insertion(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        int tmp = a[i];
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
            a[j] = tmp;
        }
}

void insertion_c(int a[], int n){
    int i, j;
    for (i = 1; i < n; i++) {
        int tmp = (nasgn++, a[i]);
        for (j = i; j > 0 && (ncomp++, a[j - 1] > tmp); j--){
            nasgn++, a[j] = a[j - 1];
        }
        nasgn++, a[j] = tmp;
    }
}


void insertion_t(int a[], int n){
    int i, j, m;
    for (i = 1; i < n; i++) {
        int tmp = a[i];
        for (m = 0; m < n; m++)
            printf("%3d ", a[m]);
            putchar("\n");
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
            a[j] = tmp;
            printf("%*s%s", 4 * j , "", (i != j) ? "^-" : " ");
                for (m = 0; m < 4*(i-j); m++)
                    putchar("-");
            printf("+\n\n");
            }
        for (m = 0; m < n; m++)
            printf("%3d ", a[m]);
            putchar('\n');
} 

void shell(int a[], int n){
    int i, j, h;
    for (h = 1; h < n / 3; h = h * 3 + 1);
        for (; h > 0; h /= 3) {
            for (i = h; i < n; i++) {
                int tmp = a[i];
                for (j = i - h; j >= 0 && a[j] > tmp; j -= h){
                    a[j + h] = a[j];
                }
            a[j + h] = tmp;
        }
    }
}

void shell_c(int a[], int n){
    int i, j, h;
    for (h = 1; h < n / 7; h = h * 7 + 1);
        for (; h > 0; h /= 7){
            for (i = h; i < n; i++) {
                int tmp = a[i];
                nasgn++;
            for (j = i - h; ncomp++, j >= 0 && a[j] > tmp; j -= h){
                nasgn++, a[j + h] = a[j];
                }
            nasgn++, a[j + h] = tmp;
        }
    }
}

void shell_t(int a[], int n){
	int i, j, k, h;
	for (h = 1; h < n / 9; h = h * 3 + 1);
		for (; h > 0; h /= 3){
			printf("h = %2d ", h);
			for (k = 0; k < n; k++) {
				printf(" %2d", a[k]);
		}
		putchar('\n');
	for (i = h; i < n; i++) {
		int tmp = a[i];
		for (j = i - h; j >= 0 && a[j] > tmp; j -= h){a[j + h] = a[j];
			}
			a[j + h] = tmp;
			printf("h = %2d, i = %2d :", h, i);
		for (k = 0; k <= i; k++) {
			if((k - i) % h == 0 && k > j){
				printf(" %2d", a[k]);}
			else {
				printf(" ");
			}
		}
		putchar("\n");
		}
	}
}  

void qsort(const void *base,size_t nmemb,size_t size,int (*compar)(const void *, const void *));

void quick(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
		pl++;
		pr--;
		}
	} while (pl <= pr);
	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

void quick_c(int a[], int left, int right){
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];
	do {
		while (ncomp++, a[pl] < x) pl++;
		while (ncomp++, a[pr] > x) pr--;
		if (pl <= pr) {
			nswap++;
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
			}
		} while (pl <= pr);
	if (left < pr) quick_c(a, left, pr);
	if (pl < right) quick_c(a, pl, right);

}

void quick_t(int a[], int left, int right, int n){
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];
	int i;
	printf(" a[%2d]-a[%2d] : %*s", left, right, left*3, "");
	for (i = left; i < right; i++)
		printf("%2d ", a[i]);
		printf("%2d%*s x=%2d\n", a[right], (n - i) * 3, "", x);

		do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
			}
			printf(" a[%2d]-a[%2d] : %*s", left, right, left*3, "");
		for (i = left; i < right; i++)
			printf("%2d ", a[i]);
			printf("%2d%*s pl=%2d pr=%2d \n", a[right], (n - i) * 3, "", pl, pr);
			} while (pl <= pr);
		if (left < pr) quick_t(a, left, pr, n);
		if (pl < right) quick_t(a, pl, right, n);
}

void check(int *a, int n){
    int i;
    if(n < THRESHOLD){
        printf("%*s", 16, ""); print(a, n);
    } else {
        int nerror = 0;
        for(i = 0; i < n-1; i++){
            if(a[i] > a[i+1]){
                printf("a[%d]=%d > a[%d]=%d\n",
    i, a[i], i+1, a[i+1]);
            nerror++;
        }
    }
        if(nerror == 0){
            printf("sort is complete\n");
        }
    }
}