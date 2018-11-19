


#include <stdlib.h>


#define New( TYPE ) ((TYPE*)malloc(sizeof(TYPE)))

//分配内存
#define Delete( VAR ) free(VAR)
//释放内存

typedef void* DATA_TYPE;

//默认内存释放器
void defaultDeleter(int p, DATA_TYPE value) {
	if (value) {
		Delete(value);
	}
}

struct Node {
	DATA_TYPE data;
	struct Node* next;
};

typedef struct Node Node;

Node* newNode(DATA_TYPE data) {
	Node* node = New(Node);
	node->next = NULL;
	node->data = data;
	return node;
}

struct LinkList {
	Node* head;
	int size; //链表的长度
};

typedef struct LinkList LinkList;


LinkList* createList();

int emptyList(LinkList* list);

DATA_TYPE removeList(LinkList* list, int index);

DATA_TYPE removeListIf(LinkList* list, int(*condition)(int, DATA_TYPE));

void insertList(LinkList* list, int index, DATA_TYPE value);

void clearList(LinkList* list);

void pushFront(LinkList* list, DATA_TYPE value);
void pushBack(LinkList* list, DATA_TYPE value);
DATA_TYPE popFront(LinkList* list);
DATA_TYPE popBack(LinkList* list);
void sortList(LinkList* list, int(*comparetor)(DATA_TYPE, DATA_TYPE));
DATA_TYPE getItem(LinkList* list, int pos);
void seekList(LinkList* list, int(*action)(int, DATA_TYPE));
void destroyList(LinkList* list, void(*onItemDelete)(int, DATA_TYPE));
LinkList* appendList(LinkList* list, LinkList* other);
DATA_TYPE findMaxInList(LinkList* list, int(*comparetor)(DATA_TYPE, DATA_TYPE));
int lengthOfList(LinkList* list);


LinkList* createList() {
	//创建空链表
	LinkList* linkList = New(LinkList);
	linkList->head = NULL;
	linkList->size = 0;
	return linkList;
}

int emptyList(LinkList* list) {
	return list == NULL || list->head == NULL;
}

DATA_TYPE removeList(LinkList* list, int index) {
	if (index >= list->size) {
		return NULL;
	}
	if (index == 0) {
		return popFront(list);
	}
	Node *position = list->head, *last = position;
	while (position && index--) {
		last = position;
		position = position->next;

	}
	last->next = position->next;
	DATA_TYPE value = position->data;
	Delete(position);
	list->size--;
	return value;
}


DATA_TYPE removeListIf(LinkList* list, int(*condition)(int, DATA_TYPE)) {
	Node *position = list->head, *last = position;
	int index = 0;
	if (condition(index, position->data)) {
		return popFront(list);
	}

	while (position) {
		last = position;
		position = position->next;
		index++;
		if (condition(index, position->data)) {
			break;
		}

	}
	last->next = position->next;
	DATA_TYPE value = position->data;
	Delete(position);
	list->size--;
	return value;

}

void insertList(LinkList* list, int index, DATA_TYPE value) {
	if (index > list->size || value == NULL) {
		return;
	}

	Node* node = newNode(value);
	if (index == 0) {
		pushFront(list, value);
	}
	Node *position = list->head, *last = position;
	while (position && index--) {
		last = position;
		position = position->next;
	}
	last->next = node;
	node->next = position;
	list->size++;

}

void clearList(LinkList* list) {
	if (list->head) {
		destroyList(list, defaultDeleter);
	}
}

void pushFront(LinkList* list, DATA_TYPE value) {
	if (value == NULL) {
		return;
	}
	Node* node = newNode(value);
	node->next = list->head;
	list->head = node;
	list->size++;
}

DATA_TYPE popFront(LinkList* list) {
	Node* node = list->head;
	if (list->head) {
		list->head = node->next;
		node->next = NULL;
		list->size--;
	}
	return node->data;
}

DATA_TYPE popBack(LinkList* list) {
	DATA_TYPE value = NULL;
	Node *position = list->head, *last = NULL;
	if (list->head == NULL) {
		return NULL;
	}
	if (list->head->next == NULL) {
		value = position->data;
		Delete(list->head);
		list->head = NULL;
		return value;
	}

	while (position->next) {
		last = position;
		position = position->next;
	}
	value = position->data;
	Delete(position);
	last->next = NULL;
	return value;
}

void sortList(LinkList* list, int(*comparetor)(DATA_TYPE, DATA_TYPE)) {
	if (list->head == NULL) {
		return;
	}
	DATA_TYPE temp;
	for (Node* i = list->head; i != NULL; i = i->next) {
		for (Node* j = i->next; j != NULL; j = j->next) {
			if (comparetor(i->data, j->data) >= 0) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;

			}

		}

	}

}

void pushBack(LinkList* list, DATA_TYPE value) {
	if (value == NULL) {
		return;
	}
	Node* node = newNode(value);
	if (node) {
		node->next = NULL;
	} else {
		return;
	}
	if (list->head) {
		Node* position = list->head;
		while (position->next) {
			position = position->next;
		}
		position->next = node;
	} else {
		list->head = node;

	}

	list->size++;
}

DATA_TYPE getItem(LinkList* list, int pos) {

	if (pos > list->size) {
		return NULL;
	}
	Node* position = list->head;
	int index = 0;
	while (position) {
		if (index == pos) {
			return position->data;
		}
		position = position->next;
		index++;
	}
	return NULL;
}

void seekList(LinkList* list, int(*action)(int, DATA_TYPE)) {
	Node* position = list->head;
	int index = 0;
	while (position) {
		if (action(index, position->data)) {
			break;
		}
		position = position->next;
		index++;
	}
}

void destroyList(LinkList* list, void(*onItemDelete)(int, DATA_TYPE)) {
	Node *position = list->head, *freeNode = NULL;
	int index = 0;
	while (position) {
		freeNode = position;
		position = position->next;
		onItemDelete(index, freeNode->data);

		Delete(freeNode);
		index++;
	}
	list->head = NULL;

	Delete(list);
}

LinkList* appendList(LinkList* list, LinkList* other) {
	pushBack(list, other->head->data);
	list->size += (other->size - 1);
	other->head = NULL;
	other->size = 0;
	return list;
}

DATA_TYPE findMaxInList(LinkList* list, int(*comparetor)(DATA_TYPE, DATA_TYPE)) {
	Node* position = list->head;
	DATA_TYPE max = position ? position->data : NULL;

	while (position) {
		if (comparetor(max, position->data) < 0) {
			max = position->data;
		}
		position = position->next;
	}

	return max;
}

int lengthOfList(LinkList* list) {
	return list->size;
}




