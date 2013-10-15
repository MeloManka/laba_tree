#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

using namespace std;

class MainTree
{
    struct Tree
    {
        Tree *left;
        Tree *right;
        int data;
        int number;

        Tree(const int dt)
        {
            number = 1;
            data = dt;
            left = 0;
            right = 0;
        }
        int getData()const;
    } *root;

    public:
        MainTree();  //�����������
        MainTree (const MainTree &original);  //����������� �����������

        void insert(int);  //������� ��������
        void out(int); //����� �� ����� ������
        void unite(MainTree,MainTree); //�����������

        void copyTree(Tree *&newTree, Tree *original);
        void deleteTree(Tree *&element);
        MainTree &operator=(const MainTree &original);

    private:
        void insertTree(Tree *&,int); //�������������� ������� ������� ��������
        void outTree(Tree *&, int);  //�������������� ������� ������ �� �����
        void uniteTrees(Tree *&,Tree *&);  //�������������� ������� �����������
        //void insertTree(TREE *element,int value);
};

#endif // TREE_H_INCLUDED
