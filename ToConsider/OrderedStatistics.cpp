#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  pair<int,int>,
  null_type,
  less<pair<int,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

 
    ordered_set t;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        ans[t.order_of_key({x,++sz})]++;
        t.insert({x,sz});
    }
 
    for(int i=0;i<n;i++)
        cout<<ans[i]<<'\n';
// If we want to get map but not the set, as the second argument type must be used mapped type. Apparently, the tree supports the same operations as the set (at least I haven't any problems with them before), but also there are two new features — it is find_by_order() and order_of_key(). The first returns an iterator to the k-th largest element (counting from zero), the second — the number of items in a set that are strictly smaller than our item. Example of use:


//     ordered_set X;
//     X.insert(1);
//     X.insert(2);
//     X.insert(4);
//     X.insert(8);
//     X.insert(16);

//     cout<<*X.find_by_order(1)<<endl; // 2
//     cout<<*X.find_by_order(2)<<endl; // 4
//     cout<<*X.find_by_order(4)<<endl; // 16
//     cout<<(end(X)==X.find_by_order(6))<<endl; // true

//     cout<<X.order_of_key(-5)<<endl;  // 0
//     cout<<X.order_of_key(1)<<endl;   // 0
//     cout<<X.order_of_key(3)<<endl;   // 2
//     cout<<X.order_of_key(4)<<endl;   // 2
//     cout<<X.order_of_key(400)<<endl; // 5

