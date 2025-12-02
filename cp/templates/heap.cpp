#include <bits/stdc++.h>

using namespace std;


class Heap{
    int size=0;
    vector<int> tree;

    public:
    Heap(){
        tree.push_back(-1);
    }
    
    void push(int val)
    {
        size++;
        int index=size;
        tree.push_back(val);

        while(!isRoot(index)){
            int parent=index/2;

            if(tree[parent]<tree[index])
            {
                swap(tree[parent],tree[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void pop(){

        tree[root()]=tree[size];
        int index=root();
        tree.pop_back();
        size--;

        while(index!=-1 || isnode(index))
        {
            int child=-1;
            int left=2*index;
            int right=2*index+1;

            if(isnode(left) && tree[left]>tree[index])
            {
                child=left;
            }

            if(isnode(right) && tree[right]>tree[left])
            {
                child=right;
            }

            if(child!=-1)
            {
                swap(tree[index],tree[child]);
            }
            else{
                break;
            }
            index=child;
        }
    }

    void heapify(vector<int> &arr,int n,int ind){
        //same process that we do in delete
    }

    bool isRoot(int index)
    {
        return index==1;
    }

    bool isnode(int index)
    {
        return index<=size;
    }

    int root(){
        return 1;
    }

    void print(){
        for(auto &x:tree)
        {
            if(x==-1) continue;
            cout<<x<<" ";
        }
        cout<<endl;
    }
};


int main(){

    Heap a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);

    a.print();
    a.pop();
    a.print();

}