#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct _bTreeNode
{
	Data data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
Data GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, Data data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void VisitFuncPtr(Data data);

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action, int withP);
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

#endif
