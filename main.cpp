#include <stdio.h>
#include <stdlib.h> 

#define SIZE 10000

void test_main(void);

static int stack[10][SIZE];

static int sp[10];

static int queue[SIZE];

static int qs;

static int hold;

static long long SCORE = 0;

void my_push(int s)
{
    SCORE++;
    stack[s][sp[s]++] = hold;
}

int my_pop(int s)
{
    SCORE++;
    hold = stack[s][--sp[s]];
    stack[s][sp[s]] = -1;
    return hold;
}

void enqueue(void)
{
    queue[qs++] = hold;
    hold = -1;
}

static void build_data(void)
{
    for (int c = 0; c < SIZE; c++)
    {
        stack[0][c] = rand() % 1024;
    }
    sp[0] = SIZE;
    for (int c = 1; c < 10; c++) sp[c] = 0;
    qs = 0;
}

static void is_sorted(void)
{
    int min = 0;

    for (int i = 0; i < SIZE; i++) {
        if (min <= queue[i]) {
            min = queue[i];
        }
        else {
            printf("queue is not sorted!!\n");
            printf("index : %d\n", i);
            return;
        }
    }
    
    printf("queue is sorted.\n");
}

static void print_queue(void) {
    printf("index 0~19 : ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    printf("index 1738 ~ 1757 : ");
    for (int i = 1738; i < 1758; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    printf("index 4959 ~ 4978 : ");
    for (int i = 4959; i < 4979; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    printf("index 9980 ~ 9999 : ");
    for (int i = 9980; i < 9999; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n\n");
}

static void print_stack(int s, int idx_start, int idx_end) {
    printf("stack[%d] idx %d ~ %d : ", s, idx_start, idx_end);
    for (int i = idx_start; i < idx_end; i++) {
        printf("%d ", stack[s][i]);
    }
    printf("\n");
}

int main(void)
{
    SCORE = 0;
    for (int c = 0; c < 100; c++)
    {
    	printf("try : %d\n", c);
        build_data();
        test_main();
        
        //// see all stacks
        //for (int i = 0; i < 10; i++) {
        //    printf("stack %d : ", i);
        //    
        //    for (int j = 0; j < 10; j++) {
        //        printf("%d ", stack[i][j]);
        //    }
        //    printf("\n");
        //}
        //printf("\n");

        //print_queue();
        is_sorted();
    }
    printf("SCORE = %d\n", SCORE);
}

int stack2_list[10][9] = { // 두번째 분할에 사용
	{-1, -1, -1, -1, -1, -1, -1, -1, -1}, // by stack 0
	{ 0,  2,  3,  4,  5,  6,  7,  8,  9}, // by stack 1
	{ 0,  1,  3,  4,  5,  6,  7,  8,  9}, // by stack 2
	{ 0,  1,  2,  4,  5,  6,  7,  8,  9}, // by stack 3
	{ 0,  1,  2,  3,  5,  6,  7,  8,  9}, // by stack 4
	{ 0,  1,  2,  3,  4,  6,  7,  8,  9}, // by stack 5
	{ 0,  1,  2,  3,  4,  5,  7,  8,  9}, // by stack 6
	{ 0,  1,  2,  3,  4,  5,  6,  8,  9}, // by stack 7
	{ 0,  1,  2,  3,  4,  5,  6,  7,  9}, // by stack 8
	{ 0,  1,  2,  3,  4,  5,  6,  7,  8}  // by stack 9
};

int stack3_list[10][13] = { // 세번쨰 분할에 사용
	//배열에 숫자가 담긴 순서 : (hold - s) 의 결과. 해당 코드 참조
	//0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12
	{-1,  1,  2,  3,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 0
	{-1,  0,  2,  3,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 1
	{-1,  0,  1,  3,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 2
	{-1,  0,  1,  2,  4,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 3
	{-1,  0,  1,  2,  3,  5,  6,  7,  8,  9,  9,  9,  9}, // Select stack 4
	{-1,  0,  1,  2,  3,  4,  6,  7,  8,  9,  9,  9,  9}, // Select stack 5
	{-1,  0,  1,  2,  3,  4,  5,  7,  8,  9,  9,  9,  9}, // Select stack 6
	{-1,  0,  1,  2,  3,  4,  5,  6,  8,  9,  9,  9,  9}, // Select stack 7
	{-1,  0,  1,  2,  3,  4,  5,  6,  7,  9,  9,  9,  9}, // Select stack 8
	{-1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  8,  8,  8}  // Select stack 9
};

int stack4_list[4] = { -1, 0, 1, 2 }; // 네번째 분할에 사용

int s2_list[10] = { -1, 0, 114, 228, 342, 456, 570, 684, 798, 912 }; // 두번째 분할에 사용

typedef struct _range {
	int s1, d1;
	int s2, d2;
	int s3, d3;
	int s4, d4;
}range;

typedef struct _count {
	int stack1[10];
	int stack2[10];
	int stack3[10];
	int stack4[10];
	int queue;
}count;

void print_count(count, int);

void test_main() {
	int i, j;
	int temp;
	int hold;
	int s, d;
	int stack1, stack2, stack3, stack4;
	range r;
	count c;

	c = 
	{ {10000, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // stack1
	  {	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // stack2
	  {	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // stack3
	  {	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0 }; // stack4, queue

	// 첫번째 분할 : 하나의 스택에 114 종류의 숫자 포함 (마지막 스택은 114-2 = 112종)
	r.s1 = 0;
	r.d1 = 113;

	while (c.stack1[0] != 0) {
		hold = my_pop(0);
		c.stack1[0]--;

		for (stack1 = 1; stack1 <= 9; stack1++) {
			s = r.s1 + 114 * (stack1 - 1);
			d = r.d1 + 114 * (stack1 - 1);

			if (s <= hold && hold <= d) {
				my_push(stack1);
				c.stack1[stack1]++;
				break;
			}
		}
	}

	for (stack1 = 1; stack1 <= 9; stack1++) { // 첫번째 분할에서 나온 스택을 차례대로 선택
		r.s2 = s2_list[stack1];
		r.d2 = r.s2 + 12;

		while (c.stack1[stack1] != 0) { // 두번째 분할 : 하나의 스택에 13종류의 숫자 포함 (마지막은 13-3 = 10종류)
			hold = my_pop(stack1);
			c.stack1[stack1]--;
			
			for (i = 0; i < 9; i++) {
				s = r.s2 + (i * 13);
				d = r.d2 + (i * 13);

				if (s <= hold && hold <= d) {
					stack2 = stack2_list[stack1][i];

					my_push(stack2);
					c.stack2[stack2]++;
					break;
				}
			}
		}

		// 세번째 분할 : 두번째 분할을 꺼내서, 가장 작은 숫자부터 큐에 넣기
		for (i = 0; i < 9; i++) {
			stack2 = stack2_list[stack1][i];

			s = r.s2 + (i * 13);
			d = r.d2 + (i * 13);

			while (c.stack2[stack2] != 0) { // 두번째 분할에서 값을 꺼낸다.
				hold = my_pop(stack2);
				c.stack2[stack2]--;

				if (hold == s) {
					enqueue();
					c.queue++;
				}
				else {
					stack3 = stack3_list[stack2][hold - s];

					my_push(stack3);
					c.stack3[stack3]++;
				}
			}

			// 3번쨰 분할의 마지막 스택을 제외하고 숫자를 차례대로 큐에 넣는다.
			// 단, 2번쨰 분할의 마지막 스택을 작업하는 경우, 2번쨰 분할의 숫자의 종류는 10개나 8개이다. 따라서 바료 큐에 넣고 작업을 종료한다.
			if (i == 8) temp = 10;
			else temp = 9;
			for (j = 1; j < temp; j++) { 
				stack3 = stack3_list[stack2][j];

				while (c.stack3[stack3] != 0) {
					hold = my_pop(stack3);
					c.stack3[stack3]--;

					enqueue();
					c.queue++;
				}
			}
			if (temp == 10) continue;
			else {
				r.s4 = hold + 1;
			}

			// 2번쨰 분할의 숫자의 종류가 13종류인 경우, 3번째 분할의 마지막 스택에는 4종류의 숫자가 남아있다.
			// 이걸 꺼내서 4번쨰 분할로 만든다.
			stack3 = stack3_list[stack2][9];
			while (c.stack3[stack3] != 0) {
				hold = my_pop(stack3);
				c.stack3[stack3]--;

				if (hold == r.s4) {
					enqueue();
					c.queue++;
				}
				else {
					stack4 = stack4_list[hold - r.s4];

					my_push(stack4);
					c.stack4[stack4]++;
				}
			}

			// 4번째 분할에서 바로 큐에 값을 넣는다.
			for (j = 1; j <= 3; j++) {
				stack4 = stack4_list[j];

				while (c.stack4[stack4] != 0) {
					hold = my_pop(stack4);
					c.stack4[stack4]--;

					enqueue();
					c.queue++;
				}
			}
		}
	}
}

void print_count(count c, int phase) {
	int i;

	if (phase == 1) {
		for (i = 0; i < 10; i++) {
			printf("c.stack1[%d] = %d\n", i, c.stack1[i]);
		}
	}
	else if (phase == 2) {
		for (i = 0; i < 10; i++) {
			printf("c.stack2[%d] = %d\n", i, c.stack2[i]);
		}
	}
	else if (phase == 3) {
		for (i = 0; i < 10; i++) {
			printf("c.stack3[%d] = %d\n", i, c.stack3[i]);
		}
	}
	else if (phase == 4) {
		for (i = 0; i < 10; i++) {
			printf("c.stack4[%d] = %d\n", i, c.stack4[i]);
		}
	}
	printf("queue = %d\n", c.queue);
}
