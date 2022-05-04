#include <stdio.h>
#include <stdlib.h>	//malloc, free 함수가 선언된 헤더 파일

//연결리스트의 노드 구조체
struct list {
	int year;
	int month;
	int day;
	struct list* next;
};

//기준 노드 뒤에 노드를 추가하는 함수
void add_list(struct list *target, int year, int month, int day)
{
	struct list *newNode = (struct list*)malloc(sizeof(struct list));	//새 노드를 생성
	newNode->next = target->next;	//새 노드의 다음 노드에 기준 노드의 다음 노드를 지정
	newNode->year = year;			//데이터 저장
	newNode->month = month;			//데이터 저장
	newNode->day = day;			//데이터 저장

	target->next = newNode;	//기준 노드의 다음 노드에 새 노드를 지정
}

//특정 노드 노드 검색 함수 (첫 번째 노드부터 마지막 노느까지 차례로 검색
struct list *findNode(struct list *node, int data)
{
	if (node == NULL)
		return NULL;

	struct list *curr = node->next;
	while (curr != NULL)
	{
		if (curr->month == data)
			return curr;

		curr = curr->next;
	}

	return NULL;
}

int weekDay(struct list* week, int month, int day) {
	int total = (2022 - 1) * 365 + (2022) / 4 - (2022) / 100 + (2022) / 400;

	printf("\n%d\n", week->year);
	
	//printf("\n%d\n", total);
	for (int i = 0; i < month - 1; i++) {
		struct list* wfound = findNode(week, i+1);
		printf("\n%d\n", wfound->day);
		total += wfound->day;
	}
	total++;
	printf("\n total = % d \n", total);
	return (total % 7);
}

void show_calender(struct list* show) {
	int count = 0;
	int i, j, k;
	
	for (j = 1; j < 13; j++) {
		printf("\n");
		count = 0;
		struct list* found = findNode(show, j);
		printf("\n----------- %d 월 -----------\n", found->month);
		printf("\n|  일  월  화  수  목  금  토  |\n\n");
		int wday = weekDay(found, j, 1);
		printf("\n무슨요일? %d \n", wday);
		for (k = 0; k < wday; k++) {
			printf("   0");
			count++;
		}
		int fday = found->day;
		for (i = 0; i < fday; i++) {
			if (i < 9) {
				printf("   %d", i + 1);
			}
			else
				printf("  %d", i + 1);
			count++;
			if (count == 7) {
				printf("\n");
				count = 0;
			}
		}
	}
}

int main()
{
	//머리 노드 생성
	struct list *head = (struct list*)malloc(sizeof(struct list));
	head->next = NULL;

	//머리 노드 뒤에 새 노드 추가
	add_list(head, 2022, 1, 31);
	add_list(head, 2022, 2, 28);
	add_list(head, 2022, 3, 31);
	add_list(head, 2022, 4, 30);
	add_list(head, 2022, 5, 31);
	add_list(head, 2022, 6, 30);
	add_list(head, 2022, 7, 31);
	add_list(head, 2022, 8, 31);
	add_list(head, 2022, 9, 30);
	add_list(head, 2022, 10, 31);
	add_list(head, 2022, 11, 30);
	add_list(head, 2022, 12, 31);

	//달력 출력 함수
	show_calender(head);
	
	//날짜 검색 함수
	struct list *found = findNode(head, 2);
	printf("\n%d %d %d\n", found->year, found->month, found->day);

	//연결리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	struct list *curr = head->next;
	while (curr != NULL)
	{
		struct list *next = curr->next;
		free(curr);
		curr = next;
	}

	free(head);

	return 0;
}