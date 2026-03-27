#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, k , x0, y0;
struct point{
    int x = 0;
    int y = 0;
};
struct node{
    point site = {0, 0};
    vector<node*> children;
    int lenth = 0;
};
void addnode(node* site0, int x_new, int y_new){
    if(site0->site.x + x_new < n && site0->site.y + y_new < n && site0->site.x + x_new >= 0 && site0->site.y + y_new >= 0){
        node* child = new node;
        child->site.x = site0->site.x + x_new;
        child->site.y = site0->site.y + y_new;
        site0->children.push_back(child);
        site0->lenth++;
        return;
    }
    else return;
}
void addall(node* sitechild){
    addnode(sitechild, 1, 2);
    addnode(sitechild, 1, -2);
    addnode(sitechild, 2, 1);
    addnode(sitechild, 2, -1);
    addnode(sitechild, -1, 2);
    addnode(sitechild, -1, -2);
    addnode(sitechild, -2, 1);
    addnode(sitechild, -2, -1);
    return;
}
int main(){
    cin >> n >> k >> x0 >> y0;
    vector<vector<bool>> map(n, vector<bool>(n, false));
    node* root = new node;
    root->site.x = x0 - 1;
    root->site.y = y0 - 1;
    queue<node*> que;
    que.push(root);
    //创建全部节点集合 避免死循环
    vector<node*> all;
    //遍历首节点的所有子节点
    for(int i = 0; i < k; i++){
        addall(que.front());
        node head = *que.front();
        for(int j = 0; j < head.lenth; j++){
            que.push(head.children[j]);
        }
        que.pop();
    }
    queue<node*> que_;
    que_.push(root);
    while(true){
        if(que_.empty()) break;
        else{
            //添加头节点的所有子节点到队列
            for(int i = 0; i < que_.front()->lenth; i++){
                //判断头节点的第i个节点已经探索
                bool in = false;
                for(int j = 0; j < (int)all.size(); j++){
                    if(que_.front()->children[i] == all[j]){
                        in = true;
                    }
                }
                if(in) continue;
                //把第i个子节点分别添加到队列和vector
                else{
                    que_.push(que_.front()->children[i]);
                    all.push_back(que_.front()->children[i]);
                }
            }
            //把头结点添加到地图中
            map[que_.front()->site.x][que_.front()->site.y] = true;
            que_.pop();
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            if(map[i][j]){
                ans = ans+1;
            }
        }
    }
    cout << ans;
    return 0;
}