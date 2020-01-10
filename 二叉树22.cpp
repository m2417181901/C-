#include<iostream>
using namespace std;

//����ڵ�
typedef struct node
{
    struct node *lchild;
    struct node *rchild;
    char data;
}BiTreeNode, *BiTree; ������ //*BiTree����˼�Ǹ� struct node*���˸���������BiTree����BiTreeΪָ��ڵ��ָ�롣


//����ǰ��˳����������
void createBiTree(BiTree &T) //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BiTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
{               ���������������� 
    char c;
    cin >> c;
    if('#' == c)             //������#ʱ�������ĸ��ڵ�ΪNULL���Ӷ������÷�֧�ĵݹ�
        T = NULL;
    else
    {
        T = new BiTreeNode;
        T->data=c;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
}

//ǰ���������������ӡ
void preTraverse(BiTree T)
{
    if(T)
    {
        cout<<T->data<<" ";
        preTraverse(T->lchild);
        preTraverse(T->rchild);
    }
}
//�����������������ӡ
void midTraverse(BiTree T)
{
    if(T)
    {
        midTraverse(T->lchild);
        cout<<T->data<<" ";
        midTraverse(T->rchild);
    }
}
//������������������ӡ
void postTraverse(BiTree T)
{
    if(T)
    {
        postTraverse(T->lchild);
        postTraverse(T->rchild);
        cout<<T->data<<" ";
    }
}
int main()
{
    BiTree T;               //����һ��ָ����������ڵ��ָ��               
    createBiTree(T);
    cout<<"������������ɣ�"<<endl;
    cout<<"ǰ�������������"<<endl;
    preTraverse(T);
    cout<<endl;
    cout<<"���������������"<<endl;
    midTraverse(T);
    cout<<endl;
    cout<<"���������������"<<endl;
    postTraverse(T);
    return 0;
}
