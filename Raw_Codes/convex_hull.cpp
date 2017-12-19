#include <bits/stdc++.h>
 
#define long long long int
using namespace std;
     
#define Max 1000010 
// #define cons 1000000000+7
#define mp make_pair
#define pb push_back
#define INF 1e16
#define INF2 1e9+9
#define pi 3.141592653589
#define x first
#define y second
     

struct point{
    int x, y;
    point(int _x = 0, int _y = 0){
        x = _x, y = _y;
    }
    friend bool operator < (point a, point b){
        return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
    }
};

point pt[2*Max], hull[2*Max];
int idx=0,cur;
// Area of the triangle formed by the ordered triplet (a, b, c)
// Returns a positive value if a -> b -> c forms a counterclockwise turn
inline long area(point a, point b, point c){
    return (b.x - a.x) * 1LL * (c.y - a.y) - (b.y - a.y) * 1LL * (c.x - a.x);
}

// Distance between points a and b
inline long dist(point a, point b){
    return (a.x - b.x) * 1LL * (a.x - b.x) + (a.y - b.y) * 1LL * (a.y - b.y);
}

// Returns true if b is to the right quadrant with respect to a as the origin
inline bool is_right(point a, point b){
    int dx = (b.x - a.x);
    int dy = (b.y - a.y);
    return (dx > 0) || (dx == 0 && dy > 0);
}

// Sorts all points in counterclockwise order with respect to pt[1]
inline bool compare(point b, point c){
    long det = area(pt[1], b, c);
    if(det == 0){
        // If one is to the right of pt[1] and other isn't
        if(is_right(pt[1], b) != is_right(pt[1], c))
            return is_right(pt[1], b);
        return (dist(pt[1], b) < dist(pt[1], c));
    }
    return (det > 0);
}

// Convex Hull of pt[] array :
// hull[] stores the convex hull in ccw order, idx denotes # of points in hull[]
void convexHull(){
    int min_x = pt[1].x, min_y = pt[1].y, min_idx = 1;
    // Find lowest point, it's always in the hull
    for(int i = 2; i <= cur; i++){
        if(pt[i].y < min_y || (pt[i].y == min_y && pt[i].x < min_x)){
            min_x = pt[i].x;
            min_y = pt[i].y;
            min_idx = i;
        }
    }
    swap(pt[1], pt[min_idx]);
    // Sort all points with respect to lowest point
    sort(pt + 2, pt + 1 + cur, compare);
    idx = 2;

    // for(int i=1;i<=cur;i++)
    //  cout<<pt[i].x<<" "<<pt[i].y<<" "<<i<<endl;
    // Add first 3 points to the stack and simulate the process
    hull[1] = pt[1], hull[2] = pt[2];
    for(int i = 3; i <= cur; i++){
        // Clockwise turn --> pop()
        while(idx>=2 && (area(hull[idx - 1], hull[idx], pt[i]) <= 0)) idx-- ;
        
        hull[++idx] = pt[i] ;
    }
}

double distance(int i,int j,int k)
{
    // cout<<i<<" "<<j<<" "<<k<<endl;
    double denom1=hull[i].x-hull[j].x;
    double denom2=hull[i].y-hull[j].y;

    double num1=hull[k].x-hull[i].x;
    double num2=hull[k].y-hull[i].y;

    double num=num2*denom1-num1*denom2;
    num=abs(num);

    denom1*=denom1;
    denom2*=denom2;
    double denom=sqrt(denom1+denom2);

    // cout<<num<<endl;
    return (num/denom);
}

void solve(int n)
{
    double dis=0;
    int cur=-1;

    for(int i=3;i<=n;i++){
        double temp_dis=distance(1,2,i);
        if(temp_dis>dis){
            dis=temp_dis;
            cur=i;
        }
        else
            break;
    }
    double ans=dis;
    // cout<<ans<<endl;

    int first=cur;

    for(int i=2;i<=n;i++){
        int j=(i+1);
        if(j==n+1)
            j=1;
        int temp=cur+1;
        dis=distance(i,j,cur) ;
        if(temp==n+1)
            temp=1;

        while(true){
            double dis2=distance(i,j,temp);
            if(dis2>dis){
                dis=dis2;
                cur=temp;
            }
            else
                break;
            temp++;
            if(temp==n+1)
            temp=1;
        }
        // cout<<dis<<endl;
        ans=min(ans,dis);
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;
}


int main(){
    int n,r ;
    cin >>n >> r;

    map<pair<int,int>,int> m;

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        m[{x,y}]=1;
    }
    n=0 ;

    for(auto itr:m){
        pt[++n]=point(itr.x.x,itr.x.y);
    }

    cur=n;
    // cout<<n<<endl;
    convexHull() ;
    n=idx;
    /*for(int i=1;i<=idx;i++)
    {
     cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }*/
    solve(n);
}