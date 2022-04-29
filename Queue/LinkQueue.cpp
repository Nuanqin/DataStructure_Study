/*
* 链式存储实现队列
* status: Archived
*/


typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;								//依旧有带头或不带头区分

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


/*
* 初始化
*/
bool InitLinkQueue(LinkQueue &Q) {

}