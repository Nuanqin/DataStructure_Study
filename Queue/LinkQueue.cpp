/*
* ��ʽ�洢ʵ�ֶ���
* status: Archived
*/


typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;								//�����д�ͷ�򲻴�ͷ����

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;


/*
* ��ʼ��
*/
bool InitLinkQueue(LinkQueue &Q) {

}