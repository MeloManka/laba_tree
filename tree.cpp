#include <iostream>
#include <fstream>
#include <stdlib.h>

#include "tree.h"


MainTree::MainTree (const MainTree &original)
{
    if (original.root)
    {
        root=new Tree(original.root->data);
        copyTree(root, original.root);
    }
    else root=0;
}

void MainTree::copyTree(Tree *&newTree, Tree *original)
{
    if(original==0)
        newTree = 0;

    if (original)
    {
        newTree= new Tree(original->data);
        if(original->left)
            copyTree(newTree->left,original->left);
        else
            newTree->left =0;

        if(original->right)
            copyTree(newTree->right,original->right);
        else
            newTree->right =0;
    }
}

MainTree &MainTree::operator=(const MainTree &original)
{
    if(this==&original)
        return *this;
    deleteTree(root);
    copyTree(root,original.root);
    return *this;
}

void MainTree::deleteTree(Tree *&element)
{
    if(element)
    {
        deleteTree(element->left);
        deleteTree(element->right);
        delete element;
        element=0;
    }
}

int MainTree::Tree::getData()const
{
    return data;
}

MainTree::MainTree()
{
    root = 0;
}

void MainTree::insert(int value)
{
    insertTree(root,value);
}

void MainTree::out(int k)
{
    outTree(root,k);
}

void MainTree::unite(MainTree intTree1,MainTree intTree2)
{
    copyTree(root,intTree1.root);
    uniteTrees(root,intTree2.root);
}

void MainTree::insertTree(Tree *&element,int value)
{

    if(element == 0)
    {
        element = new Tree(value);
    }
    else
    {
        if(value < (element)->data)
        {
            if ((element)->left == 0)
            {
                (element)->left = new Tree(value);
            }
            else
            {
                insertTree((element)->left, value);
            }
        }
        else
        {
            if(value == element->data)
            {
                ++element->number;
            }
            else
            {
                if ((element)->right == 0)
                {
                    (element)->right = new Tree(value);
                }
                else
                {
                    insertTree((element)->right, value);
                }
            }
        }
    }
}

void MainTree::outTree(Tree *&root, int k)
{

    if (root != 0)
    {
        outTree(root->right, k + 3);
        for(int i = 0; i < k; i++)
        {
            cout<<" ";
        }

        cout<< root->data;
        cout<<"("<<root->number<<")"<<endl;
        outTree(root->left, k + 3);
    }
 }

void MainTree::uniteTrees(Tree *&root3,Tree *&root2)
{
    if(root2!=0)
    {
        insertTree(root3,root2->data);
        uniteTrees(root3,root2->left);
        uniteTrees(root3,root2->right);
    }
}


