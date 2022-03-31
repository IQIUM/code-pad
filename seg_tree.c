#include <stdio.h>  

//定义最大的节点个数
#define MAX_LEN 1000

/**
 * arr: 代表原数组
 * tree： 代表我们要建的那个树
 * node: 代表从那个节点开始
 * start: 代表节点开始区间
 * end： 代表节点结束区间
 */
void build_tree(int arr[],int tree[],int node,int start,int end){
    //递归建树
    //出口
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    //返回中间数
    int mid = (start+end)/2;
    //建左子树
	int left_node = 2*node + 1;
    build_tree(arr,tree,left_node,left,mid);
    //建右子树
    int right_node = 2*node + 2;
    build_tree(arr,tree,right_node,mid+1,right);

    tree[node] = tree[left_node]+tree[right_node];

}

/**
* 函数功能：把arr[idx] 更新为 val
* tree： 代表 树
* node: 当前节点
* idx: 索引
*/
void update_tree(int arr[],int tree[],int node,int start,int end,int idx,int val){
	//递归搜索
    if(start == end){
        arr[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    int left_node = 2*node + 1;
    int right_node = 2*node +2;
    //确认修改的是左分支还是右分支
    if(idx >= start && idx <= mid){
		update_tree(tree,left_node,start,mid,idx,val);
    } else {
        update_tree(tree,right_node,mid+1,end,idx,val);
    }
    //修改完分支 更新 tree[node]
    tree[node] = tree[left_node] + tree[right_node];
}


/**
 * 函数功能；查询由L到R这段的数据和
 */
void query_tree(int arr[],int tree[],int node,int start,int end,int L,int R){
	if(L > end || R < start){
        return 0;
    } else if(start == end){
		return tree[node]; 
    } else if(start <= L && R <= end){
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left_node = 2*node + 1;
    int right_node = 2*node + 2;

    int sum_left = query_tree(arr,tree,left_node,start,mid,L,R);
    int sum_right = query_tree(arr,tree,right_node,mid+1,end,L,R);
    return sum_left+sum_right;
}



int main(){
	//准备工作
    int arr[] = {1,3,5,7,9,11};
    int size = 6;
    int tree[MAX_LEN] = {0};

	build_tree(arr,tree,0,0,size-1);

    return 0;
}