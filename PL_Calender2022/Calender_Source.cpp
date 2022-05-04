#include <stdio.h>
#include <stdlib.h>	//malloc, free �Լ��� ����� ��� ����

//���Ḯ��Ʈ�� ��� ����ü
struct list {
	int year;
	int month;
	int day;
	struct list* next;
};

//���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
void add_list(struct list *target, int year, int month, int day)
{
	struct list *newNode = (struct list*)malloc(sizeof(struct list));	//�� ��带 ����
	newNode->next = target->next;	//�� ����� ���� ��忡 ���� ����� ���� ��带 ����
	newNode->year = year;			//������ ����
	newNode->month = month;			//������ ����
	newNode->day = day;			//������ ����

	target->next = newNode;	//���� ����� ���� ��忡 �� ��带 ����
}

//Ư�� ��� ��� �˻� �Լ� (ù ��° ������ ������ ������� ���ʷ� �˻�
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
		printf("\n----------- %d �� -----------\n", found->month);
		printf("\n|  ��  ��  ȭ  ��  ��  ��  ��  |\n\n");
		int wday = weekDay(found, j, 1);
		printf("\n��������? %d \n", wday);
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
	//�Ӹ� ��� ����
	struct list *head = (struct list*)malloc(sizeof(struct list));
	head->next = NULL;

	//�Ӹ� ��� �ڿ� �� ��� �߰�
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

	//�޷� ��� �Լ�
	show_calender(head);
	
	//��¥ �˻� �Լ�
	struct list *found = findNode(head, 2);
	printf("\n%d %d %d\n", found->year, found->month, found->day);

	//���Ḯ��Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
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