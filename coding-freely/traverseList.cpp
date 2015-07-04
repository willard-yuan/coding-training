# include <iostream>

using namespace std;

class node{
public:
	int data;
	node *next;
	node(int x): data(x),next(NULL){} //���캯����ʼ����Ա�б� http://www.cnblogs.com/bluetzar/articles/1223169.html
};

//��ӡ����
void print(node *head){
	for(node *p = head; p != NULL; p = p->next)
		cout<<p->data<<" ";
	cout<<endl;
	cout<<endl;
}

//��ȡ������
int linkLength(node *head){
	int length = 0;
	while(head != NULL){
		head = head->next;
		length++;
	}
	return length;
}

//ɾ�������е�Ԫ��
node* removeElements(node *head, int val){
	//�������Ԫ��Ϊ�գ��򷵻�NULL
	if(head == NULL) return NULL;
	//���ɾ����Ԫ��Ϊ�����ͷ��ֵ
	if(NULL != head && head->data == val) //head != NULL��ʾ����
		head = head->next;
	node *p = head;
	while(p->next != NULL){
		if(p->next->data == val){
			p->next = p->next->next;
		}
		else{
			p = p->next;
		}
	}
	return head;
}

int main(){
	node *node1 = new node(1); 
	node *node2 = new node(2);
	node *node3 = new node(1);
	node *node4 = new node(4);
	node1->next = node2; //node1Ϊͷ���head
	node2->next = node3;
	node3->next = node4;

	cout<<"ԭ����:"<<endl;
	print(node1); //��ӡ����

	int linkLen = linkLength(node1); //��ȡ������

	node *node0 = removeElements(node1, 2);
	cout<<"ɾ��Ԫ�غ������:"<<" "<<linkLen<<endl;
	print(node0); //��ӡɾ��Ԫ�غ������

	cout<<"link length is:"<<" "<<linkLen<<endl;
	system("pause");
}
