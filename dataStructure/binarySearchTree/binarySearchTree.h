#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

//이진탐색트리의 구현.

typedef int Data;

//중위 순회시 사용될 함수.
typedef void (*Func) (int);

//이진탐색트리.
typedef struct _tree {

	Data data;
	struct _tree * left;
	struct _tree * right;

} Tree;


//이진트리 함수.
//트리 노드 생성.
Tree * MakeTreeNode();
//노드의 데이터 설정.
void SetData(Tree * tree, Data data);
//노드의 데이터 얻기
Data GetData(Tree * tree);
//노드의 자식 노드 설정.
void SetLeftSub(Tree * pTree, Tree * cTree);
void SetRightSub(Tree * pTree, Tree * cTree);
//노드의 자식노드 주소값 리턴.
Tree * GetLeftSub(Tree * pTree);
Tree * GetRightSub(Tree * pTree);
//자식노드 변경
void ChangeLeftSub(Tree * pTree, Tree * cTree);
void ChangeRightSub(Tree * pTree, Tree * cTree);
//자식 노드 제거
Tree * RemoveLeftSub(Tree * pTree);
Tree * RemoveRightSub(Tree * pTree);
//중위순회
void LeftTraverse(Tree * root, Func func);


//이진탐색트리 함수.
//이진탐색트리 초기화.
void BTreeInit(Tree ** tree);
//데이터 삽입
void InsertData(Tree ** tree, Data data);
//데이터 탐색
Tree * SearchData(Tree * tree, Data target);
//데이터 삭제
Tree * DeleteData(Tree ** tree, Data target);

#endif
