# LinkListC

- 这是一个可以储存任何类型的链表，使用c语言实现。

##### 功能列表：

- 创建1个链表

`LinkList* createList();`

- 判断是否为空

`int emptyList(LinkList* list);`

- 删除指定位置的1个元素

`DATA_TYPE removeList(LinkList* list, int index);`

- 删除指定条件的元素

`DATA_TYPE removeListIf(LinkList* list, int(*condition)(int, DATA_TYPE));`

- 在指定位置插入1个元素

`void insertList(LinkList* list, int index, DATA_TYPE value);`

- 清空链表所有元素

`void clearList(LinkList* list);`

- 在前面插入1个元素

`void pushFront(LinkList* list, DATA_TYPE value);`

- 在后面插入1个元素

`void pushBack(LinkList* list, DATA_TYPE value);`

- 在前面弹出1个元素

`DATA_TYPE popFront(LinkList* list);`

- 在后面弹出1个元素

`DATA_TYPE popBack(LinkList* list);`

- 链表按照指定规则排序（冒泡排序）

`void sortList(LinkList* list, int(*comparetor)(DATA_TYPE, DATA_TYPE));`

- 获取指定位置的1个元素

`DATA_TYPE getItem(LinkList* list, int pos);`

- 遍历链表的所有元素，相当于forEach

`void seekList(LinkList* list, int(*action)(int, DATA_TYPE));`

- 用指定删除器清除元素。比如释放内存free。

`void destroyList(LinkList* list, void(*onItemDelete)(int, DATA_TYPE));`

- 合并链表

`LinkList* appendList(LinkList* list, LinkList* other);`

- 找出最大的元素

`DATA_TYPE findMaxInList(LinkList* list, int(*comparetor)(DATA_TYPE, DATA_TYPE));`

- 获取链表长度

`int lengthOfList(LinkList* list);`
